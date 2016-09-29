#ifndef ARBOL_EXPRESION_H
#define ARBOL_EXPRESION_H

#include "arbol_binario.h"
#include "funciones.h"

/*Produce el arbol de expresion de la ecuacion*/
extern arbol*genera_arbol_expresion(arbol*raiz, char*linea);

/*Resuelve el arbol*/
extern int resolver_arbol_expresion(nodo*inicio, struct hash_table*operaciones);

/*Destruir arbol de expresiones*/
extern void arbol_expresion_destruir(nodo*raiz);

#endif
