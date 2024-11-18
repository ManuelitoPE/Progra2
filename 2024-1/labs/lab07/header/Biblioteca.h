//Author: MAKO

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "EstanteHorizontal.h"
#include "EstanteVertical.h"

class Biblioteca{
private:
    EstanteVertical estantesVerticales[10];
    int cantidad_estantes_verticales;
    EstanteHorizontal estantesHorizontales[10];
    int cantidad_estantes_horizontales;
    Enciclopedia enciclopedias[10];
    int cantidad_total_enciclopedias;
    Novela novelas[10];
    int cantidad_total_novelas;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    ~Biblioteca();

    void setCantidad_estantes_verticales(const int cantidad);
    void setCantidad_estantes_horizontales(const int cantidad);
    void setCantidad_total_enciclopedias(const int cantidad);
    void setCantidad_total_novelas(const int cantidad);

    int getCantidad_estantes_verticales() const;
    int getCantidad_estantes_horizontales() const;
    int getCantidad_total_enciclopedias() const;
    int getCantidad_total_novelas() const;

    void cargar_libros(const char* nomArch);
    void cargar_estantes(const char* nomArch);
    void posicionar_libros();
    void mostar_datos(const char* nomReport);

};


#endif