//Author: MAKO
#ifndef NPEDIDO_H
#define NPEDIDO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class NPedido{
private:
    char* codigo;
    int cantidad;
    double peso;
    NPedido* sig;
public:
    NPedido();
    NPedido(const NPedido& orig);
    ~NPedido();

    void getCodigo(char* codigo) const;
    int getCantidad() const;
    double getPeso() const;
    void setCodigo(const char* codigo);
    void setCantidad(const int cantidad);
    void setPeso(const double peso);
    void operator =(const NPedido& npedido);
    void imprime(ofstream& report);
    void lee(ifstream& arch);
    friend class Vehiculo;
};

#endif