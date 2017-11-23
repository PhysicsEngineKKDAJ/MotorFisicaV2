#ifndef _Particles_H_
#define _Particles_H_

#include "Objeto3D.h"
#include "World.h"

class Particles : public Objeto3D
{
public:
	Particles(PuntoVector3D *p, GLfloat gravedad = (-9.81), GLfloat maxVida = 100, GLfloat minVida = 90);
	~Particles();
	virtual	void dibuja();
	virtual void update(GLfloat dt);

	void reset();
	PuntoVector3D* computeForces();
	bool isDead() { return !viva; }
	void setSize(int tam){ size = tam; }
	void setPos(PuntoVector3D* aux){ pos = aux; }
	void setVel(PuntoVector3D* aux){ vel = aux; }

	void setDestroy(bool b) { _eliminar = b; }

private:
	GLfloat life;
	GLfloat lifeAct;

	int size;
	PuntoVector3D* pos;
	PuntoVector3D* vel;
	PuntoVector3D* acc;
	PuntoVector3D* color;

	World* world;
	bool _eliminar = false;

	bool viva = true;
	int segundos_;
	GLfloat gravedad_;
	GLfloat masa = 1;
	PuntoVector3D *posInicial;
	bool activa;
};
#endif
