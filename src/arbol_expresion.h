#ifndef ARBOL_EXPRESION_H
#define ARBOL_EXPRESION_H

#include "arbol_binario.h"
#include "funciones.h"


/*Divide las expresiones es arreglos*/
char**split_expresion(char*palabra, int len);

/*Libera la memoria que se uso en el split*/
void destruir_split_expresion(char**split);

/*Es una sub-operacion de las funciones:
 * - char***dividir_operandos_binario
 * - char**expresion_dividir_operador_unario
 * */
void quitar_parentesis_operador(char**operandos, char**ecuacion, int i);

/*Separa los dos operadores de una operacion binaria*/
char***dividir_operandos_binario(char**expresion);

/*Da el operador de la operacion unaria - NOT*/
char**expresion_dividir_operador_unario(char**ecuacion);

/*Auxiliar de genera_arbol_expresion*/
nodo*aux_genera_arbol_expresion(char**);

/*Produce el arbol de expresion de la ecuacion*/
arbol*genera_arbol_expresion(char**expresion);

/*Recorreo el arbol generado imprimiendo sus valores
 * en postorden*/
void imprimir_arbol_postorden(nodo*);

/*Resuelve el arbol*/
int resolver_arbol_expresion(nodo*inicio, hash_table*operaciones);

/*Destruir arbol de expresiones*/
void arbol_expresion_destruir(nodo*raiz);

#endif
