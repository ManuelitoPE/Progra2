#include "header/Novela.h"

Novela::Novela(){
    tipo = {};
}
Novela::Novela(const Novela& orig) : Libro(orig){
    *this = orig;
}
Novela::~Novela(){
    delete[] tipo;
}
void Novela::setTipo(const char* tipo){
    if(this->tipo != nullptr)delete[] this->tipo;
    this->tipo = new char[strlen(tipo)+1]{};
    strcpy(this->tipo,tipo);
}
void Novela::getTipo(char* tipo) const{
    if(tipo != nullptr)
        strcpy(tipo,this->tipo);
}
void Novela::operator=(const Novela& novela){
    char buffer[100];
    Libro::operator=(novela);
    novela.getTipo(buffer);
    this->setTipo(buffer);
}

void Novela::cargar(ifstream& arch){
    //Datos
    char *ptr;
    double peso; 
    Libro::cargar(arch);
    ptr = lecturaExacta(arch,',');
    arch>>peso;     arch.get();
    setTipo(ptr);
    setPeso(peso);
}

