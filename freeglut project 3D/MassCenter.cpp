#include "MassCenter.h"


MassCenter::MassCenter(Objeto3DFisico* rb, PuntoVector3D posicion) :rigidBody(rb), Objeto3DFisico()
{
}


MassCenter::~MassCenter()
{
}

void MassCenter::giraRB(){
	rigidBody->rota(50, 1, 1, 1);
}

void MassCenter::posicionaRB(){
	rigidBody->posiciona(this->getmT()->getM()[12], this->mT->getM()[13], this->mT->getM()[14]);
}

void MassCenter::update(){
	/*dt -= segundos_;
	dt /= 1000000;

	PuntoVector3D aceleration = computeForces();

	aceleration.mult(dt);
	vel.sumar(&aceleration);
	PuntoVector3D Velocidad(vel);
	Velocidad.mult(dt);
	pos.sumar(&Velocidad);
	acc.mult(0);
	cubo->mt->reinicia();
	cubo->mt->traslada(&pos);

	if (cubo->mt->damePos().getY() <= BOTTOM_DEADZONE || cubo->mt->damePos().getY() >= TOP_DEADZONE) {

	setDestroy(true);
	}*/
}
