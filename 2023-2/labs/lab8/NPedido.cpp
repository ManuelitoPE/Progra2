//Auhtor: MAKO
#include "header/NPedido.h"


NPedido::NPedido(){
    codigo = {};
    cantidad = {};
    peso = {};
    sig = {};
}

NPedido::NPedido(const NPedido& orig){
    *this = orig;
}

void NPedido::operator =(const NPedido& npedido){
    char buffer[200];
    npedido.getCodigo(buffer);
    this->setCodigo(buffer);
    cantidad = npedido.getCantidad();
    peso     = npedido.getPeso();
    //Aqui solo se copia la direcciondel siguiente nodo, no todo el nodo
    sig = npedido.sig;
}

NPedido::~NPedido(){
    delete sig;
    delete[] codigo;
}

void NPedido::getCodigo(char* codigo) const{
    if(codigo != nullptr)
        stpcpy(codigo,this->codigo);
}

int NPedido::getCantidad() const{
    return cantidad;
}

double NPedido::getPeso() const{
    return peso;
}
    
void NPedido::setCodigo(const char* codigo){
    if(this->codigo != nullptr)delete[] this->codigo;
    this->codigo =  new char[strlen(codigo)+1]{};
    strcpy(this->codigo,codigo);
}

void NPedido::setCantidad(const int cantidad){
    this->cantidad = cantidad;
}

void NPedido::setPeso(const double peso){
    this->peso = peso;
}

void NPedido::imprime(ofstream& report){
    report<<setw(20)<<" "<<setw(10)<<codigo
          <<setw(5)<<cantidad
          <<setw(5)<<peso<<endl;
}

void NPedido::lee(ifstream& arch){
    //Datos
    char buffer[100];
    //Lectura 
    arch.getline(buffer,100,',');
    arch>>cantidad;
    arch.ignore();  
    arch>>peso;
    arch.ignore();
}