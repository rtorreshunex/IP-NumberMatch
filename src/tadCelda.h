/*
 * tadCelda.h
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#ifndef TADCELDA_H_
#define TADCELDA_H_

#include <iostream>
using namespace std;

struct Celda {
	int numero;
	bool celdaVacia;
	bool borradaCelda;

};

/*
 * PRE: {1 <= num <= 9; c debe estar correctamente inicializada.}
 * POST: {}
 * DESCRIPCIÓN: Crea una nueva celda que contiene un número
 * COMPL:
 */
void crearCelda (Celda &c,int num);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {}
 * DESCRIPCIÓN: Crea una nueva celda vacía.
 * COMPL: O (1)
 */
void crearCeldaVacia(Celda &c);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {}
 * DESCRIPCIÓN: Marca cómo “borrado” el número almacenado en la celda
 * COMPL: O (1)
 */
void borrarNumCelda(Celda &c);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {Devuelve el número almacenado en la celda c}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
int obtenerNumCelda (Celda c);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {Devuelve true si la celda está vacía y false en caso contrario.}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool esVaciaCelda (Celda c);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {Devuelve true si la celda contiene un número borrado y false si contiene un número sin borrar}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool esBorradaCelda (Celda c);

/*
 * PRE: {c debe estar correctamente inicializada.}
 * POST: {Devuelve true si las celdas c1 y c2 pueden formar pareja, es decir, contienen
		  números no borrados, que son iguales o que suman 10}
 * DESCRIPCIÓN:
 * COMPL: O (1)
 */
bool sonPareja (Celda c1, Celda c2);

/*
 * PRE:
 * POST:
 * DESCRIPCIÓN: Muestra la información de la celda
 * COMPL: O (1)
 */
void mostrarCelda(Celda c);


#endif /* TADCELDA_H_ */
