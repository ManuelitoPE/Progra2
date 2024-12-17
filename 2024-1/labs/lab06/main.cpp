// Author: MAKO
#include <iostream>
#include <iomanip>
using namespace std;
#include "header/rectangulo.h"

int main(){
    Rectangulo rec;
    rec.setBase(10);
    rec.setAltura(10);
    double area = rec.calcularArea();
    cout<<area;
    return 0;
}