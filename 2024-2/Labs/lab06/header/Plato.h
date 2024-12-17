#ifndef PLATO_H
#define PLATO_H

#include<iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "funciones.h"

class Plato{
private:
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;
public:
    Plato();
    Plato(const Plato& orig);
    ~Plato();

    void setCodigo(const char* codigo);
    void setNombre(const char* nombre);
    void setPrecio(const double precio);
    void setCategoria(const char* categoria);
    void setPreparados(const int preparados);
    void setDescuento(const double descuento);
    void setAtendidos(const int atendidos);
    void setNoAtendidos(const int noAtendidos);
    void setTotalEsperado(const double totalEsperado);
    void setTotalBruto(const double totalBruto);
    void setTotalNeto(const double totalNeto);

    void getCodigo(char* codigo) const;
    void getNombre(char* nombre) const;
    double getPrecio() const;
    void getCategoria(char* categoria) const;
    int getPreparados() const;
    double getDescuento() const;
    int getAtendidos() const;
    int getNoAtendidos() const;
    double getTotalEsperado() const;
    double getTotalBruto() const;
    double getTotalNeto() const;

    void operator =(const Plato& plato);
    void actualizar();
};

bool operator >>(ifstream& arch,Plato& plato);

#endif