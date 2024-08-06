//Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/funciones.h"

int main(){
    //Variables
    void *productos, *clientes;
    //Procesos
    cargarProductos(productos);
    cargarClientes(clientes);
    cargaPedidos(productos,clientes);
    // imprimirReporte(clientes);
    return 0;
}
