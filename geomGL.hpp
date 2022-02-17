#ifndef GEOM_GL
#define GEOM_GL

#include "VectorND.hpp"
#include <GL/glut.h>

enum geom {point = GL_POINTS, line = GL_LINES};

class objGL {
    protected:
        VectorND *col, *ver;
        bool isAlpha = false, isPersp = false;
        double w_persp = 1.0;

    public:
        objGL(geom,
              std::initializer_list<VectorND>,
              std::initializer_list<VectorND>);
        
        void stateColour(uint16_t);
        void stateVertex(uint16_t);
        void editPersp(double = 1.0);
};

#endif