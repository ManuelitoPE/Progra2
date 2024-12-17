#include <iostream>
#include <string>

using namespace std;

int main() {
    string texto = "holammmm 1_23_45_ASDF mundo 2 triste 3";
    string palabra;

    size_t pos = 0; // Posición inicial
    while ((pos = texto.find_first_not_of(' ', pos)) != string::npos) { // Ignorar espacios iniciales
        size_t espacio = texto.find(' ', pos); // Buscar el próximo espacio
        palabra = texto.substr(pos, espacio - pos); // Extraer la palabra
        cout << palabra << endl;

        if (espacio == string::npos) break; // Si no hay más espacios, salir
        pos = espacio + 1; // Mover la posición al siguiente carácter
    }

    return 0;
}