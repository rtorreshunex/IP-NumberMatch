/*
 * tadJuego.cpp
 *
 *  Created on: Dec 28, 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#include <iostream>
#include "tadJuego.h"
using namespace std;

void iniciar(){
	int fil, col, filas_iniciales, maxReplicas, maxAyudas, deDonde;
	int m[MAX_FILAS][MAX_COLUMNAS];
	Tablero t;

	if(entornoCargarConfiguracion(fil, col, filas_iniciales, maxReplicas, maxAyudas, deDonde, m)){
		entornoIniciar(fil, col);

		int fila, columna;
		for ( fila = 0; fila < fil; fila++) {
			for ( columna = 0; columna < col; columna++) {
				ponerValorCeldaConc(t, m[fila][columna], fila, columna);
				if (fila < filas_iniciales){
					entornoActivarNumero(fila, columna, m[fila][columna]);
				}else{
					entornoPonerVacio(fila, columna);
					vaciarCelda(t, fila, columna);
				}
			}
		}
		jugar(t, fila, columna, col, fil, filas_iniciales, maxReplicas, maxAyudas);
	}
}

void jugar(Tablero t, int fila, int col, int numColumnas, int numFilas, int filasIniciales, int maxReplicas, int maxAyudas){
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
			if(!estaVacia(t, fila, col) && !estaBorrada(t, fila, col) && !estaSeleccionada(t, fila, col)){
				seleccionarCelda(t, fila, col);
				entornoSeleccionarPosicion(fila,col);
			}else{
				deseleccionarCelda(t, fila, col);
				entornoDeseleccionarPosicion (fila,col);
			}
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
			if(maxReplicas > 0){
				maxReplicas--;
				puntos += 10;
				entornoPonerPuntuacion(puntos,10);
			} else entornoMostrarMensaje("No quedan más réplicas", 0.5);
			break;
		case TF2:
			if(maxAyudas > 0){
				maxAyudas--;
				for (int i = 0; i < filasIniciales; i++) {
					entornoPonerVacio(i,i);
					entornoPausa(0.5);
				}
			} else entornoMostrarMensaje("No quedan más ayudas", 0.5);
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

void comprobarEmparejamiento(int fila1, int col1, int fila2, int col2){

}

void terminar(){
	entornoMostrarMensajeFin("¡¡¡¡Adios!!!!");
	entornoTerminar();
}
