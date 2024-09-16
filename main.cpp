#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

int puntuacionMaxima = 0;
string nombreDelMaximo = "";

int actualizarJugadorMaximo(int puntuacion,string nombre) {
    if (puntuacion > puntuacionMaxima) {
        puntuacionMaxima = puntuacion;
        nombreDelMaximo = nombre;
    }
}


int main(){

    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::cls();
    menu();
    return 0;
}
