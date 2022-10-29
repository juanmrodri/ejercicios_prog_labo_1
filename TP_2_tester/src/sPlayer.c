/*
 * sPlayer.c
 *
 *  Created on: 18 oct 2022
 *      Author: juanm
 */
#include "sPlayer.h"

#define EMPTY 1
#define OCCUPIED 0

// static functions

static int newIdGenerator(void);

static void getPositionSelectedToArrayChar(int auxPositionSelected, char auxPosition[]);

// static developing

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}

static void getPositionSelectedToArrayChar(int auxPositionSelected, char auxPosition[])
{
	char auxLen[50];

	switch(auxPositionSelected)
	{
	case 1:
		strncpy(auxPosition,"Arquero",sizeof(auxLen));
		break;
	case 2:
		strncpy(auxPosition,"Defensor",sizeof(auxLen));
		break;
	case 3:
		strncpy(auxPosition,"Mediocampista",sizeof(auxLen));
		break;
	case 4:
		strncpy(auxPosition,"Delantero",sizeof(auxLen));
		break;
	}
}


int sPlayer_initArray(sPlayer pArray[],int len)
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

void sPlayer_forceLoad(sPlayer pArray[], int len, char name[], char position[], short  shirtNumber, float salary, short contractYears, int confederationId)
{
	int indexFree;
	indexFree=sPlayer_findEmptyArrayPosition(pArray, len);
	pArray[indexFree].id=newIdGenerator();
	strncpy(pArray[indexFree].name,name,sizeof(pArray[indexFree].name));
	strncpy(pArray[indexFree].position,position,sizeof(pArray[indexFree].position));
	pArray[indexFree].shirtNumber=shirtNumber;
	pArray[indexFree].salary=salary;
	pArray[indexFree].contractYears=contractYears;
	pArray[indexFree].confederationId=confederationId;
	pArray[indexFree].isEmpty=OCCUPIED;
}

int sPlayer_findEmptyArrayPosition(sPlayer pArray[],int len)
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

int sPlayer_findPlayerById(sPlayer pArray[],int len, int id)
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

int sPlayer_findPlayerConfederationId(sPlayer pArray[],int len, int id)
{
	int ret=-1;

		if(pArray!=NULL && len>0 && id>0)
		{
			for(int i=0;i<len;i++)
			{
				if(pArray[i].id==id && pArray[i].isEmpty==OCCUPIED)
				{
					ret=pArray[i].confederationId;
					break;
				}
			}
		}
		return ret;
}

int sPlayer_isPlayerAdded(sPlayer pArray[],int len)
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

int sPlayer_load(sPlayer pArray[], int len, int confederationId)
{
	int ret=-1;
	int indexFree;
	char auxName[50];
	char auxPosition[50];
	int auxPositionSelected; // es nos permite obtener la seleccion de la posicion y pasarla despues a cadena de caracteres
	short auxShirtNumber;
	float auxSalary;
	short auxContractYears;

	if(pArray!=NULL && len>0)
	{
		indexFree=sPlayer_findEmptyArrayPosition(pArray, len);
		if(indexFree>-1 && pArray[indexFree].isEmpty==EMPTY && confederationId>99)
		{
			if(utn_getText(auxName, 50,"\nPor favor ingrese el nombre del jugador: ", "Error al ingresar el nombre\n", 2)==0)
			{
				if(utn_getInt(&auxPositionSelected, "\nPor favor ingrese la posicion del jugador\n1-ARQUERO 2-DEFENSOR 3-MEDIOCAMPISTA 4-DELANTERO:  ", "Error al ingresar la posicion\n", 1, 4, 2)==0)
				{
					getPositionSelectedToArrayChar(auxPositionSelected, auxPosition);

					if(utn_getShort(&auxShirtNumber, "\nPor favor ingrese el numero de camiseta: ", "Error al ingresar el numero de camiseta\n", 1, 99, 2)==0)
					{
						if(utn_getFloat(&auxSalary, "\nPor favor ingrese el sueldo del jugador (50000 a 50000000): ", "Error al ingresar el sueldo\n", 50000, 50000000, 2)==0)
						{
							if(utn_getShort(&auxContractYears, "\nPor favor ingrese los anios de contrato (1 a 5): ", "Error al ingresar los anios de contrato\n", 1, 5, 2)==0)
							{
								// se ingreso todo correctamente
								if(sPlayer_add(pArray, len, auxName, auxPosition, auxShirtNumber, auxSalary, auxContractYears, confederationId)==0)
								{
									ret=0;
									printf("\nJugador ingresado correctamente!\n");
								}
							}
							else
									{
										ret=-1;
										printf("\nSe produjo un error al ingresar los anios de contrato!\n");
									}
						}
						else
								{
									ret=-1;
									printf("\nSe produjo un error al ingresar el sueldo!\n");
								}
					}
					else
							{
								ret=-1;
								printf("\nSe produjo un error al ingresar el numero de camiseta!\n");
							}
				}
				else
						{
							ret=-1;
							printf("\nSe produjo un error al ingresar la posicion!\n");
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
int sPlayer_add(sPlayer pArray[], int len, char name[], char position[], short  shirtNumber, float salary, short contractYears, int confederationId)
{
	int ret=-1;
	int indexFree;
	if(pArray!=NULL && len>0 && name!=NULL && position!=NULL && shirtNumber>0 && salary>49000 && salary<50000001 && contractYears>0 && contractYears<6 && confederationId>99)
	{
		ret=0;
		indexFree=sPlayer_findEmptyArrayPosition(pArray, len);
		pArray[indexFree].id=newIdGenerator();
		strncpy(pArray[indexFree].name,name,sizeof(pArray[indexFree].name));
		strncpy(pArray[indexFree].position,position,sizeof(pArray[indexFree].position));
		pArray[indexFree].shirtNumber=shirtNumber;
		pArray[indexFree].salary=salary;
		pArray[indexFree].contractYears=contractYears;
		pArray[indexFree].confederationId=confederationId; // llave foranea
		pArray[indexFree].isEmpty=OCCUPIED;
	}

	return ret;
}

int sPlayer_removePlayer(sPlayer pArray[],int len, int id, char auxConfederationName[])
{
	int ret=-1;
	int auxResponse;

	if(pArray!=NULL && len>0  && id>0 && auxConfederationName!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(pArray[i].id==id && pArray[i].isEmpty==OCCUPIED)
			{
				// el id no fue dado de baja entonces, mostramos
				printf("\nEsta por dar de baja: \n\n");
				sPlayer_printPlayer(pArray[i],auxConfederationName);
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

int sPlayer_ModifyPlayer(sPlayer pArray[],int len, int pos, char auxConfederationName[], int option)
{
	int ret=-1;
	int auxResponse;
	char auxName[50];
	char auxPosition[50];
	int auxPositionSelected;
	short int auxShirtNumber;
	float auxSalary;
	short int auxContractYears;

	if(pArray!=NULL && len>0 && pos>-1 && auxConfederationName!=NULL && option>0)
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
					if(utn_getText(auxName, 50,"\nPor favor ingrese el nuevo nombre del jugador: ", "Error al ingresar el nombre\n", 2)==0)
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
			printf("\nEsta por modificar la posicion: %s\n",pArray[pos].position);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				if(auxResponse==1)
				{
					// se modifica
					if(utn_getInt(&auxPositionSelected, "\nPor favor ingrese la nueva posicion del jugador\n1-ARQUERO 2-DEFENSOR 3-MEDIOCAMPISTA 4-DELANTERO:  ", "Error al ingresar la posicion\n", 1, 4, 2)==0)
					{
						// convertimos la posicion seleccionada en cadena de caracteres
						getPositionSelectedToArrayChar(auxPositionSelected, auxPosition);

						ret=0;
						strncpy(pArray[pos].position,auxPosition,sizeof(pArray[pos].position));
						printf("\nPosicion modificada correctamente!\n");
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
						printf("\nNo se modificara la posicion\n\n");
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
			printf("\nEsta por modificar el numero de camiseta: %hd\n",pArray[pos].shirtNumber);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				if(auxResponse==1)
				{
					// se modifica
					if(utn_getShort(&auxShirtNumber, "\nPor favor ingrese el nuevo numero de camiseta: ", "Error al ingresar el numero de camiseta\n", 1, 99, 2)==0)
					{
						ret=0;
						pArray[pos].shirtNumber=auxShirtNumber;
						printf("\nNumero de camiseta modificado correctamente!\n");
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
						printf("\nNo se modificara el numero de camiseta\n\n");
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
		case 5:
			printf("\nEsta por modificar el sueldo: $%.2f\n",pArray[pos].salary);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				if(auxResponse==1)
				{
					// se modifica
					if(utn_getFloat(&auxSalary, "\nPor favor ingrese el nuevo sueldo del jugador (50000 a 50000000): ", "Error al ingresar el sueldo\n", 50000, 50000000, 2)==0)
					{
						ret=0;
						pArray[pos].salary=auxSalary;
						printf("\nSueldo modificado correctamente!\n");
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
						printf("\nNo se modificara el sueldo\n\n");
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
		case 6:
			printf("\nEsta por modificar los anio(s) de contrato: %hd\n",pArray[pos].contractYears);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				if(auxResponse==1)
				{
					// se modifica
					if(utn_getShort(&auxContractYears, "\nPor favor ingrese los anios de contrato (1 a 5): ", "Error al ingresar los anios de contrato\n", 1, 5, 2)==0)
					{
						ret=0;
						pArray[pos].contractYears=auxContractYears;
						printf("\nAnio(s) de contrato modificado correctamente!\n");
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
						printf("\nNo se modificaran los anio(s) de contrato\n\n");
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

int sPlayer_ModifyPlayerConfederation(sPlayer pArray[],int len, int pos, char auxConfederationName[], int auxIdConfederationSelectedToModify)
{
	int ret=-1;
	int auxResponse;

		if(pArray!=NULL && len>0 && pos>-1 && auxConfederationName!=NULL && auxIdConfederationSelectedToModify>-1)
		{
			printf("\nEsta por modificar la confederacion: %s\n",auxConfederationName);
			if(utn_getInt(&auxResponse, "\nDesea continuar? (1 si- 2 no): ", "\nPor favor elija una opcion correcta", 1, 2, 2)==0)
			{
				switch(auxResponse)
				{
				case 1:
					ret=0;
					pArray[pos].confederationId=auxIdConfederationSelectedToModify;
					break;
				case 2:
					// no se modifica
					ret=-1;
					printf("\nNo se modificara la confederacion!\n\n");
					break;
				}
			}
			else
			{
				// no se modifica
				ret=-1;
				printf("\nError al elegir opcion\n\n");
			}
		}

	return ret;
}


void sPlayer_printPlayer(sPlayer player, char auxConfederationName[])
{
	printf("===================================================================================================================================================\n");
	printf("|   ID      |    NOMBRE               |     POSICION        |      N DE CAMISETA     |   SUELDO       |   CONFEDERACION   |   ANIOS DE CONTRATO   |\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|   %-8d|    %-20s |   %-17s |          %-13hd |  %-13.2f |      %-12s |          %-12hd |\n", player.id,player.name,player.position,player.shirtNumber,player.salary,auxConfederationName,player.contractYears);
}

