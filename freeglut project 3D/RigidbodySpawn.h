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
	virtual void dibuja() {
		for (auto &p : vectorRigidBody) {
			p->dibuja();
		}
	};
	virtual void update(GLfloat dt);
	Rigidbody * createSolid(int);
private:
	std::vector<Rigidbody*> vectorRigidBody;
};
#endif