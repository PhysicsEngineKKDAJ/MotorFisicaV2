#ifndef _H_Test1_H_
#define _H_Test1_H_

#include "World.h"
#include "Objeto3DFisico.h"

class Test1
{
public:
	Test1();
	~Test1();

	void dibuja();

private:
	GLfloat lastTimeUpdate, frequency;

	Objeto3DFisico * rainParticles1;
	Objeto3DFisico * rainParticles2;

	World* world_;
};
#endif

