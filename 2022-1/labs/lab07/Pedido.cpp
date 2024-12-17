//Author: MAKO
#include "header/Pedido.h"

void Pedido::setCodigo(int codigo){
    this->codigo = codigo;
}
void Pedido::setNombre(const char* nombre){
    if(this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}
void Pedido::setCantidad(int cantidad){
    this->cantidad = cantidad;
}
void Pedido::setPrecio(double precio){
    this->precio = precio;
}
void Pedido::setDni(int dni){
    this->dni = dni;
}
void Pedido::setFecha(int fecha){
    this->fecha = fecha;
}
int Pedido::getCodigo() const{
    return this->codigo;
}
void Pedido::getNombre(char* nombre) const{
    if(nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre,this->nombre);
}
int Pedido::getCantidad() const{
    return this->cantidad;
}
double Pedido::getPrecio() const{
    return this->precio;
}
int Pedido::getDni() const{
    return this->dni;
}
int Pedido::getFecha() const{
    return this->fecha;
}