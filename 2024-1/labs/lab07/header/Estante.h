#ifndef ESTANTE_H
#define ESTANTE_H

#include "Espacio.h"

class Estante{
private:
    char* codigo;
    int anchura;
    int altura;
    Espacio* espacios;
    double pesoSoportado;
    double pesoActual;

public:
    Estante();
    Estante(const Estante& orig);
    ~Estante();

    void setCodigo(const char*);
    void setAnchura(const int);
    void setAltura(const int);
    void setPesoSoportado(const double);
    void setPesoActual(const double);
    void setEspacios(const int cant);


    void getCodigo(char* ) const;
    int getAnchura() const;
    int getAltura() const;
    double getPesoSoportado() const;
    double getPesoActual() const;

    void cargar(ifstream& arch);
    bool espacioSobrante(char tipo,int num);
    void pintar(char c,int anchuraLibro,int alturaLibro);
    void imprimir(ofstream& report, int n,char tipo);
};

#endif