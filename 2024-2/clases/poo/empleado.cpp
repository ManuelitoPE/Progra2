#include "empleado.h"

void Empleado::cargarEmpleado(const char* nomArch, Empleado*& empleados, int& num){
    Empleado buffer[1000];
    ifstream arch(nomArch,ios::in);
    num = 0;
    while(arch>>buffer[num])num++;
}
void Empleado::cargarEmpleado(const char* nomArch, Empleado*& empleados){

}