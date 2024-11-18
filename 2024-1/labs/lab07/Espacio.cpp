//Author: MAKO
#include "header/Espacio.h"

Espacio::Espacio(){
    // contenido = {};
    posx = {};
    posy = {};
}

Espacio::Espacio(const Espacio& orig){
    *this = orig;
}

Espacio::~Espacio(){
}

void Espacio::setContenido(const char contenido){
    this->contenido = contenido;
}

void Espacio::setPosx(const int posx){
    this->posx = posx;
}

void Espacio::setPosy(const int posy){
    this->posy = posy;
}
    
char Espacio::getContenido() const{
    return contenido;
}

int Espacio::getPosx() const{
    return posx;
}

int Espacio::getPosy() const{
    return posy;
}

