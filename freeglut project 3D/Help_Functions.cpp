#include "Includes.h"
#include "Help_Functions.h"

//------------------VECTOR OPERATIONS----------------------------
//Multiplicación de todas las coordenas de dos vectores, entra para calcular colision
double dotProduct(PuntoVector3D& v1, PuntoVector3D& v2) {
	return (v1.getX()*v2.getX() + v1.getY()*v2.getY() + v1.getZ()*v2.getZ());
}
//------------------VECTOR OPERATIONS----------------------------


//-----------------PARTICLES OPERATIONS-------------------------

//Crea un tipo de partículas segun el preset
void InitParticles(vector<Particles*> & particulas, int size, Preset preset)
{
	switch (preset)
	{
		//Partículas con un ID
	case Preset_id:

		for (int i = 0; i<size; i++)
			particulas[i]->id = i;

		break;

		//Partículas con una masa aleatoria
	case Preset_random_m:

		for (int i = 0; i<size; i++)
			particulas[i]->setMasa(2000.0*(rand() % 1000 + 0.001));
		break;

		//Partículas con un radio en función de la masa
	case Preset_radius:

		for (int i = 0; i<size; i++)
			particulas[i]->setRadio(0.75 + 0 * particulas[i]->getMasa()/ (75 * pow(10.0, 10)));
		break;

		//Partículas con una velocidad aleatoria
	case Preset_random_v:

		for (int i = 0; i<size; i++)
			particulas[i]->setVel(PuntoVector3D((rand() % 1000 - 500) / 100.0, (rand() % 1000 - 500) / 100.0, (rand() % 1000 - 500) / 100.0, 1));
		break;

	default:
		break;
	}
}

/*void InitParticles(vector<Estrella> & particulas, int size, Preset preset)
{
	switch (preset)
	{
		//Partículas con un ID
	case Preset_id:

		for (int i = 0; i<size; i++)
			particulas[i].id = i;

		break;

		//Partículas con una masa aleatoria
	case Preset_random_m:

		for (int i = 0; i<size; i++)
			particulas[i].mass = 2000.0*(rand() % 1000 + 0.001);
		break;

		//Partículas con un radio en función de la masa
	case Preset_radius:

		for (int i = 0; i<size; i++)
			particulas[i].radius = 0.75 + 0 * particulas[i].mass / (75 * pow(10.0, 10));
		break;

		//Partículas con una velocidad aleatoria
	case Preset_random_v:

		for (int i = 0; i<size; i++)
			particulas[i].velocity = Vector3d((rand() % 1000 - 500) / 100.0, (rand() % 1000 - 500) / 100.0, (rand() % 1000 - 500) / 100.0);
		break;

	default:
		break;
	}
}*/

//Devuelvo un estado con los atributos de la partícula atributo
State ParticleToState(Particles& particula) {

	State STATE;
	STATE.id = particula.id;
	STATE.mass = particula.getMasa();
	STATE.lastPos = particula.getPos();
	STATE.lastVel = particula.getVel();
	return STATE;
}

//Copia size estados en particulas
void CopyParticles(vector<State> & estados, vector<Particles> & particulas, int size) {
	for (int i = 0; i<size; i++)
		estados[i] = ParticleToState(particulas[i]);
}

/*void CopyParticles(vector<State> & estados, vector<Estrella> & particulas, int size) {
	for (int i = 0; i<size; i++)
		estados[i] = ParticleToState(particulas[i]);
}*/

//Copia size particulas en estados
void CopyStates(State* estados, Particles* particulas, int size) {
	for (int i = 0; i<size; i++)
	{
		particulas[i].setPos(estados[i].lastPos);
		particulas[i].setVel(estados[i].lastVel);
		particulas[i].setAcc(estados[i].lastAcc);
	}
}

//-----------------PARTICLE3D OPERATIONS-------------------------

//-----------------DEBUG---------------------------

//Dibuja una linea desde una posición dada por coordenadas hasta otra dada por un vector
void DrawVector3d(PuntoVector3D& v, double x, double y, double z)
{
	glBegin(GL_LINES);

	glVertex3f(x, y, z);
	glVertex3f(x + v.getX(), y + v.getY(), z + v.getZ());

	glEnd();
}

//-----------------DEBUG---------------------------

//-----------------UTILIDADES---------------------------

//Distancia entre dos puntos
double Distance3d(PuntoVector3D p1, PuntoVector3D p2) {
	double d = sqrt((p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
		(p1.getY() - p2.getY())*(p1.getY() - p2.getY()) +
		(p1.getZ() - p2.getZ())*(p1.getZ() - p2.getZ())
	);
	return d;
}

//Aplica un color del enum del atributo a la matriz de modelado
void SetColor(COLOR color) {

	switch (color)
	{
	case BLACK:
		glColor3f(0.0, 0.0, 0.0);
		break;

	case G75:
		glColor3f(0.75, 0.75, 0.75);
		break;

	case G50:
		glColor3f(0.5, 0.5, 0.5);
		break;

	case G25:
		glColor3f(0.25, 0.25, 0.25);
		break;

	case WHITE:
		glColor3f(1.0, 1.0, 1.0);
		break;

	case RED:
		glColor3f(1.0, 0.0, 0.0);
		break;

	case GREEN:
		glColor3f(0.0, 1.0, 0.0);
		break;

	case BLUE:
		glColor3f(0.0, 0.0, 1.0);
		break;

	case YELLOW:
		glColor3f(1.0, 1.0, 0.0);
		break;

	case MAGENTA:
		glColor3f(1.0, 0.0, 1.0);
		break;
	default:
		break;
	}
}
//-----------------UTILIDADES---------------------------

