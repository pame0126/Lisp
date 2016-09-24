#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbol_expresion.h"

/*Separa las expresiones en cadenas de string.
 * 
 * Nota: los valores 40 y 41 en ascii representan los
 *       caracteres '(' y ')' respectivamente*/
char**split_plabra(char*palabra, int largo)
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
                i+=(palabra[i] == ' ')? 1 : 0;

                if( palabra[i] == 40 || palabra[i] == 41 )//si es uno de los parentesis
                {
                        actual = calloc(15, sizeof(char));
                        actual[0] = palabra[i++];	
                        actual[1] = '\0';
                        respuesta[top++] = actual;
                }
                else
                {
                        actual = calloc(15, sizeof(char));
                        j = 0;
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


void destruir_split_palabra(char**split)
{
        for(int i = 0; split[i]!=NULL;i++){
			free( *(split+i) );
			split[i] = NULL;
		}
		free(split);
		split = NULL;
}

int largo_split(char**split)
{
	int i;
	for(i = 0;split[i][0]!='\n' ;i++);
	return i;
}



void quitar_parentesis_operandor(char**operandos, char**ecuacion, int i)
{
	int a = 0;
	int cont_parntesis = 1;
	i++;	
	//mientras sea diferente de --> 0
	while( cont_parntesis )
	{
		operandos[a] = ecuacion[i];
		a++;
		i++;
		cont_parntesis+= (ecuacion[i][0] == 40)?1:0;// --> (
		cont_parntesis-= (ecuacion[i][0] == 41)?1:0;// --> )

	}
	operandos[a] = "\n\0";
}


/*A los operadores tienen dos elementos por operar se separar*/
char***expresion_dividir_operandor_binario(char**ecuacion)
{
	int largo = largo_split(ecuacion);
	
	char***operandos = calloc( 2, sizeof(char**));
	operandos[0] = calloc( largo, sizeof(char*));
	operandos[1] = calloc( largo, sizeof(char*));
	
	int i = 1;//desde 1 para quitar el operador
	int j = 0;
	int a;
	
	int cont_parntesis = 1;
	
	for(; j < 2;j++)
	{
		a = 0;
		if(ecuacion[i][0] == 40)// si e igual a --> (
		{
			quitar_parentesis_operandor( operandos[j] , ecuacion , i );
			//~ printf( "%d \n", i);
			i += largo_split( operandos[j] ) + 2;//suma 2 por 2 parentesis
			//~ printf( "%d %d\n", i);
		}

		else//si no es ni '('  --> numero
		{
			operandos[j][0] = ecuacion[i++];
			operandos[j][1] = "\n\0";
			//~ printf("%s\n", operandos[j][0]);
		}
	}
	return operandos;
}


char**expresion_dividir_operador_unario(char**ecuacion)
{
	int largo = largo_split(ecuacion);
	
	char**operador = calloc(largo, sizeof(char*));

	//si el primer elemento empieza con un parentesis -> '('
	if( ecuacion[1][0] == 40 )
	{
		quitar_parentesis_operandor( operador, ecuacion , 1);
	}
	else//sino es un numero
	{
		operador[0] = ecuacion[1];
		operador[1] = "\n\0";
	}
	return operador;
}


nodo*aux_genra_arbol_expresion(char**ecuacion)
{
	if( f_ptr_es_numero(ecuacion[0]) ){//si es numero
		return nodo_crear( atoi(ecuacion[0]), ecuacion[0] );
	}

	else if( f_ptr_es_operador_unario( ecuacion[0] ) ){//si es el not, unario
		
		nodo*unario = nodo_crear(1,ecuacion[0]);
		nodo*izq = aux_genra_arbol_expresion( expresion_dividir_operador_unario( ecuacion ) );
		
		nodo_insertar_der(unario, NULL);
		nodo_insertar_izq(unario,  izq );
		return unario;
		
	}
	else//es binario
	{
		nodo*binario = nodo_crear(1,ecuacion[0]);
		char***operadores = expresion_dividir_operandor_binario( ecuacion );
		
		nodo_insertar_izq( binario, aux_genra_arbol_expresion( operadores[0] ) );
		nodo_insertar_der(binario, aux_genra_arbol_expresion( operadores[1] ) );
		
		return binario;
	}
}

arbol*genera_arbol_expresion(char**expresion)
{
	arbol*respuesta = arbol_crear();
	respuesta->inicio = aux_genra_arbol_expresion( expresion );
	
	return respuesta;
}



/*Recorrido arbol, imprime los valores*/
void postorden(nodo*raiz){
	if(raiz != NULL)
	{
		postorden(raiz->izq);
		postorden(raiz->der);
		printf("%s ",(char*)raiz->elemento);
	}
}
