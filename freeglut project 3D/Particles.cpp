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
	pos_ = p;
	posInicial = pos_;
	acc_ = PuntoVector3D(0, 0, 0, 1);
	segundos_ = glutGet(GLUT_ELAPSED_TIME);
	life_ = world_->getRandomNum(minVida, maxVida);
	lifeAct_ = life_;
	gravedad_ = gravedad;
	size_ = 1;
}


Particles::~Particles()
{
}
void Particles::dibuja() {
	if (activa) {
		glPushMatrix();

		glTranslated(pos_.getX(), pos_.getY(), pos_.getZ());
		glColor4f(color_.getX(), color_.getY(), color_.getZ(), color_.getA());
		//std::cout << vidaAct / vida << " !- - - - -! "<< (int)(color.getA() * 10) / 10.0 <<  " Cual es la puta diferencia" << "\n";//descomentar si quieres una bomba nucelar
		glutSolidSphere(size_, 5, 5);

		glPopMatrix();
	}
}


void Particles::update(GLfloat dt) {
	dt -= segundos_;
	dt /= 10000;

	PuntoVector3D aceleration = computeForces();
	aceleration.mult(dt);
	vel_.sumar(&aceleration);

	PuntoVector3D Velocidad(vel_);
	Velocidad.mult(dt);

	pos_.sumar(&Velocidad);
	acc_.mult(0);

	lifeAct_--;
	if (pos_.getY() <= BOTTOM_DEADZONE || pos_.getY() >= TOP_DEADZONE || lifeAct_ <= 0) {
		//resetea();
		setDestroy(true);
	}

}
PuntoVector3D Particles::computeForces(){
	acc_.sumar(&PuntoVector3D(0, gravedad_, 0, 0));
	return acc_;
}
void Particles::reset()
{
	if (pos_.getY() <= BOTTOM_DEADZONE) {
		setPos(PuntoVector3D(pos_.getX(), world_->getRandomNum(300, 350), pos_.getZ(), 0));
		segundos_ = glutGet(GLUT_ELAPSED_TIME);
		setVel(PuntoVector3D(0, 0, 0, 0));
	}
}
