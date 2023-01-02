/*
 * tadJuego.cpp
 *
 *  Created on: Dec 28, 2022
 *      Author: ruben
 */

#include <iostream>
#include "tadJuego.h"
using namespace std;

void iniciar(){
	int fil, col, filas_iniciales, maxReplicas, maxAyudas, deDonde;
	int m[MAX_FILAS][MAX_COLUMNAS];

	if(entornoCargarConfiguracion(fil, col, filas_iniciales, maxReplicas, maxAyudas, deDonde, m)){
		entornoIniciar(fil, col);

		int fila, columna;
		for ( fila = 0; fila < fil; fila++) {
			for ( columna = 0; columna < col; columna++) {
				if (fila % 2 ==0)
					entornoActivarNumero(fila, columna, m[fila][columna]);
				else entornoDesactivarNumero(fila, columna, m[fila][columna]);
			}
		}
		jugar(fila, columna, col, fil, filas_iniciales);
	}
}

void jugar(int fila, int col, int numColumnas, int numFilas, int filasIniciales){
	bool salir = false; //bandera utilizada para finalizar el bucle
	TipoTecla tecla;    //almacena la tecla pulsada por el usuario
	int puntos = 0;

	fila = 0;
	col  = 0;
	entornoMarcarPosicion(fila,col);
	entornoPonerPuntuacion (puntos,0);
	entornoMostrarMensaje("Pulsa ESC para salir",1.5);
	entornoMostrarMensaje("Pulsa F1 para aumentar puntuacion",1.5);
	entornoMostrarMensaje("Pulsa F2 para eliminar algunos números",1.5);
	//el bucle permite al jugador desplazarse por el tablero de juego
	while (!salir) {
		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:
			entornoSeleccionarPosicion(fila,col);
			entornoPausa (0.5);
			entornoDeseleccionarPosicion (fila,col);
			break;
		case TDerecha:
			entornoDesmarcarPosicion(fila, col);
			if (col < numColumnas - 1)
					col++;
			else
					col = 0;
			entornoMarcarPosicion(fila, col);
			break;
		case TIzquierda:
			entornoDesmarcarPosicion(fila, col);
			if (col > 0)
				col--;
			else
				col = numColumnas - 1;
			entornoMarcarPosicion(fila, col);
			break;
		case TArriba:
			entornoDesmarcarPosicion(fila, col);
			if (fila > 0)
				fila--;
			else
				fila = numFilas - 1;
			entornoMarcarPosicion(fila, col);
			break;
		case TAbajo:
			entornoDesmarcarPosicion(fila, col);
			if (fila < numFilas - 1)
				fila++;
			else
				fila = 0;
			entornoMarcarPosicion(fila, col);
			break;

		case TF1:
			puntos = puntos + 10;
			entornoPonerPuntuacion(puntos,10);
			break;
		case TF2:
			for (int i = 0; i < filasIniciales; i++) {

						entornoPonerVacio(i,i);
						entornoPausa(0.5);
					}
			break;
		case TSalir:
			salir = true;
			break;

		case TNada:
			break;
		} //Fin de switch
	}//Fin de while
	terminar();
}

void terminar(){
	entornoMostrarMensajeFin("¡¡¡¡Adios!!!!");
	entornoTerminar();
}
