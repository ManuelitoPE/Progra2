//Author: MAKO
#ifndef CAMION_H 
#define CAMION_H

#include "Vehiculo.h"

class Camion : public Vehiculo{
private:
    int ejes;
    int llantas;
public:
    Camion();
    Camion(const Camion& orig);
    ~Camion();
    void operator =(const Camion& orig);
    void setEjes(const int ejes);
    void setLlantas(const int llantas);
    int getEjes() const;
    int getLlantas() const;
    
    void lee(ifstream& arch);
    void imprime(ofstream& report);
};


#endif