/*
 * pr_tadTablero.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#ifndef PR_TADTABLERO_H_
#define PR_TADTABLERO_H_

#include "tadTablero.h"

/*
 * DESCRIPCIÓN: muestra el tablero después de ser creado
 */
void pr_crearTablero();

/*
 * DESCRIPCIÓN: muestra el tablero después de ser creado
 */
void pr_crearTableroAleatorio();

/*
 * DESCRIPCIÓN: muestra el tablero modificado después de vaciar una celda determinada por [fil][col]
 */
void pr_vaciarCelda();

/*
 * DESCRIPCIÓN: muestra el tablero modificado después de borrar una celda determinada por [fil][col]
 */
void pr_borrarCelda();

/*
 * DESCRIPCIÓN: muestra el número de la celda de la posición [fil][col]
 */
void pr_obtenerNum();

/*
 * DESCRIPCIÓN: muestra si la celda de la posición [fil][col] está vacía o no
 */
void pr_estaVacia();

/*
 * DESCRIPCIÓN: muestra si la celda de la posición [fil][col] está borrada o no
 */
void pr_estaBorrada();

/*
 * DESCRIPCIÓN: muestra si la celda de la posición [fil][col] está seleccionada o no.
 */
void pr_estaSeleccionada();

/*
 * DESCRIPCIÓN: muestra si la fila está borrada.
 */
void pr_estaBorradaFila();

/*
 * DESCRIPCIÓN: muestra si la información de la fila está borrada.
 */
void pr_borrarInfoFila();

/*
 * DESCRIPCIÓN: muestra si la información de 2 celdas diferentes hacen pareja o no.
 */
void pr_sonParejaCeldas();

/*
 * DESCRIPCIÓN: engloba a las llamadas a los módulos de pruebas.
 */
void pruebasTablero();

#endif /* PR_TADTABLERO_H_ */
