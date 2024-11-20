//Author: MAKO
#include "header/Revista.h" 

Revista::Revista() {
    ISSN = {};
    anho = {};
    numero = {};
    vigencia = 1;
}

Revista::Revista(const Revista& orig):Libro(orig){
    *this = orig;
}

Revista::~Revista() {
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

