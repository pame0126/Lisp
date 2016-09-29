#include <stdlib.h>
#include <stdio.h>

#include "arbol_binario.h"

/*Crear espacio para el arbol vacio*/
arbol*arbol_crear()
{
         arbol*raiz = calloc(1, sizeof(arbol));
         raiz->inicio = NULL;
         return raiz;
}

/*Crea espacio para el nodo del arbol*/
nodo*nodo_crear(int valor, void*simbolo)
{
        nodo*actual = calloc( 1, sizeof(nodo));
        actual->izq = NULL;
        actual->der = NULL;
        actual->valor = valor;
        actual->elemento = simbolo;
        return actual;
}

/*Insertar nodo -> izq*/
void nodo_insertar_izq(nodo*actual, nodo*izquierda)
{
        actual->izq = izquierda;
}

/*Insertar nodo -> der*/
void nodo_insertar_der(nodo*actual, nodo*derecha)
{
        actual->der = derecha;
}

/*Destruir nodo*/
void nodo_destruir(nodo*actual)
{
        free(actual);
        actual = NULL;
}


/*Destruir raiz el arbol*/
void arbol_destruir_raiz(arbol*raiz)
{
        free(raiz);
        raiz = NULL;
}

/*auxiliar que destruye el arbol recursivamente*/
void aux_destruir_arbol(nodo*actual)
{
        if (actual != NULL){
                aux_destruir_arbol( actual->izq );
                aux_destruir_arbol( actual->der );

                free(actual);
                actual = NULL;
        }
}
