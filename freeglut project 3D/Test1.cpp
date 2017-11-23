#include "Test1.h"

#include "ParticleRainSystem.h"

Test1::Test1()
{
	world_ = new World();
	rainP = new ParticleRainSystem();
	rainP->setWorld(world_);
}


Test1::~Test1()
{
}

void Test1::draw() {
	GLfloat ticks = glutGet(GLUT_ELAPSED_TIME);
	bool update = false;
	rainP->dibuja();

	if (update || lastTimeUpdate + frequency <= ticks) 
		rainP->update(ticks);
}

Particles* Test1::createParticle()
{
	Particles* p = new Particles(PuntoVector3D(0, 1, 0, 0));
	p->setColor(PuntoVector3D(world_->getRandomNum(0.5, 1), world_->getRandomNum(0, 0.5), 0, 0));
	p->setVel(PuntoVector3D(world_->getRandomNum(-50, 50), 50, world_->getRandomNum(-50, 50), 1));
	p->setWorld(world_);
	return p;
}

