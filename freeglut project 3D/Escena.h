#ifndef _H_Escena_H_
#define _H_Escena_H_

#include <Windows.h>

#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include "Coche.h"
#include "ObjetoCompuesto.h"
#include <vector>
#include "QuadTree.h"

enum movCoche{ ArribaIz, AbajoIz, ArribaDe, AbajoDe };

// Viewport size

class Escena : public ObjetoCompuesto {
public:
	Escena(int n);
	~Escena();

	void dibuja();

	void moverCoche(movCoche avanza);
	
	inline void cambiarModo(){ isCulled = !isCulled; };

private:

	int nArbolesTalados;
	int numArboles;
	const GLfloat angGiro = 15;

	bool isCulled;


	bool colisionCocheArbol(Objeto3D* arbol);

	QuadTree *treeQuadtree;
};
#endif
