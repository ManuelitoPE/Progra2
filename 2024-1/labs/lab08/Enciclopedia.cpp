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

