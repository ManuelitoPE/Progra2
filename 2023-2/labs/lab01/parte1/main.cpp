//Author: MAKO
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "header/funciones.h"
#include "header/Cliente.h"
#include "header/Producto.h"

int main(){
    //Datos
    Cliente cliente[150]{};
    Producto producto[150]{};
    int num = 0; 
    ifstream arch("docs/Productos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Clientes.txt"<<endl;
        exit(1);
    }
    ofstream report("docs/reporte.txt",ios::out);    
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir reporte.txt"<<endl;
        exit(1);
    }
    Producto* ptrProducto = producto;
    while(arch>>*(ptrProducto))
        ptrProducto++;
    for (int i = 0; producto[i].precio; i++){
        cout<<&producto[i];
    }
    
    return 0;
}