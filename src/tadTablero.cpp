/*
 * tadTablero.cpp
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */


#include <iostream>
#include "tadTablero.h"
using namespace std;

void crearTablero(Tablero &t, int filas, int columnas, int filasIniciales, int celdasUtiles, int filUlt, int colUlt) {
	t.n_filas = filas;
	t.n_columnas = columnas;
	t.filas_iniciales = filasIniciales;
	t.celdas_utiles = celdasUtiles;
	t.col_ult = colUlt;
	t.fil_ult = filUlt;
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
	for (int i = 0; i< t.n_columnas; i++){
		if(!estaBorrada(t,fila,i))
			borrarNumCelda(t.vTablero[fila][i]);
	}
}

void replCeldNoBorr(Tablero &t){

	for (int i = 0; i < t.n_filas; i++){
		for (int j = 0; j < t.n_columnas; j++){
			if(!estaBorrada(t,i,j));

		}
	}

}

bool sonParejaCeldas(Tablero t, int fila1, int col1, int fila2, int col2){

	bool pareja = false;
	if((fila1 + 1 == fila2 && (col1 == col2 || col1 + 1 == col2 || col1 - 1 == col2)) || // Fila de abajo pegada arriba o en diagonal por arriba
		(fila1 - 1 == fila2 && (col1 == col2 || col1 + 1 == col2 || col1 - 1 == col2)) || // Fila de arriba pegada abajo o en diagonal por abajo
		(col1 + 1 == col2 && (fila1 == fila2 || fila1 + 1 == fila2 || fila1 - 1 == fila2)) || // Columna de la derecha pegada a la izquierda o en diagonal por la izquierda
		(col1 - 1 == col2 && (fila1 == fila2 || fila1 + 1 == fila2 || fila1 - 1 == fila2)) || // Columna de la izquierda pegada a la derecha o en diagonal por la derecha
		(fila1 == fila2 && ((col1 == 0 && col2 == t.col_ult) || (col1 == t.col_ult && col2 == 0))) || // Misma fila pegada por los extremos
		(col1 == col2 && ((fila1 == 0 && fila2 == t.fil_ult) || (fila1 == t.fil_ult && fila2 == 0))) || // Misma columna pegada por los extremos
		((fila1 == 0 && col1 == 0) && (fila2 == t.fil_ult && col2 == t.col_ult)) || // Esquina superior izquierda pegada a esquina inferior derecha
		((fila1 == 0 && col1 == t.col_ult) && ((fila2 == t.fil_ult && col2 == 0))) // Esquina superior derecha pegada a esquina inferior izquierda
		) pareja = sonPareja(t.vTablero[fila1][col1], t.vTablero[fila2][col2]);
	return pareja;

}

