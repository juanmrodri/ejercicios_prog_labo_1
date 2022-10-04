/*
 * sResource.c
 *
 *  Created on: 1 oct 2022
 *      Author: juanm
 */

#include "sResource.h"
#include "utn_input.h"


#define EMPTY 1
#define OCCUPIED 0

// static functions

static int newIdGenerator(void);

// static developing

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}



int resource_initArray(Resource pArray[], int len)
{
	int ret=-1;

	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			pArray[i].isEmpty = EMPTY;
		}
	}

	return ret;
}

int resource_findEmptyArrayPosition(Resource pArray[], int len)
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

int resource_load(Resource pArrayRes[], int lenRes, Type pArrayType[], int lenType)
{
	int ret=-1;
	char auxDescripcion[21];
	float auxPricePerHour;
	int auxType;
	int auxTypeId;
	int indexFree;

	if(pArrayRes!=NULL && lenRes>0)
	{
		indexFree = resource_findEmptyArrayPosition(pArrayRes, lenRes);

		if(indexFree>-1 && pArrayRes[indexFree].isEmpty==EMPTY)
		{
			printf("\n----------------------------------------------\n");
			if(utn_getText(auxDescripcion, 21, "\nPor favor ingrese la descripcion del recurso: ", "Error al ingresar la descripcion\n", 2)==0)
			{
				if(utn_getFloat(&auxPricePerHour, "\nPor favor ingrese el precio por hora ($100 - $1500000): ", "Error al ingresar el precio\n", 100, 1500000, 2)==0)
				{
					printf("\n----------------------------------------------\n\n");
					// mostramos los tipos disponibles para poder elegir
					type_printTypes(pArrayType, lenType);
					if(utn_getInt(&auxType, "Por favor ingrese el tipo de recurso (1- Locucion 2- Animacion 3- Iluminacion 4- Dj): ", "Error al ingresar el tipo\n", 1, 4, 2)==0)
					{
							// con esto obtenemos el id y lo mandamos al add como llave foranea de Resource
							auxTypeId = type_findIdByPos(pArrayType,lenType, auxType);

							resource_add(pArrayRes, lenRes, auxDescripcion, auxPricePerHour, auxTypeId);
					}
					else
					{
						ret=-1;
						printf("Se produjo un error al ingresar el tipo!\n");
					}

				}
				else
				{
					ret=-1;
					printf("Se produjo un error al ingresar el precio por hora!\n");
				}
			}
			else
			{
				ret=-1;
				printf("Se produjo un error al ingresar la descripcion!\n");
			}
		}
		else
		{
			ret=-1;
			printf("Se produjo un error al intentar cargar!\n");
		}
	}
	else
	{
		ret=-1;
		printf("Error al realizar la carga!\n");
	}

	return ret;
}

int resource_add(Resource pArray[], int len, char description[], float price, int idType)
{
	int ret=-1;
	int indexFree; // aca se guardara el primer index libre

	if(pArray!=NULL && len>0 && description!=NULL && price>0) // typeId>0
	{
		indexFree = resource_findEmptyArrayPosition(pArray, len);
		pArray[indexFree].idResource = newIdGenerator();
		strncpy(pArray[indexFree].description,description,sizeof(pArray[indexFree].description));
		pArray[indexFree].pricePerHour=price;
		pArray[indexFree].typeId=idType;
		pArray[indexFree].isEmpty=OCCUPIED; // importantisimo cambiar el estado
	}

	return ret;
}

int resource_printResource(Resource pArray[])
{
	int ret=-1;
	if(pArray!=NULL)
	{
		printf("id: %d\n"
				"Descripcion:%s\n"
				"Precio por hora: $%.2f\n"
				"IdType: %d\n\n", pArray->idResource,pArray->description,pArray->pricePerHour,pArray->typeId);
	}
	return ret;
}

int resource_printResources(Resource pArray[], int len)
{
	int ret=-1;
	if(pArray!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==OCCUPIED)
			{
				resource_printResource(&pArray[i]);
			}
		}
	}
	return ret;
}


