#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "hash_table.h"
#include "arbol_expresion.h"

#define SIZE_EXP 100// tamaño maximo de la expresion

void leerLinea(char*linea)
{
        char caracter;
        int i = 0;
        scanf("%c",&caracter);
        while(caracter != '\n' && caracter != '\0')
        {
                *(linea + i) = caracter;
                scanf("%c",&caracter);
                i++;
        }
        *(linea + i) = '\0';
}


int main()
{
        /*Inicializar siempre los punteros a funciones,
         *  sino da error 0 de la funcion no definida*/
        //~ f_ptr_inicializa_operacion();

        char*expresion = (char*)calloc(SIZE_EXP, sizeof(char));

        //~ while(1)
        //~ {
                //~ printf("lisp> ");
        leerLinea(expresion);//lee una linea

        int largo = strlen(expresion);
        char**res = split_plabra(expresion, largo);
		arbol*p = genera_arbol_expresion( res );
		postorden(p->inicio);
		printf("\n");
		//~ printf("%s - %s %s\n", (char*)(p->inicio)->elemento, (char*)(p->inicio->izq)->elemento,(char*)(p->inicio->der)->elemento);
        
        return 0;
}

