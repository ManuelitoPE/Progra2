//Author: MAKO
#include "header/Restaurante.h" 

Restaurante::Restaurante(){
    clientes = {};
    cantidadDeClientes = {};
    capacidadDeClientes = {};
    platos = {};
    cantidadDePlatos = {};
    capacidadDePlatos = {};
}

Restaurante::~Restaurante(){
    delete[] clientes;
    delete[] platos;
}

void Restaurante::operator <(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    Cliente cliente{};
    while(arch>>cliente){
        incrementarCliente();
        clientes[cantidadDeClientes++] = cliente;
    }
}
void Restaurante::operator <=(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    Plato plato{};
    while(arch>>plato){
        incrementarPlato();
        platos[cantidadDePlatos++] = plato;
    }
}
void Restaurante::incrementarPlato(){
    capacidadDePlatos++;
    if(platos == nullptr){
        platos = new Plato[capacidadDePlatos]{};
    }else{
        Plato* aux = new Plato[capacidadDePlatos]{};
        for (int i = 0; i < cantidadDePlatos; i++)
            aux[i] = platos[i]; 
        delete[] platos;
        platos = aux;    
    }
}
void Restaurante::incrementarCliente(){
    capacidadDeClientes++;
    if(clientes == nullptr){
        clientes =  new Cliente[capacidadDeClientes]{};
    }else{
        Cliente* aux = new Cliente[capacidadDeClientes]{};
        for (int i = 0; i < cantidadDeClientes; i++)
            aux[i] = clientes[i];
        delete[] clientes;
        clientes = aux;
    }
}
void Restaurante::operator <<=(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    //Datos
    int num,dni,llavePlato,llaveCLiente,cant;
    char *codigo;
    while(true){
        arch>>num;
        if(arch.eof())break;
        arch.ignore();  arch>>dni;
        llaveCLiente = buscar(dni);
        if(llaveCLiente!= NO_ENCONTRADO){
            clientes[llaveCLiente].actualizar(arch);
            while(arch.get()!='\n'){
                codigo = lecturaExacta(arch,',');
                arch>>cant;
                llavePlato = buscar(codigo);
                if(llavePlato != NO_ENCONTRADO){
                    platos[llavePlato].actualizar();
                }
            }
        }
    }
}
int Restaurante::buscar(int dni){
    for (int i = 0; i < cantidadDeClientes; i++){
        if(clientes[i].getDni() == dni)return i;
    }
    return NO_ENCONTRADO;
}
int Restaurante::buscar(const char* codigo){
    char buffer[500];
    for (int i = 0; i < cantidadDePlatos; i++){
        platos[i].getCodigo(buffer);
        if(strcmp(codigo,buffer)==0)return i;
    }
    return NO_ENCONTRADO;
}
void Restaurante::mostrar(){
    char buffer[500];
    for (int i = 0; i < cantidadDePlatos; i++){
        platos[i].getCodigo(buffer);
        cout<<i+1<<" "<<buffer<<endl;
    }
    cout<<cantidadDePlatos<<endl;
}
