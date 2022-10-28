/*
 ============================================================================
 Name        : ejercicio-17-1.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
	int idProducto;
	char descripcion[21];
	char nacionalidad[21];
	int tipo;
	float precio;

}eProducto;

int main(void) {
	setbuf(stdout, NULL);

	eProducto nuevoProducto;

	nuevoProducto.idProducto=1;
	strncpy(nuevoProducto.descripcion,"Iphone",sizeof(nuevoProducto.descripcion));
	strncpy(nuevoProducto.nacionalidad,"USA",sizeof(nuevoProducto.nacionalidad));
	nuevoProducto.tipo=1000; // suponiendo que esto es un idforaneo
	nuevoProducto.precio=150000;

	printf("Id: %d\nDescripcion:%s\nNacionalidad:%s\nTipo: %d\nPrecio: $%.2f\n",nuevoProducto.idProducto,nuevoProducto.descripcion,nuevoProducto.nacionalidad,nuevoProducto.tipo,nuevoProducto.precio);

	return EXIT_SUCCESS;
}
