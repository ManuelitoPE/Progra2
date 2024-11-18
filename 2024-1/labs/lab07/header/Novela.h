#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela : public Libro{
private:
    char* tipo;
public:
    Novela();
    Novela(const Novela& orig);
    ~Novela();
    
    void setTipo(const char* tipo);
    void getTipo(char* tipo) const;
    void cargar(ifstream& arch);

    void operator=(const Novela& novela);
};

#endif