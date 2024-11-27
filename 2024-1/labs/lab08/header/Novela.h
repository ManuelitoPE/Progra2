//Author: MAKO
#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela : public Libro{
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(const char* autor);
    void GetAutor(char* autor) const;
    void operator=(const Novela& orig);
    void lee(ifstream& arch);
    void actualiza();
    void imprime(ofstream& arch);
private:
    char* autor;
};

#endif /* NOVELA_H */



