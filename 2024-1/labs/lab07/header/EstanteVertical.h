#ifndef ESTANTEVERTICAL_H
#define ESTANTEVERTICAL_H

#include "Estante.h"
#include "Enciclopedia.h"
#include "Novela.h"

class EstanteVertical : public Estante{
private:
    Enciclopedia enciclopedias[10];
    int cantidad_enciclopedia;
public:
    EstanteVertical();
    EstanteVertical(const EstanteVertical& orig);
    ~EstanteVertical();

    void setCantidad(const int);
    int getCantidad() const;
    bool espacioSobrante(int anchuraLibro,int alturaLibro);
    void actualizar(const Enciclopedia& enciclopedia);
    void actualizar(const Novela& novela);
    void imprimir(ofstream& );
};

#endif