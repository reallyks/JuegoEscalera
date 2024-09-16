#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

void leaderboard(int puntuacionMaxima,string nombre){
    rlutil::hidecursor();
    rlutil::setColor(rlutil::YELLOW);
  for(int y=0;y<5; y++){
    rlutil::locate(40 ,9 + y);
    cout<<(char)219;
    rlutil::locate(73 ,9 + y);
    cout<<(char)219;
  }
  for(int x=0;x<32; x++){
    rlutil::locate(41 + x,9);
    cout<<(char)223;
    rlutil::locate(41 + x,13);
    cout<<(char)220;
  }
  rlutil::setColor(rlutil::BLACK);
  for(int f=0;f<54;f++){
    rlutil::locate(31 +f,18);
    cout<<(char)223;
  }
  rlutil::setColor(rlutil::WHITE);
  rlutil::locate(55 ,11);
  cout<< nombre << endl;
  rlutil::locate(55 ,12);
  cout<< puntuacionMaxima << endl;
  rlutil::locate(31 ,17);
  cout<< "Presione cualquier tecla para volver al menu principal"<< endl;
  rlutil::setColor(rlutil::BLACK);
  rlutil::anykey();
  menu();
}

void estructuraCambioRonda(){
        for(int i=0; i<61;i++){
        rlutil::locate(30+i,8);
        cout << (char) 223;                                      // ======> MARCOs HORIZONTALES
        rlutil::locate(30+i,22);
        cout << (char) 223;
    }

    for(int i=0;i<14;i++){
        rlutil::locate(30,8+i);
        cout << (char) 219;                                      // ======> MARCOs VERTICALES
        rlutil::locate(90,8+i);
        cout << (char) 219;
    }
};

void estructura(){
  char a[8];
  a[0] = 219;
  a[1] = 223;
  a[2] = 220;
  a[3] = 32;
  a[4] = 205;
  a[5] = 202;
  a[6] = 186;
  a[7] = 203;

    for(int i=0; i<100;i++){
        rlutil::locate(10+i,4);
        cout << a[1];                                      // ======> MARCOs HORIZONTALES
        rlutil::locate(10+i,28);
        cout << a[2];
    }

    for(int i=0;i<25;i++){
        rlutil::locate(10,4+i);
        cout << a[0];                                      // ======> MARCOs VERTICALES
        rlutil::locate(110,4+i);
        cout << a[0];
    }

    for(int i=0;i<99;i++){
        rlutil::locate(11+i,8);
        cout << a[4];                                      // ======> HORIZONTALES INTERNOS
        rlutil::locate(11+i,14);
        cout << a[4];
    }


    for(int i=0;i<3;i++){
        rlutil::locate(47,7-i);
        cout << a[6];
        rlutil::locate(75,7-i);
        cout << a[6];
    }
    rlutil::locate(47,8);
    cout << a[5];
    rlutil::locate(75,8);
    cout << a[5];

    rlutil::locate(47,4);
    cout << a[0];
    rlutil::locate(75,4);
    cout << a[0];

};

void encuadroMenu(){

    for(int z=0;z<40;z++){
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(40 + z,7);
    cout<<(char)223;
    rlutil::locate(40 + z,10);
    cout<<(char)223;
    rlutil::locate(40 + z,13);
    cout<<(char)223;
    rlutil::locate(40 + z,16);
    cout<<(char)223;
    rlutil::locate(40 + z,19);
    cout<<(char)223;
    rlutil::locate(40 + z,22);
    cout<<(char)223;
}
    for(int l=0;l<15;l++){
    rlutil::locate(40 ,7 + l);
    cout<<(char)219;
    rlutil::locate(79 ,7 + l);
    cout<<(char)219;
    }
    rlutil::setColor(rlutil::WHITE);
}

void encuadroNames(){

rlutil::setColor(rlutil::BLACK);
  for(int y=0;y<5; y++){
    rlutil::locate(40 ,9 + y);
    cout<<(char)219;
    rlutil::locate(73 ,9 + y);
    cout<<(char)219;
  }
  for(int x=0;x<32; x++){
    rlutil::locate(41 + x,9);
    cout<<(char)223;
    rlutil::locate(41 + x,13);
    cout<<(char)220;
  }
  rlutil::setColor(rlutil::WHITE);
}

string validarNombre(string nombre){
    while(nombre.length() > 8){
        rlutil::locate(42,11);
        cout << "Nombre muy extenso, elige otro" << endl;
        rlutil::locate(41,12);
        cout << "                                ";
        rlutil::locate(50,12);
        cin >> nombre;
    }

    for(int i = 0; i < nombre.length(); i++){
        if((int) nombre[i] > 96 && (int) nombre[i] < 126){
             nombre[i] = (int) nombre[i] - 32;
        }
    }
    return nombre;
};

void |menu() {
rlutil::cls();
  int puntajeGanador = 0;
  int op = 1, y = 0;
  rlutil::hidecursor();
  do {
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(45, 8);
    cout << "JUEGO DE QUINIENTOS O ESCALERA\n" << endl;
    rlutil::locate(54, 11);
    cout << "1 JUGADOR\n";
    rlutil::locate(53, 14);
    cout << "2 JUGADORES\n";
    rlutil::locate(53, 17);
    cout << "LEADERBOARD";
    rlutil::locate(56, 20);
    cout << "SALIR\n";

    encuadroMenu();

    rlutil::locate(50, 11 + y);
    cout << (char)175 << endl;

    int key = rlutil::getkey();
    switch (key) {
    case 14: // UP
      rlutil::locate(50, 11 + y);
      cout << " " << endl;
      y-=3;
      if (y < 0) {
        y = 0;
      }
      break;
    case 15: // DOWN
      rlutil::locate(50, 11 + y);
      cout << " " << endl;
      y+=3;
      if (y > 9) {
        y = 9;
      }
      break;
    case 1: // ACEPTAR
      switch (y) {
      case 0:
        rlutil::cls();
        op = 0;
        juego1();
        rlutil::locate(1,1);
        cout << puntajeGanador;
        rlutil::anykey();
        break;
      case 3:
        op = 0;
        rlutil::cls();
        juego2();
        break;
      case 6:
        rlutil::cls();
        op=0;
        leaderboard(puntuacionMaxima,nombreDelMaximo);
        break;
      case 9:
        rlutil::cls();
        rlutil::setColor(rlutil::BLACK);
        cout << "¡Hasta la proxima!"<< endl;
        op = 0;
        break;
      }
    }
  } while (op != 0);
  return;
}

void dados(int valor,int x,int y) {
  char a[4];
  a[0] = 219;
  a[1] = 223;
  a[2] = 220;
  a[3] = 32;


  if (valor == 6) {
        rlutil::locate(x,y);
    cout      << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout      << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout      << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout      << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout      << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }

  if (valor == 5) {
        rlutil::locate(x,y);
    cout     << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout     << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout     << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout     << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout     << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }

  if (valor == 4) {
        rlutil::locate(x,y);
    cout    << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout    << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout    << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout    << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }

  if (valor == 3) {
        rlutil::locate(x,y);
    cout    << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout    << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout    << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }

  if (valor == 2) {
        rlutil::locate(x,y);
    cout    << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout    << a[0] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout    << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }

  if (valor == 1) {
        rlutil::locate(x,y);
    cout    << a[0] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[1] << a[0] << "\n";
        rlutil::locate(x,y+1);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+2);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << a[0] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+3);
    cout    << a[0] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[3] << a[0] << "\n";
        rlutil::locate(x,y+4);
    cout    << a[0] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[2] << a[0] << "\n";
  }
}

void animacionDados(){
    int num =1,num2=2,num3=3;
    while(!kbhit()){     // ---> anykey pero devuelve bool
            num = (num % 6) + 1;
            num2 = (num2 % 6) + 1;      // reloj con rango utilizando modulo.
            num3 = (num2 % 6) + 1;

             dados(num3,17,20);

             dados(num2,32,20);

             dados(num, 47,20);            // =========> num de dado | posicion x | posicion y

             dados(num2,62,20);

             dados(num3,77,20);

             dados(num2,92,20);
            rlutil::msleep(150);
    rlutil::locate(36,17);
    cout << "Presiona cualquier tecla para tirar los dados";
    }
}

int validar(int arreglo[6]) {
    int valorDeLaRonda = 0,aux,iguales=0,valortrio=0;

        for(int i=0;i<5;i++){
                                             // BUBBLESORT
         for(int j=i+1;j<6;j++){
            if(arreglo[i] > arreglo[j]){

                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
              }
           }
        }

        ///Escalera
        for (int i = 1; i <= 6; i++) {
        if (arreglo[i - 1] == i) {
            valorDeLaRonda = valorDeLaRonda + 1;
            if (valorDeLaRonda == 5) {
                valorDeLaRonda = 1;
                return valorDeLaRonda;             //  ----- >  Retorna 1 si es una escalera
            }
        } else {
            valorDeLaRonda = 0;
            break;
        }
    }

    /// Seis 6
    if (arreglo[0] == 6 && arreglo[1] == 6 && arreglo[2] == 6 && arreglo[3] == 6 && arreglo[4] == 6 && arreglo[5] == 6) {
        valorDeLaRonda=0;
    }
    ///6 dados iguales (menos para el número 6)
    else if (arreglo[0] == arreglo[1] && arreglo[1] == arreglo[2] && arreglo[2] == arreglo[3] && arreglo[3] == arreglo[4] && arreglo[4] == arreglo[5]) {
        valorDeLaRonda = arreglo[0] * 50;
    }

    else{
     for (int j=0;j<3;j++){
        if (arreglo[0+j]==arreglo[1+j] && arreglo[1+j] == arreglo[2+j]){         //Pregunto si son iguales los numeros en grupos de 3,
            iguales = 1;                                                         //sumando indices, el mas grande repetido queda.
            valortrio = arreglo[0+j];
        }
     }
        ///trio
        if (iguales == 1){
        valorDeLaRonda=valortrio*10;
        }

        ///suma de dados
        else{
        valorDeLaRonda=arreglo[0]+arreglo[1]+arreglo[2]+arreglo[3]+arreglo[4]+arreglo[5];
        }
    }

    return valorDeLaRonda;
  };

void mostrarDados(int arreglo[6]){
    int aux;

    for(int i=0;i<5;i++){
                                             // BUBBLESORT
         for(int j=i+1;j<6;j++){
            if(arreglo[i] > arreglo[j]){

                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
              }
           }
        }

   dados(arreglo[0],17,20);
   dados(arreglo[1],32,20);
   dados(arreglo[2],47,20);
   dados(arreglo[3],62,20);
   dados(arreglo[4],77,20);
   dados(arreglo[5],92,20);

};

int mostrarRondaMasAlta(int resultadoRonda,int maxPuntajeRonda){

    if(resultadoRonda > maxPuntajeRonda){
        maxPuntajeRonda = resultadoRonda;
    }
    return maxPuntajeRonda;
};
