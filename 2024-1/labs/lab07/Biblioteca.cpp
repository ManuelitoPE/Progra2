//Author: MAKO

#include "header/Biblioteca.h"

Biblioteca::Biblioteca(){
    cantidad_estantes_verticales = {};
    cantidad_estantes_horizontales = {};
    cantidad_total_enciclopedias = {};
    cantidad_total_novelas = {};
}
Biblioteca::Biblioteca(const Biblioteca& orig){
    *this = orig;
}
Biblioteca::~Biblioteca(){
}

void Biblioteca::setCantidad_estantes_verticales(const int cantidad){
    cantidad_estantes_verticales = cantidad;
}
void Biblioteca::setCantidad_estantes_horizontales(const int cantidad){
    cantidad_estantes_horizontales = cantidad;
}
void Biblioteca::setCantidad_total_enciclopedias(const int cantidad){
    cantidad_total_enciclopedias = cantidad;
}
void Biblioteca::setCantidad_total_novelas(const int cantidad){
    cantidad_total_novelas = cantidad;
}

int Biblioteca::getCantidad_estantes_verticales() const{
    return cantidad_estantes_verticales;
}
int Biblioteca::getCantidad_estantes_horizontales() const{
    return cantidad_estantes_horizontales;
}
int Biblioteca::getCantidad_total_enciclopedias() const{
    return cantidad_total_enciclopedias;
}
int Biblioteca::getCantidad_total_novelas() const{
    return cantidad_total_novelas;
}

void Biblioteca::cargar_libros(const char* nomArch){
    ifstream arch;
    aperturaArchLeer(nomArch,arch);
    //Datos
    char tipo;
    while (true){
        arch>>tipo;
        if(arch.eof())break;
        arch.ignore();
        if(tipo == 'N'){
            novelas[cantidad_total_novelas++].cargar(arch);
        }else enciclopedias[cantidad_total_enciclopedias++].cargar(arch);
        
    }
}
void Biblioteca::cargar_estantes(const char* nomArch){
    //Datos
    char tipo;
    ifstream arch;
    aperturaArchLeer(nomArch,arch);
    while (true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        if(tipo == 'H'){
            estantesHorizontales[cantidad_estantes_horizontales++].cargar(arch);
        }else estantesVerticales[cantidad_estantes_verticales++].cargar(arch);
    } 
}
void Biblioteca::posicionar_libros(){
    int posEstante = 0, posEstanteAux = 0;
    //Posicionar enciclopedias
    for (int i = 0; i < cantidad_total_enciclopedias; i++){
        posEstante = posEstanteAux = 0;
        while(true){
        //Primero me fijo por los primeros estantes
        if(estantesVerticales[posEstante].espacioSobrante(enciclopedias[i].getAncho(),enciclopedias[i].getAlto()) 
           and estantesVerticales[posEstante].getPesoActual()+ enciclopedias[i].getPeso() <= 
           estantesVerticales[posEstante].getPesoSoportado()){
            //Si el estante tiene espacio   
            //Se ingresa
            enciclopedias[i].setColocado(true);
            estantesVerticales[posEstante].actualizar(enciclopedias[i]);
            break;
        }else if(posEstante+1 < cantidad_estantes_verticales)posEstante++; //Si el estante ya no tiene espacio, paso al siguiente estante
        else{
            //Si ya no tengo mas estantes verticales
            //Ingreso en los estantes horizontales solo uno
            // if(estantesHorizontales[posEstanteAux].espacioSobrante(enciclopedias[i].getAncho(),enciclopedias[i].getAlto())
            //    and estantesHorizontales[posEstanteAux].getPesoActual()+ enciclopedias[i].getPeso() <= 
            //    estantesHorizontales[posEstanteAux].getPesoSoportado()){
            //     //Se ingresa 
            //     enciclopedias[i].setColocado(true);
            //     estantesHorizontales[posEstanteAux].actualizar(enciclopedias[i]);
            // }else if(posEstanteAux+1 < cantidad_estantes_horizontales)posEstanteAux++;
            // else{
                //No se colocaron estas enciclopedias
                enciclopedias[i].setColocado(false);
                break;
            // }
        }
        }
    }
    //Posicionar novelas
    for (int i = 0; i < cantidad_total_novelas; i++){
        posEstante = posEstanteAux = 0;
        while(true){
        //Primero me fijo por los primeros estantes
        if(estantesHorizontales[posEstante].espacioSobrante(novelas[i].getAncho(),novelas[i].getAlto())
           and estantesHorizontales[posEstante].getPesoActual()+ novelas[i].getPeso() <= 
           estantesHorizontales[posEstante].getPesoSoportado()){
            //Si el estante tiene espacio   
            novelas[i].setColocado(true);
            estantesHorizontales[posEstante].actualizar(novelas[i]);
            break;
        }else if(posEstante+1 < cantidad_estantes_horizontales)posEstante++; //Si el estante ya no tiene espacio, paso al siguiente estante
        else{
            //Si ya no tengo mas estantes horizontales
            //Ingreso en los estantes verticales solo uno
            // if(estantesVerticales[posEstanteAux].espacioSobrante(novelas[i].getAncho(),novelas[i].getAlto())
            //    and estantesVerticales[posEstanteAux].getPesoActual()+ novelas[i].getPeso() <= 
            //    estantesVerticales[posEstanteAux].getPesoSoportado()){
            //     //Se ingresa 
            //     novelas[i].setColocado(true);
            //     estantesVerticales[posEstanteAux].actualizar(novelas[i]);
            // }else if(posEstanteAux+1 < cantidad_estantes_verticales)posEstanteAux++;
            // else{
                //No se colocaron estas novelas
                novelas[i].setColocado(false);
                break;
            // }
        }
        }
    }

}
void Biblioteca::mostar_datos(const char* nomReport){
    ofstream report;
    aperturaArchEscr(nomReport,report);
    encabezado(report);
    report<<"Cantidad de Estantes: "<<cantidad_estantes_horizontales+
                                      cantidad_estantes_verticales<<endl;
    for (int i = 0; i < cantidad_estantes_verticales; i++){
        linea(report,MAX_LINEA,'-');
        estantesVerticales[i].imprimir(report);
    }
    for (int i = 0; i < cantidad_estantes_horizontales; i++){
        linea(report,MAX_LINEA,'-');   
        estantesHorizontales[i].imprimir(report);
    }
    report<<endl<<endl;
    linea(report,MAX_LINEA,'=');
    report<<endl<<right<<setw(40)<<"Informacion de todos los libros"<<endl;
    linea(report,MAX_LINEA,'-');
    report<<"Cantidad de Libros Total:"<<cantidad_total_enciclopedias+
                                         cantidad_total_novelas<<endl<<left;
    for (int i = 0; i < cantidad_total_enciclopedias; i++)
        enciclopedias[i].imprimir(report);
    for (int i = 0; i < cantidad_total_novelas; i++)
        novelas[i].imprimir(report);    
}