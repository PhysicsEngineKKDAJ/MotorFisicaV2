#include "World.h"
#include <time.h>       /* time */


World::World()
{
	gravity = new PuntoVector3D(0, GRAVITY, 0, 1);
	srand(time(NULL));

}


World::~World()
{
	delete gravity;
}

//NO SE USA
PuntoVector3D* World::getRandomPoint(GLfloat magnitud) {
	GLfloat pi = getRandomNum(0.0f, PI);
	// De 0 a 180 grados en radianes
	GLfloat theta = acos(getRandomNum(-1, 1));				// sin (theta * pi)
	PuntoVector3D *v = new PuntoVector3D(sin(theta)*cos(pi), sin(theta)*sin(pi), cos(theta), 1);
	PuntoVector3D *aux = new PuntoVector3D(magnitud, magnitud, magnitud, 1);
	v->productoEscalar(aux);
	delete aux;
	return v;
}