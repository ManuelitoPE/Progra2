//Author: MAKO
#include "header/Alumno.h"


Alumno::Alumno(){
    codigo = {};
    nombre = {};
    apellido = {};
    edad = {};
    ciclo = {};
    promedio = {};
}

Alumno::Alumno(const Alumno& orig){
    *this = orig;
}

Alumno::~Alumno(){
}

void Alumno::setCodigo(const int codigo){
    this->codigo = codigo;
}

void Alumno::setNombre(const string nombre){
    this->nombre = nombre;
}

void Alumno::setApellido(const string apellido){
    this->apellido = apellido;
}

void Alumno::setEdad(const int edad){
    this->edad = edad;
}

void Alumno::setCiclo(const int ciclo){
    this->ciclo = ciclo; 
}

void Alumno::setPromedio(const double promedio){
    this->promedio = promedio;
}

int Alumno::getCodigo() const{
    return codigo;
}

string Alumno::getNombre() const{
    return nombre;
}

string Alumno::getApellido() const{
    return apellido;
}

int Alumno::getEdad() const{
    return edad;
}

int Alumno::getCiclo() const{
    return ciclo;
}

double Alumno::getPromedio() const{
    return promedio;
}

Alumno& Alumno::operator=(const Alumno& orig){
    codigo = orig.getCodigo();
    nombre = orig.getNombre();
    apellido = orig.getApellido();
    edad = orig.getEdad();
    ciclo = orig.getCiclo();
    promedio = orig.getPromedio();
    return *this;
}

void Alumno::leer(ifstream& arch){
    arch>>codigo;   arch.ignore();
    getline(arch,nombre,',');
    getline(arch,apellido,',');
    arch>>edad;     arch.ignore();
    arch>>ciclo;    arch.ignore();
    arch>>promedio; arch.ignore();
}

void Alumno::imprimir(ofstream& arch){
    arch<<codigo<<" "<<nombre<<" "<<promedio<<" ";
}