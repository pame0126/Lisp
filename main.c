#include <stdio.h>

#include "hash_table.h"
#include "operaciones.h"

int main()
{
        inicializar_punteros();
        hash_table*nuevo = crear_tabla();

        int pos = (buscar_posicion(nuevo,AND))(3,0);

        printf("%d\n",pos);
        return 0;
}

