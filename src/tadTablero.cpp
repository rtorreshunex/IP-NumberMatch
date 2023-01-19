/*
 * tadTablero.cpp
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */


#include <iostream>
#include "tadTablero.h"
using namespace std;

void crearTablero(Tablero &t, int filas, int columnas, int filasIniciales, int m[MAX_FIL][MAX_COL]) {
	t.n_filas = filas;
	t.n_columnas = columnas;
	t.filas_iniciales = filasIniciales;

	for (int fila = 0; fila < t.n_filas; fila++) {
		for (int columna = 0; columna < t.n_columnas; columna++) {
			if (fila < t.filas_iniciales){
				crearCelda(t.vTablero[fila][columna], m[fila][columna]);
				t.celdas_utiles++;
			} else crearCeldaVacia(t.vTablero[fila][columna]);
			if(fila + 1 == t.filas_iniciales && columna + 1 == t.n_columnas){
				t.fil_ult = fila;
				t.col_ult = columna;
			}
		}
	}
}

void crearTableroAleatorio(Tablero &t, int filas, int columnas, int filasIniciales) {
	t.n_filas = filas;
	t.n_columnas = columnas;
	t.filas_iniciales = filasIniciales;
	for (int i = 0; i < t.n_filas; i++){
		for (int j = 0; j < t.n_columnas; j++){
			if(i < t.filas_iniciales){
				crearCelda(t.vTablero[i][j], rand() % 9 + 1);
				t.celdas_utiles++;
			} else crearCeldaVacia(t.vTablero[i][j]);
			if(i + 1 == t.filas_iniciales && j + 1 == t.n_columnas){
				t.fil_ult = i;
				t.col_ult = j;
			}
		}
	}
}

void vaciarCelda(Tablero &t, int fila, int col) {
	crearCeldaVacia(t.vTablero[fila][col]);
}

void devolverNumFilasYCol(Tablero t, int &filas, int &columnas) {
	filas = t.n_filas;
	columnas = t.n_columnas;
}

void devolverCoordenadasCeldaOcup (Tablero t, int &filas, int &columnas){
	filas = t.fil_ult;
	columnas = t.col_ult;
}

void borrarCelda(Tablero &t, int fila, int col) {
	borrarNumCelda(t.vTablero[fila][col]);
}

void seleccionarCelda(Tablero &t, int fila, int col){
	seleccionarCelda(t.vTablero[fila][col]);
}

void deseleccionarCelda(Tablero &t, int fila, int col){
	deseleccionarCelda(t.vTablero[fila][col]);
}

int obtenerNum(Tablero t, int fila, int col) {
	return obtenerNumCelda(t.vTablero[fila][col]);
}

int obtenerCeldasUtiles(Tablero t){
	return t.celdas_utiles;
}

void obtenerUltCelda(Tablero t, int &fila, int &col){
	fila = t.fil_ult;
	col = t.col_ult;
}

void ponerCeldasUtiles(Tablero &t, int num){
	t.celdas_utiles = num;
}

void ponerValorCeldaConc(Tablero &t, int num, int fila, int col){
	crearCelda(t.vTablero[fila][col],num);
}

bool estaVacia(Tablero t, int fila, int col) {
	return esVaciaCelda(t.vTablero[fila][col]);
}

bool estaBorrada(Tablero t, int fila, int col) {
	return esBorradaCelda(t.vTablero[fila][col]);
}

bool estaSeleccionada(Tablero t, int fila, int col){
	return esSeleccionadaCelda(t.vTablero[fila][col]);
}

bool estaBorradaFila(Tablero t, int fila){
	bool borrada = true;

	for(int i = 0; i < t.n_columnas && borrada; i++){
		if(!estaBorrada(t, fila, i)){
			borrada = false;
		}
	}
	return borrada;
}

void borrarInfoFila(Tablero &t, int fila){
	for(int i = fila; i <= t.fil_ult; i++){
		for(int j = 0; j < t.n_columnas; j++){
			if(!((i + 1) > t.fil_ult)){
				if(esVaciaCelda(t.vTablero[i + 1][j]))
					crearCeldaVacia(t.vTablero[i][j]);
				crearCelda(t.vTablero[i][j], obtenerNumCelda(t.vTablero[i + 1][j]));
				if(esBorradaCelda(t.vTablero[i + 1][j]))
					borrarNumCelda(t.vTablero[i][j]);
			} else crearCeldaVacia(t.vTablero[i][j]);
		}
	}
	t.fil_ult--;
}

void replCeldNoBorr(Tablero &t){

	// Obtener posiciones de la primera celda vacía
	int col, fil;
	int celdas_utiles = 0;
	if((t.col_ult + 1) >= t.n_columnas){
		col = 0;
		fil = t.fil_ult + 1;
	} else {
		col = t.col_ult + 1;
		fil = t.fil_ult;
	}
	// Replicar celdas útiles
	for (int i = 0; i <= t.fil_ult; i++){
		for (int j = 0; j < t.n_columnas; j++){
			if(i != t.fil_ult || j <= t.col_ult)
				if(!esBorradaCelda(t.vTablero[i][j])){
					crearCelda(t.vTablero[fil][col], obtenerNumCelda(t.vTablero[i][j]));
					celdas_utiles++;
					col++;
					if(col >= t.n_columnas){
						col = 0;
						fil++;
					}
				}
		}
	}
	// Asignar la nueva última celda útil
	if(col == 0){
		t.fil_ult = --fil;
		t.col_ult = t.n_columnas - 1;
	}else {
		t.fil_ult = fil;
		t.col_ult = --col;
	}
	t.celdas_utiles += celdas_utiles;

}

bool sonParejaCeldas(Tablero t, int fila1, int col1, int fila2, int col2){

	bool pareja = false;
	if((fila1 + 1 == fila2 && (col1 == col2 || col1 + 1 == col2 || col1 - 1 == col2 || (col1 == (t.n_columnas - 1) && col2 == 0))) || // Fila de abajo pegada arriba, en diagonal por arriba o en la primera columna
		(fila1 - 1 == fila2 && (col1 == col2 || col1 + 1 == col2 || col1 - 1 == col2 || (col1 == 0 && col2 == (t.n_columnas - 1)))) || // Fila de arriba pegada abajo o en diagonal por abajo
		(col1 + 1 == col2 && (fila1 == fila2 || fila1 + 1 == fila2 || fila1 - 1 == fila2)) || // Columna de la derecha pegada a la izquierda o en diagonal por la izquierda
		(col1 - 1 == col2 && (fila1 == fila2 || fila1 + 1 == fila2 || fila1 - 1 == fila2)) // Columna de la izquierda pegada a la derecha o en diagonal por la derecha
		) pareja = sonPareja(t.vTablero[fila1][col1], t.vTablero[fila2][col2]);
	return pareja;

}

bool sonParejaSeparadas(Tablero t, int fila1, int col1, int fila2, int col2){

	bool pareja = false;
	bool horizontal = true;
	bool vertical = true;
	bool diagonal = true;
	int aux;

	// Ordenar celdas
	if((fila1 > fila2) || (fila1 == fila2 && col1 > col2)){
		aux = fila1;
		fila1 = fila2;
		fila2 = aux;
		aux = col1;
		col1 = col2;
		col2 = aux;
	}

	// Celdas en horizontal
	for(int i = fila1; i <= fila2 && horizontal; i++)
		for(int j = 0; j < t.n_columnas; j++){
			if(i == fila1 && j <= col1)
				if((col1 + 1) < t.n_columnas)
					j = col1 + 1;
				else {
					i++;
					j = 0;
				}
			if(!estaBorrada(t, i, j) && (i != fila2 || j < col2))
				horizontal = false;
		}

	// Celdas en vertical
	if(col1 == col2){
		for(int i = fila1 + 1; i < fila2; i++)
			if(!estaBorrada(t, i, col1))
				vertical = false;
	} else vertical = false;

	// Celdas en diagonal
	if((col1 + fila2 == col2 || col1 - fila2 == col2)){
		for(int i = fila1 + 1; i < fila2; i++)
			if((col1 + fila2 == col2 && !estaBorrada(t, i, col1 + i)) || (col1 - fila2 == col2 && !estaBorrada(t, i, col1 - i)))
				diagonal = false;
	} else diagonal = false;

	if(horizontal || vertical || diagonal)
		pareja = sonPareja(t.vTablero[fila1][col1], t.vTablero[fila2][col2]);
	return pareja;

}

bool encontrarParejas(Tablero t, int &fila1, int &col1, int &fila2, int &col2){
	bool pareja = false;
	int celdasBuscadas = 0;
	while(celdasBuscadas < t.celdas_utiles && !pareja){
		bool primeraCelda = false;
		int celdasSaltadas = 0;
		for(int i = 0; i <= t.fil_ult && !pareja; i++)
			for(int j = 0; j < t.n_columnas; j++){
				// Encontrar pareja
				if((primeraCelda && celdasSaltadas >= celdasBuscadas) && (sonParejaCeldas(t, fila1, col1, i, j) || sonParejaSeparadas(t, fila1, col1, i, j))){
					fila2 = i;
					col2 = j;
					pareja = true;
				}
				// Conseguir primera celda útil
				if(!estaVacia(t, i, j) && !estaBorrada(t, i, j) && (!primeraCelda || celdasSaltadas <= celdasBuscadas)){
					fila1 = i;
					col1 = j;
					primeraCelda = true;
					celdasSaltadas++;
				}
			}
		celdasBuscadas++;
	}
	return pareja;
}

