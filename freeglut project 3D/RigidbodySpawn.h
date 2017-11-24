#ifndef _RigidbodySpawn_H_
#define _RigidbodySpawn_H_

#include "Objeto3DFisico.h"
#include "Rigidbody.h"
#include <vector>

class RigidbodySpawn :public Objeto3DFisico
{
public:
	RigidbodySpawn(World* world);
	~RigidbodySpawn();
	virtual void dibuja();
	virtual void update(GLfloat dt);

	void replicaCubos();

	Rigidbody * createSolid(PuntoVector3D pos, int rbMass, GLfloat accY, Color newColour);
private:
	std::vector<Rigidbody*> vectorRigidBody;
};
#endif