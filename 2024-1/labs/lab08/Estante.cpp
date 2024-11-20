//Author: MAKO
#include "header/Estante.h"

Estantes::Estantes() {
    clase = {};
    id = {};
    capacidad = {};
    Llibros = {};
}

Estantes::Estantes(const Estantes& orig) {
}

Estantes::~Estantes() {
}

void Estantes::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estantes::GetCapacidad() const {
    return capacidad;
}

void Estantes::SetId(int id) {
    this->id = id;
}

int Estantes::GetId() const {
    return id;
}

void Estantes::SetClase(char clase) {
    this->clase = clase;
}

char Estantes::GetClase() const {
    return clase;
}

