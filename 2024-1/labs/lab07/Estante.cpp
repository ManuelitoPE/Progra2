//Auhtor::MAKO

#include "header/Estante.h"

Estante::Estante(){
    codigo = {};
    anchura = {};
    altura = {};
    espacios = {};
    pesoSoportado = {};
    pesoActual = {};
}
Estante::Estante(const Estante& orig){
    *this = orig;
}
Estante::~Estante(){
    delete[] codigo;
    delete[] espacios;
}

void Estante::setCodigo(const char* codigo){
    if(this->codigo != nullptr)delete[] this->codigo;
    this->codigo = new char[strlen(codigo)+1]{};
    strcpy(this->codigo,codigo);
}
void Estante::setAnchura(const int anchura){
    this->anchura = anchura;
}
void Estante::setAltura(const int altura){
    this->altura = altura;
}
void Estante::setPesoSoportado(const double pesoSoportado){
    this->pesoSoportado = pesoSoportado;
}
void Estante::setPesoActual(const double pesoActual){
    this->pesoActual = pesoActual;
}
void Estante::setEspacios(const int cant){
    if(espacios != nullptr) delete[] espacios;
    espacios = new Espacio[cant]{};
}    
void Estante::getCodigo(char* codigo) const{
    if(codigo != nullptr)
        strcpy(codigo,this->codigo);
}
int Estante::getAnchura() const{
    return anchura;
}
int Estante::getAltura() const{
    return altura;
}
double Estante::getPesoSoportado() const{
    return pesoSoportado; 
}
double Estante::getPesoActual() const{
    return pesoActual;
}
void Estante::cargar(ifstream& arch){
    //Datos
    char *codigo,c;
    int altura, anchura,pesoMax;
    arch.get();
    codigo = lecturaExacta(arch,',');
    arch>>anchura>>c>>altura>>c>>pesoMax;
    arch.get();
    setCodigo(codigo);
    setAltura(altura);
    setAnchura(anchura);
    setPesoSoportado(pesoMax);
    setEspacios(altura*anchura);
}
bool Estante::espacioSobrante(char tipo,int num){
    int pintado = 0;
    if(tipo == 'V'){
        for (int i = 1; i <= altura; i++){
            if(espacios[(i*anchura)-1].getContenido()=='*')
                pintado++;
        }
        if(altura-pintado>=num)return true;
    }else{
        for (int i = 0; i < anchura; i++){
            if(espacios[i+(altura-1)*anchura].getContenido()=='*')
                pintado++;
        }
        if(anchura-pintado>=num)return true;
    }
    return false;
}

void Estante::pintar(char c,int anchuraLibro,int alturaLibro){
    int pos,aux;
    if(c == 'V'){
        aux = anchuraLibro;
        for (int i = altura; i > 0; i--){
            pos = (i*anchura)-1;
            if(espacios[pos].getContenido()==' '){
                if(aux>0){
                    for (int j = 0;j<alturaLibro ; j++){
                        espacios[pos - j].setContenido('*');
                    }
                    aux--;
                }else break;
            }
        } 
    }else{
        for (int i = 0; i < anchura; i++){
            pos = i+(altura-1)*anchura;
            if(espacios[pos].getContenido()==' '){
                if(anchuraLibro>0){
                    for (int j = 0; j < alturaLibro; j++){
                        espacios[pos - j*anchura].setContenido('*');
                    }
                    anchuraLibro--;
                }else break;
            }
        }
    }
}
void Estante::imprimir(ofstream& report,int n,char tipo){
    char buffer[10];
    char aux[11] = "Horizontal";
    if(tipo=='V')strcpy(aux,"Vertical");
    this->getCodigo(buffer);
    report<<left<<setw(17)<<"Codigo Estante:"<<setw(10)<<buffer
          <<setw(17)<<"Cantidad de Libros:"<<right<<setw(5)<<n<<left<<endl
          <<setw(17)<<"Altura X Anchura: "<<this->getAltura()<<" x "<<setw(5)<<this->getAnchura()
          <<setw(23)<<"Peso Maximo: "<<setw(5)<<this->getPesoSoportado()<<endl
          <<setw(6)<<"Tipo:"<<setw(21)<<aux<<"Peso Total: "<<right<<setw(15)<<this->getPesoActual()  
          <<endl;
    linea(report,MAX_LINEA,'-');
    for (int i = 0; i < altura; i++){
        for (int j = 0; j < anchura; j++){
            char c = espacios[anchura*i + j].getContenido();
            report<<'['<<c<<"] ";
        }
        report<<endl;
    }
    
}
