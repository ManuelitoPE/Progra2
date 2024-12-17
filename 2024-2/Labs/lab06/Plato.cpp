#include "header/Plato.h"

Plato::Plato(){
    codigo = {};
    nombre = {};
    precio = {};
    categoria = {};
    preparados = {};
    descuento = {};
    atendidos = {};
    noAtendidos = {};
    totalEsperado = {};
    totalBruto = {};
    totalNeto = {};
}
Plato::Plato(const Plato& orig){
    *this = orig;
}
Plato::~Plato(){    
    delete[] codigo;
    delete[] nombre;
    delete[] categoria;
}
void Plato::setCodigo(const char* codigo){
    if(this->codigo != nullptr) delete[] this->codigo;
    this->codigo = new char[strlen(codigo)+1]{};
    strcpy(this->codigo,codigo);
}
void Plato::setNombre(const char* nombre){
    if(this->nombre != nullptr) delete[] this->nombre;
    this->nombre = new char[strlen(nombre)+1]{};
    strcpy(this->nombre,nombre);
}
void Plato::setPrecio(const double precio){
    this->precio = precio;
}
void Plato::setCategoria(const char* categoria){
    if(this->categoria != nullptr) delete[] this->categoria;
    this->categoria = new char[strlen(categoria)+1]{};
    strcpy(this->categoria,categoria);
}
void Plato::setPreparados(const int preparados){
    this->preparados = preparados;
}
void Plato::setDescuento(const double descuento){
    this->descuento = descuento;
}
void Plato::setAtendidos(const int atendidos){
    this->atendidos = atendidos;
}
void Plato::setNoAtendidos(const int noAtendidos){
    this->noAtendidos = noAtendidos;
}
void Plato::setTotalEsperado(const double totalEsperado){
    this->totalEsperado = totalEsperado;
}
void Plato::setTotalBruto(const double totalBruto){
    this->totalBruto = totalBruto;
}
void Plato::setTotalNeto(const double totalNeto){
    this->totalNeto = totalNeto;
}

void Plato::getCodigo(char* codigo)const{
    if(codigo != nullptr)
        strcpy(codigo,this->codigo);
}
void Plato::getNombre(char* nombre)const{
    if(nombre != nullptr)
        strcpy(nombre,this->nombre);
}
double Plato::getPrecio() const{
    return precio;
}
void Plato::getCategoria(char* categoria) const{
    if(categoria != nullptr)
        strcpy(categoria,this->categoria);
}
int Plato::getPreparados() const{
    return preparados;
}
double Plato::getDescuento() const{
    return descuento;
}
int Plato::getAtendidos() const{
    return atendidos;
}
int Plato::getNoAtendidos() const{
    return noAtendidos;
}
double Plato::getTotalEsperado() const{
    return totalEsperado;
}
double Plato::getTotalBruto() const{
    return totalBruto;
}
double Plato::getTotalNeto() const{
    return totalNeto;
}

void Plato::operator =(const Plato& plato){
    char buffer[500];
    plato.getNombre(buffer);
    // cout<<buffer<<endl;
    this->setNombre(buffer);
    plato.getCategoria(buffer);
    // cout<<buffer<<endl;
    this->setCategoria(buffer);
    plato.getCodigo(buffer);
    // cout<<buffer<<endl;
    this->setCodigo(buffer);
    
    this->setPrecio(plato.getPrecio());
    this->setPreparados(plato.getPreparados());
    this->setDescuento(plato.getDescuento());
    
    this->setAtendidos(plato.getAtendidos());
    this->setNoAtendidos(plato.getNoAtendidos());

    this->setTotalBruto(plato.getTotalBruto());
    this->setTotalEsperado(plato.getTotalEsperado());
    this->setTotalNeto(plato.getTotalNeto());
}

void Plato::actualizar(){
    char buffer[500];
    this->getCodigo(buffer);
    cout<<"si q cc "<<buffer<<endl;
}

bool operator >>(ifstream& arch,Plato& plato){
    //Datos
    double precio,descuento;
    int preparados;
    char* codigo = lecturaExacta(arch,',');
    if(codigo == nullptr)return false;
    plato.setCodigo(codigo);
    char* nombre = lecturaExacta(arch,',');
    plato.setNombre(nombre);
    arch>>precio;
    plato.setPrecio(precio);
    arch.ignore();
    char* categoria = lecturaExacta(arch,',');
    plato.setCategoria(categoria);
    arch>>preparados;
    plato.setPreparados(preparados);
    if(arch.get()!='\n'){
        arch>>descuento;
        plato.setDescuento(descuento);
        arch.ignore(); arch.ignore();
    }else plato.setDescuento(0);

    return true; 
}