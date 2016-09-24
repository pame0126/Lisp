#include <stdlib.h>
#include <stdio.h>

#include "arbol_binario.h"



/*Crear espacio para el arbol vacio*/
arbol*arbol_crear()
{
         arbol*raiz = calloc( 1, sizeof(arbol));
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

/*Modificar valores del nodo del arbol*/
void nodo_modificar(nodo*actual, int valor, void*elemento)
{
        actual->valor = valor;
        actual->elemento = elemento;
}

/*Verifica si el nodo es hoja*/
int nodo_es_hoja(nodo*actual)
{
        return ( actual->izq == NULL && actual->der == NULL )? 1 : 0;
}

/*Verifica si el nodo es hijo del actual*/
int nodo_es_hijo(nodo*actual, nodo*hijo)
{
        return ( actual->izq == hijo || actual->der == hijo )? 1 : 0;
}

/*Verifica si el nodo es hijo derecho*/
int nodo_es_hijo_derecho(nodo*actual, nodo*hijo)
{
        return ( actual->der == hijo )? 1 : 0;
}

/*Verifica si el nodo es hijo izquierdo*/
int nodo_es_hijo_izquierdo(nodo*actual, nodo*hijo)
{
        return ( actual->der == hijo )? 1 : 0;
}



/*Verificar si el hijo derecho es hoja*/
int nodo_hijo_der_es_hoja(nodo*padre)
{
        return  nodo_es_hoja( padre->der );
}

/*Verificar si el hijo izquierda es hoja*/
int nodo_hijo_izq_es_hoja(nodo*padre)
{
        return nodo_es_hoja( padre->izq ) ;
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
void aux_destruir_arbol(nodo*actual){
        if(actual != NULL)
        {
                aux_destruir_arbol( actual->izq );
                aux_destruir_arbol( actual->der );
                
                if( sizeof( actual->elemento ) > 1 )
                {
                        free(actual->elemento);
                        actual->elemento = NULL;
                }
                free(actual);
                actual = NULL;
        }
}


/*Destruir todo el arbol*/
void arbol_destruir_todo(arbol*raiz){
        if( raiz->inicio != NULL )
        {
                aux_destruir_arbol(raiz->inicio);
        }
        free( raiz );
        raiz = NULL;
}

