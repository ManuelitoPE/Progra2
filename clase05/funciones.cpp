//Author: MAKO
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "header/funciones.h"
#define NO_ENCONTRADO -1

void cargarProductos(void *&productos){
    ifstream arch("docs/Productos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Productos"<<endl;
        exit(1);
    }
    //Variables
    void **prod = nullptr, *infoProd;
    int cantDatos = 0, capDat = 0;
    while(true){
        infoProd = lecturaProductos(arch);
        if(arch.eof())break;
        if(cantDatos == capDat)
            incrementarEspacio(prod,cantDatos,capDat);
        prod[cantDatos-1] = infoProd;
        cantDatos++;
    }
    productos = prod;
    imprimeProductos(productos);
}
void *lecturaProductos(ifstream& arch){
    //Variables
    void **datsProd = new void*[4];
    char *code,*description,*tipo = new char,c;
    double *precio = new double;
    code = lecturaExactar(arch,',');
    if(arch.eof())return nullptr;
    description = lecturaExactar(arch,',');
    arch>>(*precio)>>c>>(*tipo); arch.get();
    datsProd[0] = code;
    datsProd[1] = description;
    datsProd[2] = precio;
    datsProd[3] = tipo;
    return datsProd;
}
char* lecturaExactar(ifstream& arch,char deli){
    //Variables
    char buffer[200], *ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
void incrementarEspacio(void **&prod,int &cantDatos,int &capDat){
    //Incremento
    capDat += 5;
    if(prod == nullptr){
        prod = new void*[capDat]{};
        cantDatos++;   
    }else{
        void **aux = new void*[capDat]{};
        for(int i=0 ; i<cantDatos ; i++){
            aux[i] = prod[i];
        }
        delete prod;
        prod = aux;
    }
}
void cargarClientes(void *& clientes){
    ifstream arch("docs/Clientes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Clientes.csv"<<endl;
        exit(1);
    }
    //Variables
    void **dataClientes = nullptr,*infoCliente;
    int cantDatos = 0, capDat = 0;
    while (true){
        infoCliente = lecturaClientes(arch);
        if(arch.eof())break;
        if(cantDatos == capDat)
            incrementarEspacio(dataClientes,cantDatos,capDat);
        dataClientes[cantDatos-1] = infoCliente;
        cantDatos++;
    }
    clientes = dataClientes;
    imprimeClientes(clientes);
}
void* lecturaClientes(ifstream& arch){
    //Variables
    void **dataCliente = new void*[4];
    int *dni = new int,num;
    double *lineaCredito = new double;
    char *nombre,c;
    arch>>(*dni);
    if(arch.eof())return nullptr; arch.get();
    nombre = lecturaExactar(arch,',');
    arch>>num>>c>>(*lineaCredito); arch.get();
    dataCliente[0] = dni;
    dataCliente[1] = nombre;
    dataCliente[2] = nullptr;
    dataCliente[3] = lineaCredito;
    return dataCliente;
}
void imprimeProductos(void *productos){
    ofstream report("docs/ReporteProductos.txt", ios::out);
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir ReporteProductos"<<endl;
        exit(1);
    }
    //Variables
    void **listaProd = (void**)productos;
    for (int i = 0;listaProd[i]; i++){
        void **datosProd = (void**)listaProd[i];
        report<<left<<setw(10)<<(char*)datosProd[0]
              <<setw(50)<<(char*)datosProd[1]
              <<setw(10)<<*(double*)datosProd[2]
              <<setw(10)<<*(char*)datosProd[3]<<endl;
    }
}
void imprimeClientes(void* clientes){
    ofstream report("docs/ReporteClientes.txt", ios::out);
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir ReporteProductos"<<endl;
        exit(1);
    }
    //Variables
    void **listaClientes = (void**)clientes;
    for (int i = 0;listaClientes[i]; i++){
        void **datosClientes = (void**)listaClientes[i];
        void **pedidos = (void**)datosClientes[2];
        report<<left<<setw(10)<<*(int*)datosClientes[0]
              <<setw(50)<<(char*)datosClientes[1]
              <<setw(10)<<*(double*)datosClientes[3]<<endl;
        report<<"-----------------------------------------"<<endl;
        for (int i = 0; pedidos[i]; i++){
            void **pedido = (void**)pedidos[i];
            report<<setw(20)<<(char*)pedido[0]
                  <<setw(20)<<*(int*)pedido[1]
                  <<setw(20)<<*(double*)pedido[2]<<endl;
        }
        
    }
}
void cargaPedidos(void *&productos,void *&clientes){
    ifstream arch("docs/Pedidos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Pedidos.csv"<<endl;
        exit(1);
    }
    //Variables
    char *code,c; int dni,cant; 
    while(true){
        code = lecturaExactar(arch,',');
        if(arch.eof())break;
        arch>>dni>>c>>cant; arch.get();
        procesarDatos(productos,clientes,code,dni,cant);
    }   
    imprimeClientes(clientes);
}
void procesarDatos(void *&productos,void *&clientes,
                   char* code,int dni,int cant){
    //Variables
    void **listaProductos = (void**)productos;
    void **listaClientes = (void**)clientes;
    int posProducto = busqueda(listaProductos,code);
    int posCliente = busqueda(listaClientes,dni);
    void **dataProducto = (void**)listaProductos[posProducto];
    void **dataCliente  = (void**)listaClientes[posCliente];
    if(*(char*)dataProducto[3]=='S'){
        if(*(double*)dataCliente[3]>=*(double*)dataProducto[2]*cant){
            *(double*)dataCliente[3] -= *(double*)dataProducto[2]*cant;
            ingresarProducto(dataCliente[2],code,cant,
                             *(double*)dataProducto[2]);
        }
    }else{  
        ingresarProducto(dataCliente[2],code,cant,*(double*)dataProducto[2]);
    }
}
void ingresarProducto(void *&dataCliente,char *code,int cant,
                      double precio){
    int *cantidad = new int;
    double *totalPedido = new double;
    *cantidad = cant;
    *totalPedido = cant*precio;
                        
    if(dataCliente == nullptr){
        //Variables
        void **listaPedidos = new void*[2]{};
        void **aux = new void*[3];
        aux[0] = code;
        aux[1] = cantidad;
        aux[2] = totalPedido;
        listaPedidos[0] = aux;
        dataCliente = listaPedidos;
    }else{
        //Variables
        void **listaPedidos = (void**)dataCliente;
        int cantDatos = 0;
        //Contamos los datos
        while(listaPedidos[cantDatos])cantDatos++;
        //Copiamos
        void **auxLista =  new void*[cantDatos+1]{};
        for (int i = 0; listaPedidos[i]; i++) auxLista[i]=listaPedidos[i];
        void **aux = new void*[3];
        aux[0] = code;
        aux[1] = cantidad;
        aux[2] = totalPedido;
        auxLista[cantDatos] = aux;
        delete dataCliente;
        dataCliente = auxLista;
    }
}
int busqueda(void **listaProductos,char* code){
    for (int i = 0; listaProductos[i]; i++){
        //Variables
        void** dataProducto = (void**)listaProductos[i]; 
        if(strcmp((char*)dataProducto[0],code)==0)return i;
    }
    return NO_ENCONTRADO;
}
int busqueda(void** listaClientes, int dni){
    for (int i = 0;listaClientes[i]; i++){
        //Variables
        void **dataCliente = (void**)listaClientes[i];
        if(dni == *(int*)dataCliente[0])return i;
    }
    return NO_ENCONTRADO;
}
