
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

bool igual_que(int op1, int op2);

bool mayor_que(int op1, int op2);

bool menor_que(int op1, int op2);

bool mayor_igual_que(int op1, int op2);

bool menor_igual_que(int op1, int op2);


/**Logicas**/

bool and_(int op1, int op2);

bool or_(int op1, int op2);

bool not_(int op1, int op2);
#endif
