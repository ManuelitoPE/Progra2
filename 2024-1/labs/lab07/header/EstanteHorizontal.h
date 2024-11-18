//Author: MAKO

#ifndef ESTANTEHORIZONTAL_H
#define ESTANTEHORIZONTAL_H

#include "Estante.h"
#include "Novela.h"
#include "Enciclopedia.h"

class EstanteHorizontal : public Estante{ 
private:
    Novela novelas[10];
    int cantidad_novelas;
public:
    EstanteHorizontal();
    EstanteHorizontal(const EstanteHorizontal& orig);
    ~EstanteHorizontal();

    void setCantidad(const int);
    int getCantidad() const;

    void actualizar(const Enciclopedia& enciclopedia);
    void actualizar(const Novela& novela);
    bool espacioSobrante(int anchuraLibro,int alturaLibro);
    void imprimir(ofstream& report);
};

#endif
