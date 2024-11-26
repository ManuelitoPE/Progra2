//Auhtor: MAKO
#ifndef FURGON_H 
#define FURGON_H

#include "Vehiculo.h"

class Furgon : public Vehiculo{
private:
    int filas;
    int puertas;
public:
    Furgon();
    Furgon(const Furgon& orig);
    ~Furgon();
    void operator =(const Furgon& orig);
    void setFilas(const int filas);
    void setPuertas(const int puertas);
    int getFilas() const;
    int getPuertas() const;

    void lee(ifstream& arch);
    void imprime(ofstream& report);
    
};


#endif