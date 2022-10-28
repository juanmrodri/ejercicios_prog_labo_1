/*
 * empleado.h
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
    int legajo;
    char nombre[31];
    char sexo;
    float sueldo;
} eEmpleado;

eEmpleado* newEmpleado(); //encapsula el malloc
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo); //encapsula el malloc
int empleadoSetLegajo(eEmpleado* this, int legajo);
int empleadoSetNombre(eEmpleado* this, char* nombre);
int empleadoSetSueldo(eEmpleado* this, float sueldo);
int empleadoSetSexo(eEmpleado* this, char sexo);
int empleadoGetLegajo(eEmpleado* this, int *pLegajo);
int empleadoGetNombre(eEmpleado* this, char * pNombre);
int empleadoGetSexo(eEmpleado* this, char* pSexo);
int empleadoGetSueldo(eEmpleado* this, float* pSueldo);


#endif /* EMPLEADO_H_ */
