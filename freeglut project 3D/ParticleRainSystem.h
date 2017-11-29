#ifndef _ParticleRainSystem_H_
#define _ParticleRainSystem_H_
/*
Sistema de part�culas que simula la lluvia 
mediante un flujo constante de part�culas generadas
en una altura determinada y que caen,
muriendo a los pocos segundos.
*/

#include "Objeto3DFisico.h"
#include "Particles.h"
#include "World.h"
#include <list>

class ParticleRainSystem :  public Objeto3DFisico
{
public:
	ParticleRainSystem(World* world, PuntoVector3D pos, GLfloat r);
	virtual ~ParticleRainSystem();

	virtual void dibuja();							// Viene de Objeto3D. Dibuja el vector.
	virtual void update(GLfloat dt);					//Update de las particulas: Determina su pos y vida.

	Particles *createParticle();					//Creadora din�mica de part�culas

private:
	std::list<Particles*> particles;			//Vector de part�culas
	
	GLfloat radius_;
};
#endif
