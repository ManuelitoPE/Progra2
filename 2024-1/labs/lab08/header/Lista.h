#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
private:
    double peso;
    Nodo* ini;
};

#endif /* LISTA_H */

