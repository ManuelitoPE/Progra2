#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia : public Libro{
private:
    int volumen;
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    ~Enciclopedia();

    void operator=(const Enciclopedia& enciclopedia);

    void setVolumen(const int volumen);
    int getVolumen()const; 
    void cargar(ifstream& arch);
};


#endif