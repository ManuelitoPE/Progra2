//Author: MAKO
#ifndef ALUMNOINTERCAMBIO_H
#define ALUMNOINTERCAMBIO_H

#include "Alumno.h"

class AlumnoIntercambio : public Alumno{
private:
    string paisOrigen;
    string universidadOrigen;
    int duracion;
public:
    AlumnoIntercambio();
    AlumnoIntercambio(const AlumnoIntercambio& orig);
    ~AlumnoIntercambio();
    AlumnoIntercambio& operator=(const AlumnoIntercambio& orig);
    Alumno* clonar();

    void setPaisOrigen(const string);
    void setUniversidadOrigen(const string);
    void setDuracion(const int);

    string getPaisOrigen() const;
    string getUniversidadOrigen() const;
    int getDuracion() const;
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);
};

#endif