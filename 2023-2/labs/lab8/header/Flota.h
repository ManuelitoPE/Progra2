//Author: MAKO 
#ifndef FLOTA_H
#define FLOTA_H

#include "LVehiculos.h"
#include "Funciones.h"

class Flota{
private:
    LVehiculos lista;
public:
    Flota();
    ~Flota();
    void cargarFlota();
    void cargarPedidos();
    void muestraCarga();
};


#endif