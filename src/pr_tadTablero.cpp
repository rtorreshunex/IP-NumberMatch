/*
 * pr_tadTablero.cpp
 *
 *  Created on: 7 dic. 2022
 *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
 */

#include "pr_tadTablero.h"

void rellenarMatriz(int m[MAX_FIL][MAX_COL]){
  for (int i = 0; i < MAX_FIL; i++)
    for (int j = 0; j < MAX_COL; j++)
      m[i][j] = rand() % 9 + 1;
}

void pr_crearTablero() {
    cout << "Inicio pruebas crearTablero" << endl;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    int m[MAX_FIL][MAX_COL];
    rellenarMatriz(m);
    Tablero t;
    crearTablero(t, fil, col, filIni,m);

    // Estructura Tablero
    if(t.n_filas != fil)
        cout << "Número de filas incorrecto" << endl;
    if(t.n_columnas != col)
        cout << "Número de columnas incorrecto" << endl;
    if(t.filas_iniciales != filIni)
        cout << "Número de filas iniciales incorrecto" << endl;

    // Celdas fuera de rango
    for(int i = filIni; i < fil; i++)
        for(int j = 0; j < col; j++)
            if(!estaVacia(t, i, j))
                cout << "Número en celda [" + to_string(i) + "][" + to_string(j) + "] fuera de rango" << endl;

    // Contenido tablero
    for(int i = 0; i < fil; i++)
    	for(int j = 0; j < col; j++)
    		mostrarCelda(t.vTablero[i][j]);


    fil = 7;
	col = 8;
	filIni = 3;
	crearTablero(t, fil, col, filIni, m);

	// Estructura Tablero
	if (t.n_filas != fil)
		cout << "Número de filas incorrecto" << endl;
	if (t.n_columnas != col)
		cout << "Número de columnas incorrecto" << endl;
	if (t.filas_iniciales != filIni)
		cout << "Número de filas iniciales incorrecto" << endl;

	// Celdas fuera de rango
	for(int i = filIni; i < fil; i++)
		for(int j = 0; j < col; j++)
			if(!estaVacia(t, i, j))
				cout << "Número en celda [" + to_string(i) + "][" + to_string(j) + "] fuera de rango" << endl;

	// Contenido tablero
	for(int i = 0; i < fil; i++)
		for(int j = 0; j < col; j++)
			mostrarCelda(t.vTablero[i][j]);


	fil = 10;
	col = 6;
	filIni = 2;

	crearTablero(t, fil, col, filIni, m);

	// Estructura Tablero
	if (t.n_filas != fil)
		cout << "Número de filas incorrecto" << endl;
	if (t.n_columnas != col)
		cout << "Número de columnas incorrecto" << endl;
	if (t.filas_iniciales != filIni)
		cout << "Número de filas iniciales incorrecto" << endl;

	// Celdas fuera de rango
	for(int i = filIni; i < fil; i++)
		for(int j = 0; j < col; j++)
			if(!estaVacia(t, i, j))
				cout << "Número en celda [" + to_string(i) + "][" + to_string(j) + "] fuera de rango" << endl;

	// Contenido tablero
	for(int i = 0; i < fil; i++)
		for(int j = 0; j < col; j++)
			mostrarCelda(t.vTablero[i][j]);

    cout << "Fin pruebas crearTablero" << endl;
}

void pr_crearTableroAleatorio(){
	cout << "Inicio pruebas crearTableroAleatorio" << endl;
	int fil = 9;
	int col = 5;
	int filIni = 4;
	int m[MAX_FIL][MAX_COL];
	rellenarMatriz(m);
	Tablero t;
	crearTableroAleatorio(t, fil, col, filIni);

	// Estructura Tablero
	if (t.n_filas != fil)
		cout << "Número de filas incorrecto" << endl;
	if (t.n_columnas != col)
		cout << "Número de columnas incorrecto" << endl;
	if (t.filas_iniciales != filIni)
		cout << "Número de filas iniciales incorrecto" << endl;

	// Celdas fuera de rango
	for(int i = filIni; i < fil; i++)
		for(int j = 0; j < col; j++)
			if(!estaVacia(t, i, j))
				cout << "Número en celda [" + to_string(i) + "][" + to_string(j) + "] fuera de rango" << endl;

	// Contenido tablero
	for(int i = 0; i < fil; i++)
		for(int j = 0; j < col; j++)
			mostrarCelda(t.vTablero[i][j]);

	cout << "Fin pruebas crearTableroAleatorio" << endl;
}

void pr_vaciarCelda() {
    cout << "Inicio pruebas vaciarCelda" << endl;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    int m [MAX_FIL][MAX_COL];
    Tablero t;
    crearTablero(t, fil, col, filIni,m);

    fil = 3;
    col = 0;
    vaciarCelda(t, fil, col);
    if(!esVaciaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;

    fil = 7;
    col = 2;
    vaciarCelda(t, fil, col);
    if(!esVaciaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;

    fil = 5;
    col = 1;
    vaciarCelda(t, fil, col);
    if(!esVaciaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;



    cout << "Fin pruebas vaciarCelda" << endl;
}

void pr_borrarCelda() {
    cout << "Inicio pruebas borrarCelda" << endl;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    Tablero t;
    //crearTablero(t, fil, col, filIni);

    fil = 3;
    col = 0;
    borrarCelda(t, fil, col);
    if(!esBorradaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    fil = 7;
    col = 2;
    borrarCelda(t, fil, col);
    if(!esBorradaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    fil = 5;
    col = 1;
    borrarCelda(t, fil, col);
    if(!esBorradaCelda(t.vTablero[fil][col]))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    cout << "Fin pruebas borrarCelda" << endl;
}

void pr_obtenerNum() {
    cout << "Inicio pruebas obtenerNum" << endl;
    int num;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    Tablero t;
    //crearTablero(t, fil, col, filIni);

    fil = 3;
    col = 0;
    num = 5;
    crearCelda(t.vTablero[fil][col], num);
    if(obtenerNum(t, fil, col) != num)
        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
    fil = 7;
    col = 2;
    num = 6;
    crearCelda(t.vTablero[fil][col], num);
    if(obtenerNum(t, fil, col) != num)
        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
    fil = 5;
    col = 1;
    num = 8;
    crearCelda(t.vTablero[fil][col], num);
    if(obtenerNum(t, fil, col) != num)
        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
    cout << "Fin pruebas obtenerNum" << endl;
}

void pr_estaVacia() {
    cout << "Inicio pruebas estaVacia" << endl;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    Tablero t;
    //crearTablero(t, fil, col, filIni);

    fil = 3;
    col = 0;
    crearCeldaVacia(t.vTablero[fil][col]);
    if(!estaVacia(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
    fil = 7;
    col = 2;
    crearCeldaVacia(t.vTablero[fil][col]);
    if(!estaVacia(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
    fil = 5;
    col = 1;
    crearCeldaVacia(t.vTablero[fil][col]);
    if(!estaVacia(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
    cout << "Fin pruebas estaVacia" << endl;
}

void pr_estaBorrada() {
    cout << "Inicio pruebas estaBorrada" << endl;
    int fil = 9;
    int col = 5;
    int filIni = 4;
    Tablero t;
   // crearTablero(t, fil, col, filIni);

    fil = 3;
    col = 0;
    borrarNumCelda(t.vTablero[fil][col]);
    if(!estaBorrada(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    fil = 7;
    col = 2;
    borrarNumCelda(t.vTablero[fil][col]);
    if(!estaBorrada(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    fil = 5;
    col = 1;
    borrarNumCelda(t.vTablero[fil][col]);
    if(!estaBorrada(t, fil, col))
        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
    cout << "Fin pruebas estaBorrada" << endl;
}

void pr_estaSeleccionada(){

}

void pr_estaBorradaFila(){

}

void pr_borrarInfoFila(){

}

void pr_sonParejasCeldas(){

}

void pruebasTablero() {
    cout << "Inicio pruebas Tablero" << endl;
    pr_crearTablero();
    pr_vaciarCelda();
    pr_borrarCelda();
    pr_obtenerNum();
    pr_estaVacia();
    pr_estaBorrada();
    cout << "Fin pruebas Tablero" << endl;
}
