//Author: MAKO

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX_LINEA 60


void aperturaArchLeer(const char* nomArch,ifstream& arch);
void aperturaArchEscr(const char* nomArch,ofstream& arch);
char* lecturaExacta(ifstream& arch, char deli);
void linea(ofstream& report,int n,char c);
void encabezado(ofstream& report);
void encabezado2(ofstream& report);

#endif