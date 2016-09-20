SALIDA = ExprLisp

HASH = hash_table.h hash_table.c 
FUNC = funciones.h funciones.c
OPER = operaciones.h operaciones.c
ARBOL = arbol_binario.h arbol_binario.c

ARCHIVOS = $(FUNC) $(HASH) $(OPER) $(ARBOL)
all:
	gcc -std=c11  main.c $(ARCHIVOS) -lm -o $(SALIDA)
#para que sirva math.h usar -lm despues de los archivos
run:
	./$(SALIDA)
	
.PHONY clean:
	rm $(SALIDA)
