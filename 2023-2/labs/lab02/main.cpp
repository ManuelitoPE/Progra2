//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;;
#include "header/funciones.h"

int main(){
    //Datos
    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;  

    lecturaDeProductos("docs/Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("docs/ReporteDeProductos.txt",productos,
                                stock,precios);
    
    lecturaDePedidos("docs/Pedidos.csv",fechaPedidos,codigoPedidos,
                     dniCantPedidos);
    pruebaDeLecturaDePedidos("docs/ReporteDePedidos.txt",fechaPedidos,codigoPedidos,
                              dniCantPedidos);   
    reporteDeEnvioDePedidos("docs/ReporteDeEntregaDePedidos.txt",productos,
                            stock,precios,fechaPedidos,codigoPedidos,
                            dniCantPedidos);
    return 0;
}