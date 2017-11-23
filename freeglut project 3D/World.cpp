#include "World.h"


World::World()
{
	gravity = new PuntoVector3D(0, GRAVITY, 0, 1);
}


World::~World()
{
	delete gravity;
}

PuntoVector3D* World::getRandomVector(GLfloat magnitud) {
	GLfloat phi = getNumRandom(3.1415f, 0.0f);
	GLfloat cosTheta = getNumRandom(1, -1);

	GLfloat theta = acosf(cosTheta);
	GLfloat x = sinf(theta)*cosf(phi), y = sinf(theta)*sinf(phi), z = cosf(theta);
	PuntoVector3D *v = new PuntoVector3D(x,y,z,1);
	PuntoVector3D* aux = new PuntoVector3D(magnitud, magnitud, magnitud, 1);
	v->productoEscalar(aux);
	delete aux;
	return v;
}