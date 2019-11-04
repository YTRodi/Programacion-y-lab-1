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

    char id[10];
    char nombre[50];
    char horasTrabajadas[10];
    char sueldo[30];

    //int control;
    Employee* auxEmple;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        auxEmple = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        //ACA ESTABA EL ERRORRRRRRRRRRRRRRRR LAREPTM

        if(auxEmple != NULL)
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }
    }

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
    int leido=0;
    Employee* auxEmple;// = employee_new();

    //fread(auxEmple,sizeof(Employee),1,pFile);

    while(!feof(pFile))
    {
        auxEmple = employee_new();
        leido = fread(auxEmple,sizeof(Employee),1,pFile);
        if(auxEmple!=NULL && leido!=0)
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }
    }

    return retorno;
    //return 1;
}
