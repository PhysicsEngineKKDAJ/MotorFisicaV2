#pragma once

#include "Includes.h"
#include "Particles.h"


//METODOS DE AYUDA PARA VECTORES, PARTICULAS Y DEBUG


//---Vector Operations---
double dotProduct(PuntoVector3D& v1, PuntoVector3D& v2);

//---Particles---

//Crea un tipo de partículas según el preset
void InitParticles(vector<Particles*> & particulas, int size, Preset preset);
//void InitParticles(vector<Estrella> & particulas, int size, Preset preset);

State ParticleToState(Particles & particula);//Devuelvo un estado con los atributos de la partícula atributo

void CopyParticles(vector<State> & estados, vector<Particles> & particulas, int size);
//void CopyParticles(vector<State> & estados, vector<Estrella> & particulas, int size);

void CopyStates(State*, Particles*, int);//Copia size particulas en estados


			//---Drawing---
void DrawVector3d(PuntoVector3D & v, double x, double y, double z);//Dibuja una linea desde una posición dada por coordenadas hasta otra dada por un vector
void SetColor(COLOR c);//Aplica un color del enum del atributo a la matriz de modelado

			//---Debug---
double Distance3d(PuntoVector3D p1, PuntoVector3D p2);//Distancia entre dos puntos