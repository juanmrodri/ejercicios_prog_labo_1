/*
 * controller.c
 *
 *  Created on: 27 oct 2022
 *      Author: juanm
 */


#include "controller.h"

int controlerCargarDesdeTexto(char* path, eEmpleado** empleados)
{
    int retorno=0;
    FILE* pArchivo;

    if(path!=NULL && empleados!=NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo!=NULL)
        {
            if(parseEmpleadoDesderTexto(pArchivo, empleados)){

                printf("Se leyo el archivo correctamente\n");

            }else{

                 printf("ERROR al leer el archivo\n");
            }

        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

int controlerCargarDesdeBinario(char* path, eEmpleado** empleados)
{
    int retorno=0;
    FILE* pArchivo;

    if(path!=NULL && empleados!=NULL)
    {
        pArchivo=fopen(path,"rb");

        if(pArchivo!=NULL)
        {
            if(parseEmpleadoDesderTexto(pArchivo, empleados)){

                printf("Se leyo el archivo correctamente\n");

            }else{

                 printf("ERROR al leer el archivo\n");
            }

        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

