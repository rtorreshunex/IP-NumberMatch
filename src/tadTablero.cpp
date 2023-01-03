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
	for (int i = 0; i < filas; i++){
		if(i<filasIniciales)
			for (int j = 0; j < columnas; j++){
				crearCelda(t.vTablero[i][j], rand() % 9 + 1);
			}
		else
			for (int j = 0; j < columnas; j++){
				crearCeldaVacia(t.vTablero[i][j]);
			}
	}
//	for(int i=0;i<filas;i++){
//		for(int j=0;j<columnas;j++)
//			cout << to_string(obtenerNumCelda(t.vTablero[i][j])) + " ";
//		cout << endl;
//	}
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
	bool borrada = false;

	for(int i = 0; i < t.n_columnas; i++){
		if(estaBorrada(t, fila, i)){
			borrada = true;
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

