/*
 * tadTablero.h
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include <iostream>
#include "tadCelda.h"
using namespace std;

const int MAX_FIL = 12;
const int MAX_COL = 9;
typedef Celda TVectorTablero [MAX_FIL][MAX_COL];
struct Tablero {
	TVectorTablero vTablero;
	int n_filas;
	int n_columnas;
	int filas_iniciales;
	int num_seleccionadas;
};

/*
 * PRE: {1 <= filas <= 12; 1 <= columnas <= 9; filasIniciales <= filas;
 * 		t debe estar correctamente inicializada}
 * POST: {}
 * DESCRIPCIÓN: Crea un tablero de dimensión filas * columnas en el que las primeras filas (filasIniciales) contienen
 * números (con valores entre 1 y 9) generados aleatoriamente. El resto de las filas están vacías.
 * COMPL: O (n²)
 */
void crearTablero (Tablero &t, int filas, int columnas, int filasIniciales);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {}
 * DESCRIPCIÓN: Vacía la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void vaciarCelda (Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {}
 * DESCRIPCIÓN: Marca como borrada la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void borrarCelda (Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve el número almacenado en la celda del tablero que ocupa la posición (fila, col).}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
int obtenerNum (Tablero t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve true si la celda del tablero que ocupa la posición (fila, col) está vacía
 	      y false en caso contrario}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool estaVacia (Tablero t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve true si la celda del tablero que ocupa la posición (fila, col) contiene
		  un número borrado y false si contiene un número sin borrar}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool estaBorrada (Tablero t, int fila, int col);




#endif /* TADTABLERO_H_ */
