/*

  Programa   :  Tetris.c
  Utilidad   :  Juego de tetrix utilizando la libreria ncurses.h
  Autor      :  Michel Daniel Betancourt
  e-mail     :  Michel_Betancourth@hotmail.com, MichelBetancourt23@gmail.com
  Codificada :  Editor: Sublime text 2, Compilador Gcc
  Metodo :  Ejecutar el archivo compilar.sh

*/
	

/*
	MIT License

	Copyright (c) 2016 Michel Betancourt

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

// Librerias estandar
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>
#include <time.h>

// Librerias propias
#include <slibutil.h>

// Modulos
#include "formas.c"

#define TAM_Y 150
#define TAM_X 300

//--------- Prototipos ---------//
void dibujarMarco();
void reiniciarForma();
void crearForma();
int initComponent();
int compruebaColision();
void *hiloTiempo();
void *hiloMovObjeto();
void *hiloRefresh();
void makeInicio();
void gameOver();
void compruebaLineal();
void borrarLinea(int i);
void iniciarCampo();
//------------------------------//


//--------- Variables ----------//
int score = 0, tiempoS = 0, tiempoM = 0;				// Almacena lo del tablero
int formaMostrada;										// Forma actual de la figura (cruz, cuadrado etc..)
pthread_t idTiempo, idMovObjeto, idRefresh;				// Id de los thread
int CAMPO_X, CAMPO_Y;									// Tama;o del campo
int actualX, actualY;									// Posicion del objeto
int sig = 0;											// Lleva contando la siguiente figura
int posicionF = 1, limite;								// Mantienen el limite de los lados y su posicion
int movimiento = 300000;								// Velocidad de la pelota se reduce al presionar abajo
char almacena[TAM_Y][TAM_X];							// Guarda las fichas del campo
int finJuego=0, valorRand[2][1000];						// Fin del juego y array para guardar todas las piezas
//------------------------------//


int main () {
	char tecla;																// Guarda la tecla pulsada
	iniciarArray(almacena, TAM_Y, TAM_X);									// Coloca espacios en el array
	
	if(initComponent() != 0){
		clear();
		move(LINES / 2,COLS / 2);
		printw("ERROR AL CREAR HILOS DE EJECUCIÓN.");
		sleep(5);
		return -1;	
	}



	do {
		tecla = getch();
		if(tecla != 's' || tecla != 'B')
			movimiento = 300000;
	    if (tecla == 'A' || tecla == 'w') { 
	    	if (compruebaColisionLateral(almacena, formaMostrada, posicionF + 1, actualY, actualX) == 0){

		    	if (limite == 0) {
		    		if (posicionF < getPos(formaMostrada) - 1)
		    			posicionF++;
		    		else 
		    			posicionF = 0;
		    	} else if (limite == 1 && actualX >= 1) {
		    		if (posicionF < getPos(formaMostrada) - 1)
		    			posicionF++;
		    		else 
		    			posicionF = 0;
		    	} else if (limite == 2 && actualX <= CAMPO_X){
		    		if (posicionF < getPos(formaMostrada) - 1)
		    			posicionF++;
		    		else 
		    			posicionF = 0;
		    	} else if (limite == 3 && (actualX <= CAMPO_X && actualX > 0)){
		    		if (posicionF < getPos(formaMostrada) - 1)
		    			posicionF++;
		    		else 
		    			posicionF = 0;
		    	}
	    	}
	    	
	    }

	    if ((tecla == 'D' || tecla == 'a') && compruebaColisionLateral(almacena, formaMostrada, posicionF, actualY, actualX) == 0) { 
	    	if (actualX > 1 && (limite == 0 || limite == 2)){
	    		actualX--;
	    	} else if ( (limite == 1 || limite == 3) && actualX >= 1) {
	    		actualX--;
	    	}
	    }
	    if ((tecla == 'C' || tecla == 'd') && compruebaColisionLateral(almacena, formaMostrada, posicionF, actualY, actualX) == 0) { 
	    	if (actualX < CAMPO_X && (limite == 0 || limite == 1)){
	    		actualX++;
	    	} else if ( (limite == 2 || limite == 3) && actualX <= CAMPO_X){
	    		actualX++;
	    	}
	    }
	    if (tecla == 'B' || tecla == 's'){
	    	movimiento = 100000;
	    	usleep(40000);
	    }
		
	}while (tecla != 'q' && finJuego == 0);

	endwin(); kill(hiloTiempo); kill(hiloRefresh); kill(hiloMovObjeto); return 0; // Finaliza la aplicacion
}


/*
	Hilo que mueve el objeto en todo momento.
*/
void *hiloMovObjeto () {
	for(;finJuego == 0;) {

		if(actualY == CAMPO_Y - 3 && getLimite(formaMostrada, posicionF) != 1){
			usleep(movimiento - 100000);
			fillCampo(actualY, actualX, formaMostrada, posicionF, almacena);
			reiniciarForma();
		} else if(compruebaColision(almacena, formaMostrada, posicionF, actualY, actualX) == 0 && actualY != CAMPO_Y - 3)
			actualY++;
		else if(getLimite(formaMostrada, posicionF) == 0){
			usleep(movimiento - 100000);
			fillCampo(actualY, actualX, formaMostrada, posicionF, almacena);
			reiniciarForma();
		} else if(getLimite(formaMostrada, posicionF) == 1){
			if (compruebaColision(almacena, formaMostrada, posicionF, actualY, actualX) == 0)
				actualY++;
			usleep(movimiento - 100000);
			fillCampo(actualY, actualX, formaMostrada, posicionF, almacena);
			reiniciarForma();
		}

		usleep(movimiento - (tiempoS * 200));
	}
}

/*
	El hilo que hace el mayor trabajo sobre todo el juego 
	limpia, dibuja el marco, crea la forma y refresca la pantalla para que el
	usuario vea el cambio.
*/
void *hiloRefresh() {
	int posicionF = 0;
	for(;finJuego == 0;) {
		clear();
		dibujarMarco();
		crearForma();
		refresh();
		usleep(33000);
	}
}

/*
	Hilo practicamente inutil solo se encarga de llevar un contador de los segundos
	transcurridos.
*/
void *hiloTiempo() {
	for (;finJuego == 0;) {
		tiempoS++;
		if (tiempoS == 60){
			tiempoS = 0;
			tiempoM++;
		}
		score = tiempoS * 10 + (600 * tiempoM);
		sleep(1);
	}
}


/*
	Dibuja los limites del juego y a su vez crea el tablero de
	score, minutos y segundos. Tambien muestra la proxima figura
*/
void dibujarMarco() {
	int i, k;
	colorON(AMARILLO_NEGRO);
	for(i = 1; i < CAMPO_Y; i++) {
		mvprintw(i, 0, "|");
		mvprintw(i, CAMPO_X + 3, "|");
	}
	 
	for(i = 1; i < CAMPO_X + 3; i++){
		mvprintw(0, i, "_");
		mvprintw(CAMPO_Y, i, "\"");
	}
	colorOFF(AMARILLO_NEGRO);
	for(i = 0; i < TAM_Y; i++){
		for (k = 0; k < TAM_X; ++k)
		{
			if (almacena[i][k] == 'X'){
				mvprintw(i,k,"X");
			}
		}
	}
	colorON(VERDE_NEGRO);
	
	mvprintw((CAMPO_Y / 2) - 6, CAMPO_X + 8, "Siguiente");
	
	for(i = (CAMPO_Y / 2) - 4; i < (CAMPO_Y / 2) + 1; i++) {
		mvprintw(i, CAMPO_X + 8, "|");
		mvprintw(i, CAMPO_X + 16, "|");
	}
	 
	for(i = CAMPO_X + 8; i < CAMPO_X + 17; i++){
		mvprintw((CAMPO_Y / 2) - 5, i, "_");
		mvprintw((CAMPO_Y / 2) + 1, i, "\"");
	}

	makeFigura(valorRand[0][sig],valorRand[1][sig],(CAMPO_Y / 2) - 3, CAMPO_X + 11);
	
	colorON(VERDE_NEGRO);
	mvprintw((CAMPO_Y / 2) + 3, CAMPO_X + 6, "Score: %i", score);
	mvprintw((CAMPO_Y / 2) + 5, CAMPO_X + 6,"Tiempo: %i:%i", tiempoM, tiempoS);
	colorOFF(VERDE_NEGRO);
}

/*
	Coloca la forma al principio mostrando una nueva.
	Si al momento de colocar una pieza se tropieza gameover
*/
void reiniciarForma() {
	movimiento = 300000;
	actualY = 1; 
	actualX = (CAMPO_X / 2) - 1;
	compruebaLineal();
	if(compruebaColision(almacena, formaMostrada, posicionF, actualY, actualX) != 0){
		finJuego = 1;
		gameOver();
	}

	
	formaMostrada = valorRand[0][sig];
	
	
	posicionF = valorRand[1][sig];
	sig++;
	if (sig == 1000){
		sig = 0;
	}
	
}

/* 
	Funcion que muestra la forma en pantalla no va directo en el hilo porque
	este no se percata de los cambios en posicionF. No se como arreglarlo xD
*/
void crearForma(){
	limite = makeFigura(formaMostrada, posicionF, actualY, actualX);
}

/*
	Esta funcion inicia todos los componentes necesarios dejando el main lo mas
	vacio posible y permitindo que este a su vez solo se encargue de captar las teclas
	retorna -1 si hay un error.
*/
int initComponent(){
	
	int i;
	int temp;
	srand(time(NULL));
	iniciarFormas();														// Funcion del modulo formas.c
	
	int errorTiempo, errorMovObj, errorRefresh;								// Sirven para ver si hubo un error al crear los hilos
	for (i = 0; i < 1000; ++i)
	{
		temp = rand() % 1000;
		if (temp < 200){
			valorRand[0][i] = 1;
		} else if (temp < 400){
			valorRand[0][i] = 2;		
		} else if (temp < 600){
			valorRand[0][i] = 0;		
		} else if (temp < 800){
			valorRand[0][i] = 3;		
		} else if (temp < 1000) {
			valorRand[0][i] = 4;
		}
		valorRand[1][i] = rand() % getPos(valorRand[0][i]);
	}
	
	initscr();																// Arrancamos ncurses
	noecho();																// Oculta lo escrito
	iniColor();																// Funcion de la libreria slibutil.h
	curs_set(0);
	makePantallaNcurses(COLS, LINES);
	makeAutor(COLS, LINES);
	fflush(stdin);
	makePantallaNcurses(COLS, LINES);
	makeInicio();
	dibujarMarco();
	CAMPO_X = COLS - 23; CAMPO_Y = LINES - 1;								// Tamaño del campo sin contar el contador y score
	reiniciarForma();														// Coloca la forma en la parte superior
	

	
	errorTiempo = pthread_create(&idTiempo, NULL, hiloTiempo, NULL);		// Error del hilo 
	errorMovObj = pthread_create(&idMovObjeto, NULL, hiloMovObjeto, NULL);	// Error del hilo 
	errorRefresh = pthread_create(&idRefresh, NULL, hiloRefresh, NULL);		// Error del hilo 
	if (errorTiempo != 0 || errorMovObj != 0 || errorRefresh != 0)			// Error del hilo 
		return -1;
}

/* 
	Muestra el inicio una pantalla presentadora
*/
void makeInicio(){
	int centerX = COLS / 2, centerY = LINES / 2;

	mvprintw(centerY - 2, centerX - 6, "Bienvenido!!");	
	mvprintw(centerY - 1, centerX - 26, "Este juego esta basado en el famoso juego de tetris,");	
	mvprintw(centerY, centerX - 29, "consiste en apilar los bloques de manera que no se acumulen");	
	mvprintw(centerY + 1, centerX - 29, "iras ganando puntos mientras mas tiempo sobrevivas tambien");	
	mvprintw(centerY + 2, centerX - 25, "por cada linea completa que llenes. Buena Suerte!!");	

	refresh();
	getch();
}

/* 
	Funcion al final del Juego
*/
void gameOver(){
	
	clear();
	makePantallaNcurses(COLS, LINES);
	int centerX = COLS / 2, centerY = LINES / 2;
	char tec;
	mvprintw(centerY - 1, centerX - 4, "GAMEOVER");	
	mvprintw(centerY, centerX - 23, "Has perdido el juego tu puntuacion fue de: %i", score);
	refresh();
}

/*
	Comprueba que exista una linea entera de x para eliminarla por alguna razon no funciona.
 */
void compruebaLineal(){
	int k, i;
	int contador;
	for (i = 1; i < CAMPO_Y; ++i)
	{
		for (k = 1, contador = 0; k < CAMPO_X + 3; ++k)
		{
			if(almacena[i][k] == 'X'){
				contador++;
			}
		}
		if(contador >= CAMPO_X + 2){
			borrarLinea(i);
		}
	}
}

/*
	Elimina la linea tampoco funciona
 */
void borrarLinea(int i) {
	int k, j;
	for (k = i; k > 0; --k) {
		for (j = 0; j < CAMPO_X + 3; j++) {
			almacena[k][j] = almacena[k - 1][j];
		}
	}
	score += 1200;
}