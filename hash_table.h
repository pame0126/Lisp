
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define CASILLAS 100

/*Macros, punteros y tipo de funciones con ptr*/
#include "funciones.h"

/*Estructura tabla hash*/
typedef struct hash_table
{
         f_ptr tabla[CASILLAS];
}hash_table;


hash_table*crear_tabla();

void eliminar_tabla(hash_table*tabla);

int codigo_hash(char*clave);

void insertar(hash_table*tabla,char*llave, f_ptr funcion);

f_ptr buscar_posicion(hash_table*tabla,char*llave);

#endif
