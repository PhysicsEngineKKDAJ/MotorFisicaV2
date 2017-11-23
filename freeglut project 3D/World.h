#ifndef _H_World_H_
#define _H_World_H_

#include "PuntoVector3D.h"
#include <math.h>

#define GRAVITY -9.81f
class World
{
public:
	World();
	~World();

	virtual PuntoVector3D*  getGravity(){ return gravity; };
	GLfloat getNumRandom(GLfloat max, GLfloat min) 
	{
		return min + static_cast <GLfloat> (rand()) / (static_cast <GLfloat> (RAND_MAX / (max - min)));
	}
	PuntoVector3D*  getRandomVector(GLfloat magnitud);
private:
	PuntoVector3D*  gravity;
};
#endif

