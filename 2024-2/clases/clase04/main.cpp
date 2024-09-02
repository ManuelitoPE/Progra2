//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/funciones.h"
int main(){
    //Variables 
    char ***productos, ***codigoPedidos;
    int *stock, *fechasPedidos, ***dniCantPedidos;
    double *precios;
    
    //Procesos
    lecturaDeProductos("docs/Productos.csv", productos, stock, precios);
    pruebaDeLecturaDeProductos("docs/ReporteDeProductos.txt", productos, stock, precios);
    lecturaDePedidos("docs/Pedidos.csv",fechasPedidos,
                    codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("docs/ReporteDePedidos.txt",fechasPedidos,
                             codigoPedidos,dniCantPedidos);
    
    return 0;
}