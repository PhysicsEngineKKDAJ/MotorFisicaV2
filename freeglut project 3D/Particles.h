#ifndef _Particles_H_
#define _Particles_H_

#include "Objeto3DFisico.h"
#include "World.h"

class Particles : public Objeto3DFisico
{
public:
	Particles(World *world,PuntoVector3D p, GLfloat minLife, GLfloat maxLife);
	~Particles();
	virtual	void dibuja();						//Dibuja una partícula
	virtual void update(GLfloat dt);			//Update de una partícula

private:
	int seconds_;								//Cuenta la vida de la particula
	const int DeadTriggerUp = 300;
	const int DeadTriggerDown = 0;
	/*
	GLfloat mass;
	PuntoVector3D forceAccumulator;
	bool activa;								//Si la particula está viva o no.
	*/
};
#endif
