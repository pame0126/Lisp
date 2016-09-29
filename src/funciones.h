#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "hash_table.h"

/*Se imprimen estos valores*/
#define False "#f"
#define True "#t"

/*Macros para simbolos de llaves en las funciones*/
#define SUM "+"
#define RES "-"
#define MUL "*"
#define DIV "quotient"
#define MOD "modulo"

#define IGUAL "="
#define MAYOR ">"
#define MENOR "<"
#define MAYOR_IGUAL ">="
#define MENOR_IGUAL "<="

#define AND "and"
#define OR "or"
#define NOT "not"

/*Define puntero tipo funcion*/
typedef int(*f_ptr)(int,int);


/****Punteros a funciones****/

/*Operaciones aritmetica*/
int (*sumar)(int,int);

int (*restar)(int,int);

int (*multiplicar)(int,int);

int (*quotient)(int,int);

int (*modulo)(int,int);

/*Operaciones comparativas*/
int (*igual)(int,int);

int (*mayor)(int,int);

int (*menor)(int,int);

int (*mayor_igual)(int,int);

int (*menor_igual)(int,int);


/*Operaciones logicas*/
int (*not)(int,int);//deberia de recibir solo un argumento
        //se coloca dos para que se encuentre
        //la logicca en sincronia con las demas funciones.

int (*and)(int,int);

int (*or)(int,int);


/****Funciones****/

/*Inicializa y iguala las funciones definidas y los punteros
 * de ellas*/
extern void f_ptr_inicializa_operacion();

/*Inserta en la tabla hash las funciones que va a usar*/
extern void f_ptr_inserciones_hash(struct hash_table*hash);

/*Verifica si el operador es unario*/
extern int f_ptr_es_operador_unario(char*operador);

/*Verifica que sea numero*/
extern int f_ptr_es_numero(char*elemento);

/*Reotorna si el operador es un operador boleano*/
extern int f_ptr_es_operador_boleano(char*elemento);

/*Retorna el valor boleano del operador*/
extern char*f_ptr_respuesta_operador_boleano(int valor);

#endif
