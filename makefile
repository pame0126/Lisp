TEST_1 = pruebas.c
SALIDA = Tests

OP = src/operaciones.h src/operaciones.h
TABLA = src/hash_table.h src/hash_table.c


all:
	gcc $(TABLA) $(OP) $(TEST_1) -lm -lcmocka -o $(SALIDA)

test_valgrind:
	valgrind ./$(SALIDA)
clean:
	rm $(SALIDA)
