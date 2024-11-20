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

void Novela::SetAutor(const char* autor) {
    if(this->autor != nullptr)delete[] this->autor;
    this->autor = new char[strlen(autor)+1]{};
    strcpy(this->autor,autor);
}

void Novela::GetAutor(char* autor) const {
    if(autor != nullptr)
        strcpy(autor,this->autor);
}

