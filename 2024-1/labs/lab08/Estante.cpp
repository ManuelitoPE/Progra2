//Author: MAKO
#include "header/Estante.h"

Estante::Estante() {
    clase       = {};
    id          = {};
    capacidad   = {};
    Llibros     = {};
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

bool Estante::lee(ifstream& arch){
    arch>>clase;
    if(arch.eof())return false;
    arch.ignore();  arch>>id;
    arch.ignore();  arch>>capacidad;
    arch.ignore();
    return true;
}

void Estante::imprime(ofstream& arch){
    arch<<"Estantes:"<<endl;
    linea(arch,MAX_LINEA,'=');
    arch<<"Id:"<<id<<endl
        <<"Tipo"<<clase<<endl
        <<"Capacidad:"<<capacidad<<endl
        <<"Libros Contenidos: "<<endl;
    linea(arch,MAX_LINEA,'=');
    Llibros.imprime(arch);
}

bool Estante::insertar(Libro* libro){
    if(capacidad >= Llibros.getPeso()+libro->GetPeso()){
        Llibros.insertar(libro);
        return true;
    }
    return false;
}

void Estante::actualiza(){
    Llibros.actualiza();
}