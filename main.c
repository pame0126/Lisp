#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
//~ #include "hash_table.h"

int sumasss(int a,int b){
	return a+b;
}
f_ptr add;

int main()
{
	/*Funciona void* con f_ptr*/
        add = sumasss;
        void*arr = (void*)malloc(sizeof(f_ptr));
        arr = add;
        f_ptr pruea = (f_ptr)(arr);
        
        printf("%d\n",pruea(3,3));
        /*++++++++++++++++*/
        return 0;
}

