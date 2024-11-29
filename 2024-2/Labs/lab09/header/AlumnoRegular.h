//Author: MAKO

#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H
#include "Alumno.h" 

class AlumnoRegular : public Alumno{
private:
    int annoIngreso;
public:
    AlumnoRegular(/* args */);
    AlumnoRegular(const AlumnoRegular& orig);
    ~AlumnoRegular();
    Alumno* clonar();
    AlumnoRegular& operator=(const AlumnoRegular& orig);
    

    void setAnnoIngreso(const int);
    int getAnnoIngreso() const;
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);
};

#endif
