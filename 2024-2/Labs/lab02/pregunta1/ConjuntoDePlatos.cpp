/* 
 * Archivo: ConjuntoDePlatos.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:50
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "header/ConjuntoDePlatos.hpp"
#include "libraries/AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo) {
    ifstream archivo_de_platos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_platos, nombre_de_archivo);
    archivo_de_platos >> conjuntoDePlatos;
    archivo_de_platos.close();
}

void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos) {
    //Variables
    Plato bufferPlatos[MAX_PLATOS]{};
    int cantDatos = 0;
    while(archivo_de_platos>>bufferPlatos[cantDatos])cantDatos++;
    conjuntoDePlatos.conjunto_de_datos = new Plato[cantDatos+1]{};
    conjuntoDePlatos.cantidad = cantDatos;
    for (int i = 0; i < cantDatos; i++){
        conjuntoDePlatos.conjunto_de_datos[i] = bufferPlatos[i];
    }
}

void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos) {

}

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {    
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].precio;
    }
}

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}