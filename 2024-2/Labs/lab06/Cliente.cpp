#include "header/Cliente.h"

Cliente::Cliente(){
    dni = {};
    nombre = {};
    distrito = {};
    descuento = {};
    totalPagado = {};
}
Cliente::Cliente(const Cliente& orig){
    *this = orig;
}

Cliente::~Cliente(){
    delete[] distrito;
    delete[] nombre;
}
void Cliente::setDni(const int dni){
    this->dni = dni;
}
void Cliente::setNombre(const char* nombre){
    if(this->nombre!=nullptr)delete[] this->nombre;
    this->nombre = new char[strlen(nombre)+1]{};
    strcpy(this->nombre,nombre);
}
void Cliente::setDistrito(const char* distrito){
    if(this->distrito!=nullptr)delete[] this->distrito;
    this->distrito = new char[strlen(distrito)+1]{};
    strcpy(this->distrito,distrito);

}
void Cliente::setDescuento(const double descuento){
    this->descuento = descuento;
}
void Cliente::setTotalPagado(const double total){
    this->totalPagado + total;
}
    
int  Cliente::getDni() const{
    return dni;
}
void Cliente::getNombre(char* nombre) const{
    if(nombre != nullptr)
        strcpy(nombre,this->nombre);
}
void Cliente::getDistrito(char* distrito) const{
    if(distrito != nullptr)
        strcpy(distrito,this->distrito);
}
double Cliente::getDescuento() const{
    return descuento;
}
double Cliente::getTotalPagado() const{
    return totalPagado;
}
void Cliente::operator =(const Cliente& cliente){
    char buffer[500];
    cliente.getNombre(buffer);
    this->setNombre(buffer);
    cliente.getDistrito(buffer);
    this->setDistrito(buffer);
    this->setDni(cliente.getDni());
    this->setDescuento(cliente.getDescuento());
    this->setTotalPagado(cliente.getTotalPagado());
}
void Cliente::actualizar(ifstream& arch){
    cout<<"hola kbro "<<this->getDni()<<endl;
}


bool operator>>(ifstream& arch,Cliente& cliente){
    int dni;
    char *nombre,*distrito;
    double descuento;
    arch>>dni;
    if(arch.eof())return false;
    arch.ignore();
    cliente.setDni(dni);
    nombre = lecturaExacta(arch,',');
    distrito = lecturaExacta(arch,',');
    cliente.setNombre(nombre);
    cliente.setDistrito(distrito);
    if(arch.get()=='S'){
        arch.ignore();
        arch>>descuento; 
        arch.ignore();
        cliente.setDescuento(descuento);
    }else cliente.setDescuento(0);
    arch.ignore();
    return true;
}

