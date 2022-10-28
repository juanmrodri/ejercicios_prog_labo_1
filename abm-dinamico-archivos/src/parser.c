/*
 * parser.c
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */

#include "parser.h"

int parseEmpleadoDesderTexto(FILE* pArchivo, eEmpleado** empleados)
{
    int retorno = 0;
    char auxlegajo[2000];
    char auxnombre[2000];
    char auxsexo[2000];
    char auxsueldo[2000];
    int auxLegajoInt;
    float auxSueldoFlo;
    eEmpleado* pEmpleado;
    int retornoVariable;

    if(pArchivo!=NULL && empleados!=NULL)
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]",auxlegajo,auxnombre,auxsexo,auxsueldo); //LECTURA FANTASMA
        do{
            retornoVariable = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]",auxlegajo,auxnombre,auxsexo,auxsueldo);
            if(retornoVariable == 4)
            {
                auxLegajoInt = atoi(auxlegajo);
                auxSueldoFlo = atof(auxsueldo);

               pEmpleado = newEmpleadoParam(auxLegajoInt, auxnombre, auxsexo, auxSueldoFlo);

               if(pEmpleado != NULL){

                   //ACA LLAMO A LA FUNCION QUE ASIGNA MI PUNTERO EMPLEADO, AL ARRAY DE PUNTEROS EMPLEADOS.
               }
               retorno = 1;
            }else{

                retorno = 0;
                break; //si no leyo 4 variables break. se rompe
            }

        }while(!feof(pArchivo));
    }

    return retorno;
}

int parserEmpleadoDesdeBinario(FILE* pArchivo, eEmpleado** empleados){

    int retorno = 0;
    int auxLegajo;
    char auxNombre[2000];
    char auxSexo;
    float auxSueldo;
    eEmpleado* pEmpleado;
    int retornoVariable;

    if(pArchivo!=NULL && empleados!=NULL)
    {

        do{
            retornoVariable = fread(pEmpleado, sizeof(eEmpleado), 1, pArchivo);

            if(retornoVariable == 1)
            {
                if(empleadoGetLegajo(pEmpleado, &auxLegajo) &&
                    empleadoGetNombre(pEmpleado, auxNombre) &&
                    empleadoGetSexo(pEmpleado, auxSexo) &&
                    empleadoGetSueldo(pEmpleado, &auxSueldo)){

                    //ACA LLAMO A LA FUNCION DONDE VA A PASAR ALGO...

                }

               retorno = 1;
            }else{

                retorno = 0;
                break; //si no leyo bien el archivo.
            }

        }while(!feof(pArchivo));
    }

    return retorno;
}



