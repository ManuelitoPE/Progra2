#include "header/funciones.h"


/*
 * 
 */
int main(int argc, char** argv) {

    void *productos, *clientes;
    
    cargaproductos(productos);
    imprimeproductos(productos);
    cargaclientes(clientes);
    imprimeclientes(clientes);
    cargapedidos(productos, clientes);
    imprimerepfinal(clientes);
    return 0;
}