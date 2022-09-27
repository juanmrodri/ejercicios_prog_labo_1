/*
 ============================================================================
 Name        : testers_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int toBinary(int number);

int main(void) {
	setbuf(stdout, NULL);

	int number=5;

	toBinary(number);


	return EXIT_SUCCESS;
}

int toBinary(int number)
{
	int auxNumber;
	int auxBinaryNumber;

	auxNumber=number;

	while(auxNumber!=1)
	{
		auxBinaryNumber=auxNumber%2;
		auxNumber=auxNumber/2;
		printf("Resultados: %d\n"
					"resto: %d\n",auxNumber,auxBinaryNumber);
	}

	return 0;
}

