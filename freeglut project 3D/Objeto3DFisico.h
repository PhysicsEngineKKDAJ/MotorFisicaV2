#ifndef _H_Objeto3DFisico_H_
#define _H_Objeto3DFisico_H_

#include "Objeto3D.h"
#include "World.h"

class Objeto3DFisico : public Objeto3D
{
public:
	Objeto3DFisico();
	~Objeto3DFisico();
	//Particles
	void setPos(PuntoVector3D* aux){ pos = aux; }
	void setVel(PuntoVector3D* aux){ vel = aux; }

	void setDestroy(bool b) { _eliminar = b; }
	bool getDestroy() { return _eliminar; }

	//ParticleRainSystem
	void setColor(PuntoVector3D* aux){ color = aux; }
	GLfloat getLifeAct() { return lifeAct; };
	GLfloat getLife() { return life; };
	void setWorld(World* worlde) { world = worlde; }

	virtual void update(GLfloat dt) {};

protected:
	GLfloat life;
	GLfloat lifeAct;

	int size;
	PuntoVector3D* pos;
	PuntoVector3D* vel;
	PuntoVector3D* acc;
	PuntoVector3D* color;

	World* world;
	bool _eliminar = false;
};
#endif
