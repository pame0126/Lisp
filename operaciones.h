
#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "funciones.h"


/*Asignacion de punteros funciones*/
void inicializar_punteros();

typedef enum { false = 0, true = 1 } bool;

/*****Definicion de funciones*****/

/**Aritmeticas*/

/*Suma de dos enteros*/
int suma(int op1, int op2);

/*Resta de dos enteros*/
int resta(int op1, int op2);

/*Multiplicacion de dos enteros*/
int multiplicacion(int op1, int op2);

/*Division de dos enteros*/
int division(int op1, int op2);

/*Modulo de dos enteros*/
int mod(int op1, int op2);

/**Comparacion**/

int igual_que(int op1, int op2);

int mayor_que(int op1, int op2);

int menor_que(int op1, int op2);

int mayor_igual_que(int op1, int op2);

int menor_igual_que(int op1, int op2);

/**Logicas**/

int and_(int op1, int op2);

int or_(int op1, int op2);

int not_(int op1, int op2);
#endif
