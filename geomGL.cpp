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
        VectorND aux = VectorND{ver[it][0],ver[it][1],ver[it][2],w_persp};
        stateColour(it);
        stateVertex(it);
    }
}

void objGL::stateColour(uint16_t it) {
    VectorND sel_v = *(col+it);
    isAlpha = (sel_v.dim()>3) ? true : false;
    isAlpha ? 
        glColor4f(sel_v[0],sel_v[1],sel_v[2],sel_v[3]) :
        glColor3f(sel_v[0],sel_v[1],sel_v[2]);
}

void objGL::stateVertex(uint16_t it) {
    VectorND sel_v = *(ver+it);
    isPersp = (sel_v.dim()>3) ? true : false;
    isPersp ? 
        glVertex4f(sel_v[0],sel_v[1],sel_v[2],sel_v[3]) :
        glVertex3f(sel_v[0],sel_v[1],sel_v[2]);
}

void objGL::editPersp(double new_val) 
{  w_persp = new_val;  }