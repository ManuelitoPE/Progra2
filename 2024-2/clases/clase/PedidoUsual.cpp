#include "header/PedidoUsual.h"

void PedidoUsual::setDescuento(double descuento){
    this->descuento = descuento;
}
double PedidoUsual::getDescuento() const{
    return this->descuento;
}
    
void PedidoUsual::setFlete(double Flete){
    this->flete = flete;
}
double PedidoUsual::getFlete() const{
    return this->flete;
}