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
        struct hash_table*tabla = hash_crear();
        arbol*raiz = arbol_crear();
        char*linea;
        char**expresion;
        int resultado;
        /*Inicializar siempre los punteros a funciones,
         *  sino da error 0 de la funcion no definida*/
        f_ptr_inicializa_operacion();
        f_ptr_inserciones_hash(tabla);

        linea = (char*)calloc(SIZE_EXP, sizeof(char));//linea donde guarda entrada
        printf("Salida con q\nlisp> ");
        leerLinea(linea);//lee una linea

        /*Mientras que no escriba 'q' */
        while (linea[0]!='q'){
                raiz = genera_arbol_expresion(raiz, linea);
                resultado = resolver_arbol_expresion(raiz->inicio, tabla);

                /*Si es un operador boleano la raiz*/
                if ( f_ptr_es_operador_boleano((char*)raiz->inicio->elemento) ){
                        /*Imprime #t o #f, valor boleano*/
                        printf("%s\n", f_ptr_respuesta_operador_boleano(resultado));
                }
                /*Si no, --> es numero*/
                else{
                        printf("%d\n", resultado);
                }
                arbol_expresion_destruir(raiz->inicio);
                printf("lisp> ");
                leerLinea(linea);//lee una linea
        }
        free(linea);
        linea = NULL;
        hash_destruir(tabla);
        free(raiz);
        raiz = NULL;

        return 0;
}

