/*
 * pr_tadCelda.cpp
 *
 *  Created on: 7 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#include "pr_tadCelda.h"

void pr_crearCelda() {
	cout << "Inicio pruebas crearCelda: "<<endl;
	Celda c1,c2,c3;

	crearCelda(c1,4);
	mostrarCelda(c1);

	crearCelda(c2,1);
	mostrarCelda(c2);

	crearCelda(c3,7);
	mostrarCelda(c3);

	cout << "Fin pruebas crearCelda: "<<endl;
}

void pr_crearCeldaVacia() {
	cout << "Inicio pruebas crearCeldaVacia: "<<endl;
	Celda c1,c2,c3;
	crearCeldaVacia(c1);
	if(c1.celdaVacia!=true)
		cout << "La celda  c1 no está vacía."<<endl;

	crearCeldaVacia(c2);
	if(c2.celdaVacia!=true)
			cout << "La celda  c2 no está vacía."<<endl;

	crearCeldaVacia(c3);
	if(c3.celdaVacia!=true)
			cout << "La celda c3 no está vacía."<<endl;

	cout << "Fin pruebas crearCeldaVacia: "<<endl;
}

void pr_borrarNumCelda() {
	cout << "Inicio pruebas borrarNumCelda: "<<endl;
	Celda c1,c2,c3;

	borrarNumCelda(c1);
	if(c1.borradaCelda != true)
		cout << "La celda  c1 no está borrada."<<endl;

	borrarNumCelda(c2);
	if(c2.borradaCelda != true)
			cout << "La celda  c2 no está borrada."<<endl;

	borrarNumCelda(c3);
	if(c3.borradaCelda != true)
			cout << "La celda c3 no está borrada."<<endl;

	cout << "Fin pruebas borrarNumCelda: "<<endl;
}

void pr_obtenerNumCelda() {
	cout << "Inicio pruebas obtenerNumCelda: "<<endl;
	Celda c1,c2,c3;

	crearCelda(c1,5);
	if(obtenerNumCelda(c1)!=5)
		cout << "Error al obtener el número de la celda c1."<<endl;

	crearCelda(c2,8);
	if(obtenerNumCelda(c2)!=8)
			cout << "Error al obtener el número de la celda c2."<<endl;

	crearCelda(c3,2);
	if(obtenerNumCelda(c3)!=2)
			cout << "Error al obtener el número de la celda c3."<<endl;

	cout << "Fin pruebas obtenerNumCelda: "<<endl;
}

void pr_esVaciaCelda() {
	cout << "Inicio pruebas esVaciaCelda: " << endl;
	Celda c1, c2, c3;

	crearCeldaVacia(c1);
	if (!esVaciaCelda(c1))
		cout << "La celda c1 no está vacía." << endl;

	crearCeldaVacia(c2);
	if (!esVaciaCelda(c2))
		cout << "La celda c2 no está vacía." << endl;

	crearCeldaVacia(c3);
	if (!esVaciaCelda(c3))
		cout << "La celda c3 no está vacía." << endl;

	cout << "Fin pruebas esVaciaCelda: " << endl;
}

void pr_esBorradaCelda() {
	cout << "Inicio pruebas esBorradaCelda: " << endl;
	Celda c1, c2, c3;

	crearCelda(c1, 5);
	if (esBorradaCelda(c1) != false)
		cout << "La celda c1 no está borrada." << endl;

	crearCelda(c2, 8);
	if (esBorradaCelda(c2) != false)
		cout << "La celda c2 no está borrada." << endl;

	crearCelda(c3, 2);
	if (esBorradaCelda(c3) != false)
		cout << "La celda c3 no está borrada." << endl;

	cout << "Fin pruebas esBorradaCelda: " << endl;
}

void pr_esSeleccionadaCelda(){
	cout << "Inicio pruebas esSeleccionadaCelda: " << endl;
	Celda c1, c2, c3;

	crearCelda(c1, 5);
	seleccionarCelda(c1);
	if (esSeleccionadaCelda(c1) != true)
		cout << "La celda c1 no está seleccionada." << endl;

	crearCelda(c2, 8);
	deseleccionarCelda(c2);
	if (esSeleccionadaCelda(c2) != false)
		cout << "La celda c2 está selccionada." << endl;

	crearCelda(c3, 2);
	seleccionarCelda(c3);
	if (esSeleccionadaCelda(c3) != true)
		cout << "La celda c3 no está seleccionada." << endl;

	cout << "Fin pruebas esSeleccionadaCelda: " << endl;
}

void pr_sonPareja() {
	cout << "Inicio pruebas sonPareja: " << endl;
	Celda c1, c2, c3,c4,c5,c6;

	crearCelda(c1, 5);
	crearCelda(c4,5);
	if (sonPareja(c1,c4) != true)
		cout << "Error al comprobar si c1 y c4 son pareja." << endl;

	crearCelda(c2, 8);
	crearCelda(c5,3);

	if (sonPareja(c2,c5) != false)
			cout << "Error al comprobar si c2 y c5 son pareja." << endl;

	crearCelda(c3, 2);
	crearCelda(c6, 2);
	if (sonPareja(c3,c6) != true)
			cout << "Error al comprobar si c3 y c6 son pareja." << endl;

	cout << "Fin pruebas sonPareja: " << endl;
}


void pruebasCelda() {
	cout << "Inicio pruebas celda: "<<endl;
	pr_crearCelda();
	pr_crearCeldaVacia();
	pr_borrarNumCelda();
	pr_obtenerNumCelda();
	pr_esVaciaCelda();
	pr_esBorradaCelda();
	pr_esSeleccionadaCelda();
	pr_sonPareja();
	cout << "Fin pruebas celda: "<<endl;
}




