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
        //~ free(actual->elemento)
        free(actual);
        actual = NULL;
}

/*Destruir raiz el arbol*/
void arbol_destruir_raiz(arbol*raiz)
{
        free(raiz);
}

//~ /*Destruir todo el arbol*/
//~ void arbol_destruir_todo(arbol*raiz)
//~ {
        //~ nodo*actual = raiz->inicio;
        //~ nodo*pila[100];// = (nodo*)calloc(100, sizeof(nodo));
        //~ int top = -1;
        
        //~ top++;
        //~ pila[top] = actual;

        //~ while( raiz->inicio != NULL )
        //~ {
				//~ printf("top %d - %d\n",top,actual->valor);
                //~ if( nodo_es_hoja( actual ) )
                //~ {
                        //~ printf("%d\n", actual->valor);
                        //~ nodo_destruir(actual);
                        //~ pila[top] = NULL;
                        //~ printf("%d\n", actual->valor);
                        //~ --top;
                        //~ printf("--top %d\n",top);

                        //~ printf("%d\n", actual->valor);
                //~ }
                //~ else
                //~ {		printf("insertar\n");
                        //~ if( actual->izq != NULL )
                        //~ {
                                //~ ++top;
                                //~ pila[top] = actual->izq;
                                //~ printf("- %d\n", pila[top]->valor);
                        //~ }
                        //~ if( actual->der != NULL )
                        //~ {
                                //~ ++top;
                                //~ pila[top] = actual->der;
                                //~ printf("- %d\n", pila[top]->valor);
                        //~ }
                        //~ actual = (top > -1)?pila[top]:NULL;
				//~ }
				//~ actual = ( top > -1 )? pila[top] : NULL;
        //~ }
        //~ free(raiz->inicio);
        //~ free(raiz);
//~ }
