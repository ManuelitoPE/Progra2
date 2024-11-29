//Author: MAKO
#include "header/AlumnoUniversitario.h"

AlumnoUniversitario::AlumnoUniversitario(){
    ptrAlumno = {};
}

AlumnoUniversitario::AlumnoUniversitario(const AlumnoUniversitario& orig){
    *this = orig;
}

AlumnoUniversitario::~AlumnoUniversitario(){
}

AlumnoUniversitario& AlumnoUniversitario::operator=(const AlumnoUniversitario& orig){
    ptrAlumno = orig.ptrAlumno->clonar();
    return *this; 
}

bool AlumnoUniversitario::leer(ifstream& arch){
    //Datos 
    char c;
    arch>>c;
    if(arch.eof())return false;
    arch.ignore();
    if(c == 'R')
        ptrAlumno = new AlumnoRegular;
    else
        ptrAlumno = new AlumnoIntercambio;
    ptrAlumno->leer(arch);
    return true; 
}

void AlumnoUniversitario::imprimir(ofstream& arch){
    ptrAlumno->imprimir(arch);
}
string AlumnoUniversitario::getNombre() const{
    return ptrAlumno->getNombre();
}

string AlumnoUniversitario::getApellido() const{
    return ptrAlumno->getApellido();
}

int AlumnoUniversitario::getCodigo() const{
    return ptrAlumno->getCodigo();
}

//Para el queue
//Less
bool AlumnoUniversitario::operator<(const AlumnoUniversitario& a) const{
    return this->ptrAlumno->getPromedio() < a.ptrAlumno->getPromedio();
}
//Greater
bool AlumnoUniversitario::operator>(const AlumnoUniversitario& a) const{
    return this->ptrAlumno->getPromedio() > a.ptrAlumno->getPromedio();
}    