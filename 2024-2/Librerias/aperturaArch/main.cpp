//Author: MAKO
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "header/apertura.h"
int main(){
    ifstream arch;
    aperturaLeer(arch,"hola.txt");
    char hola[50];
    arch>>hola;
    ofstream leer;
    aperturaEscribir(leer,"Lectura.txt");
    leer<<hola;
    return 0;
} 