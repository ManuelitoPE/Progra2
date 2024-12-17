//Author: MAKO
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"
#include "Estructuras.h"

int main(){
    //Datos
    Cliente cliente[150]{};
    Producto producto[170]{};
    Pedido pedido[570]{};
    int num = 0; 
    ifstream archPedidos("Pedidos.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir Clientes.txt"<<endl;
        exit(1);
    }
    ifstream archProducto("Productos.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir Clientes.txt"<<endl;
        exit(1);
    }
    ifstream archCliente("Clientes.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir Clientes.txt"<<endl;
        exit(1);
    }
    ofstream report("reporte.txt",ios::out);    
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir reporte.txt"<<endl;
        exit(1);
    }
    Producto* ptrProducto = producto;
    Cliente* ptrCliente = cliente;
    Pedido* ptrPedido = pedido;
    while(archProducto>>*ptrProducto) ptrProducto++;
    while(archCliente>>*ptrCliente) ptrCliente++;
    while(archPedidos>>*ptrPedido) ptrPedido++;
    pedido[0].precioProducto = 120;
    if(producto+=pedido[0])
        for (int i = 0; producto[i].precio; i++){
            report<<&producto[i];
        }
    
    
    return 0;
}