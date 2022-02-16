#include "geomGL.hpp"

objGL::objGL(geom opc,
             std::initializer_list<VectorND> vl,
             std::initializer_list<VectorND> cl) {
    // Checamos si se definen colores con transparencia
    isAlpha = ((*(cl.begin())).dim()==4) ? true : false;
    col = (VectorND*) malloc (cl.size()*sizeof(VectorND));
    ver = (VectorND*) malloc (vl.size()*sizeof(VectorND));
    for(auto it = 0; it<vl.size(); ++it) {
        *(col+it) = *(cl.begin()+it);
        *(ver+it) = *(vl.begin()+it);
    }
    glBegin(opc);
    for(auto it = 0; it<vl.size(); ++it) {
        stateColour(it);
    }
}

void objGL::stateColour(uint16_t it) const {
    VectorND sel_v = *(col+it);
    isAlpha ? 
        glColor4f(sel_v[0],sel_v[1],sel_v[2],sel_v[3]) :
        glColor3f(sel_v[0],sel_v[1],sel_v[2]);
}