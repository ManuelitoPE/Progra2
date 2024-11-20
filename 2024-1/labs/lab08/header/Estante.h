#ifndef ESTANTES_H
#define ESTANTES_H

#include "Lista.h"

class Estantes {
public:
    Estantes();
    Estantes(const Estantes& orig);
    virtual ~Estantes();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
};

#endif /* ESTANTES_H */

