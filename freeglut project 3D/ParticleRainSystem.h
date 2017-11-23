#ifndef _ParticleRainSystem_H_
#define _ParticleRainSystem_H_
/*
Sistema de partículas que simula la lluvia 
mediante un flujo constante de partículas generadas
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

	Particles *createParticle();					//Creadora dinámica de partículas

private:
	std::vector<Particles*> particleVector;			//Vector de partículas
	GLfloat ang;									//Angulo para generar las partículas
};
#endif
