#ifndef _H_Objeto3D_H_
#define _H_Objeto3D_H_

#include "TAfin.h"
struct Color{
	GLdouble r;
	GLdouble g;
	GLdouble b;
	GLdouble a;
};

enum TColor{Rojo,Azul,Verde,Rosa,Blanco};

//VIRTUAL PURA
class Objeto3D
{
public:
	Objeto3D() : visible(true) {
		mT = new TAfin();
	};
	virtual ~Objeto3D(){
		delete mT;
	};
	//...

	inline void traslada(PuntoVector3D* v){ mT->traslada(v); };
	inline void rota(GLfloat a, GLfloat x, GLfloat y, GLfloat z ){ mT->rota(a,x,y,z); };
	inline void escala(PuntoVector3D* v){ mT->escala(v); };

	inline bool esVisible() const { return visible; };
	inline void setInvisible() { visible = false; };
	inline TAfin* getmT() const { return mT; };
	inline void posiciona(GLfloat doce, GLfloat trece, GLfloat catorce){ mT->posiciona(doce,trece,catorce); };
	virtual void dibuja() = 0;

protected:
	TAfin* mT;//Contiene la matriz por la que es necesario post-multiplicar  la de modelado-vista antes de dibujarlo
	Color color;
	bool visible;
	//...

};
#endif
