/*
 * tadCelda.cpp
 *
 *  Created on: 6 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#include <iostream>
#include "tadCelda.h"
using namespace std;

void crearCelda(Celda &c, int num) {
	c.numero = num;
	c.borradaCelda = false;
	c.celdaVacia = false;
	c.celdaSeleccionada = false;
}

void crearCeldaVacia(Celda &c) {
	c.celdaVacia = true;
}

void borrarNumCelda(Celda &c) {
	c.borradaCelda = true;
}

void seleccionarCelda(Celda &c){
	c.celdaSeleccionada = true;
}

void deseleccionarCelda(Celda &c){
	c.celdaSeleccionada = false;
}

int obtenerNumCelda(Celda c) {
	return c.numero;
}

bool esVaciaCelda(Celda c) {
	return c.celdaVacia;
}

bool esBorradaCelda(Celda c) {
	return c.borradaCelda;
}

bool esSeleccionadaCelda(Celda c){
	return c.celdaSeleccionada;
}

bool sonPareja(Celda c1, Celda c2) {
	bool pareja = false;
	if (!c1.borradaCelda && !c2.borradaCelda && (c1.numero == c2.numero || c1.numero+c2.numero == 10)){
		pareja = true;
	}
	return pareja;
}

void mostrarCelda(Celda c) {
	cout << "Número: " << c.numero << " - Está vacía: " << c.celdaVacia << " - Está borrada: " << c.borradaCelda <<endl;
}
