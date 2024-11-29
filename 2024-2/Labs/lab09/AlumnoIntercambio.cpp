//Author: MAKO
#include "header/AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio(){
    paisOrigen = {};
    universidadOrigen = {};
    duracion = {};
}

AlumnoIntercambio::AlumnoIntercambio(const AlumnoIntercambio& orig):Alumno(orig){
    *this = orig;
}

AlumnoIntercambio::~AlumnoIntercambio(){
}

AlumnoIntercambio& AlumnoIntercambio::operator=(const AlumnoIntercambio& orig){
    Alumno::operator=(orig);
    paisOrigen = orig.getPaisOrigen();
    universidadOrigen = orig.getUniversidadOrigen();
    duracion = orig.getDuracion();
    return *this;
}

Alumno* AlumnoIntercambio::clonar(){
    return new AlumnoIntercambio(*this);
}

void AlumnoIntercambio::setPaisOrigen(const string paisOrigen){
    this->paisOrigen = paisOrigen;
}

void AlumnoIntercambio::setUniversidadOrigen(const string universidadOrigen){
    this->universidadOrigen = universidadOrigen;
}

void AlumnoIntercambio::setDuracion(const int duracion){
    this->duracion = duracion;
}

string AlumnoIntercambio::getPaisOrigen() const{
    return paisOrigen;
}

string AlumnoIntercambio::getUniversidadOrigen() const{
    return universidadOrigen;
}

int AlumnoIntercambio::getDuracion() const{
    return duracion;
}

void AlumnoIntercambio::leer(ifstream& arch){
    Alumno::leer(arch);
    getline(arch,paisOrigen,',');
    getline(arch,universidadOrigen,',');
    arch>>duracion;
    arch.ignore();
}

void AlumnoIntercambio::imprimir(ofstream& arch){
    Alumno::imprimir(arch);
    arch<<paisOrigen<<" "<<universidadOrigen<<" "<<duracion<<endl;
}