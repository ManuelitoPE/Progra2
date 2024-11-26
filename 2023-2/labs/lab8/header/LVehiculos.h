//Author: mako
#ifndef LVEHICULO_H 
#define LVEHICULO_H

#include "NodoLista.h"
#include "Camion.h"
#include "Furgon.h"

class LVehiculos{
private:
    NodoLista* lini;
    NodoLista* lfin;
public:
    LVehiculos();
    ~LVehiculos();
    void insertar(Vehiculo* vehiculo);
    void mostrar(ofstream&);
    void ingresaPedido(int cliente,const NPedido& nuevo);
};

#endif