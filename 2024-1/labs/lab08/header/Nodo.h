#ifndef NODO_H
#define NODO_H

#include "Libro.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
private:
    Libro* plibro;
    Nodo* sig;
};

#endif /* NODO_H */

