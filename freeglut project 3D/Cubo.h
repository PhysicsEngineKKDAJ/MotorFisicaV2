#ifndef Cubo_H_
#define Cubo_H_

#include "Malla.h"

class Cubo : public Malla {
public:
	Cubo(GLfloat l, Color c);
	~Cubo(void);
private:
	GLfloat arista;
};
#endif
