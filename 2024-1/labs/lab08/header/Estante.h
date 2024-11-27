#ifndef ESTANTE_H
#define ESTANTE_H

#include "Lista.h"
#include "funciones.h"
#define MAX_LINEA 100
class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    bool lee(ifstream& arch);
    bool insertar(Libro* libro);
    void actualiza();
    void imprime(ofstream& arch);
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
};

#endif /* ESTANTES_H */

