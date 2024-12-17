//Author: MAKO
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "header/funciones.h"
#include "header/AperturaArch.h"
#include "header/Enums.h"
#define INCREMENTO 5
#define MAX_LINEA 120
#define CLIENTE_NO_ENCONTRADO -1

void lecturaDeLibros(const char* nomLibros,char***& libros,
                     int**& stock){
    //apertura
    ifstream arch; aperturaArchLectura(arch,nomLibros);
    //DATOS
    libros = nullptr;
    char *codigo,*titulo,*autor,c;
    int cantDatos = 0, capacidad = 0,aux_stock;
    double precio;
    while (true){
        codigo = lecturaExacta(arch,',');
        if(codigo==nullptr)break;
        titulo = lecturaExacta(arch,',');
        autor = lecturaExacta(arch,',');
        arch>>aux_stock>>c>>precio; 
        arch.ignore();
        //Incrementar si es necesario
        if(cantDatos==capacidad) 
            incrementar(libros,stock,capacidad,cantDatos);
        ingresarDatos(libros[cantDatos-1],stock[cantDatos-1],codigo,
                      titulo,autor,aux_stock);
        cantDatos++;
    }
    
}
void pruebaDeLecturaDeLibros(const char* nomReporte,char*** libros,
                     int** stock){
    ofstream report; aperturaArchEscritura(report,nomReporte);
    report.precision(2); report<<fixed;
    encabezadoLibros(report);
    //Datos
    char** infoLibro;
    int* infoStock; 
    for (int i = 0; libros[i]; i++){
        infoLibro = libros[i];
        infoStock = stock[i];
        report<<left<<setw(10)<<infoLibro[LIBRO::_CODIGO]
              <<left<<setw(70)<<infoLibro[LIBRO::_TITULO]
              <<left<<setw(28)<<infoLibro[LIBRO::_AUTOR]
              <<right<<setw(10)<<infoStock[STOCK::_INICIAL]<<endl;
    }
    
}
void atencionDePedidos(const char* nomPedidos,char***& libros,
                    int**& stock,int**& pedidosClientes,
                    char***& pedidosLibros,bool**& pedidosAtendidos){
    ifstream arch; aperturaArchLectura(arch,nomPedidos);
    //Datos
    pedidosLibros = nullptr; pedidosClientes = nullptr; pedidosAtendidos = nullptr;
    int numPedido,dniCliente;
    int cantDatos = 0,capacidad = 0;   
    int cantClientes = 0, capacidadClientes = 0;
    while(true){
        arch>>numPedido;
        if(arch.eof())break;
        arch.ignore();  arch>>dniCliente;
        if(cantClientes==capacidad)
            incrementar(pedidosClientes,capacidadClientes,cantClientes);
        agregarCliente(pedidosClientes,dniCliente,numPedido,cantClientes);
        if(capacidad == cantDatos || numPedido>capacidad)
            incrementar(pedidosLibros,pedidosAtendidos,capacidad,
                        cantDatos,numPedido);
        
        lecturaDeLibrosPedido(arch,pedidosLibros[cantDatos-1]);

        cout<<dniCliente<<endl;
        cantDatos++;
    } 
    ofstream reporte; aperturaArchEscritura(reporte,"docs/reportePrueba");
   
}
void pruebaDeLecturaDeLibros(const char* nomReporte,char***& libros,
                    int**& stock){
}
void ordenarPedidosClientes(int**& pedidosClientes){

}
void reporteDeEntregaDePedidos(const char* nomReporte,int** pedidosClientes,
                    char*** pedidosLibros,bool** pedidosAtendidos){

}

//Funciones Auxiliares
char* lecturaExacta(ifstream& arch,char deli){
    //Datos
    char buffer[200],*ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr; 
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
void ingresarDatos(char**& infoLibros,int*& infostock,char* codigo,
                   char* titulo,char* autor,int aux_stock){
    infoLibros = new char*[3];
    infoLibros[LIBRO::_CODIGO] = codigo;
    infoLibros[LIBRO::_TITULO] = titulo;
    infoLibros[LIBRO::_AUTOR] = autor;
    infostock = new int[2];
    infostock[STOCK::_INICIAL] = aux_stock;
    infostock[STOCK::_NO_ATENDIDA] = 0;
}
void linea(ofstream& report,int n,char c){
    for (int i = 0; i < n; i++)report<<c;
    report<<endl;
}
void lecturaDeLibrosPedido(ifstream& arch,char**& listaLibros){
    //Datos
    char codigo[8]; 
    int cantLibro = 0, capacidad = 0;
    while (arch.get()!='\n'){
        arch>>ws>>codigo;
        if(cantLibro==capacidad)
            incrementar(listaLibros,capacidad,cantLibro);
        agregarLibro(listaLibros[cantLibro-1],codigo);
        cantLibro++;
    } 
}
void agregarLibro(char*& libro,char* codigo){
    libro = new char[strlen(codigo)+1];
    strcpy(libro,codigo);
}
void agregarCliente(int**& pedidosClientes,int dniCliente,int numPedido,
                    int& cantClientes){
    //Datos
    int posCliente = buscarCliente(pedidosClientes,dniCliente,cantClientes);
    int* infoCliente, posPedido;
    if(posCliente==CLIENTE_NO_ENCONTRADO){
        //Creamos espacio para los datos del cliente
        pedidosClientes[cantClientes-1] = new int[3];
        infoCliente = pedidosClientes[cantClientes-1];
        infoCliente[CLIENTE::_DNI] = dniCliente;
        infoCliente[CLIENTE::_CANT_PEDIDOS] = 1;
        infoCliente[CLIENTE::_PRIMER_PEDIDO] = numPedido;
        cantClientes++;
    }else{
        //Incrementar Pedidos
        incrementar(pedidosClientes[posCliente]);
        infoCliente = pedidosClientes[posCliente];
        posPedido = infoCliente[CLIENTE::_CANT_PEDIDOS] + 2;
        infoCliente[posPedido] = numPedido;
        infoCliente[CLIENTE::_CANT_PEDIDOS]++;
    }
}
int buscarCliente(int** pedidosClientes,int dni,int cantClientes){
    //Datos
    int* infoCliente;
    for (int i = 0; i<cantClientes; i++){
        infoCliente = pedidosClientes[i];
        if(infoCliente==nullptr)return CLIENTE_NO_ENCONTRADO;
        if(infoCliente[CLIENTE::_DNI]==dni)return i;
    }
    return CLIENTE_NO_ENCONTRADO;
}
//Incrementos 
void incrementar(char***& libros,int**& stock,int& capacidad,
                 int& cantDatos){
    //Incrementamos
    capacidad+=INCREMENTO;
    if(libros==nullptr){
        libros = new char**[capacidad]{};
        stock = new int*[capacidad]{};
        cantDatos++;
    }else{
        char*** auxLibros = new char**[capacidad]{};
        int** auxStock = new int*[capacidad]{};
        for (int i = 0; libros[i] ; i++){
            auxLibros[i] = libros[i];
            auxStock[i] = stock[i];   
        }
        delete libros;
        delete stock;
        libros = auxLibros;
        stock = auxStock;
    }
}
void incrementar(char**& listaLibros,int& capacidad,int& cantLibro){ 
    //Incrementamos
    capacidad+=INCREMENTO;
    if(listaLibros==nullptr){
        listaLibros = new char*[capacidad]{};
        cantLibro++;
    }else{
        char** auxListaLibros = new char*[capacidad]{};
        for (int i = 0; listaLibros[i]; i++)
            auxListaLibros[i] = listaLibros[i];   
        delete listaLibros;
        listaLibros = auxListaLibros;
    }
}
void incrementar(char***& pedidosLibros,bool**& pedidosAtendidos,
                 int& capacidad,int& cantDatos,int numPedido){
    //Incremento de la capacidad
    if(numPedido>capacidad)capacidad = numPedido+INCREMENTO;
    else capacidad+=INCREMENTO;
    
    if(pedidosLibros==nullptr){
        pedidosLibros = new char**[capacidad]{};
        pedidosAtendidos = new bool*[capacidad]{};
        cantDatos++;
    }else{
        char*** auxPedidosLibros = new char**[capacidad]{};
        bool** auxPedidosAtendidos = new bool*[capacidad]{};
        for (int i = 0;pedidosLibros[i]; i++){
            auxPedidosLibros[i] = pedidosLibros[i];
            auxPedidosAtendidos[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = auxPedidosLibros;
        pedidosAtendidos = auxPedidosAtendidos;
    }
}
void incrementar(int**& pedidosClientes,int& capacidadClientes,
                 int& cantClientes){
    //Incrementar
    capacidadClientes+=INCREMENTO;
    if(pedidosClientes==nullptr){
        pedidosClientes = new int*[capacidadClientes]{};
        cantClientes++;
    }else{
        int** auxPedidosClientes = new int*[capacidadClientes]{};
        for (int i = 0; pedidosClientes[i]; i++)
            auxPedidosClientes[i] = pedidosClientes[i];
        delete pedidosClientes;
        pedidosClientes = auxPedidosClientes;
    }
}
void incrementar(int* cliente){
    //Se agrega espacio el dni,cantPedidos y el nuevo codigo
    int cant = cliente[CLIENTE::_CANT_PEDIDOS]+3;  
    int* auxCliente = new int[cant]{};
    for (int i = 0; i < cant; i++)
        auxCliente[i] = cliente[i];
    delete cliente;
    cliente = auxCliente;
}  

//Encabezados
void encabezadoLibros(ofstream& report){
    report<<setw(50)<<"REPORTE DE STOCK DE LIBROS"<<endl;
    linea(report,MAX_LINEA,'=');
    report<<left<<setw(10)<<"CODIGO"
          <<left<<setw(70)<<"TITULO"
          <<left<<setw(28)<<"AUTOR"
          <<left<<setw(10)<<"STOCK"<<endl;
    linea(report,MAX_LINEA,'-');
}