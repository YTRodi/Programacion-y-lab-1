#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char buffer[4][30];
    int cant = 0;//cantidad de variables que nos pudo retornar.

    /*char id[10];
    char nombre[50];
    char horasTrabajadas[10];
    char sueldo[30];*/

    //int control;
    Employee* auxEmple;

    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant < 4)
        {
            break;
        }
        else
        {
            /***
            buffer[0] es el id;
            buffer[1] es el nombre;
            buffer[2] son las horas trabajadas;
            buffer[3] es el sueldo;
            ***/
            auxEmple = employee_newParametros((buffer[0]),buffer[1],(buffer[2]),(buffer[3]));//parseamos.

            if(auxEmple!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmple);//agrego un puntero al final del linkedlist.
                retorno=0;
            }




        }
    }

   /* while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        auxEmple = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        //ACA ESTABA EL ERRORRRRRRRRRRRRRRRR LAREPTM

        if(auxEmple != NULL)
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }
    }*/

    return retorno;
    //return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    //int leido=0;
    Employee* auxEmple = NULL;// = employee_new();
    int cant = 0;

    //fread(auxEmple,sizeof(Employee),1,pFile);

    while(!feof(pFile))
    {
        auxEmple = employee_new();

        if(auxEmple==NULL)
        {
            break;
        }

        cant = fread(auxEmple,sizeof(Employee),1,pFile);

        if(cant<1)//significa que estaria todo mal
        {
            break;
        }
        else
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }


        /*leido = fread(auxEmple,sizeof(Employee),1,pFile);

        if(auxEmple!=NULL && leido!=0)
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }*/
    }

    return retorno;
    //return 1;
}
