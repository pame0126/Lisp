#ifndef ARBOL_EXPRESION_H
#define ARBOL_EXPRESION_H

#include "arbol_binario.h"
#include "funciones.h"

char**split_plabra(char*palabra, int len);

void destruir_split_palabra(char**split);

//~ void aux_dividir_operandos_binario(char***operandos, char**ecuacion, int j, int i);

void quitar_parentesis_operandor(char**operandos, char**ecuacion, int i);

char***dividir_operandos_binario(char**expresion);

char**expresion_dividir_operador_unario(char**ecuacion);

arbol*genera_arbol_expresion(char**expresion);
#endif
