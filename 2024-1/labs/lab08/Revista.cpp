//Author: MAKO
#include "header/Revista.h" 

Revista::Revista() {
    ISSN    = {};
    anho    = {};
    numero  = {};
    vigencia = 1;
}

Revista::Revista(const Revista& orig):Libro(orig){
    *this = orig;
}

Revista::~Revista() {
}

void Revista::operator=(const Revista& orig){
    Libro::operator=(orig);
    ISSN = orig.GetISSN();
    anho = orig.GetAnho();
    numero = orig.GetNumero();
    vigencia = orig.GetVigencia();
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

void Revista::lee(ifstream& arch){
    Libro::lee(arch);
    arch>>ISSN;     arch.ignore();
    arch>>anho;     arch.ignore();
    arch>>numero;   arch.ignore();
}

void Revista::actualiza(){
    if(anho<=2020)vigencia = 0;
}

void Revista::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"ISSN: "<<ISSN<<setw(5)<<" "
        <<"Ano: "<<anho<<setw(5)<<" "
        <<"Numero: "<<numero<<setw(5)<<" "
        <<"Vigencia: "<<vigencia<<endl;
}
