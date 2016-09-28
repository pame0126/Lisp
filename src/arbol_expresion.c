#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbol_expresion.h"

#define TAM_NUM 15


/*Verifica que si es un valor boleano lo intercambie por
 * valores 1 y 0 que se interpreta como true o false*/
char*aux_split_expresion( char*expresion )
{
        if( !strcmp(expresion, True) )
        {
                free( expresion );
                expresion = NULL;
                expresion = calloc( 2 , sizeof(char) );
                strcpy( expresion, "1\0");
                return expresion;

        }
        else if( !strcmp(expresion, False) )
        {
                free( expresion );
                expresion = NULL;
                expresion = calloc( 2 , sizeof(char) );
                strcpy( expresion, "0\0");
                return expresion;
        }
        else
        {
                return expresion;
        }
}


/*Separa los operadores, numeros y simbolos
 * en cadenas de string.
 *
 * Nota: - los valores 40 y 41 en ascii representan los
 *       caracteres '(' y ')' respectivamente
 *      - La cadena 'palabra' o linea como esta en menu
 *        se libera el espacio en memoria.
 * */
char**split_expresion(char*palabra, int largo)
{
        char**respuesta = calloc( largo+1, sizeof(char*) );
        static int top;
        static int i;
        static int tamano;
        //~ respuesta = (char**)calloc( largo + 1, sizeof(char*) );
        top = 0;
        i = 0;//indice de la palabra q ingresa

        /*obia los parentesis que estan en el principio y final de la expresion*/
        for(; palabra[i] == (char)40 ;i++,largo--);

        /*Recorrera toda la cadena*/
        while( i < largo )
        {
                if( palabra[i] == 40 || palabra[i] == 41 )//si es uno de los parentesis
                {
                        respuesta[top] = calloc( TAM_NUM , sizeof(char) );
                        respuesta[top][0] = palabra[i++];
                        respuesta[top][1] = '\0';
                        top++;
                }
                else if( palabra[i] == ' ' )
                {
                        ++i;
                }
                else
                {
                        static int j;
                        static int bandera;
                        j = 0;//indice para variable actual
                        bandera = 1;//bandera de salida a un ciclo
                        respuesta[top] = calloc( TAM_NUM, sizeof(char) );
                        /*Guarda los caracteres antes de los parametros de parada*/
                        while( bandera )
                        {
                                switch( palabra[i] )
                                {
                                        case ' ':
                                                i++;
                                                bandera--;
                                                break;

                                        case '\n':
                                                i++;
                                                bandera--;
                                                break;

                                        case '\0':
                                                i++;
                                                bandera--;
                                                break;

                                        case (char)40:// (
                                                bandera--;
                                                break;

                                        case (char)41:// )
                                                bandera--;
                                                break;

                                        default:
                                                respuesta[top][j++] = palabra[i++];
                                                break;
                                }
                        }
                        respuesta[top][j] = '\0';
                        /*Si es de valor #t o #f intercambia valores por 0 o 1*/
                        respuesta[top] = aux_split_expresion( respuesta[top] );
                        top++;
                }
        }

        /*Asigna el espacio en respuesta*/
        respuesta[top] = calloc( 2, sizeof(char) );
        strcpy(respuesta[top], "\n\0");

        return respuesta;
}


/*Imprime la hilera split*/
void imprimir_split_expresion( char**split )
{
        static int i;
        for( i = 0 ; split[i][0] != '\n' ; i++ ){
                printf( "%s ", split[i] );
        }
        printf( "%s",split[i] );//imprime el ultimo elemento, salto
}


/*Calcula el largo del split, del arreglo de char**
 * el elemento final es el salto de linea.
 * Entrada: - arreglo char* split.
 * Salida: - largo int del arrglo split.
 * */
int largo_split(char**split)
{
        static int i;
        /*Se contara hasta que llege al salto de linea*/
        for( i = 0 ; split[i][0] != '\n' ; i++ );
        return i;
}


/*Libera el espacio del elemento split ejecutado*/
void destruir_split_expresion(char**split)
{
        static int i;
        if( split == NULL )
        {
                return;
        }
        i = 0 ;
        while( split[i][0] != '\n' )
        {
                //~ printf("- %s\n",split[i]);
                free( split[i] );
                split[i++] = NULL;
        }
        //~ i++;
        free( split[i] );//libera ultimo elemento
        split[i] = NULL;
        free( split );//libera puntero
        split = NULL;
}


/*Funcion auxiliar
 * quitar_parentesis_operador
 * Entrada:-- el elemento donde se almacena el resultado -> espacio
 *         - la expresion que se copiara -> expresion
 *         - la posicion actual del parentesis en la expresion -> i
 * */
void quitar_parentesis_operador(char**espacio, char**expresion, int i)
{
        static int tamano;
        static int a;
        static int cont_parentesis;
        a = 0;//contador de 'espacio'
        cont_parentesis = 1;
        i++;//omite el parentesis inicial

        //mientras sea diferente de --> 0
        while( cont_parentesis )
        {
                tamano = strlen( expresion[i] ) + 1;
                espacio[a] = calloc( tamano, sizeof(char) );
                strcpy( espacio[a], expresion[i] );
                /*Aumenta contadores*/
                a++;
                i++;
                /*Evalua la condicion de parada*/
                cont_parentesis+= ( expresion[i][0] == 40 )? 1 : 0 ;// --> (
                cont_parentesis-= ( expresion[i][0] == 41 )? 1 : 0 ;// --> )
        }
        /*elemento final que marca el fin del arreglo char**/
        espacio[a] = calloc( 2, sizeof(char) );
        strcpy( espacio[a],"\n\0" );
}


/* Separa a dos operadores de una expresion, las divide
 * Entrada -- La expresion inicial - char** ecuacion
 * Salida  -- Regresa un arreglo de tamaño 2 de tipo char** donde
 *            esta los dos operadores.
 * A los operadores que tienen dos elementos por operar se separar
 * */
char***expresion_dividir_operandor_binario(char**ecuacion)
{
        static int largo;
        static int i;
        static int j;//Contador de 'espacio'
        /*Largo de la ecuacion*/
        largo = largo_split( ecuacion ) + 1;
        /*contador de 'ecuacion', comienza en 1 para omitir el operador binario*/
        i = 1;
        /*Separa los espacio en memoria para los dos operadores*/
        char***espacio;
        espacio = calloc( 2, sizeof(char**) );
        espacio[0] = calloc( largo , sizeof(char*) );
        espacio[1] = calloc( largo , sizeof(char*) );

        /*Repite el paso 2 veces*/
        for( j = 0 ; j < 2;j++)
        {
                if( ecuacion[i][0] == 40 )// si empieza igual a --> (
                {
                        /*Copia los elementos - ( Destino, origen, posicion_actual_del_origen )*/
                        quitar_parentesis_operador( espacio[j] , ecuacion , i );
                        i+= largo_split( espacio[j] ) + 2;//suma 2 por 2 parentesis
                }
                else//si no es '('  --> numero
                {
                        /*Numero guardar*/
                        static int tamano;
                        tamano = strlen( ecuacion[i] ) + 1;
                        espacio[j][0] = calloc( tamano , sizeof(char) );
                        strcpy( espacio[j][0], ecuacion[i] );
                        i++;
                        /*Final del linea*/
                        espacio[j][1] = calloc(2, sizeof(char));
                        strcpy( espacio[j][1] , "\n\0" );
                }
        }
        destruir_split_expresion( ecuacion );
        return espacio;
}


/*Separa de la operacion el numero o valor*/
char**expresion_dividir_operador_unario(char**ecuacion)
{
        static int largo;
        largo = largo_split( ecuacion ) + 1;
        char**operador = calloc( largo, sizeof(char*) );

        //si el primer elemento empieza con un parentesis -> '('
        if( ecuacion[1][0] == 40 )
        {
                quitar_parentesis_operador( operador, ecuacion , 1);
        }
        else//sino--> es un numero
        {
                /*Copia el numero en un nuevo espacio en memoria*/
                static int tamano;
                tamano = strlen( ecuacion[1] ) + 1;
                operador[0] = calloc( tamano , sizeof(char) );
                strcpy( operador[0], ecuacion[1] );
                /*Final de linea*/
                operador[1] = calloc( 2 , sizeof(char) );
                strcpy( operador[1] , "\n\0" );
        }
        destruir_split_expresion( ecuacion );
        return operador;
}


/* De manera recursiva genera el arbol
 * Entrada: -- entra una expresion - char** ecuacion
 * Salida : -- puntero a espacio a memoria - nodo*
 * */
nodo*aux_genera_arbol_expresion(char**ecuacion)
{
        /*tamaño para el nuevo arreglo, con espacio extra para el
         * final de linea*/
        static int tamano;
        tamano = strlen( ecuacion[0] ) + 1;
        //~ imprimir_split_expresion(ecuacion);

        /*si es numero la cadena*/
        if( f_ptr_es_numero( ecuacion[0] ) )
        {
                //~ printf("es numero\n");
                nodo*hoja;
                char*elemento;
                elemento = calloc( tamano , sizeof(char) );
                strcpy( elemento, ecuacion[0] );

                /*Guarda el valor numerico y la cadena que lo representa*/
                hoja = nodo_crear( atoi( elemento ) , elemento );
                destruir_split_expresion( ecuacion );

                return hoja;
        }
        /*Si es la operacion NOT, unario*/
        else if( f_ptr_es_operador_unario( ecuacion[0] ) )
        {
                char*operacion;
                char**restante;
                nodo*unario;
                nodo*izq;
                /*Crea espacio y copia la operacion*/
                operacion = calloc( tamano , sizeof(char) );
                strcpy( operacion, ecuacion[0] );

                /*Saca el elemento que aplica la operacion*/
                restante = expresion_dividir_operador_unario( ecuacion );

                /*Crea el espacio para guardar la operacion*/
                unario = nodo_crear( 1, operacion );
                izq = aux_genera_arbol_expresion( restante );

                /*Crea las ramas hijas*/
                nodo_insertar_der( unario, NULL);
                nodo_insertar_izq( unario,  izq );

                return unario;
        }
        else//es binario la operacion
        {
                char*operacion;
                char***elemento_restante;
                nodo*binario;

                operacion = calloc( tamano, sizeof(char) );//elemento del nodo actual
                strcpy( operacion, ecuacion[0] );
                elemento_restante = expresion_dividir_operandor_binario( ecuacion );

                binario = nodo_crear( 1 , operacion );

                nodo_insertar_izq( binario, aux_genera_arbol_expresion( elemento_restante[0] ) );
                nodo_insertar_der( binario, aux_genera_arbol_expresion( elemento_restante[1] ) );
                /*Libera puntero*/
                free( elemento_restante );
                elemento_restante = NULL;

                return binario;
        }
}

/*Recibe el puntero del arbol
 * crea el espacio en memoria
 * llama a una funcion auxiliar para generar el arbol
 * */
arbol*genera_arbol_expresion(char**expresion)
{
        arbol*respuesta = arbol_crear();
        respuesta->inicio = aux_genera_arbol_expresion( expresion );
        return respuesta;
}


/*Recorrido arbol, imprime los valores*/
void imprimir_arbol_postorden(nodo*raiz)
{
        if(raiz != NULL)
        {
                imprimir_arbol_postorden(raiz->izq);
                imprimir_arbol_postorden(raiz->der);
                printf("%s ",(char*)raiz->elemento);
        }
}

/*Resuelve el arbol de expresiones y devuelve un valor*/
int resolver_arbol_expresion( nodo*inicio, hash_table*tabla)
{
        /* si es un numero */
        if( f_ptr_es_numero(inicio->elemento) )
        {
                return inicio->valor;
        }
        /*Si es operador de NOT*/
        else if( f_ptr_es_operador_unario( inicio->elemento ) )
        {
                static f_ptr operacion;
                static int numero;
                /*Busca la funcion que resuelve*/
                operacion = hash_buscar( tabla, (char*)inicio->elemento);
                numero = resolver_arbol_expresion( inicio->izq, tabla);
                return operacion( numero ,0);
        }
        /*Si es operador binario*/
        else
        {
                static f_ptr operacion;
                static int numero_izq;
                static int numero_der;
                /*Busca la funcion que resuelve*/
                operacion = hash_buscar( tabla, (char*)inicio->elemento);
                numero_izq = resolver_arbol_expresion( inicio->izq, tabla);
                numero_der = resolver_arbol_expresion( inicio->der, tabla);
                return operacion( numero_izq , numero_der );
        }
}


/*Funcion auxiliar que contiene la recursividad*/
void aux_arbol_expresion_destruir(nodo*actual)
{
        if(actual != NULL)
        {
                aux_arbol_expresion_destruir(actual->izq);
                aux_arbol_expresion_destruir(actual->der);
                /*Libera el elemento char* que contine*/
                free( actual->elemento );
                actual->elemento = NULL;
                /*Libera el nodo*/
                free(actual);
                actual = NULL;
        }
}

/*Libra todo el arbol de expresiones*/
void arbol_expresion_destruir(nodo*raiz)
{
        if(raiz != NULL){
                arbol_expresion_destruir(raiz->izq);
                arbol_expresion_destruir(raiz->der);
                free(raiz->elemento);
                raiz->elemento =  NULL;
                free(raiz);
                raiz = NULL;
        }
}
