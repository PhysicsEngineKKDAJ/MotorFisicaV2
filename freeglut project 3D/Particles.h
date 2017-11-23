#ifndef _Particles_H_
#define _Particles_H_

#include "Objeto3DFisico.h"
#include "World.h"

class Particles : public Objeto3DFisico
{
public:
	Particles(PuntoVector3D p, GLfloat gravedad = (-9.81), GLfloat maxVida = 100, GLfloat minVida = 90);
	~Particles();
	virtual	void dibuja();						//Dibuja una partícula
	virtual void update(GLfloat dt);			//Update de una partícula

	void reset();								//Reinicia la particula
	PuntoVector3D computeForces();				//Calcula las fuerzas

	

private:

	int segundos_;								//Cuenta la vida de la particula
	GLfloat gravedad_;							//Gravedad del mundo
	GLfloat masa = 1;							//Masa del cuerpo
	PuntoVector3D posInicial;					//posición de donde nace la partícula
	bool activa;								//Si la particula está viva o no.

};
#endif
