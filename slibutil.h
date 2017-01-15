/*

  Modulo   :  slibutil.h
  Utilidad   :  libreria con los colores y un marco
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

#ifndef _LIBUTIL_H_
#define _LIBUTIL_H_

#define ROJO_NEGRO 1
#define ROJO_COLOR 2

#define AZUL_NEGRO 3
#define AZUL_COLOR 4

#define VERDE_NEGRO 5
#define VERDE_COLOR 6

#define CYAN_NEGRO 7
#define CYAN_COLOR 8

#define AMARILLO_NEGRO 9
#define AMARILLO_COLOR 10

#define MAGENTA_NEGRO 11
#define MAGENTA_COLOR 12

#define BLANCO_NEGRO 13
#define BLANCO_COLOR 14

#define NEGRO_COLOR 15
#define NEGRO_BLANCO 16

#define NEGRO_MAGENTA 17
#define NEGRO_AMARILLO 18

#define NEGRO_CYAN 19
#define NEGRO_AZUL 20

#define NEGRO_ROJO 21
#define NEGRO_VERDE 22

void colors(char color[6]);
void iniColor();

void colorON(int valor) {
	attron(COLOR_PAIR(valor));
}
void colorOFF(int valor) {
	attroff(COLOR_PAIR(valor));
}

/*
	Crea pareja de colores
 */
void iniColor(){
	start_color();
	// Rojo
	init_pair(ROJO_NEGRO, COLOR_RED, COLOR_BLACK);
	init_pair(ROJO_COLOR, COLOR_RED, COLOR_RED);
	// Azul
	init_pair(AZUL_NEGRO, COLOR_BLUE, COLOR_BLACK);
	init_pair(AZUL_COLOR, COLOR_BLUE, COLOR_BLUE);
	// Verde
	init_pair(VERDE_NEGRO, COLOR_GREEN, COLOR_BLACK);
	init_pair(VERDE_COLOR, COLOR_GREEN, COLOR_GREEN);
	// Cyan
	init_pair(CYAN_NEGRO, COLOR_CYAN, COLOR_BLACK);
	init_pair(CYAN_COLOR, COLOR_CYAN, COLOR_CYAN);
	// Amarillo
	init_pair(AMARILLO_NEGRO, COLOR_YELLOW, COLOR_BLACK);
	init_pair(AMARILLO_COLOR, COLOR_YELLOW, COLOR_YELLOW);
	// Magenta
	init_pair(MAGENTA_NEGRO, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(MAGENTA_COLOR, COLOR_MAGENTA, COLOR_MAGENTA);
	// Blanco
	init_pair(BLANCO_NEGRO, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLANCO_COLOR, COLOR_WHITE, COLOR_WHITE);
	// Negro
	init_pair(NEGRO_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(NEGRO_BLANCO, COLOR_BLACK, COLOR_WHITE);
	init_pair(NEGRO_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(NEGRO_AMARILLO, COLOR_BLACK, COLOR_YELLOW);
	init_pair(NEGRO_CYAN, COLOR_BLACK, COLOR_CYAN);
	init_pair(NEGRO_AZUL, COLOR_BLACK, COLOR_BLUE);
	init_pair(NEGRO_ROJO, COLOR_BLACK, COLOR_RED);
	init_pair(NEGRO_VERDE, COLOR_BLACK, COLOR_GREEN);
}

/*
	muestra una pantalla muy colorida :D
	PD: fue mi parte favorita extra;o no?
 */
void makePantallaNcurses(int cols, int lines){
	clear();
	int i, e = 0;
	int rest = cols / 7;
	do {
		for(i = 1 + e; i < lines - (1 + e); i++) {
			if(i < (lines - (1+e)) / 2 ){
				colorON(CYAN_NEGRO);
				mvprintw(i, 0 + e, "\\");
				colorOFF(CYAN_NEGRO);
			} else {
				colorON(AZUL_NEGRO);
				mvprintw(i, 0 + e, "/");
				colorOFF(AZUL_NEGRO);
			}

			if(i < (lines - (1+e)) / 2 ){
				colorON(AZUL_NEGRO);
				mvprintw(i, cols - (1 + e), "/");
				colorOFF(AZUL_NEGRO);
			} else {
				colorON(CYAN_NEGRO);
				mvprintw(i, cols - (1 + e), "\\");
				colorOFF(CYAN_NEGRO);
			}
		}
		 
		for(i = 1 + e; i < cols - (e * rest); i++){
			if(i < (cols - (e * rest)) / 2 ){
				colorON(AZUL_NEGRO);
				mvprintw(0 + e, i, "\\");
				colorOFF(AZUL_NEGRO);
			} else {
				colorON(CYAN_NEGRO);
				mvprintw(0 + e, i, "/");
				colorOFF(CYAN_NEGRO);
			}
			if(i < (cols - (e * rest)) / 2 ){
				colorON(AZUL_NEGRO);
				mvprintw(lines - (1 + e), cols - (i+1), "\\");
				colorOFF(AZUL_NEGRO);
			} else {
				colorON(CYAN_NEGRO);
				mvprintw(lines - (1 + e), cols - (i+1), "/");
				colorOFF(CYAN_NEGRO);
			}
		}
		e++;
	}while(e <= 6);


}

/*
	No tocar o tu pc puede explotar, convulsionar, ser decomisada por el FBI 
	o se te podria sobreescribir la CMOS (hombre que no te arrancara la pc).
 */
void makeAutor(int cols, int lines){
	int centerX = cols / 2, centerY = lines / 2;

	mvprintw(centerY, centerX - 12, "Autor: Michel Betancourt");			// No tocar

	refresh();
	getch();
}
#endif