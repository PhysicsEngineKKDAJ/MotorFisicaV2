#ifndef _ParticleRainSystem_H_
#define _ParticleRainSystem_H_

#include "Objeto3D.h"
#include <vector>
#include "Particles.h"

class ParticleRainSystem :
	public Objeto3D
{
public:
	ParticleRainSystem();
	virtual ~ParticleRainSystem();
	virtual void dibuja();
	virtual void update(GLfloat dt);
	Particles *creaParticula();
private:
	std::vector<Particles*> Vector;
};
#endif
