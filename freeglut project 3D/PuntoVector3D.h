#ifndef _PuntoVector3D_H_
#define _PuntoVector3D_H_

//#include <math.h>
#include <GL/freeglut.h>

class PuntoVector3D {
	private:
		GLfloat x, y, z;
        int pv;
    public:
        PuntoVector3D(GLfloat x, GLfloat y, GLfloat z, int pv);
		PuntoVector3D() :x(0), y(0), z(0), pv(1){};
        ~PuntoVector3D();
        GLfloat getX();
        GLfloat getY();
        GLfloat getZ();
		GLfloat getA();
        bool esPunto();
        bool esVector();
        void escalar(GLfloat factor);
        void normalizar();
        void sumar(PuntoVector3D* pv);
		void resta(PuntoVector3D* pv);
        PuntoVector3D* clonar();
		void mult(GLfloat n) { x *= n; y *= n; z *= n; }
        GLfloat productoEscalar(PuntoVector3D* vector);
        PuntoVector3D* productoVectorial(PuntoVector3D* vector);
		double Magnitude() { return sqrt(x*x + y*y + z*z); }
};
#endif

