//Author: MAkO
#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Alumno{
private:
    int codigo;
    string nombre;
    string apellido;
    int edad;
    int ciclo;
    double promedio;
public:
    Alumno();
    Alumno(const Alumno& orig);
    ~Alumno();

    void setCodigo(const int);
    void setNombre(const string);
    void setApellido(const string);
    void setEdad(const int);
    void setCiclo(const int);
    void setPromedio(const double);

    int getCodigo() const;
    string getNombre() const;
    string getApellido() const;
    int getEdad() const;
    int getCiclo() const;
    double getPromedio() const;

    Alumno& operator=(const Alumno& orig);

    virtual void leer(ifstream& arch);
    virtual void imprimir(ofstream& arch); 
    virtual Alumno* clonar() = 0;
};

#endif