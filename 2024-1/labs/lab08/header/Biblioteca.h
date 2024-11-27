//Author: MAKO
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"
#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
    void llena();
    void insertarLibro(Libro* libro);
    void baja();
    void muestra();
    
private:
    Estante AEstantes[10];
};

#endif /* BIBLIOTECA_H */

