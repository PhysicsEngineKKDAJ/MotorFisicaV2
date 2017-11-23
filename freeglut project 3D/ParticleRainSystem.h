#ifndef _ParticleRainSystem_H_
#define _ParticleRainSystem_H_
/*
Sistema de part�culas que simula la lluvia 
mediante un flujo constante de part�culas generadas
en una altura determinada y que caen,
muriendo a los pocos segundos.
*/

#include <vector>

#include "Objeto3DFisico.h"
#include "Particles.h"

class ParticleRainSystem :  public Objeto3DFisico
{
public:
	ParticleRainSystem();
	virtual ~ParticleRainSystem();
	virtual void dibuja();							// Viene de Objeto3D. Dibuja el vector.
	virtual void update(GLfloat);					//Update de las particulas: Determina su pos y vida.

	Particles *createParticle();					//Creadora din�mica de part�culas

private:
	std::vector<Particles*> particleVector;			//Vector de part�culas
	GLfloat ang;									//Angulo para generar las part�culas
};
#endif
