#ifndef _H_Test1_H_
#define _H_Test1_H_

#include "World.h"
#include "Particles.h"

class Test1
{
public:
	Test1();
	~Test1();
	void createParticles(int num);
	void draw();
private:
	Particles* createParticle();
	GLfloat lastTimeUpdate = 0;
	GLfloat frequency = 10;
	World* world_;
	Objeto3DFisico * rainP;
	int numParticles;
};
#endif

