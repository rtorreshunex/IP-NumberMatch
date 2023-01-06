///*
// * pr_tadTablero.cpp
// *
// *  Created on: 7 dic. 2022
// *      Author: Rubén Torres Gutiérrez y Paula Jiménez Cruz
// */
//
//#include "pr_tadTablero.h"
//
///*void pr_crearTablero() {
//    cout << "Inicio pruebas crearTablero" << endl;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//    crearTablero(t, fil, col, filIni);
//
//    // Estructura Tablero
//    if(t.n_filas != fil)
//        cout << "Número de filas incorrecto" << endl;
//    if(t.n_columnas != col)
//        cout << "Número de columnas incorrecto" << endl;
//    if(t.filas_iniciales != filIni)
//        cout << "Número de filas iniciales incorrecto" << endl;
//
//    // Contenido Tablero
//    for(int i = filIni; i < fil; i++)
//        for(int j = 0; j < col; j++)
//            if(obtenerNumCelda(t.vTablero[i][j]) > 0)
//                cout << "Número en celda [" + to_string(i) + "][" + to_string(j) + "] fuera de rango" << endl;
//
//    //HACER 1 O 2 EJEMPLOS MÁS
//
//    cout << "Fin pruebas crearTablero" << endl;
//}*/
//
//void pr_vaciarCelda() {
//    cout << "Inicio pruebas vaciarCelda" << endl;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//    //crearTablero(t, fil, col, filIni);
//
//    fil = 3;
//    col = 0;
//    vaciarCelda(t, fil, col);
//    if(!esVaciaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//    fil = 7;
//    col = 2;
//    vaciarCelda(t, fil, col);
//    if(!esVaciaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//    fil = 5;
//    col = 1;
//    vaciarCelda(t, fil, col);
//    if(!esVaciaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//
//    //HACER 1 O 2 EJEMPLOS MÁS
//
//    cout << "Fin pruebas vaciarCelda" << endl;
//}
//
//void pr_borrarCelda() {
//    cout << "Inicio pruebas borrarCelda" << endl;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//    //crearTablero(t, fil, col, filIni);
//
//    fil = 3;
//    col = 0;
//    borrarCelda(t, fil, col);
//    if(!esBorradaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    fil = 7;
//    col = 2;
//    borrarCelda(t, fil, col);
//    if(!esBorradaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    fil = 5;
//    col = 1;
//    borrarCelda(t, fil, col);
//    if(!esBorradaCelda(t.vTablero[fil][col]))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    cout << "Fin pruebas borrarCelda" << endl;
//}
//
//void pr_obtenerNum() {
//    cout << "Inicio pruebas obtenerNum" << endl;
//    int num;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//    //crearTablero(t, fil, col, filIni);
//
//    fil = 3;
//    col = 0;
//    num = 5;
//    crearCelda(t.vTablero[fil][col], num);
//    if(obtenerNum(t, fil, col) != num)
//        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
//    fil = 7;
//    col = 2;
//    num = 6;
//    crearCelda(t.vTablero[fil][col], num);
//    if(obtenerNum(t, fil, col) != num)
//        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
//    fil = 5;
//    col = 1;
//    num = 8;
//    crearCelda(t.vTablero[fil][col], num);
//    if(obtenerNum(t, fil, col) != num)
//        cout << "Número de celda [" + to_string(fil) + "][" + to_string(col) + "] incorrecto" << endl;
//    cout << "Fin pruebas obtenerNum" << endl;
//}
//
//void pr_estaVacia() {
//    cout << "Inicio pruebas estaVacia" << endl;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//    //crearTablero(t, fil, col, filIni);
//
//    fil = 3;
//    col = 0;
//    crearCeldaVacia(t.vTablero[fil][col]);
//    if(!estaVacia(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//    fil = 7;
//    col = 2;
//    crearCeldaVacia(t.vTablero[fil][col]);
//    if(!estaVacia(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//    fil = 5;
//    col = 1;
//    crearCeldaVacia(t.vTablero[fil][col]);
//    if(!estaVacia(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no vacía" << endl;
//    cout << "Fin pruebas estaVacia" << endl;
//}
//
//void pr_estaBorrada() {
//    cout << "Inicio pruebas estaBorrada" << endl;
//    int fil = 9;
//    int col = 5;
//    int filIni = 4;
//    Tablero t;
//   // crearTablero(t, fil, col, filIni);
//
//    fil = 3;
//    col = 0;
//    borrarNumCelda(t.vTablero[fil][col]);
//    if(!estaBorrada(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    fil = 7;
//    col = 2;
//    borrarNumCelda(t.vTablero[fil][col]);
//    if(!estaBorrada(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    fil = 5;
//    col = 1;
//    borrarNumCelda(t.vTablero[fil][col]);
//    if(!estaBorrada(t, fil, col))
//        cout << "Celda [" + to_string(fil) + "][" + to_string(col) + "] no borrada" << endl;
//    cout << "Fin pruebas estaBorrada" << endl;
//}
//
//void pruebasTablero() {
//    cout << "Inicio pruebas Tablero" << endl;
//  //  pr_crearTablero();
//    pr_vaciarCelda();
//    pr_borrarCelda();
//    pr_obtenerNum();
//    pr_estaVacia();
//    pr_estaBorrada();
//    cout << "Fin pruebas Tablero" << endl;
//}
//
//
//
//
