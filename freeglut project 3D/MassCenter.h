#ifndef _H_MassCenter_H_
#define _H_MassCenter_H_

#include "Objeto3DFisico.h"
class MassCenter :
	public Objeto3DFisico
{
public:
	MassCenter(Objeto3DFisico* rb, PuntoVector3D posicion);
	~MassCenter();
	Objeto3DFisico* rigidBody;
	void giraRB();
	void posicionaRB();
	virtual void update();
};
#endif
