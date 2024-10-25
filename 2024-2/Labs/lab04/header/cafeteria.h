//Author: MAKO
#ifndef CAFETERIA_H 
#define CAFETERIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "apertura.h"
#include "enums.h"
#define MAX_INVENTARIO 100
#define MAX_MENU 80
//Funciones MAIN
void cargarInventario(const char* nomInventario,void*& inventario);

void cargarMenu(const char* nomMenu,void*& menu);

void actualizarMenu(const char* nomInsumos_bebidas,
                    void*& inventario,void*& menu);

void reporteMenu(const char* nomMenu,void*& menu);

void probarCargaInventario(const char* nomPrueba,void* inventario);

//Lecturas
bool lecturaInventario(void*& producto,ifstream& arch);

bool lecturaMenu(void*& producto,ifstream& arch);

//Liberar Memoria

//Funciones Auxiliares
char* lecturaExacta(ifstream& arch,char delimitador);



#endif