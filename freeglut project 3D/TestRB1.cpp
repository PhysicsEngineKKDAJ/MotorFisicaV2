#include "TestRB1.h"
#include "RigidbodySpawn.h"

TestRB1::TestRB1() : lastTimeUpdate(0), frecuency(10)
{
	world_ = new World();
	spawn = new RigidbodySpawn(world_);
}


TestRB1::~TestRB1()
{
	delete world_;
	delete spawn;
}

void TestRB1::dibuja() {
	GLfloat ticks = glutGet(GLUT_ELAPSED_TIME);
	spawn->dibuja();

	if (lastTimeUpdate + frecuency <= ticks) 
		spawn->update(ticks);
}
