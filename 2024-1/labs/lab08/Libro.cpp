//Author: MAKO
#include "header/Libro.h"

Libro::Libro() {
    nombre = {};
    paginas = {};
    peso = {};
}

Libro::Libro(const Libro& orig) {
    *this = orig;
}

Libro::~Libro() {
    delete[] nombre;
}

void Libro::SetPeso(const double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(const int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char* nombre) {
    if(this->nombre != nullptr)delete[] this->nombre;
    this->nombre = new char[strlen(nombre)+1]{};
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char* nombre) const {
    if(nombre != nullptr)
        strcpy(nombre,this->nombre);
}

void Libro::operator=(const Libro& libro){
    char buffer[200];
    libro.GetNombre(buffer);
    this->SetNombre(buffer);
    this->SetPaginas(libro.GetPaginas());
    this->SetPeso(libro.GetPeso());
}
