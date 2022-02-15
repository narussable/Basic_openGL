// COMPILE MACROS
#define DEBUGG

#include "geomGL.hpp"

#ifdef DEBUGG
    #include <iostream>
#endif

objGL::objGL(std::initializer_list<VectorND> vl, geometry opc) {
    //glBegin(opc);
    for(auto it = vl.begin(); it!=vl.end(); ++it)
        std::cerr << it << std::endl;    
    //glEnd();
}
