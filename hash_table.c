#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"
#include "funciones.h"


/*Crea el espacio en memoria de la tabla*/
hash_table*crear_tabla()
{
        int pos;
        hash_table*nueva = calloc(1,sizeof(hash_table));
        
        //~ pos = codigo_hash("+")%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = sumar;
        //~ pos = codigo_hash( "-" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = restar;
        //~ pos = codigo_hash("*")%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = multiplicar;
        //~ pos = codigo_hash( "/" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = quotient;
        //~ pos = codigo_hash("%")%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = modulo;

        //~ pos = codigo_hash( "=" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = igual;
        //~ pos = codigo_hash(">")%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = mayor;
        //~ pos = codigo_hash( "<" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = menor;
        //~ pos = codigo_hash(">=")%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = mayor_igual;
        //~ pos = codigo_hash( "<=" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = menor_igual;

        //~ pos = codigo_hash( "and" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = menor_igual;
        //~ pos = codigo_hash( "or" )%CASILLAS;
        //~ *( nueva->tabla + ( pos ) ) = menor_igual;
        //~ pos = codigo_hash( "not" )%CASILLAS;
        //~ nueva->tabla[ pos ] = menor_igual;

        return nueva;
}


/*Elimina la tabla liberando el espacio*/
void eliminar_tabla(hash_table*hash)
{
        free( hash->tabla );
        free( hash );       //libera espacio
}


/*Devuelve el codigo hash calculado por el string clave*/
int codigo_hash(char*clave)
{
        int i = 0;
        int n = strlen(clave);

        int valor = 0;
        int resta = n-1;

        while(i < n)//de i hasta n-1
        {
                valor+=*(clave+i)*(int)pow((double)31,(double)resta-i);
                i++;
        }

        return valor;
}



/*Inserta punteros a funciones*/
void insertar( hash_table*hash, char*llave, int(funcion)(int,int) )
{
        int posicion = codigo_hash( llave );
        hash->tabla[posicion] = funcion;
}


/*Devuelve la funcion donde deberia de estar en la tabla*/
int buscar_posicion( char*llave )
{
        int valor_llave = codigo_hash( llave );

        return valor_llave%CASILLAS;
}
