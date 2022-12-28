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

void pruebasTablero();

#endif /* PR_TADTABLERO_H_ */
