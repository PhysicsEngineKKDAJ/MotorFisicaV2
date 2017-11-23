#include <vector>
#include "Particles.h"
#include "world.h"
class TestRB1
{
public:
	TestRB1();
	~TestRB1();
	void dibuja();
private:

	GLfloat lastTimeUpdate = 0;
	GLfloat frecuencia = 10;
	World* world_;
	Objeto3DFisico * fuente;
	Objeto3DFisico** objetos;
	int numParticulas;
};
