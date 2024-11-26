//Author: MAKO
#ifndef VEHICULO_H 
#define VEHICULO_H

#include "NPedido.h"

class Vehiculo{
private:
    int cliente;
    char* placa;
    double maxcarga;
    double actcarga;
    NPedido* ped;

public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    ~Vehiculo();
    void operator =(const Vehiculo& orig);
    void setPlaca(const char* placa);
    void setCliente(const int cliente);
    void setMaxcarga(const double maxcarga);
    void setaActcarga(const double actcarga);
    void getPlaca(char* placa) const;
    int getCliente() const;
    double getMaxcarga() const;
    double getActcarga() const;
    void imprimePila(ofstream& report);
    void push(const NPedido& nuevo);    
    bool listaVacia();
    virtual void lee(ifstream&);
    virtual void imprime(ofstream&);
};

#endif