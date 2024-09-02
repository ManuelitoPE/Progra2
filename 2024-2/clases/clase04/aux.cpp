//Author:MAKO
#include <iostream> 
#include <iomanip> 
#include <cstring> 
#include <fstream>
using namespace std;
#include "header/funciones.h"
#define MAX_LINEA 120
#define NO_ENCONTRADO -1
#define INCREMENTO 5

void lecturaDeProductos(const char* nomArch,char ***&productos,
                        int *&stock, double *&precios){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    //Variables
    int cantidad, cantDatos = 0, capacidad = 0;
    char *codigo,*descripcion,c; 
    double precio; 
    productos = nullptr; 
    precios = nullptr;
    stock = nullptr; 

    while(true){
        codigo = lecturaExacta(arch,',');
        if(!codigo)break;
        descripcion = lecturaExacta(arch,',');
        arch>>precio>>c>>cantidad; 
        arch.get();
        //Incrementar Espacio
        if(cantDatos==capacidad)
            incrementarCapacidad(productos,stock,precios,
                                 cantDatos,capacidad);
        //Guardar Datos
        guardarDatosProducto(pro,)
    } 
}
char * lecturaExacta(ifstream& arch,char deli){
    //Variables
    char buffer[200], *ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr; 
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
void incrementarCapacidad(char ***&productos,int *&stock,
                          double *&precios, int &cantDatos, 
                          int &capacidad){
    //Incremento
    capacidad += INCREMENTO;
    

}
void guardarDatosProducto(char **&infoProd, char *codigo,
                          char *nombre){

}
void pruebaDeLecturaDeProductos(const char*nomArch,char ***productos,
                                int *stock, double *precios){

}
void lecturaDePedidos(const char *nomPedidos, int*fechasPedidos,
                     char***codigoPedidos,int ***dniCantPedidos){

}
void pruebaDeLecturaDePedidos(const char* nomReporteDePedidos,
                              int* fechasPedidos, char ***codigoPedidos,
                              int ***dniCantPedidos){

}


