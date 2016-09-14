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
		igual = (f_ptr)igual_que;
		mayor = (f_ptr)mayor_que;
		menor = (f_ptr)menor_que;
		mayor_igual = (f_ptr)mayor_igual_que;
        /*logica*/
        and = (f_ptr)and_;
        or = (f_ptr)or_;
        not = (f_ptr)not_;
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

bool igual_que(int op1, int op2)
{
        return (op1 == op2)? true:false;
}

bool mayor_que(int op1, int op2)
{
        return (op1 > op2)? true:false;
}

bool menor_que(int op1, int op2)
{
        return (op1 < op2)? true:false;
}

bool mayor_igual_que(int op1, int op2)
{
        return (op1 >= op2)? true:false;
}

bool menor_igual_que(int op1, int op2)
{
        return (op1 <= op2)? true:false;
}



/**Logicas**/

bool and_(int op1, int op2)
{
        return (op1 && op2)? true:false;
}

bool or_(int op1, int op2)
{
        return (op1 || op2)? true:false;
}

bool not_(int op1, int op2)
{
        return ( !op1 )? true:false;
}
