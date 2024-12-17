//Author: MAKO
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "header/apertura.h"
void aperturaLeer(ifstream& arch,const char* nomArch){
    arch.open(nomArch,ios::in);
    if(!arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
}
void aperturaEscribir(ofstream& arch,const char* nomArch){
    arch.open(nomArch,ios::out);
    if(!arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
}
