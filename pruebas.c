#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <stdio.h>
#include <cmocka.h>

#include "src/operaciones.h"
#include "src/hash_table.h"

/*Crear y destruir tabla hash*/
void test_tabla_hash_crear_destruir()
{
        struct hash_table*nuevo = hash_crear();
        assert_non_null(nuevo);
        hash_destruir(nuevo);
        nuevo = NULL;
        assert_null(nuevo);
}

void test_tabla_hash_insertar()
{

}

int main(void)
{
        const UnitTest tests[] =
    {
        unit_test(test_tabla_hash_crear_destruir)
    };
    return run_tests(tests);
        return 0;
}

