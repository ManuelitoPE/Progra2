//Author: MAKO
#ifndef CLIENTE_H 
#define CLIENTE_H

#include "iostream"
#include "iomanip"
#include "fstream"
#include "cstring"
using namespace std;
#include "funciones.h"

class Cliente{
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    Cliente(const Cliente& orig);
    ~Cliente();

    void setDni(const int dni);
    void setNombre(const char* nombre);
    void setDistrito(const char* distrito);
    void setDescuento(const double descuento);
    void setTotalPagado(const double total);
    
    int  getDni() const;
    void getNombre(char* nombre) const;
    void getDistrito(char* distrito) const;
    double getDescuento() const;
    double getTotalPagado() const;

    void operator =(const Cliente& cliente);
    void actualizar(ifstream& arch);
};

bool operator>>(ifstream& arch,Cliente& cliente);

#endif