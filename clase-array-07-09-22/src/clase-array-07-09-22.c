/*
 ============================================================================
 Name        : clase-array-07-09-22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void miniMaxSum(int arr_count, int* arr);

int main(void) {
	setbuf(stdout, NULL);

	int arr[] ={793810624, 895642170, 685903712, 623789054, 468592370};

	miniMaxSum(5,arr);



	return EXIT_SUCCESS;
}

void miniMaxSum(int arr_count, int* arr) {

int minNum;
int maxNum;
int flagFirst=0;
long long  minsAcum;
long long  maxsAcum;
long  minsResult;
long maxsResult;
int acumArray;
int i;

minsAcum=0;
maxsAcum=0;
acumArray=0;

if(arr_count!=0 && arr!=NULL)
	{
		for(i=0;i<arr_count;i++)
		{
			if(flagFirst==0)
			{
				flagFirst=1;
				minNum=arr[i];
				maxNum=arr[i];
				minsAcum=arr[i];
				maxsAcum=arr[i];
				printf("en el flag -> %I64d %I64d\n",minsAcum, maxsAcum);
			}
			else
			{
				if(arr[i]<minNum)
				{
					minNum=arr[i];
					minsAcum=minsAcum+minNum;
					printf("un nuevo minimo -> %d\n",minNum);
				}
				else
				{
					if(arr[i]>maxNum)
					{
						maxNum=arr[i];
						maxsAcum=maxsAcum+maxNum;
						printf("un nuevo maximo -> %d\n",maxNum);
					}
				}
			}
		}

		for(i=0;i<arr_count;i++)
		{
			acumArray =acumArray+arr[i];
		}

		minsResult=acumArray-maxNum;

		maxsResult=acumArray-minNum;

		printf("%ld %ld",minsResult, maxsResult);

	}

}