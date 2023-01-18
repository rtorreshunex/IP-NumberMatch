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
    Tablero t;
    crearTableroAleatorio(t, fil, col, filIni);

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
    crearTableroAleatorio(t, fil, col, filIni);

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
    crearTableroAleatorio(t, fil, col, filIni);

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
    crearTableroAleatorio(t, fil, col, filIni);

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
   crearTableroAleatorio(t, fil, col, filIni);

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
	cout << "Inicio pruebas estaSeleccionada" << endl;
	int fil = 9;
	int col = 5;
	int filIni = 4;
	int m [MAX_FIL][MAX_COL];
	Tablero t;
	crearTablero(t, fil, col, filIni,m);

	fil = 3;
	col = 0;
	seleccionarCelda(t,fil,col);
	if (estaSeleccionada(t,fil,col)!=true)
		cout
				<< "Celda [" + to_string(fil) + "][" + to_string(col)
						+ "] no seleccionada" << endl;
	fil = 7;
	col = 2;
	deseleccionarCelda(t,fil,col);
	if (estaSeleccionada(t,fil,col)!=false)
		cout
				<< "Celda [" + to_string(fil) + "][" + to_string(col)
						+ "] seleccionada" << endl;
	fil = 5;
	col = 1;
	seleccionarCelda(t,fil,col);
	if (estaSeleccionada(t,fil,col)!=true)
		cout
				<< "Celda [" + to_string(fil) + "][" + to_string(col)
						+ "] no seleccionada" << endl;

	cout << "Fin pruebas estaSeleccionada" << endl;
}

void pr_estaBorradaFila(){
	cout << "Inicio pruebas estaBorradaFila" << endl;
	int fil = 9;
	int col = 5;
	int filIni = 4;
	int filaBor = 2;
	Tablero t;
	crearTableroAleatorio(t, fil, col, filIni);
	for(int i = 0; i < col; i++)
		borrarCelda(t, filaBor, i);
	if (!estaBorradaFila(t, filaBor))
		cout << "Fila " + to_string(filaBor) + " no borrada"<< endl;

	fil = 7;
	col = 2;
	filIni = 4;
	filaBor = 3;
	crearTableroAleatorio(t,fil,col,filIni);
	for(int i = 0; i < col; i++)
		borrarCelda(t, filaBor, i);
	if (!estaBorradaFila(t, filaBor))
		cout << "Fila " + to_string(filaBor) + " no borrada"<< endl;

	fil = 5;
	col = 1;
	filIni = 3;
	filaBor = 2;
	crearTableroAleatorio (t,fil,col,filIni);
	for(int i = 0; i < col; i++)
		borrarCelda(t, filaBor, i);
	if (!estaBorradaFila(t, filaBor))
		cout << "Fila " + to_string(filaBor) + " no borrada"<< endl;

	cout << "Fin pruebas estaBorradaFila" << endl;
}

void pr_borrarInfoFila(){
	cout << "Inicio pruebas borrarInfoFila" << endl;
	int fil = 9;
	int col = 5;
	int filIni = 4;
	Tablero t;
	crearTableroAleatorio(t, fil, col, filIni);

	// Prueba 1
	int filaBor = 2;
	int filUlt = t.fil_ult;
	borrarInfoFila(t, filaBor);
	if (filUlt == t.fil_ult)
		cout << "Fila " + to_string(filaBor) + " no borrada" << endl;

	filaBor = 3;
	filUlt = t.fil_ult;
	borrarInfoFila(t, filaBor);
	if (filUlt == t.fil_ult)
		cout << "Fila " + to_string(filaBor) + " no borrada" << endl;

	filaBor = 1;
	filUlt = t.fil_ult;
	borrarInfoFila(t, filaBor);
	if (filUlt == t.fil_ult)
		cout << "Fila " + to_string(filaBor) + " no borrada" << endl;

	cout << "Fin pruebas borrarInfoFila" << endl;
}

void pr_sonParejaCeldas(){
	cout << "Inicio pruebas sonParejaCeldas" << endl;
	int fil = 9;
	int col = 5;
	int filIni = 4;
	Tablero t;
	crearTableroAleatorio(t, fil, col, filIni);

	crearCelda(t.vTablero[2][4],4);
	crearCelda(t.vTablero[2][3],4);
	if(sonParejaCeldas(t,2,4,2,3)!=true)
		cout << "No hacen pareja" << endl;

	fil = 10;
	col = 6;
	filIni = 4;
	crearTableroAleatorio(t,fil,col,filIni);
	crearCelda(t.vTablero[0][5], 8);
	crearCelda(t.vTablero[1][0], 2);
	if (sonParejaCeldas(t, 0, 5, 1, 0) != true)
		cout << "No hacen pareja" << endl;

	fil = 8;
	col = 6;
	filIni = 5;
	crearTableroAleatorio(t,fil,col,filIni);
	crearCelda(t.vTablero[3][4], 3);
	crearCelda(t.vTablero[4][4], 5);
	if (sonParejaCeldas(t, 3, 4, 2, 3) != false)
		cout << "No hacen pareja" << endl;

	fil = 12;
	col = 9;
	filIni = 6;
	crearTableroAleatorio(t,fil,col,filIni);
	crearCelda(t.vTablero[4][2], 6);
	crearCelda(t.vTablero[5][1], 7);
	if (sonParejaCeldas(t, 5, 1, 2, 1) != false)
		cout << "No hacen pareja" << endl;


	cout << "Fin pruebas sonParejaCeldas" << endl;
}

void pruebasTablero() {
    cout << "Inicio pruebas Tablero" << endl;
    pr_crearTablero();
    pr_crearTableroAleatorio();
    pr_vaciarCelda();
    pr_borrarCelda();
    pr_obtenerNum();
    pr_estaVacia();
    pr_estaBorrada();
    pr_estaSeleccionada();
    pr_estaBorradaFila();
    pr_borrarInfoFila();
    pr_sonParejaCeldas();
    cout << "Fin pruebas Tablero" << endl;
}
