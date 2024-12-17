#ifndef PRODUCTO_H
#define PRODUCTO_H

struct Producto{
    char* codigo;
    char* descripcion;
    double precio;
    int stock;
    int clientesServidos[20];
    int clientesNoServidos[20];
    int cantidadClientesServidos;
    int cantidadClientesNoServidos; 
};

#endif