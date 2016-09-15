#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H


typedef struct arbol{
        struct nodo*inicio;
}arbol;

typedef struct nodo{

        struct nodo*izq;
        struct nodo*der;

        int num;
        char*operador;

}nodo;


#endif
