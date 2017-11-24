#include "RigidbodySpawn.h"
#include "Rigidbody.h"
#include "MassCenter.h"

RigidbodySpawn::RigidbodySpawn(World* world)
{
	world_ = world;

	
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

	if (vectorRigidBody.size() == 0) replicaCubos();	//Cuando se acabe el efecto, vuelvo a crear los cubos.
	
}

void RigidbodySpawn::replicaCubos() {
	vectorRigidBody.push_back(createSolid(PuntoVector3D(0, 0, 0, 1), 1, 90));

	vectorRigidBody.push_back(createSolid(PuntoVector3D(0, 0, 20, 1), 1, 80));

	vectorRigidBody.push_back(createSolid(PuntoVector3D(0, 0, 40, 1), 1, 70));
}

void RigidbodySpawn::dibuja(){
	for (auto &p : vectorRigidBody) {
		p->dibuja();
	}
}

Rigidbody* RigidbodySpawn::createSolid(PuntoVector3D pos, int rbMass, GLfloat accY)
{
	Rigidbody* rb = new Rigidbody(world_, pos, accY);

	rb->setColor(Color{ 1, 0.3, 0.6, 1 });
	rb->setSize(10);
	rb->setMass(rbMass);
	rb->setVel(PuntoVector3D(10, 0, 0, 1));

	return rb;
}
