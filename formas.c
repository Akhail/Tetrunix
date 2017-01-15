/*
	Modulo   :  formas.c
	Utilidad   :  Muestra y configura todas las formas del juego
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

#ifndef _FORMAS_H_
#define _FORMAS_H_ 30


#include <string.h>
#define TAM_Y 150
#define TAM_X 300

typedef struct {
	int posX, posY;
}vertebras;

typedef struct {
	vertebras vertebra[4];
	int limite, limiteAbajo, abasto;
}objetos;

typedef struct {
	objetos estado[4];
	int color;
	int maxVertebras;
	int maxPosicion;
}formas;
	
	formas figura[5];	

void iniciarFormas() {

	//-------------------------------- Cruz ------------------------------------//
	figura[0].maxPosicion = 4;
	figura[0].maxVertebras = 4;
	figura[0].color = ROJO_NEGRO;
	// _|_
	figura[0].estado[0].vertebra[0].posX = 1; figura[0].estado[0].vertebra[0].posY = 1;
	figura[0].estado[0].vertebra[1].posX = 0; figura[0].estado[0].vertebra[1].posY = 1;
	figura[0].estado[0].vertebra[2].posX = 1; figura[0].estado[0].vertebra[2].posY = 0;
	figura[0].estado[0].vertebra[3].posX = 2; figura[0].estado[0].vertebra[3].posY = 1;
	figura[0].estado[0].limite = 0;
	figura[0].estado[0].limiteAbajo = 1;
	figura[0].estado[0].abasto = 4;
	// |-
	figura[0].estado[1].vertebra[0].posX = 1; figura[0].estado[1].vertebra[0].posY = 1;
	figura[0].estado[1].vertebra[1].posX = 1; figura[0].estado[1].vertebra[1].posY = 0;
	figura[0].estado[1].vertebra[2].posX = 2; figura[0].estado[1].vertebra[2].posY = 1;
	figura[0].estado[1].vertebra[3].posX = 1; figura[0].estado[1].vertebra[3].posY = 2;
	figura[0].estado[1].limite = 1;
	figura[0].estado[1].limiteAbajo = 0;
	figura[0].estado[1].abasto = 2;
	// -.-
	figura[0].estado[2].vertebra[0].posX = 1; figura[0].estado[2].vertebra[0].posY = 1;
	figura[0].estado[2].vertebra[1].posX = 0; figura[0].estado[2].vertebra[1].posY = 1;
	figura[0].estado[2].vertebra[2].posX = 1; figura[0].estado[2].vertebra[2].posY = 2;
	figura[0].estado[2].vertebra[3].posX = 2; figura[0].estado[2].vertebra[3].posY = 1;
	figura[0].estado[2].limite = 0;
	figura[0].estado[2].limiteAbajo = 0;
	figura[0].estado[2].abasto = 2;
	// -|
	figura[0].estado[3].vertebra[0].posX = 1; figura[0].estado[3].vertebra[0].posY = 1;
	figura[0].estado[3].vertebra[1].posX = 1; figura[0].estado[3].vertebra[1].posY = 2;
	figura[0].estado[3].vertebra[2].posX = 0; figura[0].estado[3].vertebra[2].posY = 1;
	figura[0].estado[3].vertebra[3].posX = 1; figura[0].estado[3].vertebra[3].posY = 0;
	figura[0].estado[3].limite = 2;
	figura[0].estado[3].limiteAbajo = 0;
	figura[0].estado[3].abasto = 2;
	//--------------------------------------------------------------------------//


	//--------------------------------- Linea ----------------------------------//
	figura[1].maxPosicion = 2;
	figura[1].maxVertebras = 3;
	figura[1].color = AZUL_NEGRO;
	// ---
	figura[1].estado[0].vertebra[0].posX = 1; figura[1].estado[0].vertebra[0].posY = 1;
	figura[1].estado[0].vertebra[1].posX = 0; figura[1].estado[0].vertebra[1].posY = 1;
	figura[1].estado[0].vertebra[2].posX = 2; figura[1].estado[0].vertebra[2].posY = 1;
	figura[1].estado[0].limite = 0;
	figura[1].estado[0].limiteAbajo = 1;
	figura[1].estado[0].abasto = 4;
	// |
	figura[1].estado[1].vertebra[0].posX = 1; figura[1].estado[1].vertebra[0].posY = 1;
	figura[1].estado[1].vertebra[1].posX = 1; figura[1].estado[1].vertebra[1].posY = 0;
	figura[1].estado[1].vertebra[2].posX = 1; figura[1].estado[1].vertebra[2].posY = 2;
	figura[1].estado[1].limite = 3;
	figura[1].estado[1].limiteAbajo = 0;
	figura[1].estado[1].abasto = 2;
	//--------------------------------------------------------------------------//


	//----------------------------------- Cuadrado -----------------------------//
	figura[2].maxPosicion = 1;
	figura[2].maxVertebras = 4;
	figura[2].color = CYAN_NEGRO;
	// #
	figura[2].estado[0].vertebra[0].posX = 1; figura[2].estado[0].vertebra[0].posY = 1;
	figura[2].estado[0].vertebra[1].posX = 0; figura[2].estado[0].vertebra[1].posY = 1;
	figura[2].estado[0].vertebra[2].posX = 0; figura[2].estado[0].vertebra[2].posY = 0;
	figura[2].estado[0].vertebra[3].posX = 1; figura[2].estado[0].vertebra[3].posY = 0;
	figura[2].estado[0].limite = 2;
	figura[2].estado[0].limiteAbajo = 1;
	figura[2].estado[0].abasto = 5;
	//--------------------------------------------------------------------------//



	//------------------------------ Ele ---------------------------------------//
	figura[3].maxVertebras = 4;
	figura[3].maxPosicion = 4;
	figura[3].color = AMARILLO_NEGRO;
	// """]
	figura[3].estado[0].vertebra[0].posX = 0; figura[3].estado[0].vertebra[0].posY = 0;
	figura[3].estado[0].vertebra[1].posX = 1; figura[3].estado[0].vertebra[1].posY = 0;
	figura[3].estado[0].vertebra[2].posX = 2; figura[3].estado[0].vertebra[2].posY = 0;
	figura[3].estado[0].vertebra[3].posX = 2; figura[3].estado[0].vertebra[3].posY = 1;
	figura[3].estado[0].limite = 0;
	figura[3].estado[0].limiteAbajo = 1;
	figura[3].estado[0].abasto = 3;
	// _|
	figura[3].estado[1].vertebra[0].posX = 2; figura[3].estado[1].vertebra[0].posY = 0;
	figura[3].estado[1].vertebra[1].posX = 2; figura[3].estado[1].vertebra[1].posY = 1;
	figura[3].estado[1].vertebra[2].posX = 1; figura[3].estado[1].vertebra[2].posY = 2;
	figura[3].estado[1].vertebra[3].posX = 2; figura[3].estado[1].vertebra[3].posY = 2;
	figura[3].estado[1].limite = 1;
	figura[3].estado[1].limiteAbajo = 0;
	figura[3].estado[1].abasto = 6;
	// |__
	figura[3].estado[2].vertebra[0].posX = 2; figura[3].estado[2].vertebra[0].posY = 2;
	figura[3].estado[2].vertebra[1].posX = 1; figura[3].estado[2].vertebra[1].posY = 2;
	figura[3].estado[2].vertebra[2].posX = 0; figura[3].estado[2].vertebra[2].posY = 2;
	figura[3].estado[2].vertebra[3].posX = 0; figura[3].estado[2].vertebra[3].posY = 1;
	figura[3].estado[2].limite = 0;
	figura[3].estado[2].limiteAbajo = 0;
	figura[3].estado[2].abasto = 4;
	// ["
	figura[3].estado[3].vertebra[0].posX = 0; figura[3].estado[3].vertebra[0].posY = 2;
	figura[3].estado[3].vertebra[1].posX = 0; figura[3].estado[3].vertebra[1].posY = 1;
	figura[3].estado[3].vertebra[2].posX = 0; figura[3].estado[3].vertebra[2].posY = 0;
	figura[3].estado[3].vertebra[3].posX = 1; figura[3].estado[3].vertebra[3].posY = 0;
	figura[3].estado[3].limite = 2;
	figura[3].estado[3].limiteAbajo = 0;
	figura[3].estado[3].abasto = 1;
	//--------------------------------------------------------------------------//

	//------------------------------ EleD ---------------------------------------//
	figura[4].maxVertebras = 4;
	figura[4].maxPosicion = 4;
	figura[4].color = MAGENTA_NEGRO;
	// L
	figura[4].estado[0].vertebra[0].posX = 0; figura[4].estado[0].vertebra[0].posY = 0;
	figura[4].estado[0].vertebra[1].posX = 0; figura[4].estado[0].vertebra[1].posY = 1;
	figura[4].estado[0].vertebra[2].posX = 0; figura[4].estado[0].vertebra[2].posY = 2;
	figura[4].estado[0].vertebra[3].posX = 1; figura[4].estado[0].vertebra[3].posY = 2;
	figura[4].estado[0].limite = 2;
	figura[4].estado[0].limiteAbajo = 0;
	figura[4].estado[0].abasto = 5;
	// __|
	figura[4].estado[1].vertebra[0].posX = 0; figura[4].estado[1].vertebra[0].posY = 2;
	figura[4].estado[1].vertebra[1].posX = 1; figura[4].estado[1].vertebra[1].posY = 2;
	figura[4].estado[1].vertebra[2].posX = 2; figura[4].estado[1].vertebra[2].posY = 2;
	figura[4].estado[1].vertebra[3].posX = 2; figura[4].estado[1].vertebra[3].posY = 1;
	figura[4].estado[1].limite = 0;
	figura[4].estado[1].limiteAbajo = 0;
	figura[4].estado[1].abasto = 4;
	// "|
	figura[4].estado[2].vertebra[0].posX = 1; figura[4].estado[2].vertebra[0].posY = 0;
	figura[4].estado[2].vertebra[1].posX = 2; figura[4].estado[2].vertebra[1].posY = 0;
	figura[4].estado[2].vertebra[2].posX = 2; figura[4].estado[2].vertebra[2].posY = 1;
	figura[4].estado[2].vertebra[3].posX = 2; figura[4].estado[2].vertebra[3].posY = 2;
	figura[4].estado[2].limite = 1;
	figura[4].estado[2].limiteAbajo = 0;
	figura[4].estado[2].abasto = 3;
	// |"""
	figura[4].estado[3].vertebra[0].posX = 0; figura[4].estado[3].vertebra[0].posY = 1;
	figura[4].estado[3].vertebra[1].posX = 0; figura[4].estado[3].vertebra[1].posY = 0;
	figura[4].estado[3].vertebra[2].posX = 1; figura[4].estado[3].vertebra[2].posY = 0;
	figura[4].estado[3].vertebra[3].posX = 2; figura[4].estado[3].vertebra[3].posY = 0;
	figura[4].estado[3].limite = 0;
	figura[4].estado[3].limiteAbajo = 1;
	figura[4].estado[3].abasto = 1;
	//--------------------------------------------------------------------------//
	// Si desean agregar otra figura solo coloquen la forma como 5 o 6 extienda el array y
	// aumenten el numero del rand en tetrix.c
	//--------------------------------------------------------------------------//
}

/*
	Crea la figura funcion MUY IMPORTANTE
 */
int makeFigura(int fig, int posicion, int valorY, int valorX){
	int k;
	for (k = 0; k < figura[fig].maxVertebras; ++k){
		colorON(figura[fig].color);
		mvprintw( (figura[fig].estado[posicion].vertebra[k].posY) + valorY, (figura[fig].estado[posicion].vertebra[k].posX) + valorX, "X");
		// Es muy larga la comento aqui.
		// basicamente en un cuadro imaginario de 9x9 se almacena las posiciones estas se sumaran a la posicion
		// actualx y actualy las cuales actuaran como la posicion 0,0 o
		// OXX
		// XXX
		// XXX la 'O' de ahi xD
		colorOFF(figura[fig].color);
	}
	return figura[fig].estado[posicion].limite;
}

/*
	retorna la maxima cantidad de posiciones de una figura vital para evitar "sobregirar" la figura
*/
int getPos(int forma){
	return figura[forma].maxPosicion;
}
/*
	Devuelve si la figura termina en
	XXX
	OOO
	NNN
	las 'O' y no termina en las 'N'.
	vital para detenerse a tiempo al final del array aunque se puede reutilizar la que se
	usa para comprobar la colision
 */
int getLimite(int forma, int edo){
	return figura[forma].estado[edo].limiteAbajo;
}

/*
	Innecesaria basura de una version anterior xd
*/
int getAbasto(int forma, int edo){
	return figura[forma].estado[edo].abasto;
}

/*
	Rellena el campo para luego mostrar las figuras colocadas.
 */
void fillCampo(int actualY, int actualX, int formaMostrada, int posicionF, char almacena[TAM_Y][TAM_X]){
	int i;
	for (i = 0; i < figura[formaMostrada].maxVertebras; ++i)
	{
		almacena
		[figura[formaMostrada].estado[posicionF].vertebra[i].posY + actualY]
		[figura[formaMostrada].estado[posicionF].vertebra[i].posX + actualX] = 'X';
	}
}

/*
	Casi no hay necesidad de comentarla deja con espacios el array para inicializarlo
 */
void iniciarArray(char almacena[TAM_Y][TAM_X], int maxCampoY, int maxCampoX){
	int i, k;
	for (i = 0; i < TAM_Y; ++i)
	{
		for ( k = 0; k < TAM_X; ++k)
		{
			almacena[i][k] = ' ';
		}
	}
}

/*
	Las dos siguientes funciones comprueban que no se choque con una pieza en el juego
 */
int compruebaColision(char almacena[TAM_Y][TAM_X], int formaMostrada, int posicionF, int actualY, int actualX){
	int i;
	for (i = 0; i < figura[formaMostrada].maxVertebras; ++i)
	{
		if(almacena	[actualY + 1 + figura[formaMostrada].estado[posicionF].vertebra[i].posY]
					[actualX + figura[formaMostrada].estado[posicionF].vertebra[i].posX] == 'X'){
			return 1;
		}
	}
	return 0;

}

int compruebaColisionLateral(char almacena[TAM_Y][TAM_X], int formaMostrada, int posicionF, int actualY, int actualX){
	int i;
	for (i = 0; i < figura[formaMostrada].maxVertebras; ++i)
	{
		if(	almacena	[actualY + figura[formaMostrada].estado[posicionF].vertebra[i].posY][actualX + 1 + figura[formaMostrada].estado[posicionF].vertebra[i].posX] == 'X' || 
			almacena	[actualY + figura[formaMostrada].estado[posicionF].vertebra[i].posY][(actualX - 1) + figura[formaMostrada].estado[posicionF].vertebra[i].posX] == 'X'){
			return 1;
		}
		if(	almacena	[actualY + figura[formaMostrada].estado[posicionF].vertebra[i].posY][actualX + figura[formaMostrada].estado[posicionF].vertebra[i].posX] == 'X' || 
			almacena	[actualY + figura[formaMostrada].estado[posicionF].vertebra[i].posY][actualX + figura[formaMostrada].estado[posicionF].vertebra[i].posX] == 'X'){
			return 1;
		}
	}
	return 0;

}
#endif