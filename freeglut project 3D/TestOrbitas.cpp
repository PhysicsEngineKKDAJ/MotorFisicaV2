#include "TestOrbitas.h"



TestOrbitas::TestOrbitas()
{
	//escena = new Escena(4000);
	//contEscena = 0;

	//TODO LO QUE HAY A PARTIR DE AQUÍ DEBERÍA ESTAR EN LA CONSTRUCTORA DE ESCENA

	//Da un ID a todas las particulas
	InitParticles(particulas, numParticulas, Preset_id);

	//Da un ID a todas las estrellas
	//InitParticles(estrellas, NumEstrellas, Preset_id);

	//Crea todas las partículas con una masa aleatoria
	InitParticles(particulas, numParticulas, Preset_random_m);


	//EL CHOQUECITO
	/*
	for (int i = 0; i < 5; i++)
	{
	for (int j = 0; j < 5; j++)
	{
	for (int k = 0; k < 5; k++)
	{

	particulas[i * 25 + j*5 + k].position.Set(i * 3, j * 3,k*3);
	particulas[i * 25 + j * 5 + k].velocity.Set(0, 0, 0);
	particulas[i * 25 + j * 5 + k].mass = 5000 + i * 25 + j*5 + k;
	particulas[i * 25 + j * 5 + k].radius = 1;
	}
	}

	}

	particulas[0].position.Set(5, 5, 100);
	particulas[0].velocity.Set(0, 0, -1000);
	particulas[0].mass = 1000000;
	particulas[0].radius = 10;
	*/
	/*PLANETAS ORBITANDO
	//test:
	particulas[0].mass=1000000000;
	particulas[0].radius = 20;
	particulas[0].position.Set(0, 0, 0);

	particulas[1].position.Set(200, 0, 0);
	particulas[1].velocity.Set(0, 0, 150);
	particulas[1].mass = 10000;
	particulas[1].radius = 5;

	particulas[2].position.Set(0, 0, 100);
	particulas[2].velocity.Set(220, 0, 0);
	particulas[2].mass = 100;
	particulas[2].radius= 3;

	particulas[3].position.Set(0, 100, 100);
	particulas[3].velocity.Set(0, -300, -100);
	particulas[3].mass = 1000;
	particulas[3].radius = 1;

	particulas[4].position.Set(100, 100, 100);
	particulas[4].velocity.Set(0, -0, -100);
	particulas[4].mass = 100000;
	particulas[4].radius = 1;
	*/

	/*
	particulas[5].position.Set(0, 200, 000);
	particulas[5].velocity.Set(0, -100, 0);
	particulas[5].mass = 1000;
	particulas[5].radius = 4;


	particulas[6].position.Set(0, 100, 0);
	particulas[6].velocity.Set(0, 200, 0);
	particulas[6].mass = 10000;
	particulas[6].radius = 8;*/


}


TestOrbitas::~TestOrbitas()
{
}
