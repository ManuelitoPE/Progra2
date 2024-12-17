//Author: MAKO
#ifndef CLIENTE_H 
#define CLIENTE_H 
#include "ProductoEntregado.h"

struct Cliente{
    int dni;
    char* nombre;
    int telefono;
    ProductoEntregado productosEntregados[20];
    int cantidadProductosEntregados;
    double montoTotal;
};


#endif