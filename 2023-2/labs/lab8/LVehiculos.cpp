//Author: MAKO
#include "header/LVehiculos.h" 

LVehiculos::LVehiculos(){
    lini = {};
    lfin = {};
}

LVehiculos::~LVehiculos(){
    NodoLista* ptr = lini;
    NodoLista* aux;
    while(ptr){
        aux = ptr->sig;
        delete ptr;
        ptr = aux;
    }
}

void LVehiculos::insertar(Vehiculo* vehiculo){
    NodoLista* nuevo = new NodoLista;
    nuevo->unidad = vehiculo;
    if(lini == nullptr)
        lfin = nuevo;
    nuevo->sig = lini;
    lini = nuevo;
}


void LVehiculos::mostrar(ofstream& report){
    NodoLista* ptr = lini;
    while(ptr){
        ptr->unidad->imprime(report);
        ptr = ptr->sig;
    }
}

void LVehiculos::ingresaPedido(int cliente,const NPedido& nuevo){
    NodoLista* ptr = lini;
    while(ptr){
        if(ptr->unidad->getCliente() == cliente and 
           ptr->unidad->getMaxcarga()>= ptr->unidad->getActcarga()+nuevo.getPeso())
                ptr->unidad->push(nuevo);
        ptr = ptr->sig;
    }    
}