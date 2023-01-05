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
};


/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN: Inicia la estructura de datos del juego, según la configuración del fichero match.cnf
 * COMPL:
 */
void iniciar();

/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN: Realiza la gestión general del juego (gestionar las teclas que se pulsen, actualizar el tablero y la pantalla, dar el juego por finalizado, etc.)
 * COMPL:
 */
void jugar(tadJuego &j, int fila, int col, int numColumnas, int numFilas, int filasIniciales, int maxReplicas, int maxAyudas);

/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN:
 * COMPL:
 */
void funcionamientoReplicas(tadJuego &j);

/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN:
 * COMPL:
 */
void funcionamientoEnter(tadJuego &j, int fila, int col);

/*
 * PRE: {}
 * POST: {}
 * DESCRIPCIÓN: Termina el juego, mostrando un mensaje de despedida y cerrando el entorno gráfico.
 * COMPL:
 */
void terminar(string msg);

#endif /* TADJUEGO_H_ */
