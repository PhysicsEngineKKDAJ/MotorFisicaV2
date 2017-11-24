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

	if (vectorRigidBody.size() == 0) replicaCubos();	//Cuando se acabe el efecto, vuelvo a crear los cubos.
	
}

void RigidbodySpawn::replicaCubos() {

	int desplX = 0, desplZ = 0;
	int accY = 100;

	//Colores distintos para las filas.

	for (int i = 0; i < 4; i++) {
		vectorRigidBody.push_back(createSolid(PuntoVector3D(0, 0, desplX+=20, 1), 1, accY-=10, PuntoVector3D (1,0,0,1)));
	}

	 desplX = 0;
	 accY = 100;
	for (int j = 0; j < 4; j++) {
		vectorRigidBody.push_back(createSolid(PuntoVector3D(30, 0, desplX += 20, 1), 1, accY -= 10, PuntoVector3D(1, 1 , 0, 1)));
	}

	desplX = 0;
	accY = 100;
	for (int k = 0; k < 4; k++) {
		vectorRigidBody.push_back(createSolid(PuntoVector3D(60, 0, desplX += 20, 1), 1, accY -= 10, PuntoVector3D(0.87, 0.31, 1, 1)));
	}
	
}

void RigidbodySpawn::dibuja(){
	for (auto &p : vectorRigidBody) {
		p->dibuja();
	}
}

Rigidbody* RigidbodySpawn::createSolid(PuntoVector3D pos, int rbMass, GLfloat accY, PuntoVector3D newColour)
{
	Rigidbody* rb = new Rigidbody(pos, accY, newColour);

	//rb->setColor(PuntoVector3D(1, 0.3, 0.6, 1));
	rb->setSize(10);
	rb->setMass(rbMass);
	rb->setVel(PuntoVector3D(10, 0, 0, 1));

	rb->setWorld(world_);
	return rb;
}
