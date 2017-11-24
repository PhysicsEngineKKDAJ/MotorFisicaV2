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
	virtual void setSize(int tam){ size_ = tam; }					//Define el tama�o del objeto
	virtual void setMass(int newMass) { mass = newMass; }			//Define la masa del objeto

private:				
	Objeto3D* cubo;													//Cubo  
	int segundos_;													//Segundos de vida del s�lido
	GLfloat gravedad_;												//Gravedad aplicada al s�lido
	GLfloat mass = 1;												//Masa del cuerpo
	PuntoVector3D posInicial;										//Posici�n inicial del objeto
	bool activa;													//Define si est� vivo o no el s�lido
};
#endif