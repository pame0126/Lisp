
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define CASILLAS 100


/*Estructura tabla hash*/
typedef struct hash_table
{
         void*tabla[CASILLAS];//cambiar puntero void
         char*llaves[CASILLAS];
}hash_table;


hash_table*hash_crear();

void hash_destruir(hash_table*tabla);

int hash_codigo(char*clave);

void hash_insertar(hash_table*tabla,char*llave, void*elemento);

void*hash_buscar(hash_table*tabla,char*llave);

#endif
