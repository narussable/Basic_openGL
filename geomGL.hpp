#ifndef GEOM_GL
#define GEOM_GL
#define DEBUG

#include "VectorND.hpp"
#include <GL/glut.h>

enum geom {point = GL_POINTS, line = GL_LINES};

class objGL {
    protected:
        VectorND *col, *ver;
        bool isAlpha = false;

    public:
        objGL(geom,
              std::initializer_list<VectorND>,
              std::initializer_list<VectorND>);
        
        void stateColour(uint16_t) const;
};

#endif