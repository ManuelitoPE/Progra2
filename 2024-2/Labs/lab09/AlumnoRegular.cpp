//Author: MAKO
#include "header/AlumnoRegular.h"

AlumnoRegular::AlumnoRegular(){
    annoIngreso = {};
}

AlumnoRegular::AlumnoRegular(const AlumnoRegular& orig):Alumno(orig){
    *this = orig;
}

AlumnoRegular::~AlumnoRegular(){
}

AlumnoRegular& AlumnoRegular::operator=(const AlumnoRegular& orig){
    Alumno::operator=(orig);
    annoIngreso = orig.getAnnoIngreso();
    return *this; 
}

Alumno* AlumnoRegular::clonar(){
    return new AlumnoRegular(*this);
}

void AlumnoRegular::setAnnoIngreso(const int annoIngreso){
    this->annoIngreso = annoIngreso;
}

int AlumnoRegular::getAnnoIngreso() const{
    return annoIngreso;
}

void AlumnoRegular::leer(ifstream& arch){
    Alumno::leer(arch);
    arch>>annoIngreso;
    arch.ignore();
}

void AlumnoRegular::imprimir(ofstream& arch){
    Alumno::imprimir(arch);
    arch<<annoIngreso<<endl;
}