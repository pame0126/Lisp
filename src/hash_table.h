
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define CASILLAS 100


/*Estructura tabla hash*/
extern struct hash_table{
         void*tabla[CASILLAS];//cambiar puntero void
         char*llaves[CASILLAS];
}hash_table;


extern struct hash_table*hash_crear();

extern void hash_destruir(struct hash_table*tabla);

extern int hash_codigo(char*clave);

extern void hash_insertar(struct hash_table*tabla,char*llave, void*elemento);

extern void*hash_buscar(struct hash_table*tabla,char*llave);

#endif
