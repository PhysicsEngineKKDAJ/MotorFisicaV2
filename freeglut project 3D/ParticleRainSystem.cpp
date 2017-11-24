#include "ParticleRainSystem.h"


ParticleRainSystem::ParticleRainSystem(World* world,PuntoVector3D pos) 
{
	world_ = world;
	pos_ = pos;
}


ParticleRainSystem::~ParticleRainSystem()
{
	for (auto p : particleVector) 
		delete p;
	
}
void ParticleRainSystem::update(GLfloat deltaTime)
{
	for (size_t i = 0; i < particleVector.size(); i++)
	{
		//Cambia el color en función de la vida que tiene.
		particleVector[i]->update(deltaTime);

		//Limpia las partículas muertas
		if (particleVector[i]->getDestroy()) 
			particleVector.erase(particleVector.begin() + i);
		
	}

	//Crea nuevas partículas para tener un flujo constante
	if (particleVector.size() < 8000)
	{
		for (size_t i = 0; i < 10; i++)
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
	GLfloat radius = 10;
	GLfloat random = world_->getRandomNum(-radius, radius);
	GLfloat alt = world_->getRandomNum(150,250);
	Particles *p = new Particles(world_, PuntoVector3D(pos_.getX() + random * cos(ang), alt, pos_.getZ() + random * sin(ang), 0), world_->getGravity()->getY(), 300, 100);

	int randomColor = world_->getRandomNum(0, 5);
	switch (randomColor)
	{
	case Blanco:
		p->setColor(Color{ 1, 1, 1, 1 });			//BLANCO
		break;
	case Rojo: 
		p->setColor(Color{ 1, 0,0, 1 });			//ROJO
		break;
	case Azul:
		p->setColor(Color{ 0, 0, 1, 1 });			//AZUL
		break;
	case Verde: 
		p->setColor(Color{0, 1, 0, 1 });			//VERDE
		break;
	case Rosa:
		p->setColor(Color{ 1, 0.4, 1, 1 });			//ROSA
		break;

	default:
		break;
	}
	
	return p;
}

void ParticleRainSystem::dibuja() {
	for (auto &p : particleVector) 
		p->dibuja();
};