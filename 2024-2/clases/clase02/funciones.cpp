#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"
void cargarArch(const char* nomArch, int*& numeros, int& num){
    int buffer[10000];
    num =  0;
    ifstream arch(nomArch,ios::in);
    while (!arch.eof()){
        arch>>buffer[num];
        num++;
    }
    numeros = new int[num];
    for (int i = 0; i < num; i++){
        numeros[i]=buffer[i];
    }
}
