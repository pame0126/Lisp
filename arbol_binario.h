#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H


/*Nodo-Hoja del arbol con dos punteros*/
typedef struct nodo{

        struct nodo*izq;
        struct nodo*der;

        int valor;
        void*elemento;

}nodo;


/*puntero a la raiz del arbol*/
typedef struct arbol{
        struct nodo*inicio;
        int cantidad_nodos;
}arbol;

/*Crear espacio para el arbol vacio*/
arbol*arbol_crear();

/*Crea espacio para el nodo del arbol*/
nodo*nodo_crear(int valor, void*simbolo);

/*Insertar nodo -> izq*/
void nodo_insertar_izq(nodo*actual, nodo*izquierda);

/*Insertar nodo -> der*/
void nodo_insertar_der(nodo*actual, nodo*derecha);

/*Modificar valores del nodo del arbol*/
void nodo_modificar(nodo*actual, int valor, void*elemento);

/*Verifica si el nodo es hoja*/
int nodo_es_hoja(nodo*actual);

/*Verifica si el nodo es hijo*/
int nodo_es_hijo(nodo*actual, nodo*hijo);

/*Verifica si el nodo es hijo derecho*/
int nodo_es_hijo_derecho(nodo*actual, nodo*hijo);

/*Verifica si el nodo es hijo izquierdo*/
int nodo_es_hijo_izquierdo(nodo*actual, nodo*hijo);


/*Verificar si el hijo derecho es hoja*/
int nodo_hijo_der_es_hoja(nodo*padre);

/*Verificar si el hijo izquierda es hoja*/
int nodo_hijo_izq_es_hoja(nodo*padre);


/*Destruir nodo*/
void nodo_destruir(nodo*actual);

/*Destruir raiz el arbol*/
void arbol_destruir_raiz(arbol*raiz);

/*Destruir todo el arbol*/
void arbol_destruir_todo(arbol*raiz);


#endif
