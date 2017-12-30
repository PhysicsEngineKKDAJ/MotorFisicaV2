#ifndef _H_Objeto3DFisico_H_
#define _H_Objeto3DFisico_H_

#include "Objeto3D.h"
#include "World.h"


//Struct de la derivada de Posición y Velocidad
struct Derivative
{
	PuntoVector3D dPosition, dVelocity;
};

class Objeto3DFisico : public Objeto3D
{
public:
	Objeto3DFisico();
	~Objeto3DFisico();
	//Particles
	void setPos(PuntoVector3D aux){ pos_ = aux; }
	GLfloat getPosX() { return pos_.getX(); };
	GLfloat getPosY() { return pos_.getY(); };
	GLfloat getPosZ() { return pos_.getZ(); };
	PuntoVector3D getPos() { return pos_; };

	void setVel(PuntoVector3D aux){ vel_ = aux; }
	PuntoVector3D getVel() { return vel_; };

	void setDestroy(bool b) { _eliminar = b; }
	bool getDestroy() { return _eliminar; }

	void setAcc(PuntoVector3D aux) { acc_ = aux; };

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
