#include <stdio.h>

#include "funciones.h"



/*Asigna a los ptr_funcion una funcion definida*/
void f_ptr_inicializa_operacion()
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

/*Inserta en la tabla hash las funciones que va a usar*/
void f_ptr_inserciones_hash(hash_table*hash)
{
        /*Aritmetica*/
        hash_insertar(hash, SUM, sumar);
        hash_insertar(hash, RES, restar);
        hash_insertar(hash, MUL, multiplicar);
        hash_insertar(hash, DIV, quotient);
        hash_insertar(hash, MOD, modulo);
        /*Comparativa*/
        hash_insertar(hash, IGUAL, igual);
        hash_insertar(hash, MAYOR, mayor);
        hash_insertar(hash, MENOR, menor);
        hash_insertar(hash, MAYOR_IGUAL, mayor_igual);
        hash_insertar(hash, MENOR_IGUAL, menor_igual);
        /*Logica*/
        hash_insertar(hash, AND, and);
        hash_insertar(hash, OR, or);
        hash_insertar(hash, NOT, not);
}