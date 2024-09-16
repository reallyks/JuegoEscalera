#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



extern int puntuacionMaxima;
extern string nombreDelMaximo;                                         //------> variable global
extern int actualizarJugadorMaximo(int puntuacion,string nombre);      //------> funcion global

int main();
void leaderboard();
void estructuraCambioRonda();
void encuadroMenu();
void encuadroNames();
void estructura();
string validarNombre(string nombre);
void menu();
void dados(int valor,int x,int y);
void animacionDados();
void mostrarDados(int arreglo[6]);
int validar(int arreglo[6]);
void juego1();
void juego2();
int mostrarRondaMasAlta(int resultadoRonda,int maxPuntajeRonda);


#endif // FUNCIONES_H_INCLUDED
