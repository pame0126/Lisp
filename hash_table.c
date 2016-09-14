#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"


/*Crea el espacio en memoria de la tabla*/
hash_table*crear_tabla()
{
        hash_table*nueva = calloc(1,sizeof(hash_table));

        /*Aritmetica*/
        insertar( nueva, SUM, sumar);
        insertar( nueva, RES, restar);
        insertar( nueva, MUL, multiplicar);
        insertar( nueva, DIV, quotient);
        insertar( nueva, MOD, modulo);
        /*Comparativa*/
        insertar( nueva, IGUAL, igual);
        insertar( nueva, MAYOR, mayor);
        insertar( nueva, MENOR, menor);
        insertar( nueva, MAYOR_IGUAL, mayor_igual);
        insertar( nueva, MENOR_IGUAL, menor_igual);
        /*Logica*/
        insertar( nueva, AND, and);
        insertar( nueva, OR, or);
        insertar( nueva, NOT, not);
        
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
                valor+=*( clave + i )*(int)pow( (double)31, (double)resta - i );
                i++;
        }

        return valor;
}



/*Inserta punteros a funciones*/
void insertar( hash_table*hash, char*llave, f_ptr funcion )
{
        int posicion = codigo_hash( llave )%CASILLAS;
        *( hash->tabla + posicion ) = funcion;
}


/*Devuelve la funcion donde deberia de estar en la tabla*/
f_ptr buscar_posicion( hash_table*hash, char*llave )
{
        int posicion = codigo_hash( llave )%CASILLAS;
        return *( hash->tabla + posicion );
}
