#ifndef _TestRB1_H_
#define _TestRB1_H_

#include "world.h"
#include "Objeto3DFisico.h"
class TestRB1
{
public:
	TestRB1();
	~TestRB1();

	void dibuja();

private:
	GLfloat lastTimeUpdate, frecuency;

	Objeto3DFisico* spawn;

	World* world_;
};
#endif