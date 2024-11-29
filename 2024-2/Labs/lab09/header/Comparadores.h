//Author: MAKO
#ifndef COMPARADORES_H 
#define COMPARADORES_H 

#include "AlumnoUniversitario.h"

class OrdenaAlumnoPorNombre{
public:
    bool operator()(const AlumnoUniversitario& a,
                    const AlumnoUniversitario& b) const;
};

class OrdenaAlumnoPorCodigo{
public:
    bool operator()(const AlumnoUniversitario& a,
                    const AlumnoUniversitario& b) const;
};

#endif