#include "Physics_Functions.h"

const short NumParticulas = 125;

//VARIABLES GLOBALES DE LA CLASE
vector<Particles> particulas(NumParticulas);
//vector<Estrella> estrellas(NumEstrellas);
vector<State> estadoParticulas(NumParticulas);
//vector<State> estadoEstrellas(NumEstrellas);

//Este vector guarda todas las posiciones antiguas de cada particula
vector<vector<PuntoVector3D>> posParticulas(NumParticulas);

PuntoVector3D(*acc_func)(State); //acceleration function pointer
PuntoVector3D ContactNormal; // Vector de la normal cuando dos objetos se colisionan
Particles *P;	//array of particles to reference(p3d or pp3d)
//State *PS;

short P_C;
double b_g = 6.67384*0.000080, s_g; // el 6.67384 es la constante de gravitación universal
const short NumEstrellas = 1000;


PuntoVector3D accUniversalGravitation(State ip)
{

	PuntoVector3D ACCELERATION;
	PuntoVector3D tempAcceleration;

	for (int i = 0; i<P_C; i++)
	{
		//Solo se modifica si el id es distinto a la i
		if (ip.id != i) {

			// supongo que distancia
			double d = sqrt((ip.lastPos.getX() - P[i].getPosX())*(ip.lastPos.getX() - P[i].getPosX()) +
				(ip.lastPos.getY() - P[i].getPosY())*(ip.lastPos.getY() - P[i].getPosY()) +
				(ip.lastPos.getZ() - P[i].getPosZ())*(ip.lastPos.getZ() - P[i].getPosZ())
			);

			double wk = 1.0;
			double f = -b_g*wk*ip.mass*P[i].getMasa() / (d*d);


			tempAcceleration = PuntoVector3D((ip.lastPos.getX() - P[i].getPosX())*f / d / ip.mass, (ip.lastPos.getY() - P[i].getPosY())*f / d / ip.mass,
				(ip.lastPos.getZ() - P[i].getPosZ())*f / d / ip.mass, 1);
			ACCELERATION.sumar(&tempAcceleration);
		}
	}

	return ACCELERATION;

}

PuntoVector3D accDirectionalGravity(State s) { return PuntoVector3D(0, -10, 0, 1); }


// evaluar es que le pasas un indice y le aplica las ecuaciones a la posicion y velocidad.
Derivative evaluate(int ip)
{
	Derivative output;
	output.dPosition = P[ip].getVel();
	output.dVelocity = acc_func(ParticleToState(P[ip])); //arbitrary acceleration function

	return output;
}

// Sobrecarga de la evaluacion, una forma mas compleja
Derivative evaluate(int ip, float dt, Derivative &d)
{
	State state1, state2;
	Derivative output;
	state1.id = ip;
	state1.mass = P[ip].getMasa();
	// dp (derivada de la aceleracion), dt (derivada del tiempo)

	d.dVelocity.mult(0.5*dt*dt);
	d.dPosition.mult(dt);
	d.dPosition.sumar(&d.dVelocity);
	P[ip].getPos().sumar(&d.dPosition);
	state1.lastPos = P[ip].getPos();

	d.dVelocity.mult(dt);
	P[ip].getVel().sumar(&d.dVelocity);
	state1.lastVel = P[ip].getVel();//p''=dv/dt= acceleration

	output.dPosition = state1.lastVel;
	output.dVelocity = acc_func(state1); //arbitrary acceleration function

	return output;
}

// No se usa en la demo
void DirectionalGravity_simple(int ip, Particles* p, short p_c, State& fstate, float dt)
{
	P = p;
	P_C = p_c;
	acc_func = accDirectionalGravity; //Va a dar error si quitamos el state del directionalGravity
	Derivative k1 = evaluate(ip);

	PuntoVector3D dPOSITION;
	PuntoVector3D dVELOCITY;

	dPOSITION = k1.dPosition;
	dVELOCITY = k1.dVelocity;

	dPOSITION.mult(dt);
	fstate.lastPos.sumar(&dPOSITION);

	dVELOCITY.mult(dt);
	fstate.lastVel.sumar(&dVELOCITY);

	fstate.lastAcc = dVELOCITY; //Ya está multiplicado de antes

}

//SE USA CUANDO PULSAS CLICK IZQUIERDO
void DirectionalGravity(int ip, Particles* p, short p_c, State& fstate, float dt)
{
	P = p;
	P_C = p_c;
	acc_func = accDirectionalGravity;

	// Menudos triples me voy a marcar ahora, atentos
	Derivative k1 = evaluate(ip); // determina la curva de la funcion
	Derivative k2 = evaluate(ip, dt * 0.5f, k1); // creo que son los puntos de inflexion
	Derivative k3 = evaluate(ip, dt * 0.5f, k2); // es una constante
	Derivative k4 = evaluate(ip, dt, k3); // tiene que dar 0 para que sea correcto

	//--Cálculos fraccionados para poder operar con PuntoVector3D--

	//Vector3d dPOSITION = 1.0f / 6.0f * (k1.dPosition + 2.0f * (k2.dPosition + k3.dPosition) + k4.dPosition);
	k2.dPosition.sumar(&k3.dPosition);
	k2.dPosition.mult(2.0f);
	k1.dPosition.sumar(&k2.dPosition);
	k1.dPosition.sumar(&k4.dPosition);
	k1.dPosition.mult(6.0f);
	PuntoVector3D dPOSITION = PuntoVector3D(1.0 / k1.dPosition.getX(), 1.0 / k1.dPosition.getY(), 1.0 / k1.dPosition.getZ(), 1);
	
	//Vector3d dVELOCITY = 1.0f / 6.0f * (k1.dVelocity + 2.0f * (k2.dVelocity + k3.dVelocity) + k4.dVelocity);
	k2.dVelocity.sumar(&k3.dVelocity);
	k2.dVelocity.mult(2.0f);
	k1.dVelocity.sumar(&k2.dVelocity);
	k1.dVelocity.sumar(&k4.dVelocity);
	k1.dVelocity.mult(6.0f);
	PuntoVector3D dVELOCITY = PuntoVector3D(1.0 / k1.dVelocity.getX(), 1.0 / k1.dVelocity.getY(), 1.0 / k1.dVelocity.getZ(), 1);

	dPOSITION.mult(dt);
	fstate.lastPos.sumar(&dPOSITION);

	dVELOCITY.mult(dt);
	fstate.lastVel.sumar(&dVELOCITY);
	
	fstate.lastAcc = dVELOCITY;

}

// Solo tiene una diferencia con el metodo anterior
void UniversalGravitation(int ip, Particles* p, short p_c, State& fstate, float dt, double G)
{
	P = p;
	P_C = p_c;

	// Esta es la unica diferencia
	if (G >= 0)
		b_g = G;

	// igual que en el metodo de arriba
	acc_func = accUniversalGravitation;
	Derivative k1 = evaluate(ip);
	Derivative k2 = evaluate(ip, dt * 0.5f, k1);
	Derivative k3 = evaluate(ip, dt * 0.5f, k2);
	Derivative k4 = evaluate(ip, dt, k3);

	//--Cálculos fraccionados para poder operar con PuntoVector3D--

	//Vector3d dPOSITION = 1.0f / 6.0f * (k1.dPosition + 2.0f * (k2.dPosition + k3.dPosition) + k4.dPosition);
	k2.dPosition.sumar(&k3.dPosition);
	k2.dPosition.mult(2.0f);
	k1.dPosition.sumar(&k2.dPosition);
	k1.dPosition.sumar(&k4.dPosition);
	k1.dPosition.mult(6.0f);
	PuntoVector3D dPOSITION = PuntoVector3D(1.0 / k1.dPosition.getX(), 1.0 / k1.dPosition.getY(), 1.0 / k1.dPosition.getZ(), 1);

	//Vector3d dVELOCITY = 1.0f / 6.0f * (k1.dVelocity + 2.0f * (k2.dVelocity + k3.dVelocity) + k4.dVelocity);
	k2.dVelocity.sumar(&k3.dVelocity);
	k2.dVelocity.mult(2.0f);
	k1.dVelocity.sumar(&k2.dVelocity);
	k1.dVelocity.sumar(&k4.dVelocity);
	k1.dVelocity.mult(6.0f);
	PuntoVector3D dVELOCITY = PuntoVector3D(1.0 / k1.dVelocity.getX(), 1.0 / k1.dVelocity.getY(), 1.0 / k1.dVelocity.getZ(), 1);

	dPOSITION.mult(dt);
	fstate.lastPos.sumar(&dPOSITION);

	dVELOCITY.mult(dt);
	fstate.lastVel.sumar(&dVELOCITY);

	fstate.lastAcc = dVELOCITY;
}

// Literalmente lo mismo que DirectionalGravity_simple, excepto por (*)
/*void UniversalGravitation_simple(int ip, Particles* p, short p_c, State& fstate, float dt, double G)
{
	P = p;
	P_C = p_c;

	// (*)
	if (G >= 0)
		b_g = G;
	// (*)

	acc_func = accUniversalGravitation;
	Derivative k1 = evaluate(ip);

	Vector3d dPOSITION;
	Vector3d dVELOCITY;

	dPOSITION = k1.dPosition;
	dVELOCITY = k1.dVelocity;

	fstate.Position += dPOSITION*dt;
	fstate.Velocity += dVELOCITY*dt;
	fstate.Acceleration = dVELOCITY*dt;

}*/


// Se utiliza cuando va a colisionar un objeto con otro
void dImpenetrationResolution(int i, int j, Particles *p, State *ps)
{
	// previous distances i & j
	double di = Distance3d(p[i].getPos(), ps[i].lastPos);
	double dj = Distance3d(p[j].getPos(), ps[j].lastPos);

	// Comprueba si las particulas estan separadas, solapadas o pegandose.
	// Es como una zona muerta
	double err_l = abs((p[i].getRadio() + p[j].getRadio()) - Distance3d(p[i].getPos(), p[j].getPos()));

	// dos variables que son las magnitudes de las coordenadas de la particula
	double vm1 = p[i].getVel().Magnitude(), vm2 = p[j].getVel().Magnitude();

	// ???????????????????
	double tv = 1.0 / (p[j].getMasa() + vm2) + 1.0 / (p[i].getMasa() + vm1);


	PuntoVector3D mv = ContactNormal;
	mv.normalizar();

	// a la normal de la colision le multilpicamos el error entre
	double division = (-err_l / tv);
	mv.mult(division);

	//ps[i].Position += mv * (1 / (-p[i].mass + vm1)),
	double cuenta = (1 / (-p[i].getMasa() + vm1));
	mv.mult(cuenta);
	ps[i].lastPos.sumar(&mv);

	//ps[j].Position += mv * (1 / (p[j].mass + vm2));
	double cuentaCuentos = (1 / (p[j].getMasa() + vm2));
	mv.mult(cuentaCuentos);
	ps[j].lastPos.sumar(&mv);
	
}

void CollisionResolution(int p_c, Particles *p, State *ps)
{
	double d1, d2; // estas seran las deltas de las funciones
	double ra, rb; // supongo que son los radios de las esferas
	double err_l;
	double C = 0.60;
	PuntoVector3D Normal, Tangent, Tangent2, Tangent3;

	for (int i = 0; i < p_c; i++) {
		for (int j = i; j < p_c; j++) {
			// ponemos el resto del codigo en la condicion y quitamos el continue
			if (i == j)
				continue;

			// distancia entre los objetos
			double d = (Distance3d(ps[i].lastPos, ps[j].lastPos) - (p[i].getRadio() + p[j].getRadio()));
			if (d < 0) {
				Normal = PuntoVector3D(ps[i].lastPos.getX() - ps[j].lastPos.getX(), ps[i].lastPos.getY() - ps[j].lastPos.getY(),
					ps[i].lastPos.getZ() - ps[j].lastPos.getZ(), 1);
				Normal.normalizar();
				ContactNormal = Normal;

				// Comprobacion de la colision
				dImpenetrationResolution(i, j, p, ps);

				ps[i].lastVel.resta(&ps[j].lastVel);
				double separatingVelocity = dotProduct(ps[i].lastVel, Normal);
				double newSepVelocity = -separatingVelocity * C;
				double deltaVelocity = newSepVelocity - separatingVelocity;

				// no lo entiendo muy bien la verdad
				const double totalInverseMass = 1.0 / (ps[i].mass) + 1.0 / (ps[j].mass);

				// Calculate the impulse to apply.
				double impulse = deltaVelocity / totalInverseMass;
				// Find the amount of impulse per unit of inverse mass.
				Normal.mult(impulse);
				PuntoVector3D* normalI = Normal.clonar();
				PuntoVector3D* normalJ = Normal.clonar();
				// Apply impulses: they are applied in the direction of the contact,
				// and are proportional to the inverse mass.
				double calculoI = (1 / ps[i].mass);
				double calculoJ = (- 1 / ps[j].mass);
				normalI->mult(calculoI);
				normalJ->mult(calculoJ);
				ps[i].lastVel.sumar(normalI);
				ps[j].lastVel.sumar(normalJ);
				//ps[i].Velocity = ps[i].Velocity + impulsePerIMass * (1 / ps[i].mass);
			}


		}
	}


}

/*
******************************************
******************************************
MÉTODOS EN DESUSO
******************************************
******************************************
*/


/* MÉTODO ENCARGADO DE CALCULAR LAS COLISIONES ENTRE UNA PARTÍCULA Y EL PLANO (SUELO) DE LA SIMULACIÓN */

//IMPORTANTE: NO SE USA ACTUALMENTE EN LA SIMULACIÓN 
/*void CollisionResolution_Ground(int p_c, Particles *p, State *ps) {

	//VARIABLES LOCALES
	PuntoVector3D Tangent, Tangent2, Tangent3;
	double v1n, v1t;
	double v1n2, v1t2;
	double v1n3, v1t3;
	double v1np;
	double C = 0.45;
	double groundMass = 9999999999;

	//Normalizamos Vector de la normal global
	ContactNormal.set(0, 1, 0);
	ContactNormal.Normalize();

	for (int i = 0; i<p_c; i++)
	{
		//Si la partícula ha llegado a una posición en Y determinada (< -25)
		if (ps[i].Position.y<-25)
		{
			//Recalculamos su posición para dejarla en la posición límite
			ps[i].Position.y = -25;

			PuntoVector3D &s1 = ps[i].Velocity;

			//Damos valor a las 3 tangentes para que estén acordes al plano
			Tangent.set(-ContactNormal.y, ContactNormal.x, 0);
			Tangent2.set(-ContactNormal.z, 0, ContactNormal.x);
			Tangent3.set(0, -ContactNormal.z, ContactNormal.y);

			//Suma de las normales del plano
			v1n = ContactNormal.x*s1.x + ContactNormal.y*s1.y + ContactNormal.z*s1.z;

			//Damos valor a la suma de los vectores entre tangentes y estado de partícula
			v1t = Tangent.x*s1.x + Tangent.y*s1.y;
			v1t2 = Tangent2.x*s1.x + Tangent2.z*s1.z;
			v1t3 = Tangent3.z*s1.z + Tangent3.y*s1.y;

			//Coeficiente de choque
			v1np = (v1n*(ps[i].mass - C*groundMass) + 0 * groundMass*(C + 1)) / (ps[i].mass + groundMass);

			//Añadimos al estado del cuerpo (partícula) la velocidad resultante del choque con el plano (rebote)				
			ps[i].Velocity.x = ContactNormal.x*v1np + Tangent.x*v1t + Tangent2.x*v1t2 + Tangent3.x*v1t3;
			ps[i].Velocity.y = ContactNormal.y*v1np + Tangent.y*v1t + Tangent2.y*v1t2 + Tangent3.y*v1t3;
			ps[i].Velocity.z = ContactNormal.z*v1np + Tangent.z*v1t + Tangent2.z*v1t2 + Tangent3.z*v1t3;


		}
	}

}*/



/*void CollisionResolution2(int p_c, Particle3d *p, State *ps)
{
Vector3d Normal, Tangent, Tangent2, Tangent3;
double ra, rb;
double err_l;
double C=.5;

for(int i=0; i<p_c; i++)
{
for(int j=i; j<p_c; j++)
{
if(i==j)
continue;

double d=(Distance3d(ps[i].Position, ps[j].Position)-(p[i].radius+p[j].radius));
if( d<0)
{
Normal.set(ps[i].Position.x-ps[j].Position.x, ps[i].Position.y-ps[j].Position.y,ps[i].Position.z-ps[j].Position.z);
Normal.Normalize();
ContactNormal=Normal;
dImpenetrationResolution(i, j, p, ps);

Vector3d &s1=ps[i].Velocity, &s2=ps[j].Velocity;

double v1n, v1t, v2n, v2t;
double v1n2, v1t2, v2n2, v2t2;
double v1n3, v1t3, v2n3, v2t3;
double v1np, v2np;


Tangent.set(-Normal.y, Normal.x, 0);
Tangent2.set(-Normal.z, 0, Normal.x);
Tangent3.set(0, -Normal.z, Normal.y);
v1n=Normal.x*s1.x + Normal.y*s1.y + Normal.z*s1.z;
v2n=Normal.x*s2.x + Normal.y*s2.y + Normal.z*s2.z;

v1t=Tangent.x*s1.x + Tangent.y*s1.y;
v2t=Tangent.x*s2.x + Tangent.y*s2.y;
v1t2=Tangent2.x*s1.x + Tangent2.z*s1.z;
v2t2=Tangent2.x*s2.x + Tangent2.z*s2.z;
v1t3=Tangent3.z*s1.z + Tangent3.y*s1.y;
v2t3=Tangent3.z*s2.z + Tangent3.y*s2.y;

v1np=(v1n*(ps[i].mass-C*ps[j].mass)+ v2n*ps[j].mass*(C+1))/(ps[i].mass+ps[j].mass);
v2np=(v2n*(ps[j].mass-C*ps[i].mass)+ v1n*ps[i].mass*(C+1))/(ps[i].mass+ps[j].mass);

ps[i].Velocity.x=Normal.x*v1np+ Tangent.x*v1t + Tangent2.x*v1t2 + Tangent3.x*v1t3;
ps[i].Velocity.y=Normal.y*v1np+ Tangent.y*v1t + Tangent2.y*v1t2 + Tangent3.y*v1t3;
ps[i].Velocity.z=Normal.z*v1np+ Tangent.z*v1t + Tangent2.z*v1t2 + Tangent3.z*v1t3;
ps[j].Velocity.x=Normal.x*v2np+ Tangent.x*v2t + Tangent2.x*v2t2 + Tangent3.x*v2t3;
ps[j].Velocity.y=Normal.y*v2np+ Tangent.y*v2t + Tangent2.y*v2t2 + Tangent3.y*v2t3;
ps[j].Velocity.z=Normal.z*v2np+ Tangent.z*v2t + Tangent2.z*v2t2 + Tangent3.z*v2t3;
}

}

}


}*/