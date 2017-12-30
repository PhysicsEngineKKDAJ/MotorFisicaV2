#ifndef _Particles_H_
#define _Particles_H_

#include "Objeto3DFisico.h"
#include "World.h"

/*
--------------------------------------------------------------------------------------
ENUMERADOS
--------------------------------------------------------------------------------------
*/
enum COLOR {
	BLACK, RED, GREEN, BLUE, WHITE, YELLOW, ORANGE, MAGENTA,
	G75, //75% blanco 
	G50, //50% blanco
	G25, //25% blanco
};

//Configuraciones iniciales posibles
enum  Preset
{
	Preset_id, //Asigna ID
	Preset_radius, //Asigna un radio en función de la masa
	Preset_random_m, //Establece masas aleatorias
	Preset_random_v, //Establece velocidades aleatorias
};

/*
--------------------------------------------------------------------------------------
ESTRUCTURAS
--------------------------------------------------------------------------------------
*/

//Struct del estado anterior de un cuerpo - Contiene Posición, Velocidad, Aceleración, Masa y un Identificador Numérico
struct State
{
	PuntoVector3D lastPos, lastVel, lastAcc;
	float mass;
	int id;

};

class Particles : public Objeto3DFisico
{
public:
	Particles() {}

	//Constructora principal - Cascada
	Particles(World *world,PuntoVector3D p, GLfloat minLife, GLfloat maxLife);

	//Constructora orbitas
	Particles(World *world, PuntoVector3D p, PuntoVector3D v, double r, double m);

	~Particles();
	virtual	void dibuja();						//Dibuja una partícula
	virtual void update(GLfloat dt);			//Update de una partícula

	//---SETTERS---
	void setMasa(double m) { masa_ = m; }; 
	void setRadio(double r) { radio_ = r; };

	//---GETTERS---
	double getMasa() { return masa_; };
	double getRadio() { return radio_; };

	//Identificador de cada partícula
	int id;

private:
	int seconds_;								//Cuenta la vida de la particula
	const int DeadTriggerUp = 300;
	const int DeadTriggerDown = 0;

	//Variables físicas
	double masa_, radio_;

	/*
	GLfloat mass;
	PuntoVector3D forceAccumulator;
	bool activa;								//Si la particula está viva o no.
	*/
};
#endif
