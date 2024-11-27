//Author: MAKO
#include "header/Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    sku = {};
    anho = {};
    vigencia = 1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig):Libro(orig) {
    *this = orig;
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::operator=(const Enciclopedia& orig){
    Libro::operator=(orig);
    sku  = orig.GetSku();
    anho = orig.GetAnho();
    vigencia = orig.GetVigencia();
}
void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream& arch){
    Libro::lee(arch);
    arch>>sku;      arch.ignore();
    arch>>anho;     arch.ignore();
}

void Enciclopedia::actualiza(){
    if(anho<=2020)vigencia = 0;
}

void Enciclopedia::imprime(ofstream& arch){
    Libro::imprime(arch);
    arch<<"SKU: "<<sku<<setw(5)<<" "
        <<"Ano: "<<anho<<setw(5)<<" "
        <<"Vigencia: "<<vigencia<<endl;
}