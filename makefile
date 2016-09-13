

SALIDA = clisp

ARCHIVOS = hash_table.h hash_table.c funciones.h operaciones.h operaciones.c

all:
	gcc -std=c11 $(ARCHIVOS) main.c -lm -o $(SALIDA)
#para que sirva math.h usar -lm despues de los archivos
run:
	./$(SALIDA)
	
.PHONY clean:
	rm $(SALIDA)
