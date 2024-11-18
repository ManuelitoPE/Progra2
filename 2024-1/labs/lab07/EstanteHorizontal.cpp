//Auhtor: MAKO

#include "header/EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal(){
    cantidad_novelas = {};   
}
EstanteHorizontal::EstanteHorizontal(const EstanteHorizontal& orig) : Estante(orig){
    *this = orig;
}
EstanteHorizontal::~EstanteHorizontal(){
}

void EstanteHorizontal::setCantidad(const int cantidad){
    cantidad_novelas = cantidad;
}
int EstanteHorizontal::getCantidad() const{
    return cantidad_novelas;
}
bool EstanteHorizontal::espacioSobrante(int anchuraLibro,int alturaLibro){
    if(anchuraLibro <= this->getAnchura() and alturaLibro <= this->getAltura()){
        if(Estante::espacioSobrante('H',anchuraLibro))return true;
    }
    return false;
}
void EstanteHorizontal::actualizar(const Enciclopedia& enciclopedia){
    this->setPesoActual(enciclopedia.getPeso()+this->getPesoActual());
    Estante::pintar('H',enciclopedia.getAncho(),enciclopedia.getAlto());
}
void EstanteHorizontal::actualizar(const Novela& novela){
    novelas[cantidad_novelas++] = novela;
    this->setPesoActual(novela.getPeso()+this->getPesoActual());
    Estante::pintar('H',novela.getAncho(),novela.getAlto());
}

void EstanteHorizontal::imprimir(ofstream& report){
    Estante::imprimir(report,cantidad_novelas,'H');
    encabezado2(report);
    for(int i = 0;i<cantidad_novelas;i++){
        novelas[i].imprimir(report);
    }
}
