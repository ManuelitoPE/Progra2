//Auhtor: MAKO
#ifndef CLIENTE_H 
#define CLIENTE_H
#include "Pedido.h"

class Cliente{
private:
    int dni;
    char categoria;
    char *nombre;
    Pedido* Iped;
    int numPed;
    double total;
public:
    Cliente(/* args */);
    ~Cliente();
    int Setdni;
    char Setcategoria;
    char Setnombre;
    Pedido SetIped[100];
    int SetnumPed;
    double Settotal;
    int Getdni;
    char Getcategoria;
    void Getnombre;
    Pedido GetIped;
    int GetnumPed;
    double Gettotal;
};

Cliente::Cliente(/* args */)
{
}

Cliente::~Cliente()
{
}


#endif