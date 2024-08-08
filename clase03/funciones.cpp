//Author: MAKO
#include <iostream> 
#include <iomanip> 
#include <cstring> 
#include <fstream>
using namespace std;
#include "header/funciones.h"
#define MAX_LINEA 120
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char* nomProductos,
                        char ***&productos,int *&stock,
                        double *&precios){
    ifstream arch(nomProductos,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomProductos<<endl;
        exit(1);
    }
    //Variables
    char **bufferProductos[200],c;
    int bufferStock[200], cantDatos = 0;
    double bufferPrecios[200]; 
    while(true){
        bufferProductos[cantDatos] = new char*[2];
        bufferProductos[cantDatos][0] = lecturaExacta(arch,',');
        if(arch.eof())break;
        bufferProductos[cantDatos][1] = lecturaExacta(arch,',');
        arch>>bufferPrecios[cantDatos]>>c>>bufferStock[cantDatos];
        arch.get(); cantDatos++;
    }
    //Aperturamos espacios
    productos = new char**[cantDatos+1]{};
    precios   = new double[cantDatos+1]{}; 
    stock     = new int[cantDatos+1]{};
    //Copiamos
    for (int i = 0; i < cantDatos; i++){
        productos[i] = bufferProductos[i];
        precios[i]   = bufferPrecios[i];
        stock[i]     = bufferStock[i];
    }
}
char* lecturaExacta(ifstream& arch,char deli){
    //Variables
    char buffer[200], *ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr; 
}
void preubaDeLecturaDeProductos(const char* nomReporte,
                                char ***productos,int *stock,
                                double *precios){
    ofstream report(nomReporte,ios::out);
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomReporte<<endl;
        exit(1);
    }
    report.precision(2); report<<fixed; encabezadoProductos(report);
    //Variables

    for (int i = 0; productos[i]; i++){
        report<<left<<setw(10)<<productos[i][0]   
              <<setw(60)<<productos[i][1]<<right
              <<setw(10)<<precios[i]
              <<setw(10)<<stock[i]<<endl;
    }
}
void encabezadoProductos(ofstream& report){
    report<<setw(50)<<"REPORTE DE PRODUCTOS"<<endl;
    linea(report,MAX_LINEA,'=');
    report<<left<<setw(15)<<"CODIGO"
          <<setw(59)<<"DESCRIPTION"
          <<setw(13)<<"PRECIO"
          <<setw(15)<<"STOCK"<<endl;
    linea(report,MAX_LINEA,'-');
}
void linea(ofstream& report,int n,char c){
    for (int i = 0; i < n; i++)report<<c;
    report<<endl;
}
void lecturaDePedidos(const char* nomPedidos,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos){
    ifstream arch(nomPedidos,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se puede abrir "<<nomPedidos<<endl;
        exit(1);
    }
    //Variables
    char **bufferCodigoPedidos[200], *code,c;
    int bufferFechaPedidos[200], **bufferDniCantPedidos[200];
    int dd,mm,aa,fecha,dni,cant,cantDatos = 0;
    while(true){
        code = lecturaExacta(arch,',');
        if(code == nullptr)break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        arch.get(); fecha = aa*10000+mm*100+dd;
        ingresarDatos(bufferCodigoPedidos,bufferDniCantPedidos,
                      bufferFechaPedidos,cantDatos,code,
                      fecha,dni,cant);
    }
    comprimirPedidos(bufferCodigoPedidos,
                    bufferDniCantPedidos);
    dniCantPedidos = new int**[cantDatos+1]{};
    codigoPedidos = new char**[cantDatos+1]{};
    fechaPedidos = new int[cantDatos+1]{};
    
}
void ingresarDatos(char ***bufferCodigoPedidos,int ***bufferDniCantPedidos,
                   int *bufferFechaPedidos,int &cantDatos,char *code,
                   int fecha,int dni,int cant){
    //Variables
    int posFecha = buscarFecha(bufferFechaPedidos,fecha,cantDatos); 
    if(posFecha == NO_ENCONTRADO){
        bufferDniCantPedidos[cantDatos] = new int*[100]{}; 
        bufferCodigoPedidos[cantDatos]  = new char*[100]{}; 
        bufferFechaPedidos[cantDatos]   = fecha;
        ingresarPedido(bufferDniCantPedidos[cantDatos],bufferCodigoPedidos[cantDatos],
                       code,cant,dni);
        cantDatos++;
    }else ingresarPedido(bufferDniCantPedidos[posFecha],bufferCodigoPedidos[posFecha],
                         code,cant,dni);
}
void comprimirPedidos(char ***&bufferCodigoPedidos,
                      int ***&bufferDniCantPedidos){
    //Variables
    int cantDatos = 0; 
    for (size_t i = 0; bufferCodigoPedidos[i]; i++){
        while(bufferCodigoPedidos[i][cantDatos])cantDatos++;
        char **auxCodigoPedidos  = new char*[cantDatos+1]{};
        int  **auxDniCantPedidos = new int*[cantDatos+1]{};
        for (int j = 0; j < cantDatos; j++){
            auxDniCantPedidos[j] = bufferDniCantPedidos[i][j];
            auxCodigoPedidos[j] = bufferCodigoPedidos[i][j];
        }
        delete bufferDniCantPedidos[i];
        delete bufferCodigoPedidos[i];

        bufferDniCantPedidos[i] = auxDniCantPedidos;
        bufferCodigoPedidos[i]  = auxCodigoPedidos;     
    }
    
}
int buscarFecha(int *bufferFechaPedidos,int fecha,int cantDatos){
    for (int i = 0; i < cantDatos; i++)
        if(bufferFechaPedidos[i] == fecha)return i;
    return NO_ENCONTRADO;
}
void ingresarPedido(int **bufferDniCantPedidos,char** bufferCodigoPedidos,
                    char *code,int cant,int dni){
    //Variables
    int cantDatos = 0;
    while(bufferCodigoPedidos[cantDatos])cantDatos++;
    //Copiamos CodigoPedidos 
    bufferCodigoPedidos[cantDatos] = new char[strlen(code)+1];
    strcpy(bufferCodigoPedidos[cantDatos],code);
    //Copiamos Dni y cant
    bufferDniCantPedidos[cantDatos] = new int[2];
    bufferDniCantPedidos[cantDatos][0] = dni;
    bufferDniCantPedidos[cantDatos][1] = cant;
}
void pruebaDeLecturaDePedidos(const char* nomReporte,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos){

}
