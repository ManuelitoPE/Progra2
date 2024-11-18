//AUTHOR: MAKO

#include "header/Biblioteca.h"

int main(){
    Biblioteca biblioteca;

    biblioteca.cargar_libros("docs/libros2.csv");
    biblioteca.cargar_estantes("docs/estantes2.csv");
    biblioteca.posicionar_libros();
    biblioteca.mostar_datos("docs/Reporte.txt");
    return 0;
}