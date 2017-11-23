#ifndef _Particles_H_
#define _Particles_H_

#include "Objeto3DFisico.h"
#include "World.h"

class Particles : public Objeto3DFisico
{
public:
	Particles(PuntoVector3D p, GLfloat gravedad = (-9.81), GLfloat maxVida = 100, GLfloat minVida = 90);
	~Particles();
	virtual	void dibuja();
	virtual void update(GLfloat dt);

	void reset();
	PuntoVector3D computeForces();
	bool isDead() { return !viva; }
	void setSize(int tam){ size = tam; }

private:

	bool viva = true;
	int segundos_;
	GLfloat gravedad_;
	GLfloat masa = 1;
	PuntoVector3D posInicial;
	bool activa;
};
#endif
