//Author: MAKO
#include "header/Lista.h"

Lista::Lista() {
    peso = {};
    ini = {};
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    Nodo* ptr =  ini;
    Nodo* aux;
    while(ptr){
        aux = ptr->sig;
        delete ptr;
        ptr = aux;
    }
}

void Lista::setPeso(const double peso){
    this->peso = peso;
}

double Lista::getPeso() const{
    return peso;
}

void Lista::insertar(Libro* libro){
    peso += libro->GetPeso();
    Nodo* nuevo = new Nodo;
    nuevo->plibro = libro;
    nuevo->sig = ini;
    ini = nuevo;
}

void Lista::imprime(ofstream& arch){
    Nodo* ptr = ini;
    while(ptr){
        ptr->plibro->imprime(arch);
        ptr = ptr->sig;
        arch<<endl;
    }
}

void Lista::actualiza(){
    Nodo* ptr = ini;
    while (ptr){
        ptr->plibro->actualiza();
        ptr = ptr->sig;
    }    
}