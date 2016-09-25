#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "arbol_expresion.h"



/*Separa las expresiones en cadenas de string.
 * 
 * Nota: los valores 40 y 41 en ascii representan los
 *       caracteres '(' y ')' respectivamente*/
char**split_expresion(char*palabra, int largo)
{
        char*actual;// = calloc(10, sizeof(char));
        char**respuesta = (char**)calloc(largo, sizeof(char*));

        int top = 0;
        int bandera = 1;//bandera de salida a un ciclo

        int i = 0;//indice de la palabra q ingresa
        int j = 0;//indice del espacio que se crea
        

        //obia los parentesis que estan en el principio de la expresion
        for(; palabra[i] == (char)40 ;i++,largo--);

        while( i < largo )
        {
                //~ i+=(palabra[i] == ' ')? 1 : 0;

                if( palabra[i] == 40 || palabra[i] == 41 )//si es uno de los parentesis
                {
                        actual = calloc(15, sizeof(char));
                        actual[0] = palabra[i++];	
                        actual[1] = '\0';
                        respuesta[top++] = actual;
                }
                else if( palabra[i] == ' ' )
                {
					i++;
				}
                else
                {
                        actual = calloc(15, sizeof(char));
                        j = 0;//incide para actual
                        
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
                                                actual[j++] = palabra[i++];
                                                break;
                                }
                        }
                        bandera = 1;
                        actual[j]='\0';

                        respuesta[top++] = actual;
                }
        }
        //final, ultimo elemento
        actual = calloc(15, sizeof(char));

        actual[0]='\n';
        actual[1]='\0';
        respuesta[top] = actual;

        return respuesta;
}


/*Libera el espacio del elemento split ejecutado*/
void destruir_split_expresion(char**split)
{
        for( int i = 0; split[i] != NULL ; i++ ){
                free( *(split+i) );
                split[i] = NULL;
        }
        free(split);
        split = NULL;
}

/*Calcula el largo del split, del arreglo de char** 
 * el elemento final es el salto de linea
 * */
int largo_split(char**split)
{
        int i;
        /*Se contara hasta que llege al salto de linea*/
        for(i = 0;split[i][0]!='\n' ;i++);

        return i;
}

/*Funcion auxiliar
 * quitar_parentesis_operador
 * Recibe -- el elemento donde se almacena el resultado -> espacio
 *         - la expresion que se copiara -> expresion
 *         - la posicion actual del parentesis en la expresion -> i
 * */
void quitar_parentesis_operador(char**espacio, char**expresion, int i)
{
        int a = 0;
        int cont_parentesis = 1;
        i++;

        //mientras sea diferente de --> 0
        while( cont_parentesis )
        {
                espacio[a] = expresion[i];
                a++;
                i++;
                cont_parentesis+= ( expresion[i][0] == 40 )? 1 : 0 ;// --> (
                cont_parentesis-= ( expresion[i][0] == 41 )? 1 : 0 ;// --> )
        }
        espacio[a] = "\n\0";
}


/* Separa a dos operadores de una expresion, las divide
 * Entrada -- La expresion inicial - char** ecuacion
 * Salida  -- Regresa un arreglo de tamaño 2 de tipo char** donde
 *            esta los dos operadores.
 * A los operadores que tienen dos elementos por operar se separar
 * */
char***expresion_dividir_operandor_binario(char**ecuacion)
{
        int largo = largo_split(ecuacion);

        /*Separa los espacio en memoria para los dos operadores*/
        char***espacio = calloc( 2, sizeof(char**) );
        espacio[0] = calloc( largo, sizeof(char*) );
        espacio[1] = calloc( largo, sizeof(char*) );

        //contador de 'ecuacion', comienza en 1 para omitir el operador binario
        int i = 1;
        int j = 0;//Contador de o

        /*Repite el paso 2 veces*/
        for(; j < 2;j++)
        {
                if( ecuacion[i][0] == 40 )// si empieza igual a --> (
                {
                        
                        quitar_parentesis_operador( espacio[j] , ecuacion , i );
                        i += largo_split( espacio[j] ) + 2;//suma 2 por 2 parentesis
                }

                else//si no es '('  --> numero
                {
                        espacio[j][0] = ecuacion[i++];
                        espacio[j][1] = "\n\0";
                }
        }

        return espacio;
}


char**expresion_dividir_operador_unario(char**ecuacion)
{
        int largo = largo_split( ecuacion );
        char**operador = calloc( largo, sizeof(char*) );

        //si el primer elemento empieza con un parentesis -> '('
        if( ecuacion[1][0] == 40 )
        {
                quitar_parentesis_operador( operador, ecuacion , 1);
        }
        else//sino es un numero
        {
                operador[0] = ecuacion[1];
                operador[1] = "\n\0";
        }

        return operador;
}


/* De manera recursiva genera el arbol
 * Entrada: -- entra una expresion - char** ecuacion
 * Salida : -- puntero a espacio a memoria - nodo*
 * */
nodo*aux_genera_arbol_expresion(char**ecuacion)
{
        if( f_ptr_es_numero(ecuacion[0]) )//si es numero la cadena
        {
                return nodo_crear( atoi(ecuacion[0]), ecuacion[0] );
        }

        else if( f_ptr_es_operador_unario( ecuacion[0] ) )//si es el operador NOT, unario
        {
                nodo*unario = nodo_crear(1,ecuacion[0]);
                nodo*izq = aux_genera_arbol_expresion( expresion_dividir_operador_unario( ecuacion ) );

                nodo_insertar_der(unario, NULL);
                nodo_insertar_izq(unario,  izq );

                return unario;
        }
        else//es binario el operador
        {
                nodo*binario = nodo_crear(1,ecuacion[0]);
                char***operadores = expresion_dividir_operandor_binario( ecuacion );

                nodo_insertar_izq( binario, aux_genera_arbol_expresion( operadores[0] ) );
                nodo_insertar_der( binario, aux_genera_arbol_expresion( operadores[1] ) );

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
void imprimir_arbol_postorden(nodo*raiz){
        if(raiz != NULL)
        {
                imprimir_arbol_postorden(raiz->izq);
                imprimir_arbol_postorden(raiz->der);

                printf("%s ",(char*)raiz->elemento);
        }
}


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
		f_ptr operacion = hash_buscar( tabla, (char*)inicio->elemento);
		
		int numero = resolver_arbol_expresion( inicio->izq, tabla);
		
		return operacion( numero ,0);
	}
	/*Si es operador binario*/
	else
	{
		f_ptr operacion = hash_buscar( tabla, (char*)inicio->elemento);
		
		int numero_izq = resolver_arbol_expresion( inicio->izq, tabla);
		int numero_der = resolver_arbol_expresion( inicio->der, tabla);
		
		return operacion( numero_izq , numero_der );
	}
}
