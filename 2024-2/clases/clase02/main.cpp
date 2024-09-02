//Author: MAKO
#include <iostream> 
#include <iomanip>
#include <fstream> 
using namespace std;
#include "funciones.h"
int main(){
    int* numeros,num;
    cargarArch("numeros.txt", numeros,  num);
    for (int i = 0; i < num; i++){
        cout<<numeros[i]<<endl;
    }
    delete[] numeros;
    return 0;
}