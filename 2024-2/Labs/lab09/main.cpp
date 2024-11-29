//Author: MAKO
#include "header/Universidad.h"

int main(){
    Universidad universidad;
    // Listo
    universidad.cargarAlumnos();
    universidad.imprimirAlumnos();
    // Listo
    universidad.cargarCursos();
    universidad.imprimirCursos();

    universidad.matricular();
    universidad.imprimirMatricula();

}