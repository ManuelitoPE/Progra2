//Author: MAKO
#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
class Pedido{
private:
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha; //aaaammdd
public:
    Pedido();
    Pedido(const Pedido&);
    ~Pedido();
    void setCodigo(int);
    void setNombre(const char*);
    void setCantidad(int);
    void setPrecio(double);
    void setDni(int);
    void setFecha(int);
    int getCodigo() const;
    void getNombre(char* ) const;
    int getCantidad() const;
    double getPrecio() const;
    int getDni() const;
    int getFecha() const;
};

Pedido::Pedido(){
    codigo = {};
    nombre = {};
    cantidad = {};
    precio = {};
    dni = {};
    fecha = {};
}
Pedido::Pedido(const Pedido& orig){
    *this = orig;
}
Pedido::~Pedido(){
    delete[] nombre;
}

#endif