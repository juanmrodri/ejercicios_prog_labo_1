/*
 ============================================================================
 Name        : ejercicio-2-3.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas (no más de 100), de cada persona debemos obtener los siguientes datos:

	número de cliente,
	estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
	edad( solo mayores de edad, más de 17),
	temperatura corporal (validar por favor)
	y genero('f' para femenino, 'm' para masculino, 'o' para no binario).

	NOTA: El precio por pasajero es de $600.
	Se debe informar (solo si corresponde):
	a) La cantidad de personas con estado  civil"viudo" de más de 60 años.
	b) el número de cliente y edad de la mujer soltera más joven.
	c) cuánto sale el viaje total sin descuento.
	d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroDeCliente;
	char estadoCivil;
	int edad;
	int temperaturaCorporal;
	char genero;
	int cantidadPasajeros;
	char respuestaContinuar; // s/n
	int cantidadPersonasViudMasDeSesenta;
	int banderaEdadMujer;
	int minMujerEdad;
	int maxMujerEdad;
	int numeroClienteMujerMasJoven;
	int costoDelViajeSinDescuento;
	int cantidadPasajerosMasSesenta;
	float costoDelViajeConDescuento;

	respuestaContinuar='s';
	cantidadPasajeros=0;
	cantidadPersonasViudMasDeSesenta=0;
	banderaEdadMujer=1;
	costoDelViajeSinDescuento=0;
	costoDelViajeConDescuento=0;
	cantidadPasajerosMasSesenta=0;

	while(respuestaContinuar=='s')
	{
		// n de cliente
		printf("Ingrese el numero de cliente: ");
		fflush(stdin);
		scanf("%d", &numeroDeCliente);

		// estado civil
		printf("Ingrese el estado civil (s para soltero, c para casado o v viudo): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);

		while(estadoCivil!='s' && estadoCivil!='c' && estadoCivil!='v')
		{
			printf("Por favor ingrese un estado civil valido (s para soltero, c para casado o v viudo): ");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}

		// edad
		printf("Ingrese la edad: ");
		fflush(stdin);
		scanf("%d", &edad);

		while(edad<18 || edad>99)
		{
		printf("El cliente debe ser mayor de 17 anos y tener menos de 100 anos: ");
		fflush(stdin);
		scanf("%d", &edad);
		}

		// temperatura corporal
		printf("Ingrese la temperatura corporal: ");
		fflush(stdin);
		scanf("%d", &temperaturaCorporal);
		while(temperaturaCorporal<34 || temperaturaCorporal>37)
		{
		printf("Ingrese una temperatura corporal valida: ");
		fflush(stdin);
		scanf("%d", &temperaturaCorporal);
		}

		// genero
		printf("Ingrese el genero del pasajero (f para femenino, m para masculino, o para no binario): ");
		fflush(stdin);
		scanf("%c", &genero);

		while(genero!='f' && genero!='m' && genero!='o')
		{
			printf("Por favor ingrese un genero valido (f para femenino, m para masculino, o para no binario): ");
			fflush(stdin);
			scanf("%c", &genero);
		}

		// punto a

		if(estadoCivil=='v' && edad>59)
		{
			cantidadPersonasViudMasDeSesenta++;
		}

		// punto b
		if(genero=='f' && estadoCivil=='s')
		{
			if(banderaEdadMujer==1)
			{
				banderaEdadMujer=0;
				minMujerEdad=edad;
				maxMujerEdad=edad;
			}
			else
			{
				if(edad<minMujerEdad)
				{
					minMujerEdad=edad;
					numeroClienteMujerMasJoven=numeroDeCliente;
				}
				else
				{
					if(edad>maxMujerEdad)
					{
						maxMujerEdad=edad;
					}
				}
			}
		}

		// conteo de pasajeros

		cantidadPasajeros++;

		// conteo de pasajeros +60

		if(edad>60)
		{
			cantidadPasajerosMasSesenta++;
		}

		if(cantidadPasajeros==100)
		{
			break;
		}

		// pregunta para continuar o finalizar
		printf("Desea ingresar otro pasajero? (s/n): ");
		fflush(stdin);
		scanf("%c", &respuestaContinuar);
	}

	// punto c

	costoDelViajeSinDescuento=(cantidadPasajeros)*600;

	// prints

	if(cantidadPersonasViudMasDeSesenta!=0)
	{
		printf("La cantidad de personas viudas con mas de sesenta anios es: %d\n", cantidadPersonasViudMasDeSesenta);
	}

	if(banderaEdadMujer!=1)
	{
		printf("El numero de cliente(%d)y la edad(%d) de la mujer soltera mas joven\n", numeroClienteMujerMasJoven,minMujerEdad);
	}

	if(costoDelViajeSinDescuento!=0)
	{
		printf("El costo del viaje sin descuento es: $ %d\n", costoDelViajeSinDescuento);
	}

	// punto d

	if(cantidadPasajerosMasSesenta!=0)
	{
		if(cantidadPasajerosMasSesenta==cantidadPasajeros/2)
		{
			costoDelViajeConDescuento=((float)costoDelViajeSinDescuento*25)/100;
			printf("El costo del viaje con descuento es: $ %.2f\n",costoDelViajeConDescuento);
		}
	}

	return EXIT_SUCCESS;
}
