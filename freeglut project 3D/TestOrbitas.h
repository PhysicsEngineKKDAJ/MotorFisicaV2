#pragma once

#include "Physics_Functions.h"
#include "Includes.h"

const short numParticulas = 125;

class TestOrbitas
{
public:
	TestOrbitas();
	~TestOrbitas();

	vector<Particles*> particulas;
	vector<State> estadosAnteriores;

};

