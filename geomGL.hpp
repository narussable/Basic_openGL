#ifndef GEOM_GL_HPP
#define GEOM_GL_HPP

#include <initializer_list>
#include <GL/glut.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>

#include "VectorND.hpp"

enum geometry : uint16_t {point = GL_POINTS,
                          line = GL_LINES,
                          polygon = GL_POLYGON,
                          triangle = GL_TRIANGLES,
                          quad = GL_QUADS};

class objGL {
    protected:
        double prof = 1.0;
    public:
        objGL(std::initializer_list<VectorND> vl,geometry opc = point) {
        for(auto it = vl.begin(); it!=vl.end(); ++it)
            std::cerr << *it << std::endl;    
        }
};

#endif
