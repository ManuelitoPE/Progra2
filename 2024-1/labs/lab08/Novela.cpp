//Author: MAKO
#include "header/Novela.h"

Novela::Novela() {
    autor = {};
}

Novela::Novela(const Novela& orig):Libro(orig) {
    *this = orig;
}

Novela::~Novela() {
    delete[] autor;
}

void Novela::operator=(const Novela& orig){
    char buffer[200]; 
    Libro::operator=(orig);
    orig.GetAutor(buffer);
    this->SetAutor(buffer);
}

void Novela::SetAutor(const char* autor) {
    if(this->autor != nullptr)delete[] this->autor;
    this->autor = new char[strlen(autor)+1]{};
    strcpy(this->autor,autor);
}

void Novela::GetAutor(char* autor) const {
    if(autor != nullptr)
        strcpy(autor,this->autor);
}

void Novela::lee(ifstream& arch){
    //Datos
    char buffer[200];
    //Lectura  
    Libro::lee(arch);
    arch.getline(buffer,200,'\n');
    this->SetAutor(buffer);
}

void Novela::actualiza(){
}

void Novela::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;
}
