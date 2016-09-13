#include <stdio.h>

#include "operaciones.h"

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

void inicializar_punteros(){
		sumar = suma;
		restar = resta;
		multiplicar = multiplicacion;
		quotient = division;
		modulo = mod;
		
}
