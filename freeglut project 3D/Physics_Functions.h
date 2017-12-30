#pragma once
#include "Includes.h"
#include "Help_Functions.h"
//#include "Global.h"



PuntoVector3D accDirectionalGravity(State s);	//g
PuntoVector3D accUniversalGravitation(State sip); //G


void DirectionalGravity(int, Particles*, short, State&, float);
void DirectionalGravity_simple(int, Particles*, short, State&, float);

void UniversalGravitation(int, Particles*, short, State&, float, double);
//void UniversalGravitation_simple(int, Particle3d*, short, State&, float, double);

void dImpenetrationResolution(int, int, Particles*, State*);
void CollisionResolution2(int p_c, Particles *p, State *ps);

void CollisionResolution(int p_c, Particles *p, State *ps);
void CollisionResolution_Ground(int p_c, Particles *p, State *ps);	//EN DESUSO PARA ESTA SIMULACIÓN

//-------------------------------------------
//-------------------------------------------

