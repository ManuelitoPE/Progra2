//Author: Mako
#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Curso{
private:
    int codigo;
    string nombre;
    int creditos;
    int capacidades;
public:
    Curso();
    Curso(const Curso& orig);
    ~Curso();
    Curso& operator=(const Curso& orig);

    void setCodigo(const int codigo);
    void setNombre(const string nombre);
    void setCapacidades(const int capacidades);
    void setCreditos(const int creditos);
    
    int getCodigo() const;
    string getNombre() const;
    int getCapacidades() const;
    int getCreditos() const;
    bool leer(ifstream& arch);
    void imprimir(ofstream& arch);
    //Para el map
    bool operator>(const Curso&) const;
    bool operator<(const Curso&) const;
};


#endif