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
        f_ptr_inicializa_operacion();
        
        hash_table*tabla = hash_crear();
        f_ptr_inserciones_hash(tabla);
        
        char*linea;
        int largo;
        char**expresion;
        arbol*raiz;
        int resultado;
        
        
        linea = (char*)calloc(SIZE_EXP, sizeof(char));//linea donde guarda entrada
        leerLinea( linea );//lee una linea
        largo = strlen( linea );//largo de entrada
        
        expresion = split_expresion( linea, largo);
		raiz = genera_arbol_expresion( expresion );
		
        resultado = resolver_arbol_expresion( raiz->inicio, tabla );
        
        /*Si NO es numero y es un operador boleano el valor de la raiz*/
        if( !f_ptr_es_numero(raiz->inicio->elemento) && f_ptr_es_operador_boleano(raiz->inicio->elemento) )
        {
			/*Imprime #t o #f, valor boleano*/
			printf("%s\n", f_ptr_respuesta_operador_boleano( resultado ) );
		}
		/*Si no, --> es numero*/
		else
		{
			printf("%d\n", resultado );
		}
		
		hash_destruir( tabla );
		destruir_split_expresion( expresion );
		arbol_destruir_todo( raiz );
		
		free( linea );
		linea = NULL;
        return 0;
}

