#include "header/funciones.h"

void crearLista(void*& platosLista,bool (*leenum)(ifstream& arch,void*& plato),const char* nomPlatos,
                int (*cmp)(const void* a,const void* b)){
    ifstream arch(nomPlatos,ios::in);
    if(!arch.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR "<<nomPlatos<<endl;
        exit(1);
    }
    //Datos
    platosLista = new void*[3]{};
    int *cantDatos =new int{};
    void** infoPlatos = (void**)platosLista;
    infoPlatos[PLATOS::CANT] = cantDatos;
    void* plato;
    while(leenum(arch,plato)){
        insertar(platosLista,plato,cmp);
    }
    void** infoLista = (void**)platosLista;
    void** infoPlato = (void**)infoLista[PLATOS::INICIO];
    while(infoPlato){
        void** info = (void**)infoPlato[PLATO::DATA];
        cout<<(char*)info[INFOPLATO::NAME]<<endl;
        infoPlato = (void**)infoPlato[PLATO::SGT];        
    }
    // cout<<*(int*)infoLista[PLATOS::CANT]<<endl;
    // void** infoPlato = (void**)infoLista[PLATOS::INICIO];
    // cout<<*(int*)infoPlato[PLATO::DATA]<<endl;
    infoPlato = (void**)infoLista[PLATOS::FINAL];
    void** info = (void**)infoPlato[PLATO::DATA];
    cout<<(char*)info[INFOPLATO::NAME]<<endl;
}
bool leenum(ifstream& arch, void*& plato){
    //Datos
    plato = new void*[2]{};
    void** Plato = (void**)plato;
    void** infoPlato = new void*[5];
    int *code = new int;
    int *cantidad = new int;
    double *precio = new double;
    char *nombre,*tipo,c;
    arch>>*code>>c;
    if(arch.eof())return false;
    nombre = lecturaExacta(arch,',');
    if(nombre == nullptr)return false;
    arch>>*(precio)>>c;
    tipo = lecturaExacta(arch,',');
    arch>>*(cantidad); arch.ignore();
    infoPlato[INFOPLATO::CODE] = code;
    infoPlato[INFOPLATO::NAME] = nombre;
    infoPlato[INFOPLATO::PRECIO] = precio;
    infoPlato[INFOPLATO::TIPO] = tipo;
    infoPlato[INFOPLATO::CANTIDAD] = cantidad;
    Plato[PLATO::DATA] = infoPlato;
    return true;
}
char* lecturaExacta(ifstream& arch,char delimitador){
    char buffer[200], *ptr;
    arch.getline(buffer,200,delimitador);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}

void insertar(void*& platosLista,void* plato,
             int (*cmp)(const void*,const void*)){
    void** infoLista = (void**)platosLista;
    void** infoPlato = (void**)plato;
    // Si es la primera vez
    if(infoLista[PLATOS::INICIO]==nullptr){
        //El primer elemento
        infoLista[PLATOS::INICIO] = plato;
        infoLista[PLATOS::FINAL] = plato;
        (*(int*)infoLista[PLATOS::CANT])++;
    }else{
        void** ptr = (void**)infoLista[PLATOS::INICIO];
        void** anterior = nullptr;
        while(ptr){
            if(cmp(ptr[PLATO::DATA],infoPlato[PLATO::DATA])>0)break;
            anterior = ptr;
            ptr = (void**)ptr[PLATO::SGT];
        }
        infoPlato[PLATO::SGT] = ptr;
        if(anterior != nullptr){
            if(anterior[PLATO::SGT]==nullptr){
                infoLista[PLATOS::FINAL] = plato;   
            }
            anterior[PLATO::SGT] = plato;   
        }
        else infoLista[PLATOS::INICIO] = plato; 
        (*(int*)infoLista[PLATOS::CANT])++;
    }
}
int cmpPlatos(const void* a, const void*b){
    //ptr[PLATO::DATA]
    void** infoPlatoA = (void**)a;
    void** infoPlatoB = (void**)b;
    return *(double*)infoPlatoB[INFOPLATO::PRECIO]
            - *(double*)infoPlatoA[INFOPLATO::PRECIO];
}