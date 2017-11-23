#ifndef _H_Test1_H_
#define _H_Test1_H_

#include "World.h"
#include "Particles.h"

class Test1
{
public:
	Test1();
	~Test1();
	void creaParticulas(int num);
	void dibuja();
private:
	Objeto3D* creaParticula();
	GLfloat lastTimeUpdate = 0;
	GLfloat frecuencia = 10;
	World* world_;
	Objeto3D * lluviaP;
	Objeto3D** objetos;
	int numParticulas;
};
#endif

