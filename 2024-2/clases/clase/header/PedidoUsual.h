#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include "Pedido.h"

class PedidoUsual:public Pedido{
private:
    double descuento;
    double flete;

public:
    void setDescuento(double descuento);
    double getDescuento() const;
    
    void setFlete(double Flete);
    double getFlete() const;
};

#endif