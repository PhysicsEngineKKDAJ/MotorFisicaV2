#include "Particles.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>

Particles::Particles(World *world,PuntoVector3D p, GLfloat maxVida, GLfloat minVida) :Objeto3DFisico()
{
	world_ = world;
	pos_ =  p;
	vel_ = PuntoVector3D(0, 0, 0, 1);
	acc_ = PuntoVector3D(0, world->getGravity()->getY(), 0, 1);
	seconds_ = glutGet(GLUT_ELAPSED_TIME);
	life_ = lifeAct_ =world_->getRandomNum(minVida, maxVida);
	size_ = 1;
}

Particles::Particles(World *world, PuntoVector3D p, PuntoVector3D v, double r, double m) :Objeto3DFisico()
{
	world_ = world;
	pos_ = p;
	vel_ = v;
	masa_ = m;
	radio_ = r;
	
}


Particles::~Particles()
{
}
void Particles::dibuja() {
	
	glPushMatrix();

	glTranslated(pos_.getX(), pos_.getY(), pos_.getZ());
	glColor4f(color_.r, color_.g, color_.b, color_.a);

	glutSolidSphere(size_, 5, 5);

	glPopMatrix();
	
}


void Particles::update(GLfloat dt) {
	dt -= seconds_;
	dt /= 10000;

	PuntoVector3D aceleration = acc_;
	aceleration.mult(dt);

	vel_.sumar(&aceleration);

	PuntoVector3D Velocidad= vel_;
	Velocidad.mult(dt);

	pos_.sumar(&Velocidad);

	lifeAct_--;
	if (pos_.getY() <= DeadTriggerDown || pos_.getY() >= DeadTriggerUp || lifeAct_ <= 0)
		setDestroy(true);
	

}
