//Author: MAKO
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "header/funciones.h"
#include "header/enums.h"
#define NO_ENCONTRADO -1

// Funciones Main
void lecturaDeLibros(const char* nomLibros,char***& libros,
                     int**& stock){
    ifstream arch = aperturaArch(nomLibros);
    //Variables
    char** bufferLibros[MAXI::_LIBROS];
    int* bufferStock[MAXI::_LIBROS];
    int numDatos = 0;
    while(true){
        lecturaDatosLibro(bufferLibros[numDatos],arch);
        if(bufferLibros[numDatos][LIBROS::CODIGO]==nullptr)break;
        lecturaStock(bufferStock[numDatos],arch);
        numDatos++;
    } 
    libros = new char**[numDatos+1]{};
    stock  = new int*[numDatos+1]{};
    for (int i = 0; i < numDatos; i++){
        libros[i] = bufferLibros[i];
        stock[i]  = bufferStock[i];
    }
}
void pruebaDeLecturaDeLibros(const char* nomReporte,char*** libros,
                             int** stock){
    ofstream report = aperturaReporte(nomReporte);
    encabezadoReporteLibros(report);
    for (int i = 0; libros[i]; i++){
        report<<left<<setw(10)<<libros[i][LIBROS::CODIGO]
          <<left<<setw(60)<<libros[i][LIBROS::TITULO]
          <<left<<setw(30)<<libros[i][LIBROS::AUTOR]
          <<right<<setw(10)<<stock[i][STOCK::STOCK_INICIAL]<<endl;
    }
    
}
void atencionDePedidos(const char* nomPedidos,char*** libros,
                       int**& stock,int**& pedidosClientes,
                       char***& pedidosLibros,bool**& pedidosAtendidos){
    ifstream arch = aperturaArch(nomPedidos);
    //Variables
    int* bufferPedidosClientes[MAXI::_PEDIDOS];
    char** bufferPedidosLibros[MAXI::_PEDIDOS];
    bool* bufferPedidosAtendidos[MAXI::_PEDIDOS];
    int numDatos = 0;
    int numeroPedido,dniCliente,posPedido; 
    char c; 
    while(true){
        arch>>numeroPedido; 
        if(arch.eof())break;
        arch>>c>>dniCliente;
        cout<<numeroPedido;
        ingresarPedidoCliente(bufferPedidosClientes,numDatos,dniCliente,
                       numeroPedido);
        ingresarPedidosLibrosYatendidos(bufferPedidosLibros[numeroPedido],
                                        bufferPedidosAtendidos[numeroPedido],
                                        arch);
        cout<<bufferPedidosClientes[numDatos][PEDIDOS::CLIENTE_DNI]
            <<endl<<bufferPedidosClientes[numDatos][PEDIDOS::CLIENTE_CANT]
            <<bufferPedidosClientes[numDatos][2]<<endl;
        break;
    }
}
void pruebaDeLecturaDeLibros(const char* nomPedidos,char*** libros,
                             int** stock,int** pedidosClientes,
                             char*** pedidosLibros,bool** pedidosAtendidos){

}
void reporteDeEntregaDePedidos(const char* nomReporte,int**& pedidosClientes,
                               char*** pedidosLibros,bool** pedidosAtendidos){

}

// Funciones Auxiliares
void ingresarPedidoCliente(int** bufferPedidosClientes,int numDatos,int dniCliente,
                    int numeroPedido){
    //Datos
    int posCliente = buscarCliente(bufferPedidosClientes,numDatos,dniCliente);
    int posPedido; 
    if(posCliente==NO_ENCONTRADO){
        bufferPedidosClientes[numDatos] = new int[PEDIDOS::CLIENTES]{};
        bufferPedidosClientes[numDatos][PEDIDOS::CLIENTE_DNI] = dniCliente;
        bufferPedidosClientes[numDatos][PEDIDOS::CLIENTE_CANT]++;
        posPedido = PEDIDOS::CLIENTE_CANT + bufferPedidosClientes[numDatos][PEDIDOS::CLIENTE_CANT]; 
        bufferPedidosClientes[numDatos][posPedido] = numeroPedido;
    }else{
        bufferPedidosClientes[posCliente][PEDIDOS::CLIENTE_CANT]++;
        posPedido = PEDIDOS::CLIENTE_CANT + bufferPedidosClientes[posCliente][PEDIDOS::CLIENTE_CANT]; 
        bufferPedidosClientes[posCliente][posPedido] = numeroPedido;
    }
}
int buscarCliente(int** bufferPedidosClientes,int numDatos,
                  int dniCliente){
    for (int i = 0; i < numDatos; i++)
        if(bufferPedidosClientes[i][PEDIDOS::CLIENTE_DNI]==dniCliente)
            return i;
    return NO_ENCONTRADO;
}
void linea(ofstream& report,int n,char c){
    for (int i = 0; i < n; i++)report<<c;
    report<<endl;
}
ofstream aperturaReporte(const char* nomReporte){
    ofstream report(nomReporte,ios::out);
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomReporte<<endl;
        exit(1);
    }
    report.precision(2); report<<fixed;
    return report;
}
void lecturaStock(int*& stock,ifstream& arch){
    //Datos Auxiliares
    double precio;
    stock = new int[2];
    arch>>stock[STOCK::STOCK_INICIAL];
    arch.ignore(); //Ignoro la coma
    arch>>precio; //Ignoro el precio
    arch.ignore(); //Ignoro el salto de linea
}

void lecturaDatosLibro(char**& libro,ifstream& arch){
    libro = new char*[3];
    libro[LIBROS::CODIGO] = lecturaExacta(arch,',');
    if(libro[LIBROS::CODIGO] == nullptr)return;
    libro[LIBROS::TITULO] = lecturaExacta(arch,',');
    libro[LIBROS::AUTOR] = lecturaExacta(arch,',');
}
char* lecturaExacta(ifstream& arch,char deli){
    //Variables
    char buffer[200],*ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr; 
}
ifstream aperturaArch(const char* nomLibros){
    ifstream arch(nomLibros,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomLibros<<endl;
        exit(1);
    }
    return arch;
}
// Encabezados
void encabezadoReporteLibros(ofstream& report){
    report<<setw(50)<<"REPORTE DE LIBROS"<<endl;
    linea(report,LIBROS::LINEA,'=');
    report<<left<<setw(10)<<"CODIGO"
          <<left<<setw(60)<<"TITULO"
          <<left<<setw(30)<<"AUTOR"
          <<right<<setw(10)<<"STOCK"<<endl;
    linea(report,LIBROS::LINEA,'-');
}

