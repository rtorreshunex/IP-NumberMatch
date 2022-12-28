/*
 * tadTablero.cpp
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */


#include <iostream>
#include "tadTablero.h"
using namespace std;

void crearTablero(Tablero &t, int filas, int columnas, int filasIniciales) {
	t.n_filas = filas;
	t.n_columnas = columnas;
	t.filas_iniciales = filasIniciales;
	for (int i = 0; i < filas; i++){
		if(i<filasIniciales)
			for (int j = 0; j < columnas; j++){
				crearCelda(t.vTablero[i][j], rand() % 9 + 1);
			}
		else
			for (int j = 0; j < columnas; j++){
				crearCelda(t.vTablero[i][j], 0);
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

void borrarCelda(Tablero &t, int fila, int col) {
	borrarNumCelda(t.vTablero[fila][col]);
}

int obtenerNum(Tablero t, int fila, int col) {
	return obtenerNumCelda(t.vTablero[fila][col]);
}

bool estaVacia(Tablero t, int fila, int col) {
	return esVaciaCelda(t.vTablero[fila][col]);
}

bool estaBorrada(Tablero t, int fila, int col) {
	return esBorradaCelda(t.vTablero[fila][col]);
}
