#include <stdio.h>

#include "hash_table.h"
//~ #include "funciones.h"
#include "operaciones.h"



int main()
{
	sumar = suma;
        //~ printf("and %d\n", codigo_hash("and"));
        //~ printf("or %d\n", codigo_hash("or"));
        //~ printf("not %d\n", codigo_hash("not"));
        
        //~ printf("\n+ %d\n", codigo_hash("+"));
        //~ printf("- %d\n", codigo_hash("-"));
        //~ printf("* %d\n", codigo_hash("*"));
        //~ printf("modulo %d\n", codigo_hash("mod"));
        //~ printf("quotient %d\n", codigo_hash("/"));
        
        //~ printf("\n= %d\n", codigo_hash("="));
        //~ printf("< %d\n", codigo_hash("<"));
        //~ printf("> %d\n", codigo_hash(">"));
        //~ printf("<= %d\n", codigo_hash("<="));
        //~ printf(">= %d\n", codigo_hash(">="));
        //~ bool actual = false;
        //~ printf("%d\n",actual);
        
        //~ hash_table*nuevo = crear_tabla();
        //~ int res, pos=buscar_posicion("+");
        //~ res = (nuevo->tabla[pos])(3,7);
        inicializar_punteros();
        
        printf("+ %d\n",sumar(3,4));
        printf("- %d\n",restar(3,2));
        printf("* %d\n",multiplicar(3,3));
        printf("div %d\n",quotient(20,5) );
        printf("mod %d\n",modulo(7,2));
        
        return 0;
}

