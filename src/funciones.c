#include <stdio.h>
#include <string.h>

#include "funciones.h"
#include "operaciones.h"

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
        menor_igual = (f_ptr)menor_igual_que;
        /*logica*/
        and = (f_ptr)and_;
        or = (f_ptr)or_;
        not = (f_ptr)not_;
}

/*Inserta en la tabla hash las funciones que va a usar*/
void f_ptr_inserciones_hash(struct hash_table*hash)
{
        f_ptr_inicializa_operacion();
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

/*Verifica si el operador es unario*/
int f_ptr_es_operador_unario(char*operador)
{
        return ( !strcmp(operador, NOT) )?1:0;
}

/*Verifica que sea numero*/
int f_ptr_es_numero(char*elemento)
{
        int i = 0;
        int bandera = 1;
        int len = strlen(elemento);

        while (i < len && bandera ){
                bandera = (elemento[i]-48 >= 0 && elemento[i]-48 <= 9)?1:0;
                ++i;
        }
        return bandera;
}


/*Reotorna si el operador es un operador boleano*/
int f_ptr_es_operador_boleano(char*elemento)
{
        bool es_boleano = 0;
        /*Es mayor o mayor igual*/
        if ( !strcmp(elemento, MAYOR) || !strcmp(elemento, MAYOR_IGUAL) ){
                es_boleano++;
        }
        /*Es menor o menor igual*/
        else if ( !strcmp(elemento, MENOR) || !strcmp(elemento, MENOR_IGUAL)){
                es_boleano++;
        }
        /*Es igual o not*/
        else if ( !strcmp(elemento, IGUAL) || !strcmp(elemento, NOT)){
                es_boleano++;
        }
        /*Es or o and*/
        else if ( !strcmp(elemento, OR) || !strcmp(elemento, AND)){
                es_boleano++;
        }
        return es_boleano;
}

/*Retorna el valor boleano del operador*/
char*f_ptr_respuesta_operador_boleano(int valor)
{
        return (valor)? True: False;
}

