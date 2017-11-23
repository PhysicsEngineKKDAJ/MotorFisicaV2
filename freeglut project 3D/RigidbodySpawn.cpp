#include "RigidbodySpawn.h"
#include "Rigidbody.h"
#include "MassCenter.h"

RigidbodySpawn::RigidbodySpawn()
{
}


RigidbodySpawn::~RigidbodySpawn()
{
	for (auto p : vectorRigidBody) {
		delete p;

	}
}
void RigidbodySpawn::update(GLfloat deltaTime)
{
	for (size_t i = 0; i < vectorRigidBody.size(); i++)
	{
		vectorRigidBody[i]->update(deltaTime);
		if (vectorRigidBody[i]->getDestroy()) {
			vectorRigidBody.erase(vectorRigidBody.begin() + i);
		}
	}

	if (vectorRigidBody.size() < 1)
		vectorRigidBody.push_back(createSolid(1));
}


Rigidbody* RigidbodySpawn::createSolid(int rbMass)
{
	Rigidbody* rb = new Rigidbody(PuntoVector3D(0, 0, 0, 0));

	rb->setColor(PuntoVector3D(1, 0.3, 0.6, 1));
	rb->setSize(10);
	rb->setMass(rbMass);
	rb->setVel(PuntoVector3D(10, 0, 0, 1));

	rb->setWorld(world_);
	return rb;
}
