#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "hash_table.h"
#include "arbol_expresion.h"

// tamaño maximo de la entrada
#define SIZE_EXP 100

/*Lee linea de entrada*/
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

        char*linea = (char*)calloc(SIZE_EXP, sizeof(char));

        leerLinea( linea );//lee una linea

        int largo = strlen( linea );
        char**expresion = split_expresion( linea, largo);
		arbol*raiz = genera_arbol_expresion( expresion );
		
		imprimir_arbol_postorden( raiz->inicio );
		
		printf("\n");
        
        return 0;
}

