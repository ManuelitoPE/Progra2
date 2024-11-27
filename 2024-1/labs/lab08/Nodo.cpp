//Author: MAKO
#include "header/Nodo.h"

Nodo::Nodo(){
    plibro = {};
    sig    = {};
}
Nodo::Nodo(const Nodo& orig){   
}
Nodo::~Nodo(){
    delete plibro;
} 

