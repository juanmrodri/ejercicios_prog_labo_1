/*
 ============================================================================
 Name        : abm-dinamico-archivos.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	    	do{
	    		switch(opcion){
	    			case 1:
	    			//leer el archiv pd etexto
	    			break;
	    			case 2:
	    			//leer el archiv obinario
	    			break;
	    			case 3:
	    			//agregar empleado
	    			break;
	    			case 4:
	    			//editar empleado
	    			break;
	    			case 5:
	    			//remover empleado
	    			break;
	    			case 6:
	    			//listar empleado
	    			break;
	    			case 7:
	    			//guardar archivo text
	    			break;
	    			case 8:
	    			//guardar archivo binario
	    			break;
	    			case 9:

	    			break;
	    		}
	    	}while(opcion!=9);

	    return 0;
	return EXIT_SUCCESS;
}
