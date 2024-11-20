#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(const double peso);
    double GetPeso() const;
    void SetPaginas(const int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void operator=(const Libro& libro);

private:
    char* nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

