#include "header/Enciclopedia.h"

Enciclopedia::Enciclopedia() : Libro(){
    volumen = {};
}
Enciclopedia::Enciclopedia(const Enciclopedia& orig):Libro(orig){
    *this = orig;
}
Enciclopedia::~Enciclopedia(){
}

void Enciclopedia::setVolumen(const int volumen){
    this->volumen = volumen;
}
int Enciclopedia::getVolumen()const{
    return volumen;
}
void Enciclopedia::operator=(const Enciclopedia& enciclopedia){
    Libro::operator=(enciclopedia);
    this->setVolumen(enciclopedia.getVolumen());
}

void Enciclopedia::cargar(ifstream& arch){
    //Datos
    int volumen;
    double peso;
    Libro::cargar(arch);
    arch>>volumen; arch.get();
    arch>>peso;    arch.get();
    setVolumen(volumen);
    setPeso(peso);
}
