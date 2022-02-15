#include "VectorND.hpp"
#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
    VectorND r {3,4};
    puts("Jolines");
    VectorND e = VectorND{2,3,4};
    std::cerr << "Dimensiones para ello r: " << r << std::endl;
    std::cerr << "Dimensiones para ello e: " << 6*e << std::endl;
    //std::cerr << "Dim de e: " << e.dim() << std::endl;
    //std::cerr << "Producto Cruz: " << e.normalize() << std::endl;
}
