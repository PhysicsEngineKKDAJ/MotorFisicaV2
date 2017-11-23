#include "Rigidbody.h"

#define BOTTOM_DEADZONE 0
#define TOP_DEADZONE 800

Rigidbody::Rigidbody(PuntoVector3D pos, GLfloat gravedad)
{
	pos_ = pos;
	posInicial = pos;
	acc_ = PuntoVector3D(0, 0, 0, 1);
	segundos_ = glutGet(GLUT_ELAPSED_TIME);

	gravedad_ = gravedad;
	size_ = 1;
	cubo = new Cubo(10, Color{ 1.0,1.0, 1.0 });
}


Rigidbody::~Rigidbody()
{
}
void Rigidbody::dibuja() {

	glPushMatrix();


	glColor4f(color_.getX(), color_.getY(), color_.getZ(), 1);
	cubo->dibuja();
	glPopMatrix();

}
void Rigidbody::update(GLfloat dt) {
	dt -= segundos_;
	dt /= 1000000;

	PuntoVector3D aceleration = computeForces();

	aceleration.mult(dt);
	vel_.sumar(&aceleration);
	PuntoVector3D Velocidad(vel_);
	Velocidad.mult(dt);
	pos_.sumar(&Velocidad);
	acc_.mult(0);
	cubo->getmT()->reset();
	cubo->traslada(&pos_);

	if (cubo->getmT()->getM()[13] <= BOTTOM_DEADZONE || cubo->getmT()->getM()[13] >= TOP_DEADZONE)
		setDestroy(true);
}

PuntoVector3D Rigidbody::computeForces(){
	acc_.sumar(&PuntoVector3D(0, gravedad_, 0, 0));
	return acc_;
}
