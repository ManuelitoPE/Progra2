#include "Pedido.h"
#include <cstring>
    

void Pedido::SetCodigo(int total) {
    this->codigo = codigo;
}
int Pedido::GetCodigo() const{
    return this->codigo;
}


void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}
int Pedido::GetCantidad() const {
    return this->cantidad;
}

void Pedido::SetNombre(const char* nombre) {
    if(nombre) delete this->nombre;
    if(nombre!=nullptr){
        this->nombre = new char[strlen(nombre)+1];
        strcpy(this->nombre, nombre);
    }else{
        this->nombre = new char[2];
        strcpy(this->nombre, "0");
    }
}

void Pedido::GetNombre(char* nombre) const {
    if(this->nombre==nullptr) strcpy(nombre,"0");
    else strcpy(nombre, this->nombre);
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}
void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}
