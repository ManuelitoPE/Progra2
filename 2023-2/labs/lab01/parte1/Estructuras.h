#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct ProductoEntregado{
    char* codigo;
    double precio;
};
struct Cliente{
    int dni;
    char* nombre;
    int telefono;
    ProductoEntregado productosEntregados[20];
    int cantidadProductosEntregados;
    double montoTotal;
};
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
struct Pedido{
    char* codigo;
    int dni;
    double precioProducto;
};
#endif