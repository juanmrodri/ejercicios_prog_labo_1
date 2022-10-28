/*
 * empleado.c
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */

#include "empleado.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "empleado.h"

eEmpleado *
newEmpleado ()
{				//Pide memoria dinC!mica e inicializa los datos
  eEmpleado *nuevoEmpleado = NULL;
  nuevoEmpleado = (eEmpleado *) malloc (sizeof (eEmpleado));

  if (nuevoEmpleado != NULL)
    {
      nuevoEmpleado->legajo = 0;
      strcpy (nuevoEmpleado->nombre, " ");
      nuevoEmpleado->sexo = ' ';
      nuevoEmpleado->sueldo = 0;
    }

  return nuevoEmpleado;

}

eEmpleado* newEmpleadoParam (int legajo, char *nombre, char sexo, float sueldo)
{
  //Antes de cargar deben validarse los datos
  eEmpleado *nuevoEmpleado = newEmpleado ();

  if (nuevoEmpleado != NULL)
    {
      if (!(empleadoSetLegajo (nuevoEmpleado, legajo)
	    && empleadoSetNombre (nuevoEmpleado, nombre)
	    && empleadoSetSexo (nuevoEmpleado, sexo)
	    && empleadoSetSueldo (nuevoEmpleado, sueldo)))
	{
	  free (nuevoEmpleado);
	  nuevoEmpleado = NULL;	//INDICA FUNCION NO ANDUVO BIEN.
	}
    }

  return nuevoEmpleado;

}


int empleadoSetLegajo (eEmpleado * this, int legajo)
{

  int retorno = 0;

  if (this != NULL && legajo > 0)
    {
      this->legajo = legajo;
      retorno = 1;
    }

  return retorno;
}

int
empleadoSetSexo (eEmpleado * this, char sexo)
{
  int retorno = 0;

  if (this != NULL && (sexo == 'm' || sexo == 'f'))
    {
      this->sexo = sexo;
      retorno = 1;
    }

  return retorno;
}

int
empleadoSetNombre (eEmpleado * this, char *nombre)
{
  int retorno = 0;

  if (this != NULL && nombre != NULL)
    {
      strcpy (this->nombre, nombre);
      retorno = 1;
    }

  return retorno;
}

int
empleadoSetSueldo (eEmpleado * this, float sueldo)
{
  int retorno = 0;

  if (this != NULL && sueldo > 0)
    {
      this->sueldo = sueldo;
      retorno = 1;
    }

  return retorno;
}


int empleadoGetLegajo(eEmpleado* this, int *pLegajo){

   int retorno = 0;

    if (this != NULL && pLegajo!=NULL)
    {
        *pLegajo=this->legajo;
        retorno=1;

    }

    return retorno;
}

int empleadoGetNombre(eEmpleado* this, char * pNombre){

   int retorno = 0;

    if (this != NULL && pNombre!=NULL)
    {
        strcpy(pNombre,this->nombre);
        retorno=1;

    }

    return retorno;
}

int empleadoGetSexo(eEmpleado* this, char* pSexo){

   int retorno = 0;

    if (this != NULL && pSexo!=NULL)
    {
        *pSexo=this->sexo;
        retorno=1;

    }

    return retorno;
}

int empleadoGetSueldo(eEmpleado* this, float* pSueldo){

   int retorno = 0;

    if (this != NULL && pSueldo!=NULL)
    {
        *pSueldo=this->sueldo;
        retorno=1;

    }

    return retorno;
}
