//Author: MAKO
#include "header/Furgon.h"

Furgon::Furgon(){
    filas   = {};
    puertas = {};
}

Furgon::Furgon(const Furgon& orig){
    *this = orig;
}

Furgon::~Furgon(){
}

void Furgon::operator =(const Furgon& orig){
    Vehiculo::operator=(orig);
    this->setFilas(orig.getFilas());
    this->setPuertas(orig.getPuertas());
}

void Furgon::setFilas(const int filas){
    this->filas = filas;
}

void Furgon::setPuertas(const int puertas){
    this->puertas = puertas;
}

int Furgon::getFilas() const{
    return filas;
}

int Furgon::getPuertas() const{
    return puertas;
}

void Furgon::lee(ifstream& arch){
    Vehiculo::lee(arch);
    arch>>filas;
    arch.ignore();
    arch>>puertas;
    arch.get();
}

void Furgon::imprime(ofstream& report){
    Vehiculo::imprime(report);
    report<<setw(15)<<" "<<setw(20)<<"#filas:"<<filas<<endl
          <<setw(15)<<" "<<setw(20)<<"#puertas:"<<puertas<<endl;
    Vehiculo::imprimePila(report);
}

