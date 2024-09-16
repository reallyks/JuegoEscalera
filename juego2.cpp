#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

void juego2(){
 int i,puntajeTotalJ1=0,puntajeTotalJ2=0,win = 0,numRonda=0,resultado,contadorWhile=0;
 int tiradaEntera[6];
 int lanzamiento;

 srand(time(NULL));

  string jugador1 , jugador2;
  encuadroNames();
  rlutil::locate(43,10);
  cout<<"Ingrese nombre del jugador 1"<<endl;
  rlutil::locate(54,11);
  cin>>jugador1;
  jugador1 = validarNombre(jugador1);
  rlutil::cls();
  encuadroNames();
  rlutil::locate(43,10);
  cout<<"Ingrese nombre del jugador 2"<<endl;
  rlutil::locate(54,11);
  cin>>jugador2;
  jugador2 = validarNombre(jugador2);
  rlutil::cls();


  while(puntajeTotalJ1 < 500 && puntajeTotalJ2 < 500){
     contadorWhile = contadorWhile + 1;
     int maxPuntajeRonda = 0;

        rlutil::cls();
        rlutil::setColor(rlutil::BLACK);
        estructuraCambioRonda();
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(56,12);
        cout << "Ronda N:" << char(248) << contadorWhile << endl;
        rlutil::locate(52,13);
        cout << "Proximo Turno de " << jugador1 << endl;
        rlutil::locate(52,15);
        cout << "Puntaje: " << jugador1 << ": " << puntajeTotalJ1 << endl;
        rlutil::locate(52,16);
        cout << "Puntaje: " << jugador2 << ": " << puntajeTotalJ2 << endl;
        rlutil::msleep(4000);
        rlutil::cls();

    for (lanzamiento=1;lanzamiento<4;lanzamiento++){                                                                                    // -----> jugador 1
        rlutil::cls();

       for (int d=0;d<6;d++){
            int valor=((rand()%6)+1);         // ---> del tiempo interno de la pc busca su resto de 6 para que quede un rango de 0-5
            tiradaEntera[d] = valor;
        }

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


  rlutil::cls();
  rlutil::setColor(rlutil::BLACK);
  estructuraCambioRonda();
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(56,12);
  cout << "Ronda N:  "  << char(248) << contadorWhile << endl;
  rlutil::locate(52,13);
  cout << "Proximo Turno de " << jugador2 << endl;
  rlutil::locate(52,15);
  cout << "Puntaje: " << jugador1 << ": " << puntajeTotalJ1 << endl;
  rlutil::locate(52,16);
  cout << "Puntaje: " << jugador2 << ": " << puntajeTotalJ2 << endl;
  rlutil::msleep(4000);
  rlutil::cls();


    for (lanzamiento=1;lanzamiento<4;lanzamiento++){                                                                                      // ----> jugador 2
        rlutil::cls();

       for (int d=0;d<6;d++){
            int valor=((rand()%6)+1);         // ---> del tiempo interno de la pc busca su resto de 6 para que quede un rango de 0-5
            tiradaEntera[d] = valor;
        }

        estructura();
        rlutil::locate(22,6);
        cout << "TURNO DE " << jugador2 << endl;
        rlutil::locate(55,6);
        cout << "  RONDA N: " << contadorWhile << endl;
        rlutil::locate(82,6);
        cout << "PUNTAJE TOTAL: " << puntajeTotalJ2 << " PUNTOS " << endl;
        rlutil::locate(22,10);
        cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << endl;
        rlutil::locate(22,12);
        cout << "LANZAMIENTO N: " << lanzamiento << endl;

        animacionDados();
        rlutil::anykey();
        mostrarDados(tiradaEntera);

        resultado = validar(tiradaEntera);                              //----> resultado retornado de la ronda

        puntajeTotalJ2 = puntajeTotalJ2 + resultado;
        maxPuntajeRonda = mostrarRondaMasAlta(resultado,maxPuntajeRonda);


        if(resultado == 1){
            rlutil::locate(36,26);
            cout << " ESCALERA   GANASTE   LA   PARTIDA !";
            puntajeTotalJ2 = 500;
            rlutil::anykey();
            break;
        }

        rlutil::locate(82,6);
        cout << "PUNTAJE TOTAL: " << puntajeTotalJ2 << " PUNTOS " << endl;

        rlutil::locate(36,17);
        rlutil::anykey("Presiona cualquier tecla para continuar...   ");
    }
 }
rlutil::cls();
 if(puntajeTotalJ1 > 500 && puntajeTotalJ2 > 500){
        estructuraCambioRonda();
        rlutil::locate(46,15);
        cout << "TREMENDO! HICIERON EMPATE GENTES";
        rlutil::locate(42,19);
        rlutil::anykey("PRESIONE UNA TECLA PARA JUGAR DE NUEVO");
        rlutil::cls();
 }

 else if(puntajeTotalJ1 > puntajeTotalJ2){
        estructuraCambioRonda();
        rlutil::locate(46,15);
        cout << "FELICIDADES " << jugador1 << " GANASTE !!";
        rlutil::locate(42,19);
        rlutil::anykey("PRESIONE UNA TECLA PARA JUGAR DE NUEVO");
        rlutil::cls();

 actualizarJugadorMaximo(puntajeTotalJ1,jugador1);
 }

 else if(puntajeTotalJ2 > puntajeTotalJ1){
        estructuraCambioRonda();
        rlutil::locate(46,15);
        cout << "FELICIDADES " << jugador2 << " GANASTE !!";
        rlutil::locate(42,19);
        rlutil::anykey("PRESIONE UNA TECLA PARA JUGAR DE NUEVO");
        rlutil::cls();

 actualizarJugadorMaximo(puntajeTotalJ2,jugador2);
 }

 menu();
}
