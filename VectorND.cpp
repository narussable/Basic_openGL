#include "VectorND.hpp"

// Piece of code obtained in 
// https://stackoverflow.com/questions/11644441/fast-inverse-square-root-on-x64/11644533
// to faster the inverse square root (less time in render).
double invSqrd(double number){
    double y = number;
    double x2 = y * 0.5;
    std::int64_t i = *(std::int64_t *) &y;
    // The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *(double *) &i;
    y = y * (1.5 - (x2 * y * y));   // 1st iteration
    y = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    y = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

VectorND::VectorND(std::initializer_list<double> l) : n(l.size()) {  
    initMem(n);  
    for(auto it = l.begin(); it!=l.end(); ++it){
        if(it==l.begin() || it==(l.end()-1))
            (it==(l.end()-1)) ? end = (v+1) : ini = v;
        *(v++) = *it;
    }
}

VectorND::VectorND(void)
{ ; }

const uint16_t VectorND::dim(void) const
{  return n;  }

void VectorND::initMem(uint16_t N) {
    v = (double*) malloc (N*sizeof(double));
    n = N;
}

const double VectorND::norma(void) const {
    double sum = 0.0;
    for(auto it = ini; it!=end; ++it)
        sum += (*it) * (*it);
    return std::sqrt(sum);
}

double* VectorND::p_ini(void) const 
{  return ini;  }

double* VectorND::p_end(void) const 
{  return end;  }

VectorND VectorND::normalize(void) const {
    VectorND out;
    out.initMem(n);
    /*double sum = 0.0;
    for(auto it = 0; it<n; ++it)
        sum += (*(ini+it)) * (*(ini+it));
    double modCuad = invSqrd(sum);
    for(auto it = 0; it<n; ++it)
        *(out.p_ini()+it) *= modCuad;*/
    return out;
}

double VectorND::operator [] (int16_t it) const {
    it = (it<0) ? (it%n) + n : (it%n);
    return *(p_ini()+it);
}

double& VectorND::operator [] (int16_t it) {
    it = (it<0) ? (it%n) + n : (it%n);
    return *(p_ini()+it); 
}

VectorND& VectorND::operator = (const VectorND& u) {
    initMem(u.dim());
    end = (v+u.dim()+1);
    ini = v;
    for(int16_t it = 0; it<u.dim(); ++it)
        *(ini+it) = *(u.p_ini()+it);
    return *this;
}

VectorND& VectorND::operator - (void) {
    for(auto it = ini; it!=end; ++it)
        *it *= -1;
    return *this;
}

VectorND operator + (const VectorND& u, const VectorND& v) {
    VectorND output {};
    if(u.dim()==v.dim()) {
        output.initMem(u.dim());
        double * v_p = v.p_ini();
        double * o_p = output.p_ini();
        for(auto it = u.p_ini(); it!=u.p_end(); ++it)
            *(o_p++) = *it + *(v_p++);
    } else
        std::printf("Dimension errror in + operator\n");
    return output;
}

VectorND operator - (const VectorND& u, const VectorND& v) {
    VectorND output {};
    if(u.dim()==v.dim()) {
        output.initMem(u.dim());
        double * v_p = v.p_ini();
        double * o_p = output.p_ini();
        for(auto it = u.p_ini(); it!=u.p_end(); ++it)
            *(o_p++) = *it - *(v_p++);
    } else
        std::printf("Dimension errror in + operator\n");
    return output;
}

VectorND operator % (const VectorND& u, const VectorND& v) {
    VectorND output {};
    if(u.dim()>=3 && v.dim()>=3) {
        output = VectorND{
                    u[1]*v[2] - u[2]*v[1],
                    u[2]*v[0] - u[0]*v[2], 
                    u[0]*v[1] - u[1]*v[0]};
    } else
        printf("Dimension error in cross operator\n");
    return output;
}

VectorND operator * (double       r, const VectorND& u) {
    VectorND out = u;
    out.initMem(u.dim());
    for(auto it = 0; it<u.dim(); ++it)
        *(out.p_ini()+it) = *(u.p_ini()+it) * r;
    return out;
}

VectorND operator / (const VectorND& u, double       r) {
    VectorND out {};
    out.initMem(u.dim());
    for(auto it = 0; it<u.dim(); ++it)
        *(out.p_ini()+it) = *(u.p_ini()+it) / r;
    return out;
}

double operator * (const VectorND& u, const VectorND& v) {
    double output = -1;
    if(u.dim()==v.dim()) {
        for(auto it = 0; it!=u.dim(); ++it)
            output += (*(u.p_ini()+it)) * (*(v.p_ini()+it));
        ++output;
    } else
        std::printf("Dimension errror in + operator\n");
    return output;
}

bool operator == (const VectorND& u, const VectorND& v) {
    if(u.dim()==v.dim()) {
        bool ans = true;
        for(auto it = 0; it<u.dim(); ++it)
            ans = ans && (*(u.p_ini()+it) == *(v.p_ini()+it));
    } else
        std::printf("Dimension errror in == operator\n");
    return false;
}

bool operator != (const VectorND& u, const VectorND& v) 
{  return !(u==v);  }

#ifdef FORMAT_VAR
std::ostream& operator << (std::ostream& os, const VectorND& vecA) {
    os << '<';
    double *p_v = vecA.p_ini();
    for(uint16_t it = 0; it<vecA.dim(); ++it)
        (it<(vecA.dim()-1)) ? os << *(p_v + it) << ',' : os << *(p_v + it) << '>';
    return os;
}
#endif
