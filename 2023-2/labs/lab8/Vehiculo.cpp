//Author: MAKO
#include "header/Vehiculo.h"


Vehiculo::Vehiculo(){
    cliente     = {};
    placa       = {};
    maxcarga    = {};
    actcarga    = {};
    ped         = {};
}

Vehiculo::Vehiculo(const Vehiculo& orig){
    *this = orig;
}

void Vehiculo::operator =(const Vehiculo& orig){
    char buffer[200];
    orig.getPlaca(buffer);
    this->setPlaca(buffer);
    cliente = orig.getCliente();
    maxcarga = orig.getMaxcarga();
    actcarga = orig.getActcarga();    
    //Aqui solo se esta copiando el puntero a la cabeza de la pila
    ped = orig.ped;
}

Vehiculo::~Vehiculo(){
    delete[] placa;
    delete ped;
}

void Vehiculo::setPlaca(const char* placa){
    if(this->placa != nullptr)delete[] this->placa;
    this->placa =  new char[strlen(placa)+1]{};
    strcpy(this->placa,placa);
}
void Vehiculo::setCliente(const int cliente){
    this->cliente = cliente;
}
void Vehiculo::setMaxcarga(const double maxcarga){
    this->maxcarga = maxcarga;
}
void Vehiculo::setaActcarga(const double actcarga){
    this->actcarga = actcarga;
}
void Vehiculo::getPlaca(char* placa) const{
    if(placa != nullptr)
        stpcpy(placa,this->placa);
}
int Vehiculo::getCliente() const{
    return cliente;
}
double Vehiculo::getMaxcarga() const{
    return maxcarga;
}
double Vehiculo::getActcarga() const{
    return actcarga;
}

void Vehiculo::lee(ifstream& arch){
    //Datos
    char placa[8];
    //Lectura
    arch.ignore();
    arch>>cliente;
    arch.ignore();
    arch.getline(placa,8,',');
    this->setPlaca(placa);
    arch>>maxcarga;
    arch.ignore();
}

void Vehiculo::imprime(ofstream& report){
    report<<left<<setw(15)<<" "<<setw(20)<<"Codigo Cliente:"<<cliente<<endl
          <<setw(15)<<" "<<setw(20)<<"Placa:"<<placa<<endl
          <<setw(15)<<" "<<setw(20)<<"Carga Maxima:"<<maxcarga<<endl
          <<setw(15)<<" "<<setw(20)<<"Carga Actual:"<<actcarga<<endl;
}
void Vehiculo::imprimePila(ofstream& report){
    NPedido* ptr = ped;
    if(ptr == nullptr)
        report<<setw(15)<<" "<<"No hay pedidos para el cliente"<<endl;
    while(ptr){
        ptr->imprime(report);
        ptr = ptr->sig;
    }
}

void Vehiculo::push(const NPedido& nuevo){
    actcarga += nuevo.getPeso();
    NPedido* aux = new NPedido(nuevo);
    aux->sig = ped;
    ped = aux;
}

bool Vehiculo::listaVacia(){
    if(ped == nullptr)return true;
    return false;
}