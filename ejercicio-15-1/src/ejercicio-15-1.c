/*
 ============================================================================
 Name        : ejercicio-15-1.c
 Author      : Rodriguez Juan Manuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN_ARRAY 6

void number_swap(int arrayInt[], int len);

int main(void) {
	setbuf(stdout, NULL);

	int arrayInt[LEN_ARRAY] = {2,5,8,25,2,352};

	// sin ordenar
	for(int i=0; i<LEN_ARRAY;i++)
	{
		printf("%d - ",arrayInt[i]);
	}

	printf("\n");
	//ordenado

	number_swap(arrayInt,LEN_ARRAY);


	for(int i=0; i<6;i++)
		{
			printf("%d - ",arrayInt[i]);
		}

	return EXIT_SUCCESS;
}

void number_swap(int arrayInt[], int len)
{
	/*
		 int auxNumber;
		if(*numberOne>*numberTwo)
		{
			auxNumber=*numberOne;
			*numberOne=*numberTwo;
			*numberTwo=auxNumber;
		}
	 */
	int flagSwap;
	int i;
	int buffer;
	int newLen;

			newLen=len-1;
	        do{
	            flagSwap = 0;
	            for(i = 0; i < newLen; i++)
	            {
	                if(arrayInt[i] < arrayInt[i+1])
	                {
	                    flagSwap = 1;
	                    buffer =arrayInt[i];
	                    arrayInt[i] =arrayInt[i+1];
	                    arrayInt[i+1] = buffer;
	                }
	            }
	            len--;
	        }while(flagSwap);

}
