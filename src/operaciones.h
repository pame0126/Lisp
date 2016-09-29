#ifndef OPERACIONES_H
#define OPERACIONES_H


typedef enum { false = 0, true = 1 } bool;


/**Aritmeticas*/

/*Suma de dos enteros*/
extern int suma(int op1, int op2);

/*Resta de dos enteros*/
extern int resta(int op1, int op2);

/*Multiplicacion de dos enteros*/
extern int multiplicacion(int op1, int op2);

/*Division de dos enteros*/
extern int division(int op1, int op2);

/*Modulo de dos enteros*/
extern int mod(int op1, int op2);


/**Comparacion**/

extern bool igual_que(int op1, int op2);

extern bool mayor_que(int op1, int op2);

extern bool menor_que(int op1, int op2);

extern bool mayor_igual_que(int op1, int op2);

extern bool menor_igual_que(int op1, int op2);


/**Logicas**/

extern bool and_(int op1, int op2);

extern bool or_(int op1, int op2);

extern bool not_(int op1, int op2);

#endif
