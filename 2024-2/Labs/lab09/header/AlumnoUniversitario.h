//Auhtor: MAKO
#ifndef ALUMNOUNIVERSITARIO_H
#define ALUMNOUNIVERSITARIO_H

#include "Alumno.h"
#include "AlumnoIntercambio.h"
#include "AlumnoRegular.h"

class AlumnoUniversitario{
private:
    Alumno* ptrAlumno;
public:
    AlumnoUniversitario();
    AlumnoUniversitario(const AlumnoUniversitario& orig);
    ~AlumnoUniversitario();
    AlumnoUniversitario& operator=(const AlumnoUniversitario& orig);

    string getNombre() const;
    string getApellido() const;
    int getCodigo() const;
    //Less
    bool operator<(const AlumnoUniversitario&) const;
    //Greater
    bool operator>(const AlumnoUniversitario&) const;
    
    bool leer(ifstream& arch); 
    void imprimir(ofstream& arch);

};

#endif
