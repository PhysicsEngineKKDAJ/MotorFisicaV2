#include "RigidbodySpawn.h"
#include "Rigidbody.h"
#include "MassCenter.h"

RigidbodySpawn::RigidbodySpawn()
{
}


RigidbodySpawn::~RigidbodySpawn()
{
	for (auto p : Vector) {
		delete p;

	}
}
void RigidbodySpawn::update(GLfloat dt)
{
	for (size_t i = 0; i < Vector.size(); i++)
	{
		Vector[i]->setColor(PuntoVector3D(0, 0.3, 0.6, (int)((Vector[i]->getLifeAct() / Vector[i]->getLife()) * 10) / 10.0));
		Vector[i]->update(dt);
		if (Vector[i]->getDestroy()) {
			Vector.erase(Vector.begin() + i);
		}
	}
	if (Vector.size() < 1)
		Vector.push_back(creaParticula());
}


Rigidbody* RigidbodySpawn::creaParticula()
{
	Rigidbody* rb = new Rigidbody(PuntoVector3D(0, 1, 0, 0));
	/*Objeto3D *p = new CentroMasa(rb,PuntoVector3D(0, 1, 0, 0));
	p->setColor(PuntoVector3D(0, 0.3, 0.6, 1));
	p->setSize(10);
	p->setVel(PuntoVector3D(0, 25, 0, 1));
	p->setWorld(world);
	return p;*/
	rb->setColor(PuntoVector3D(0, 0.3, 0.6, 1));
	rb->setSize(10);
	rb->setVel(PuntoVector3D(10, 25, 0, 1));
	rb->setWorld(world_);
	return rb;
}
