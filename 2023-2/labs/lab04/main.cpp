//Author: MAKO
#include "header/funciones.h"

int main(){
    //Datos
    void* productos, *clientes;
    //Funciones main
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
    return 0;
}   
