//Author: mako

#include "header/EstanteVertical.h"

EstanteVertical::EstanteVertical(){
    cantidad_enciclopedia = {};
}
EstanteVertical::EstanteVertical(const EstanteVertical& orig): Estante(orig){
    *this =  orig;
}
EstanteVertical::~EstanteVertical(){
}

void EstanteVertical::setCantidad(const int cantidad){
    this->cantidad_enciclopedia = cantidad;
}
int EstanteVertical::getCantidad() const{
    return cantidad_enciclopedia;
}
bool EstanteVertical::espacioSobrante(int anchuraLibro,int alturaLibro){
    if(anchuraLibro <= this->getAnchura() and alturaLibro <= this->getAltura()){
        if(Estante::espacioSobrante('V',anchuraLibro))return true;
    }
    return false;
}
void EstanteVertical::actualizar(const Enciclopedia& enciclopedia){
    enciclopedias[cantidad_enciclopedia++] = enciclopedia;
    this->setPesoActual(enciclopedia.getPeso()+this->getPesoActual());
    Estante::pintar('V',enciclopedia.getAncho(),enciclopedia.getAlto());

}
void EstanteVertical::actualizar(const Novela& novela){
    this->setPesoActual(novela.getPeso()+this->getPesoActual());
    Estante::pintar('V',novela.getAncho(),novela.getAlto());
}

void EstanteVertical::imprimir(ofstream& report){
    Estante::imprimir(report,cantidad_enciclopedia,'V');
    encabezado2(report);
    for (int i = 0; i < cantidad_enciclopedia; i++){
        enciclopedias[i].imprimir(report);
    }
    
}