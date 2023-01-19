/*
 * tadJuego.cpp
 *
 *  Created on: Dec 28, 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#include <iostream>
#include "tadJuego.h"
using namespace std;

void jugar(tadJuego &j){
	bool salir = false; //bandera utilizada para finalizar el bucle
	TipoTecla tecla;    //almacena la tecla pulsada por el usuario

	int numFilas,numColumnas;
	int fila = 0;
	int col  = 0;
	entornoMarcarPosicion(fila,col);
	entornoPonerPuntuacion (j.puntuacion, 0);
	//el bucle permite al jugador desplazarse por el tablero de juego
	devolverNumFilasYCol(j.tablero,numFilas,numColumnas);
	while (!salir) {
		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:
			funcionamientoEnter(j, fila, col);
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
			if(j.maxReplicas > 0){
				j.maxReplicas--;
				funcionamientoReplicas(j);
			} else terminar("Réplicas agotadas");
			break;
		case TF2:
		/*	if(maxAyudas > 0){
				maxAyudas--;
				for (int i = 0; i < filasIniciales; i++) {
					entornoPonerVacio(i,i);
					entornoPausa(0.5);
				}
			} else entornoMostrarMensaje("No quedan más ayudas", 0.5);*/
			break;
		case TSalir:
			salir = true;
			break;

		case TNada:
			break;
		} //Fin de switch
	}//Fin de while
	terminar("Has abandonado");
}

void actualizarEntorno(tadJuego &j){
	int fil,col,fil_ult,col_ult;
	devolverNumFilasYCol(j.tablero,fil,col);
	obtenerUltCelda(j.tablero,fil_ult,col_ult);
	for ( int fila = 0; fila < fil; fila++) {
		for ( int columna = 0; columna < col; columna++) {
			if (fila < fil_ult || (fila == fil_ult && columna <= col_ult)){
				entornoPonerVacio(fila, columna);
				entornoActivarNumero(fila, columna, obtenerNum(j.tablero, fila, columna));
				if(estaBorrada(j.tablero, fila, columna))
					entornoDesactivarNumero(fila, columna, obtenerNum(j.tablero, fila, columna));
			}else
				entornoPonerVacio(fila, columna);
		}
	}
}

void funcionamientoReplicas(tadJuego &j){
	int fil, col, fil_ult, col_ult;
	devolverNumFilasYCol(j.tablero, fil, col);
	replCeldNoBorr(j.tablero);
	if(obtenerCeldasUtiles(j.tablero) <= (fil * col)){
		obtenerUltCelda(j.tablero, fil_ult, col_ult);
		actualizarEntorno(j);
	}
	else
		terminar("Los datos no caben");
}

int filaBorrada(tadJuego &j, int fila){
	int filas, columnas;
	int puntuacion = 0;
	devolverNumFilasYCol(j.tablero, filas, columnas);
	if(estaBorradaFila(j.tablero, fila)){
		borrarInfoFila(j.tablero, fila);
		puntuacion += 10;
		actualizarEntorno(j);
	}
	if(fila != j.fSelec && estaBorradaFila(j.tablero, j.fSelec)){
		borrarInfoFila(j.tablero, j.fSelec);
		puntuacion += 10;
		actualizarEntorno(j);
	}
	return puntuacion;
}

void funcionamientoEnter(tadJuego &j, int fila, int col){

	if(!estaVacia(j.tablero, fila, col) && !estaBorrada(j.tablero, fila, col) && !estaSeleccionada(j.tablero, fila, col)){
		seleccionarCelda(j.tablero, fila, col);
		entornoSeleccionarPosicion(fila,col);
		if(!j.celdaSelec){
			j.fSelec = fila;
			j.cSelec = col;
			j.celdaSelec = true;
		} else {
			if(sonParejaCeldas(j.tablero, fila, col, j.fSelec, j.cSelec) || sonParejaSeparadas(j.tablero, fila, col, j.fSelec, j.cSelec)){
				int puntos;
				if(sonParejaCeldas(j.tablero, fila, col, j.fSelec, j.cSelec))
					puntos = 1;
				else puntos = 4;
				// Borrar las 2 celdas
				borrarCelda(j.tablero, fila, col);
				entornoDesactivarNumero(fila, col, obtenerNum(j.tablero, fila, col));
				borrarCelda(j.tablero, j.fSelec, j.cSelec);
				entornoDesactivarNumero(j.fSelec, j.cSelec, obtenerNum(j.tablero, j.fSelec, j.cSelec));
				// Actualizar celdas útiles
				ponerCeldasUtiles(j.tablero, obtenerCeldasUtiles(j.tablero) - 2);
				//Comprobar celdas útiles
				if(obtenerCeldasUtiles(j.tablero) <= 0)
					terminar("Has Ganado!!!");
				// Borrar filas
				int puntuacion = filaBorrada(j, fila);
				// Actualizar puntuación
				j.puntuacion += (puntuacion + puntos);
				entornoPonerPuntuacion(j.puntuacion, (puntuacion + puntos));
			}else
				entornoPausa(0.5);
			j.celdaSelec = false;
			deseleccionarCelda(j.tablero, fila, col);
			entornoDeseleccionarPosicion (fila,col);
			deseleccionarCelda(j.tablero, j.fSelec, j.cSelec);
			entornoDeseleccionarPosicion (j.fSelec, j.cSelec);
		}
	}else{
		j.celdaSelec = false;
		deseleccionarCelda(j.tablero, fila, col);
		entornoDeseleccionarPosicion (fila,col);
	}

}

void iniciar(tadJuego &j){
	int fil, col, filas_iniciales, maxAyudas, deDonde;
	int m[MAX_FILAS][MAX_COLUMNAS];
	j.puntuacion = 0;
	j.celdaSelec = false;

	if(entornoCargarConfiguracion(fil, col, filas_iniciales, j.maxReplicas, maxAyudas, deDonde, m)){
		entornoIniciar(fil, col);
		if (deDonde==0){
			crearTablero(j.tablero, fil, col, filas_iniciales, m);}
		else{
			crearTableroAleatorio(j.tablero, fil, col, filas_iniciales);
		}
		actualizarEntorno(j);
	}
}

void terminar(string msg){
	entornoMostrarMensajeFin(msg);
	entornoTerminar();
}
