/*
 ============================================================================
 Name        : clase-08-09-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 static cumple con dos funciones b�sicas dentro del lenguaje C:

1-Al usarlo sobre variables que est�n dentro de una funci�n, permite que el valor de las mismas persista entre llamadas

2-Al usarlo sobre funciones o variables de �mbito global, garantiza que dicho elemento (variable o funci�n) solo exista en la unidad de compilaci�n en la que se encuentre declarado.


 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}
