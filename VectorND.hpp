#ifndef VEC_HPP
#define VEC_HPP
#define FORMAT_VAR

#ifdef FORMAT_VAR
    #include <iostream>
#endif

#include <initializer_list>
#include <cstdint>
#include <cstdio>
#include <string>
#include <cmath>

double invSqrd(double number);

class VectorND {
    protected:
        uint16_t n = 0;
        double *v, *ini, *end;

    public:
        VectorND(std::initializer_list<double>); 
        VectorND(void);

        const uint16_t dim(void) const;
        void initMem(uint16_t);
        const double norma(void) const;
        double* p_ini(void) const; 
        double* p_end(void) const;
        VectorND normalize(void) const;

        double  operator [] (int16_t) const;
        double& operator [] (int16_t);
        VectorND& operator = (const VectorND&);
        VectorND& operator - (void);
};

VectorND operator + (const VectorND&, const VectorND&);
VectorND operator - (const VectorND&, const VectorND&);
VectorND operator % (const VectorND&, const VectorND&);
VectorND operator * (double         , const VectorND&);
VectorND operator / (const VectorND&, double         );
double operator * (const VectorND&, const VectorND&);
bool operator == (const VectorND&, const VectorND&);
bool operator != (const VectorND&, const VectorND&);

#ifdef FORMAT_VAR
    std::ostream& operator << (std::ostream& os, const VectorND& vecA); 
#endif

#endif
