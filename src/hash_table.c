#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"


/*Crea el espacio en memoria de la tabla*/
struct hash_table*hash_crear()
{
        struct hash_table*nueva = calloc(1, sizeof(struct hash_table));
        return nueva;
}

/*Elimina la tabla liberando el espacio*/
void hash_destruir(struct hash_table*hash)
{
        free(hash);       //libera espacio
        hash = NULL;
}

/*Devuelve el codigo hash calculado por el string clave*/
int hash_codigo(char*clave)
{
        int i = 0;
        int n = strlen(clave);
        int valor = 0;
        int resta = n-1;

        //de i hasta n-1
        while (i < n){
                valor+=*(clave+i)*(int)pow((double)31,(double)resta-i);
                valor%=CASILLAS;
                i++;
        }
        return valor;
}

/*localizar la posicion mas proxima vacia*/
int hash_localizar_pos_vacio(struct hash_table*hash, char*llave, int posicion)
{
        for (int i = 0; i < CASILLAS ;i++){
                posicion = (posicion+i)%CASILLAS;
                /*Si encontro una posicion vacia*/
                if( hash->tabla[posicion] == NULL )
                {
                        return posicion;
                }
        }
}

/*Inserta punteros a funciones*/
void hash_insertar(struct hash_table*hash, char*llave, void* elemento)
{
        int posicion = hash_codigo(llave)%CASILLAS;
        /*si esta vacia en la tabla, es nueva y la inserta*/
        if (hash->tabla[posicion] == NULL){
                hash->tabla[posicion] = elemento;
                hash->llaves[posicion] = llave;
        }
        /*Si es igual el nombre de la misma llave,le cae encima
         * la funcion*/
        else if ( !strcmp(hash->llaves[posicion], llave)){
                hash->tabla[posicion] = elemento;
        }
        /*Si la llave resulto igual y no tiene los mismos caracteres
         * -->busca otra posicion vacia mas proxima*/
        else{
                posicion = hash_localizar_pos_vacio(hash, llave, posicion+1);
                hash->tabla[posicion] = elemento;
                hash->tabla[posicion] = llave;
        }
}

/*localizar la posicion donde esta la llave*/
int hash_localizar_pos_llave(struct hash_table*hash, char*llave, int posicion)
{
        for (int i = 0; i < CASILLAS ;i++){
                posicion = (posicion+i)%CASILLAS;
                /*Si encontro la posicion de la llave*/
                if ( !strcmp(hash->llaves[posicion], llave)){
                        return posicion;
                }
        }
        return -1;
}

/*Devuelve la funcion donde deberia de estar en la tabla*/
void*hash_buscar(struct hash_table*hash, char*llave)
{
        int posicion = hash_codigo(llave)%CASILLAS;
        /*Si la llave es igual a la posicion en arreglo de llaves*/
        if ( !strcmp(hash->llaves[posicion], llave)){
                return hash->tabla[posicion];
        }
        /*Si no*/
        else{
                posicion = hash_localizar_pos_llave( hash, llave, posicion+1);
                return (posicion > -1)?hash->tabla[posicion]:NULL;
        }

}
