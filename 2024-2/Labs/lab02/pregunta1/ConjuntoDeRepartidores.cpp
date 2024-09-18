/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "header/ConjuntoDeRepartidores.hpp"
#include "libraries/AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    //Variables
    Repartidor bufferRepartidores[MAX_REPARTIDORES]{};
    int cantDatos = 0;
    while(archivo_de_repartidores>>bufferRepartidores[cantDatos])cantDatos++;
    conjuntoDeRepartidores.conjunto_de_datos = new Repartidor[cantDatos+1]{};
    conjuntoDeRepartidores.cantidad = cantDatos;
    for (int i = 0; i < cantDatos; i++){
        conjuntoDeRepartidores.conjunto_de_datos[i] = bufferRepartidores[i];
    }
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}