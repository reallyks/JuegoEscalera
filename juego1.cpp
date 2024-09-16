#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"


void juego1(){
 int puntajeTotalJ1=0,contadorWhile=0,resultado;
 int tiradaEntera[6];
 int lanzamiento;
 string jugador1;

 srand(time(NULL));     // toma el tiempo interno de la pc

  encuadroNames();
  rlutil::locate(43,10);
  cout<<"Ingrese nombre del jugador 1 "<<endl;
  rlutil::locate(54,11);
  cin >> jugador1;
  jugador1 = validarNombre(jugador1);
  rlutil::cls();

 while(puntajeTotalJ1 < 100 ){
     contadorWhile = contadorWhile + 1;
     int maxPuntajeRonda = 0;

     rlutil::cls();
     estructuraCambioRonda();
     rlutil::locate(54,10);
     cout << " Ronda N" << (char)248 << " " <<  contadorWhile << endl;
     rlutil::locate(57,13);
     cout << jugador1 << endl;
     rlutil::locate(55,15);
     cout << "PUNTAJE " << puntajeTotalJ1 << endl;
     rlutil::msleep(3000);

    for (lanzamiento=1;lanzamiento<4;lanzamiento++){
        rlutil::cls();

  //     for (int d=0;d<6;d++){
  //          int valor=((rand()%6)+1);         // ---> del tiempo interno de la pc busca su resto de 6 para que quede un rango de 0-5
  //          tiradaEntera[d] = valor;
  //      }

    tiradaEntera[0] = 1;
    tiradaEntera[1] = 3;
    tiradaEntera[2] = 4;
    tiradaEntera[3] = 5;                                  // ===> para probar combinacion, comentar la tirada
    tiradaEntera[4] = 6;
    tiradaEntera[5] = 2;

        estructura();
        rlutil::locate(22,6);
        cout << "TURNO DE " << jugador1 << endl;
        rlutil::locate(55,6);
        cout << "  RONDA N: " << contadorWhile << endl;
        rlutil::locate(82,6);
        cout << "PUNTAJE TOTAL: " << puntajeTotalJ1 << " PUNTOS " << endl;
        rlutil::locate(22,10);
        cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << endl;
        rlutil::locate(22,12);
        cout << "LANZAMIENTO N: " << lanzamiento << endl;

        animacionDados();
        rlutil::anykey();
        mostrarDados(tiradaEntera);


        resultado = validar(tiradaEntera);                              //----> resultado retornado de la ronda
        puntajeTotalJ1 = puntajeTotalJ1 + resultado;
        maxPuntajeRonda = mostrarRondaMasAlta(resultado,maxPuntajeRonda);

        if(puntajeTotalJ1 >= 500){
            rlutil::msleep(3000);
            break;
        }

        if(resultado == 1){
            rlutil::locate(36,26);
            cout << " ESCALERA   GANASTE   LA   PARTIDA !";
            puntajeTotalJ1 = 500;
            rlutil::anykey();
            break;
        }

        rlutil::locate(82,6);
        cout << "PUNTAJE TOTAL: " << puntajeTotalJ1 << " PUNTOS " << endl;

        rlutil::locate(36,17);
        rlutil::anykey("Presiona cualquier tecla para continuar...   ");
    }
 }

 rlutil::cls();
 estructuraCambioRonda();

 actualizarJugadorMaximo(puntajeTotalJ1,jugador1);

 rlutil::locate(46,15);
 cout << "FELICIDADES " << jugador1 << " GANASTE !!";
 rlutil::locate(42,19);
 rlutil::anykey("PRESIONE UNA TECLA PARA JUGAR DE NUEVO");
 menu();
}
