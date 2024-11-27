#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void setPeso(const double);
    double getPeso() const;
    void insertar(Libro* libro);
    void actualiza();
    void imprime(ofstream& arch);
private:
    double peso;
    Nodo* ini;
};

#endif /* LISTA_H */

