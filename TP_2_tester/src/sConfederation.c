/*
 * sConfederation.c
 *
 *  Created on: 20 oct 2022
 *      Author: juanm
 */

#include "sConfederation.h"

#define EMPTY 1
#define OCCUPIED 0

// static functions

static int newIdGenerator(void);

// static developing

static int newIdGenerator(void)
{
	static int cont=10000;
	return cont++;
}

int sConfederation_initArray(sConfederation pArray[],int len)
{
	int ret=-1;

		if(pArray!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				pArray[i].isEmpty = EMPTY;
			}
			ret=0;
		}

	return ret;
}

void sConfederation_forceLoad(sConfederation pArray[],int len, char name[], char region[], int yearOfCreation)
{
	int indexFree;
	if(pArray!=NULL && len>0 && name!=NULL && region!=NULL && yearOfCreation>1862)
	{
		indexFree=sConfederation_findEmptyArrayPosition(pArray, len);
		pArray[indexFree].id=newIdGenerator();
		strncpy(pArray[indexFree].name,name,sizeof(pArray[indexFree].name));
		strncpy(pArray[indexFree].region,region,sizeof(pArray[indexFree].region));
		pArray[indexFree].yearOfCreation=yearOfCreation;
		pArray[indexFree].isEmpty=OCCUPIED;
	}
}

int sConfederation_findEmptyArrayPosition(sConfederation pArray[],int len)
{
	int index=-1;
		if(pArray!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(pArray[i].isEmpty==EMPTY)
				{
					index = i;
					break;
				}
			}
		}
	return index;
}

int sConfederation_findConfederationById(sConfederation pArray[],int len, int id)
{
	int ret=-1;

	if(pArray!=NULL && len>0 && id>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].id==id && pArray[i].isEmpty==OCCUPIED)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int sConfederation_findIdByPos(sConfederation pArray[],int len, int auxPos)
{
	int id=-1;
	int auxIndex;
	if(pArray!=NULL && len>0 && auxPos>-1)
			{
				for(int i=0;i<len;i++)
				{
					auxIndex = auxPos-1;
					id = pArray[auxIndex].id;
				}
			}
	return id;
}

int sConfederation_isConfederationAdded(sConfederation pArray[],int len)
{
	int ret=-1;

		if(pArray!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(pArray[i].isEmpty==OCCUPIED)
				{
					ret=0;
					break;
				}
			}
		}

		return ret;
}

int sConfederation_load(sConfederation pArray[],int len)
{
	int ret=-1;
	int indexFree;
	char auxName[50];
	char auxRegion[50];
	int auxYearOfCreation;
	if(pArray!=NULL && len>0)
	{
		indexFree=sConfederation_findEmptyArrayPosition(pArray, len);
		if(indexFree>-1 && pArray[indexFree].isEmpty==EMPTY)
		{
			if(utn_getText(auxName, 50,"\nPor favor ingrese el nombre de la confederacion: ", "Error al ingresar el nombre\n", 2)==0)
			{
				if(utn_getText(auxRegion, 50,"\nPor favor ingrese la region de la confederacion: ", "Error al ingresar la region\n", 2)==0)
				{
					if(utn_getInt(&auxYearOfCreation, "\nPor favor ingrese el anio de creacion de la confederacion (1863-2022): ", "Error al ingresar el anio de creacion\n", 1863, 2022, 2)==0)
					{
						if(sConfederation_add(pArray, len, auxName, auxRegion, auxYearOfCreation)==0)
						{
							ret=0;
							printf("\nConfederacion ingresada correctamente!\n");
						}
					}
					else
							{
								ret=-1;
								printf("\nSe produjo un error el anio de creacion!\n");
							}
				}
				else
						{
							ret=-1;
							printf("\nSe produjo un error al ingresar la region!\n");
						}
			}
			else
					{
						ret=-1;
						printf("\nSe produjo un error al ingresar el nombre!\n");
					}
		}
	}

	return ret;
}

int sConfederation_add(sConfederation pArray[],int len, char name[], char region[], int yearOfCreation)
{
	int ret=-1;
	int indexFree;
	if(pArray!=NULL && len>0 && name!=NULL && region!=NULL && yearOfCreation>1863)
	{
		ret=0;
		indexFree=sConfederation_findEmptyArrayPosition(pArray, len);
		pArray[indexFree].id=newIdGenerator();
		strncpy(pArray[indexFree].name,name,sizeof(pArray[indexFree].name));
		strncpy(pArray[indexFree].region,region,sizeof(pArray[indexFree].region));
		pArray[indexFree].yearOfCreation=yearOfCreation;
		pArray[indexFree].isEmpty=OCCUPIED;
	}

	return ret;
}

int sConfederation_removeConfederation(sConfederation pArray[],int len, int id)
{
	int ret=-1;
	int auxResponse;
	if(pArray!=NULL && len>0  && id>0)
	{
		for(int i=0; i<len; i++)
				{
					if(pArray[i].id==id && pArray[i].isEmpty==OCCUPIED)
					{
						// el id no fue dado de baja entonces, mostramos
						printf("\nEsta por dar de baja: \n\n");
						sConfederation_printConfederation(pArray[i]);
						if(utn_getInt(&auxResponse, "\ndesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
						{
							switch(auxResponse)
							{
							case 1:
								ret=0;
								pArray[i].isEmpty=EMPTY;
								break;
							case 2:
								ret=-1;
								printf("\nNo se realizara la baja\n\n");
								break;
							}
						}
						else
						{
							ret=-1;
							printf("\nError al elegir opcion\n\n");
						}
					}
				}
	}

	return ret;
}

int sConfederation_modifyConfederation(sConfederation pArray[],int len, int pos, int option)
{
	int ret=-1;
	int auxResponse;
	char auxName[50];
	char auxRegion[50];
	int auxYearOfCreation;
	if(pArray!=NULL && len>0 && pos>-1 && option>0)
	{
		switch(option)
		{
		case 1:
			printf("\nEsta por modificar el nombre: %s\n",pArray[pos].name);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				if(auxResponse==1)
				{
					// se modifica
					if(utn_getText(auxName, 50,"\nPor favor ingrese el nuevo nombre de la confederacion: ", "Error al ingresar el nombre\n", 2)==0)
					{
						ret=0;
						strncpy(pArray[pos].name,auxName,sizeof(pArray[pos].name));
						printf("\nNombre modificado correctamente!\n");
						break;
					}
					else
					{
						// no se modifica
						ret=-1;
						printf("\nError al seleccionar\n\n");
					}
				}
				else
				{
					if(auxResponse==2)
					{
						// no se modifica
						ret=-1;
						printf("\nNo se modificara el nombre!\n\n");
						break;
					}
				}
			}
			else
			{
				// no se modifica
				ret=-1;
				printf("\nError al seleccionar\n\n");
			}
			break;
		case 2:
		printf("\nEsta por modificar la region: %s\n",pArray[pos].region);
		if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
		{
			if(auxResponse==1)
			{
				// se modifica
				if(utn_getText(auxName, 50,"\nPor favor ingrese nueva region de la confederacion: ", "Error al ingresar el nombre\n", 2)==0)
				{
					ret=0;
					strncpy(pArray[pos].region,auxRegion,sizeof(pArray[pos].region));
					printf("\nRegion modificada correctamente!\n");
					break;
				}
				else
				{
					// no se modifica
					ret=-1;
					printf("\nError al seleccionar\n\n");
				}
			}
			else
			{
				if(auxResponse==2)
				{
					// no se modifica
					ret=-1;
					printf("\nNo se modificara la region!\n\n");
					break;
				}
			}
		}
		else
		{
			// no se modifica
			ret=-1;
			printf("\nError al seleccionar\n\n");
		}
		break;
		case 3:
		printf("\nEsta por modificar el anio de creacion: %d\n",pArray[pos].yearOfCreation);
		if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
		{
			if(auxResponse==1)
			{
				// se modifica
				if(utn_getInt(&auxYearOfCreation, "\nPor favor ingrese el nuevo anio de creacion de la confederacion (1863-2022): ", "Error al ingresar el anio de creacion\n", 1863, 2022, 2)==0)
				{
					ret=0;
					strncpy(pArray[pos].region,auxRegion,sizeof(pArray[pos].region));
					printf("\nAnio de creacion modificado correctamente!\n");
					break;
				}
				else
				{
					// no se modifica
					ret=-1;
					printf("\nError al seleccionar\n\n");
				}
			}
			else
			{
				if(auxResponse==2)
				{
					// no se modifica
					ret=-1;
					printf("\nNo se modificara la region!\n\n");
					break;
				}
			}
		}
		else
		{
			// no se modifica
			ret=-1;
			printf("\nError al seleccionar\n\n");
		}
		break;
		}
	}
	return ret;
}

void sConfederation_printConfederation(sConfederation confederation)
{
	printf("| %-10d| %-16s | %-24s |  %-28d |\n",confederation.id,confederation.name,confederation.region,confederation.yearOfCreation);
}

void sConfederation_printConfederations(sConfederation pArray[],int len)
{
	if(pArray!=NULL && len>0)
	{
		// printeando asi, queda a la misma altura
		printf("===========================================================================================\n");
		printf("|   ID      |    NOMBRE        |     REGION               |      ANIO DE CREACION         |\n");
		printf("-------------------------------------------------------------------------------------------\n");
		for(int i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==OCCUPIED)
			{
				sConfederation_printConfederation(pArray[i]);
			}
		}
		printf("===========================================================================================\n");
		printf("\n\n");
	}
}
