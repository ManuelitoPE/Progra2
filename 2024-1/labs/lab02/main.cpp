//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/funciones.h"

int main(){
    //Datos
    char*** libros, ***pedidosLibros;
    int** stock,**pedidosClientes;
    bool** pedidosAtendidos;

    lecturaDeLibros("docs/Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("docs/ReporteDeLibrosInicial.txt",libros,
                            stock);
    atencionDePedidos("docs/Pedidos.txt",libros,stock,pedidosClientes,
                        pedidosLibros,pedidosAtendidos);
    pruebaDeLecturaDeLibros("docs/ReporteDeLibrosFinal.txt",libros,stock,pedidosClientes,
                        pedidosLibros,pedidosAtendidos);
    reporteDeEntregaDePedidos("docs/ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,
                                pedidosAtendidos);
    return 0;
}