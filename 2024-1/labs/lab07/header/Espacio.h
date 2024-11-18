#ifndef ESPACIO_H
#define ESPACIO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funciones.h"

class Espacio{
private:
    char contenido = ' '; 
    int posx;
    int posy;
public:
    Espacio();
    Espacio(const Espacio& orig);
    ~Espacio();
    
    void setContenido(const char );
    void setPosx(const int);
    void setPosy(const int);
    
    char getContenido() const;
    int getPosx() const;
    int getPosy() const;
};

#endif