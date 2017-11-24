#ifndef _H_Rigidbody_H_
#define _H_Rigidbody_H_
#include "Objeto3DFisico.h"
#include "Cubo.h"

class Rigidbody : public Objeto3DFisico
{
public:
	Rigidbody(PuntoVector3D pos_, GLfloat, PuntoVector3D color_);
	~Rigidbody();
	virtual	void dibuja();											//Dibuja un rigid body
	virtual void update(GLfloat dt);								//Update del rigid body

	//void resetea();
	PuntoVector3D computeForces();									//Calcula las fuerzas aplicadas al objeto
	virtual void setSize(int tam){ size_ = tam; }					//Define el tamaño del objeto
	virtual void setMass(int newMass) { mass = newMass; }			//Define la masa del objeto

private:				
	Objeto3D* cubo;													//Cubo  
	int segundos_;													//Segundos de vida del sólido
	GLfloat gravedad_;												//Gravedad aplicada al sólido
	GLfloat mass = 1;												//Masa del cuerpo
	PuntoVector3D posInicial;										//Posición inicial del objeto
	bool activa;													//Define si está vivo o no el sólido
};
#endif