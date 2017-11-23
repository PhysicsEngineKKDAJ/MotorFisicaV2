#include "ParticleRainSystem.h"


ParticleRainSystem::ParticleRainSystem()
{
}


ParticleRainSystem::~ParticleRainSystem()
{
	for (auto p : particleVector) {
		delete p;
	}
}
void ParticleRainSystem::update(GLfloat deltaTime)
{
	for (size_t i = 0; i < particleVector.size(); i++)
	{
		//Cambia el color en función de la vida que tiene.
		
		particleVector[i]->update(deltaTime);

		//Limpia las partículas muertas
		if (particleVector[i]->getDestroy()) {
			particleVector.erase(particleVector.begin() + i);
		}
	}

	//Crea nuevas partículas para tener un flujo constante
	if (particleVector.size() < 8000)
		for (size_t i = 0; i < 10; i++)
		{
			particleVector.push_back(createParticle());

		}
}
/*
Constructora dinámica de partículas. Asigna una posicion inicial, un color y la velocidad-
Le da también un puntero al mundo en el que existe.
Y la devuelve.
*/
Particles* ParticleRainSystem::createParticle()
{
	ang = world_->getRandomNum(0, 360);
	Particles *p = new Particles(PuntoVector3D(world_->getRandomNum(-55, 55) * cos(ang), 180, world_->getRandomNum(-55, 55) * sin(ang), 0), -0.8, 200);
	//Cambiar los colores con switch
	int randomColor = world_->getRandomNum(4, 0);
	switch (randomColor)
	{

	case 0: 
		p->setColor(PuntoVector3D(1, 1, 1, 1));			//BLANCO
		break;
	case 1: 
		p->setColor(PuntoVector3D(1, 0, 0, 1));			//ROJO
		break;
	case 2:
		p->setColor(PuntoVector3D(0, 0, 1, 1));			//AZUL
		break;
	case 3: 
		p->setColor(PuntoVector3D(0, 1, 0, 1));			//VERDE
		break;
	case 4: 
		p->setColor(PuntoVector3D(1, 0.4, 1, 1));			//ROSA
		break;

	default:
		break;
	}
	
	p->setVel(PuntoVector3D(0, 0, 0, 1));
	p->setWorld(world_);
	return p;
}

void ParticleRainSystem::dibuja() {
	for (auto &p : particleVector) {
		p->dibuja();
	}
};