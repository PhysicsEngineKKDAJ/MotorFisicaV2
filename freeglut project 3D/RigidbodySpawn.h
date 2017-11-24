#ifndef _RigidbodySpawn_H_
#define _RigidbodySpawn_H_

#include "Objeto3DFisico.h"
#include "Rigidbody.h"
#include <vector>

class RigidbodySpawn :public Objeto3DFisico
{
public:
	RigidbodySpawn();
	~RigidbodySpawn();
	virtual void dibuja();
	virtual void update(GLfloat dt);

	void replicaCubos();

	Rigidbody * createSolid(PuntoVector3D, int, GLfloat, PuntoVector3D );
private:
	std::vector<Rigidbody*> vectorRigidBody;
};
#endif