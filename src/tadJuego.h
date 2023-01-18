/*
 * tadJuego.h
 *
 *  Created on: Dec 28, 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include <iostream>
#include "tadTablero.h"
#include "entorno.h"
using namespace std;

struct tadJuego {
	Tablero tablero;
	int puntuacion;
	bool celdaSelec;
	int fSelec;
	int cSelec;
	int maxReplicas;
};


/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo}
 * DESCRIPCIÓN: Inicia la estructura de datos del juego, según la configuración del fichero match.cnf
 * COMPL: O (1)
 */
void iniciar(tadJuego &j);

/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo}
 * DESCRIPCIÓN: Realiza la gestión general del juego (gestionar las teclas que se pulsen, actualizar el tablero y la pantalla, dar el juego por finalizado, etc.)
 * COMPL: O (n)
 */
void jugar(tadJuego &j);

/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo}
 * DESCRIPCIÓN: Actualiza el entorno del juego.
 * COMPL: O (n²)
 */
void actualizarEntorno(tadJuego &j);

/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo}
 * DESCRIPCIÓN: Se encarga del funcionamiento a la hora de replicar las filas del juego.
 * COMPL: O (1)
 */
void funcionamientoReplicas(tadJuego &j);

/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo, devuelve la puntuación al borrarse una fila.}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
int filaBorrada(tadJuego &j, int fila);

/*
 * PRE: {j debe estar correctamente inicializada}
 * POST: {j se modifica después de ejecutar este módulo}
 * DESCRIPCIÓN: Se encarga del funcionamiento de la tecla enter a la hora de jugar
 * COMPL: O (1)
 */
void funcionamientoEnter(tadJuego &j, int fila, int col);

/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN: Termina el juego, mostrando un mensaje de despedida y cerrando el entorno gráfico.
 * COMPL: O(1)
 */
void terminar(string msg);

#endif /* TADJUEGO_H_ */
