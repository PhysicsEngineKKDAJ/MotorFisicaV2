#include "Test1.h"

#include "ParticleRainSystem.h"

Test1::Test1() :lastTimeUpdate(0), frequency(10)
{
	world_ = new World();
	rainParticles1 = new ParticleRainSystem(world_,PuntoVector3D(100, 0, 0, 0));
	rainParticles2 = new ParticleRainSystem(world_, PuntoVector3D(0, 0, 100, 0));
}


Test1::~Test1()
{
	delete rainParticles1;
	delete rainParticles2;
}

void Test1::dibuja() {
	GLfloat ticks = glutGet(GLUT_ELAPSED_TIME);
	rainParticles1->dibuja();
	rainParticles2->dibuja();

	if (lastTimeUpdate + frequency <= ticks)
	{
		rainParticles1->update(ticks);
		rainParticles2->update(ticks);
	}
}
