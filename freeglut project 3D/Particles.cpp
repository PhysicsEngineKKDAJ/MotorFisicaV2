#include "Particles.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>

#define TOP_DEADZONE 200
#define BOTTOM_DEADZONE 0

Particles::Particles(PuntoVector3D p, GLfloat gravedad, GLfloat maxVida, GLfloat minVida) :Objeto3DFisico()
{
	pos = p;
	posInicial = pos;
	acc = PuntoVector3D(0, 0, 0, 1);
	segundos_ = glutGet(GLUT_ELAPSED_TIME);
	life = world->getNumRandom(maxVida, minVida);
	lifeAct = life;
	gravedad_ = gravedad;
	size = 1;
}


Particles::~Particles()
{
}
void Particles::dibuja() {
	if (activa) {
		glPushMatrix();

		glTranslated(pos.getX(), pos.getY(), pos.getZ());
		glColor4f(color.getX(), color.getY(), color.getZ(), color.getA());
		//std::cout << vidaAct / vida << " !- - - - -! "<< (int)(color.getA() * 10) / 10.0 <<  " Cual es la puta diferencia" << "\n";//descomentar si quieres una bomba nucelar
		glutSolidSphere(size, 5, 5);
		glPopMatrix();
	}
}


void Particles::update(GLfloat dt) {
	dt -= segundos_;
	dt /= 10000;

	PuntoVector3D aceleration = computeForces();
	aceleration.mult(dt);
	vel.sumar(&aceleration);

	PuntoVector3D Velocidad(vel);
	Velocidad.mult(dt);

	pos.sumar(&Velocidad);
	acc.mult(0);

	lifeAct--;
	if (pos.getY() <= BOTTOM_DEADZONE || pos.getY() >= TOP_DEADZONE || lifeAct <= 0) {
		//resetea();
		setDestroy(true);
	}

}
PuntoVector3D Particles::computeForces(){
	acc.sumar(&PuntoVector3D(0, gravedad_, 0, 0));
	return acc;
}
void Particles::reset()
{
	if (pos.getY() <= BOTTOM_DEADZONE) {
		setPos(PuntoVector3D(pos.getX(), world->getNumRandom(350, 300), pos.getZ(), 0));
		segundos_ = glutGet(GLUT_ELAPSED_TIME);
		setVel(PuntoVector3D(0, 0, 0, 0));
	}
}
