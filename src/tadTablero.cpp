/*
 * tadTablero.cpp
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */


#include <iostream>
#include "tadTablero.h"
using namespace std;

void crearTablero(Tablero &t, int filas, int columnas, int filasIniciales, int &filUlt, int &colUlt, int m[MAX_FIL][MAX_COL]) {
	t.n_filas = filas;
	t.n_columnas = columnas;
	t.filas_iniciales = filasIniciales;

	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			if (fila < t.filas_iniciales){
				crearCelda(t.vTablero[fila][columna], m[fila][columna]);
				t.celdas_utiles++;
			} else crearCeldaVacia(t.vTablero[fila][columna]);
			if(fila + 1 == t.filas_iniciales && columna + 1 == columnas){
				t.fil_ult = fila;
				t.col_ult = columna;
			}
		}
	}
	colUlt = t.col_ult;
	filUlt = t.fil_ult;
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

	for(int i = 0; i < t.n_columnas; i++){
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
		for (int j = 0; j <= t.col_ult; j++){
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

