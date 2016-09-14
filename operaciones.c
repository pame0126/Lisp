#include <stdio.h>

#include "operaciones.h"



void inicializar_punteros()
{
        /*aritmetica*/
		sumar = suma;
		restar = resta;
		multiplicar = multiplicacion;
		quotient = division;
		modulo = mod;
		/*comparacion*/
		igual = igual_que;
		mayor = mayor_que;
		menor = menor_que;
		mayor_igual = mayor_igual_que;
        /*logica*/
        and = and_;
        or = or_;
        not = not_;
}


/**Aritmetica**/

/*Suma de dos numeros*/
int suma(int op1, int op2)
{
        return op1 + op2;
}


/*Restar dos numeros*/
int resta(int op1, int op2)
{
        return op1 - op2;
}


/*Multiplicar dos numeros*/
int multiplicacion(int op1, int op2)
{
        return op1 * op2;
}


/*Dividir dos numeros*/
int division(int op1, int op2)
{
        return op1 / op2;
}

/*Residuo entre dos numeros*/
int mod(int op1, int op2)
{
        return op1 % op2;
}


/**Comparacion**/

int igual_que(int op1, int op2)
{
        return (op1 == op2)? true:false;
}

int mayor_que(int op1, int op2){
        return (op1 > op2)? true:false;
}

int menor_que(int op1, int op2){
        return (op1 < op2)? true:false;
}

int mayor_igual_que(int op1, int op2)
{
        return (op1 >= op2)? true:false;
}

int menor_igual_que(int op1, int op2)
{
        return (op1 <= op2)? true:false;
}


/**Logicas**/

int and_(int op1, int op2)
{
        return (op1 && op2)? true:false;
}

int or_(int op1, int op2)
{
        return (op1 || op2)? true:false;
}

int not_(int op1, int op2)
{
        return ( !op1 )? true:false;
}
