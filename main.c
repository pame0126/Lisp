#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
#include "hash_table.h"
#include "arbol_binario.h"

int main()
{
        //~ /*Inicializar siempre los punteros a funciones,
         //~ *  sino da error 0 de la funcion no definida*/
        f_ptr_inicializa_operacion();

        //~ hash_table *hash = hash_crear();
        
        //~ f_ptr_inserciones_hash(hash);
        //~ f_ptr pruea = (f_ptr)hash_buscar(hash,NOT);
        //~ int respuesta = pruea(7,0);
        //~ printf("%d\n", respuesta);
        /*++++++++++++++++*/
        arbol*expr = arbol_crear();
        int num = 31;
        void*valor = &num;
        
        expr->inicio = nodo_crear(31,valor);
        
        nodo_insertar_der(expr->inicio, nodo_crear(1,"3"));
        nodo_insertar_izq(expr->inicio, nodo_crear(4,restar));
        
		printf("%d\n",nodo_es_hoja(expr->inicio));

        return 0;
}

