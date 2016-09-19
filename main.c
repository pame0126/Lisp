#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "hash_table.h"

int main()
{
        /*Inicializar siempre los punteros a funciones,
         *  sino da error 0 de la funcion no definida*/
        f_ptr_inicializa_operacion();

        hash_table *hash = hash_crear();
        
        hash_insertar(hash, MOD, modulo);

        f_ptr pruea = (f_ptr)hash_buscar(hash,MOD);
        int respuesta = pruea(7,7);
        printf("%d\n", respuesta);
        /*++++++++++++++++*/
        return 0;
}

