//Author: MAKO 
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream> 
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Producto.h"

bool operator>>(ifstream& arch,Producto& producto);
bool operator>>(ifstream& arch,Cliente& cliente);
char* lecturaExacta(ifstream& arch,char deli);
ostream& operator<<(ostream& os,const Cliente* cliente);
ostream& operator<<(ostream& os,const Producto* producto);
#endif