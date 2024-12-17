//AUTHOR: mako
#ifndef LIBRO_H
#define LIBRO_H

class Libro{
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro(/* args */);
    ~Libro();
};

Libro::Libro(/* args */)
{
}

Libro::~Libro()
{
}


#endif