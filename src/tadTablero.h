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
	int fil_ult;
	int col_ult;
	int celdas_utiles;
};

/*
 * PRE: {1 <= filas <= 12; 1 <= columnas <= 9; filasIniciales <= filas;
 * 		t debe estar correctamente inicializada}
 * POST:
 * DESCRIPCIÓN: Crea un tablero de dimensión filas * columnas en el que las primeras filas (filasIniciales) contienen
 * números (con valores entre 1 y 9) generados aleatoriamente. El resto de las filas están vacías.
 * COMPL: O (n²)
 */
void crearTablero (Tablero &t, int filas, int columnas, int filasIniciales,int celdasUtiles, int filUlt, int colUlt);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DECRIPCIÓN: Devuelve el número de filas y de columnas
 * COMPL: O (1)
 */
void devolverNumFilasYCol (Tablero t, int &filas, int &columnas);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DECRIPCIÓN: Devuelve las coordenadas de la última celda ocupada.
 * COMPL: O (1)
 */
void devolverCoordenadasCeldaOcup (Tablero t, int &filas, int &columnas);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Vacía la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void vaciarCelda (Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Marca como borrada la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void borrarCelda (Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Marca como seleccionada la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void seleccionarCelda(Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Marca como NO seleccionada la celda del tablero que ocupa la posición (fila, col).
 * COMPL: O (1)
 */
void deseleccionarCelda(Tablero &t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve el número almacenado en la celda del tablero que ocupa la posición (fila, col).}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
int obtenerNum (Tablero t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve el número de celdas útiles que hay en el tablero.}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
int obtenerCeldasUtiles(Tablero t);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve la posición de la última celda.}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
void obtenerUltCelda(Tablero t, int &fila, int &col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Pone en el atributo celdas_utiles el número recibido como parámetro.}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
void ponerCeldasUtiles(Tablero &t, int num);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Pone un valor en una celda concreta del tablero.
 * COMPL: O (1)
 */
void ponerValorCeldaConc(Tablero &t, int num, int fila, int col);

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

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve true si la celda del tablero que ocupa la posición (fila, col) esá
		  seleccionada y false si no lo está}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool estaSeleccionada(Tablero t, int fila, int col);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve true si la fila tiene todas sus celdas borradas, false en caso contrario.}
 * DESCRIPCIÓN: Comprueba si una fila tiene todas sus celdas borradas.
 * COMPL: O (n)
 */
bool estaBorradaFila(Tablero t, int fila);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Borra la información de una fila.
 * COMPL: O (n)
 */
void borrarInfoFila(Tablero &t, int fila);

/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST:
 * DESCRIPCIÓN: Replica las celdas no borradas em el tablero
 * COMPL: O ()
 */
void replCeldNoBorr(Tablero &t);


/*
 * PRE: {t debe estar correctamente inicializada.}
 * POST: {Devuelve true si las celdas son pareja y false si no lo son}
 * DESCRIPCIÓN:
 * COMPL: O ()
 */
bool sonParejaCeldas(Tablero t, int fila1, int col1, int fila2, int col2);


#endif /* TADTABLERO_H_ */
