//Author: MAKO
#include "header/Camion.h"


Camion::Camion(){
    ejes = {};
    llantas = {};
}

Camion::Camion(const Camion& orig):Vehiculo(orig){
    *this = orig;
}

Camion::~Camion(){
}

void Camion::operator =(const Camion& orig){
    Vehiculo::operator=(orig);
    ejes    = orig.getEjes();
    llantas = orig.getLlantas();
}

void Camion::setEjes(const int ejes){
    this->ejes = ejes;
}

void Camion::setLlantas(const int llantas){
    this->llantas = llantas;
}

int Camion::getEjes() const{
    return ejes;
}

int Camion::getLlantas() const{
    return llantas;
}

void Camion::lee(ifstream& arch){
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.ignore();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream& report){
    Vehiculo::imprime(report);
    report<<setw(15)<<" "<<setw(20)<<"#Ejes:"<<ejes<<endl
          <<setw(15)<<" "<<setw(20)<<"#Llantas:"<<llantas<<endl;
    Vehiculo::imprimePila(report);
}
