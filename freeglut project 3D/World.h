#ifndef _H_World_H_
#define _H_World_H_

#include "PuntoVector3D.h"
#include <math.h>

#define GRAVITY -9.81f // Creo que en videojuegos es 10
#define PI 3.1415f
class World
{
public:
	World();
	~World();

	virtual PuntoVector3D*  getGravity(){ return gravity; };
	GLfloat getRandomNum(GLfloat min, GLfloat max) // igual que el random de la practica de IG II 
	{
		return min + static_cast <GLfloat> (rand()) / (static_cast <GLfloat> (RAND_MAX / (max - min)));
	}

	//NO SE USA
	// Metodo que nos devuelve un punto aleatorio 
	// a partir de una direccion aleatoria que se define
	// dentro.
	PuntoVector3D*  getRandomPoint(GLfloat magnitud);

private:
	PuntoVector3D*  gravity;
};
#endif

