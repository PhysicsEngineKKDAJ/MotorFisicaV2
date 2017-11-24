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
	void setPos(PuntoVector3D aux){ pos_ = aux; }
	void setVel(PuntoVector3D aux){ vel_ = aux; }

	void setDestroy(bool b) { _eliminar = b; }
	bool getDestroy() { return _eliminar; }

	//ParticleRainSystem
	void setColor(Color aux){ color_ = aux; }
	GLfloat getLifeAct() { return lifeAct_; };
	GLfloat getLife() { return life_; };

	virtual void update(GLfloat dt) {};

protected:
	GLfloat life_;
	GLfloat lifeAct_;

	int size_;
	PuntoVector3D pos_;
	PuntoVector3D vel_;
	PuntoVector3D acc_;
	Color color_;

	World* world_;
	bool _eliminar = false;
};
#endif
