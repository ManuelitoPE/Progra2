#include "header/Libro.h"

Libro::Libro(){
    codigo = {};
    nombre = {};
    ancho = {};
    alto = {};
    peso = {};
    colocado = {};
}
Libro::Libro(const Libro& libro){
    *this = libro;
}
Libro::~Libro(){
    delete[] codigo;
    delete[] nombre;
}
    
void Libro::setCodigo(const char* codigo){
    if(this->codigo != nullptr)delete[] this->codigo;
    this->codigo = new char[strlen(codigo)+1]{};
    strcpy(this->codigo,codigo);
}
void Libro::setNombre(const char* nombre){
    if(this->nombre != nullptr)delete[] this->nombre;
    this->nombre = new char[strlen(nombre)+1]{};
    strcpy(this->nombre,nombre);
}
void Libro::setAncho(const int ancho){
    this->ancho = ancho;
}
void Libro::setAlto(const int alto){
    this->alto = alto;
}
void Libro::setPeso(const double peso){
    this->peso = peso;
}
void Libro::setColocado(const bool colocado){
    this->colocado = colocado;
}

void Libro::getCodigo(char* codigo) const{
    if(codigo != nullptr)
        strcpy(codigo,this->codigo);
}
void Libro::getNombre(char* nombre) const{
    if(nombre != nullptr)
        strcpy(nombre,this->nombre);
}
int Libro::getAncho() const{
    return ancho;
}
int Libro::getAlto() const{
    return alto;
}
double Libro::getPeso() const{
    return peso;
}
bool Libro::getColocado() const{
    return colocado;
}
void Libro::operator=(const Libro& libro){
    char buffer[100];
    libro.getCodigo(buffer);
    this->setCodigo(buffer);
    libro.getNombre(buffer);
    this->setNombre(buffer);
    this->setAlto(libro.getAlto());
    this->setAncho(libro.getAncho());
    this->setColocado(libro.getColocado());
    this->setPeso(libro.getPeso());
}

void Libro::cargar(ifstream& arch){
    //Datos
    char *codigo,*nombre,c;
    int ancho,alto;
    arch.get();
    codigo = lecturaExacta(arch,',');
    arch.get();
    nombre = lecturaExacta(arch,',');
    arch.get();
    arch>>ancho>>c>>alto>>c;
    arch.get();
    setCodigo(codigo);
    setNombre(nombre);
    setAlto(alto);
    setAncho(ancho);
}
void Libro::imprimir(ofstream& report){
    char buffer[30];
    this->getCodigo(buffer);
    report<<setw(10)<<buffer;
    if(!this->getColocado())strcpy(buffer,"NO SE COLOCO");
    else this->getNombre(buffer);
    report<<setw(30)<<buffer;
    report<<setw(8)<<this->getAncho()
          <<setw(8)<<this->getAlto()
          <<setw(8)<<this->getPeso()<<endl;
}
