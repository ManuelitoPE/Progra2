//Author: MAKO
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estantes.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void baja();
    void muestra();
    
private:
    Estantes AEstantes[10];
};

#endif /* BIBLIOTECA_H */

