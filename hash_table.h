
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define CASILLAS 20


typedef struct hash_table
{
         int(*tabla[CASILLAS])(int,int);
}hash_table;


hash_table*crear_tabla();

void eliminar_tabla(hash_table*tabla);

int codigo_hash(char*clave);

void insertar(hash_table*tabla,char*llave,int(f)(int,int));

int buscar_posicion(char*llave);

#endif
