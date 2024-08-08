//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/funciones.h"

int main(){
    //Variables 
    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    //Procesos
    lecturaDeProductos("docs/Productos.csv",productos,stock,
                        precios);
    preubaDeLecturaDeProductos("docs/ReporteDeProductos.txt",
                               productos,stock,precios); 
    lecturaDePedidos("docs/Pedidos.csv",fechaPedidos,codigoPedidos,
                     dniCantPedidos);
    pruebaDeLecturaDePedidos("docs/ReporteDePedidos.txt",fechaPedidos,
                              codigoPedidos,dniCantPedidos);

    return 0;
}