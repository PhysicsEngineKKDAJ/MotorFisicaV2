#include "ParticleRainSystem.h"

ParticleRainSystem::ParticleRainSystem(World* world, PuntoVector3D pos, GLfloat r) 
{
	world_ = world;
	pos_ = pos;
	radius_ = r;
}


ParticleRainSystem::~ParticleRainSystem()
{
	std::list<Particles*>::iterator it = particles.begin();

	while (!particles.empty())
	{
		delete (*it);
		it = particles.erase(it);
	}

}
void ParticleRainSystem::update(GLfloat deltaTime)
{
	std::list<Particles*>::iterator it = particles.begin();

	while (!particles.empty() && it != particles.end())
	{
		(*it)->update(deltaTime);

		
		//Limpia las partículas muertas
		if ((*it)->getDestroy())
			it = particles.erase(it);
		else
		
			++it;
	}
	
	//Crea nuevas partículas para tener un flujo constante
	if (particles.size() < NumMaxParticles)
	{
		for (size_t i = 0; i < ParticlesPerTick; i++)
			particles.push_back(createParticle());
	}

}
/*
Constructora dinámica de partículas. Asigna una posicion inicial, un color y la velocidad-
Le da también un puntero al mundo en el que existe.
Y la devuelve.
*/
Particles* ParticleRainSystem::createParticle()
{
	//Aleatoriedad de la particula
	GLfloat ang = world_->getRandomNum(0, 360);
	GLfloat random = world_->getRandomNum(-radius_, radius_);
	GLfloat alt = world_->getRandomNum(150,250);
	int randomColor = world_->getRandomNum(0, 5);

	Particles *p = new Particles(world_, PuntoVector3D(pos_.getX() + random * cos(ang), alt, pos_.getZ() + random * sin(ang), 0), 100, 300);

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
	if (!particles.empty())
	{
		std::list<Particles*>::iterator it = particles.begin();

		while (!particles.empty() && it != particles.end())
		{
			(*it)->dibuja();
			++it;
		}
	}

};