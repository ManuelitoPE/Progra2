//Author: mako
#ifndef NODOLISTA_H 
#define NODOLISTA_H 

#include "Vehiculo.h"

class NodoLista{
private:
    Vehiculo* unidad;
    NodoLista* sig;
public:
    NodoLista();
    ~NodoLista();
    friend class LVehiculos;
};

#endif