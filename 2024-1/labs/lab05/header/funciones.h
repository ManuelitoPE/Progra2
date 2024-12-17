//Author
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "enums.h"
void crearLista(void*& pedidos1,bool (*leenum)(ifstream&,void*&),const char* nomPlatos,
                int (*cmp)(const void*,const void*));
bool leenum(ifstream& arch, void*& plato);
void insertar(void*& platosLista,void* plato,
             int (*cmp)(const void*,const void*));
char* lecturaExacta(ifstream& arch,char delimitador);

int cmpPlatos(const void*, const void*);

#endif
