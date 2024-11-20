//Author: MAKO
#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia: public Libro {
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
private:
    int sku;
    int anho;
    int vigencia;
};

#endif /* ENCICLOPEDIA_H */

