//Author: MAKO
#include "header/Curso.h"

Curso::Curso(){
    codigo = {};
    nombre = {};
    creditos = {};
    capacidades = {};
}

Curso::Curso(const Curso& orig){
    *this = orig;
}

Curso::~Curso(){
}

Curso& Curso::operator=(const Curso& orig){
    codigo = orig.codigo;
    nombre = orig.nombre;
    creditos =  orig.creditos;
    capacidades = orig.capacidades;
    return *this;
}

void Curso::setCodigo(const int codigo){
    this->codigo =  codigo;
}

void Curso::setNombre(const string nombre){
    this->nombre = nombre;
}

void Curso::setCapacidades(const int capacidades){
    this->capacidades = capacidades;
}

void Curso::setCreditos(const int creditos){
    this->creditos = creditos;
}
    
int Curso::getCodigo() const{
    return codigo;
}

string Curso::getNombre() const{
    return nombre;
}

int Curso::getCapacidades() const{
    return capacidades;
}

int Curso::getCreditos() const{
    return creditos;
}

bool Curso::leer(ifstream& arch){
    arch>>codigo;
    if(arch.eof())return false;
    arch.ignore();      getline(arch,nombre,',');
    arch>>creditos;     arch.ignore();
    arch>>capacidades;  arch.ignore();
    return true;
}

void Curso::imprimir(ofstream& arch){
    arch<<left<<setw(10)<<codigo
        <<setw(33)<<nombre
        <<setw(10)<<creditos
        <<setw(10)<<capacidades<<endl;
}

bool Curso::operator>(const Curso& orig) const{
    return codigo > orig.codigo;
}

bool Curso::operator<(const Curso& orig) const{
    return codigo < orig.codigo;
}