#include "TestRB1.h"
#include "RigidbodySpawn.h"

TestRB1::TestRB1()
{
	world_ = new World();
	fuente = new RigidbodySpawn();
	fuente->setWorld(world_);
}


TestRB1::~TestRB1()
{
}
void TestRB1::dibuja() {
	GLfloat ticks = glutGet(GLUT_ELAPSED_TIME);
	bool update = false;
	fuente->dibuja();

	if (update || lastTimeUpdate + frecuencia <= ticks) {
		fuente->update(ticks);


	}
}
