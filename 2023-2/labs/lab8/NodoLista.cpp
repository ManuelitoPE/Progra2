//Author: mako
#include "header/NodoLista.h"

NodoLista::NodoLista(/* args */){
    unidad  = {};
    sig     = {};
}

NodoLista::~NodoLista(){
    delete unidad;
}
