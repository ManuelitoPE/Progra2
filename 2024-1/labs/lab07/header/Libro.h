#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funciones.h"

class Libro{
private:
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;
public:
    Libro();
    Libro(const Libro& libro);
    ~Libro();
    
    void setCodigo(const char* codigo);
    void setNombre(const char* nombre);
    void setAncho(const int ancho);
    void setAlto(const int alto);
    void setPeso(const double peso);
    void setColocado(const bool colocado);

    void operator=(const Libro& libro);

    void getCodigo(char* codigo) const;
    void getNombre(char* nombre) const;
    int getAncho() const;
    int getAlto() const;
    double getPeso() const;
    bool getColocado() const;
    
    void cargar(ifstream& arch);
    void imprimir(ofstream& report);
};

#endif