//Author: MAKO
#ifndef RESTAURANTE_H 
#define RESTAURANTE_H 

#include "Cliente.h"
#include "Plato.h"
#include "funciones.h"

#define NO_ENCONTRADO -1

class Restaurante{
private:
    Cliente* clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    Plato* platos;
    int cantidadDePlatos;
    int capacidadDePlatos;
public:
    Restaurante();
    ~Restaurante();
    void operator <(const char* nomArch);
    void operator <=(const char* nomArch);
    void operator <<=(const char* nomArch);
    void incrementarCliente();
    void incrementarPlato();
    int buscar(int dni);
    int buscar(const char* codigo);

    void mostrar();
};

#endif