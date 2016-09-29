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
}arbol;

/*Crear espacio para el arbol vacio*/
extern arbol*arbol_crear();

/*Destruir raiz el arbol*/
extern void arbol_destruir_raiz(arbol*raiz);

/*Crea espacio para el nodo del arbol*/
extern nodo*nodo_crear(int valor, void*simbolo);

/*Destruir nodo*/
extern void nodo_destruir(nodo*actual);
/*Insertar nodo -> izq*/
extern void nodo_insertar_izq(nodo*actual, nodo*izquierda);

/*Insertar nodo -> der*/
extern void nodo_insertar_der(nodo*actual, nodo*derecha);


#endif
