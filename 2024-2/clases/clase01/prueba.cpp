#include <iostream>
#include <iomanip>
using namespace std;
void encaebzado(char a ='a'); //encabezado
void porValor(int *&x){
    *x = 87;
    x = new int;
    *x =101;
}
int main(){
    int *p; char hola;
    p =  new int;
    *p = 33;
    porValor(p);
    encaebzado(hola); //Invocacion
    cout<<*p; //Recordar es para deferenciar
    // Parametros con valores por defecto
    // Para crear funciones con valors por defecto , solo es necesario especificarlo 
    // en el encabezado 
    return 0;
}
void encaebzado(char a){
    //implementacion
}
// La sobrecarga es una propiedad del lenguaje c++, que permite definir dos o mas funciones con el mismo nombre
// Los parametros deben ser diferentes, ya sea en numero o en tipo de dato
// Sobrecarga de operadores
// Plantillas de funciones
  //Es una herramienta del c++ que permite implementa una funcion y que ala hora de complarla els istema genere varias versiones
  // de esta funcion, sobrecargandolas automaticamente de modo quese adapten a los diferentes tipos de datos que se coloquen como 
  //parametros en la fucnion
  //para realizar esta labor, la planti;;a requiere implementa un tupo de datos generico. Este tipo de dato sera el que 
    //cambiara en cada implementascion " template <typename TIPO> "
    //El compilador revisara el modulo donde se use la plantilla y su por ejemplo en algun punto la funcion se invoca con enteros
    //y en otra con valores reales generara dos implementaciones.

//Bibliotecas estaticas de funciones
    //Una biblioteca es una agrupacion de datos, tipos de datos y funcionalidades
    //organizados de oforma que sean reutilizables en mas de un proyecto
//Existen dos tipos de bibliotecas
    //Estaticaas, archivos con extensiones ".a" o ".lib", aunque tambien se pueden considerar los archivos con extension ".o"
    //Dinamicas, con extension ".dll" (dynamic linked libraries)
//Las bibliotecas estaticas son ensambladas y enlazadas junto con el programa que las usa, y por tanto forman parte arch
// ejecutable que se crea.
//Las bibliotecas dinamicas, se ensamblan por separado y el enlace ocurre durante la ejecucion del programa que utliza la 
//biblioteca
//No todos los lenguajes de programaxion permiten la creacion y el uso de ambos tipos de bibliotecas. El lenguaje c++ permite
//crear y usar ambos tipos, mientras que JAVA y C# solo trabajan con bibliotecas dinamicas.
//Los arch con extension ".a" o ".lib" son parecidos a los archivos ".o", con una diferencia que cuadno se enlazan
//un archivo ".o " en un proyecto, se anaden a este ultimo todas las funciones que se escribieron, esto se debe en parte
// a que en el arch ".o" solo se guarda el codigo compilado de todas las funciones.

// Los arch ".a" guardan, ademas el codigo, el nombre de cada funciones, esto hace que en el momento de enlazarlas, solo
// se anaden al programa ejecutable aquellas funciones que realmentre se utilizan en el programa, descatajdose las demas
