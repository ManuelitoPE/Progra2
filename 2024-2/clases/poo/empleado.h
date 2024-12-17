#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "iostream"
#include "iomanip"
#include "fstream"
using namespace std;

class Empleado{
    private:
        int dni;
        char* nombre;
        double sueldoBruto;
        int experiencia;
    public:
        void cargarEmpleado(const char*, Empleado*&, int&);
        void cargarEmpleado(const char*, Empleado*&);

};

bool operator>>(ifstream&,Empleado&);
ostream& operator<<(ostream&, const Empleado*);
#endif
