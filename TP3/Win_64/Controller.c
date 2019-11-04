#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = -1;
    int controlCarga;
    f = fopen(path,"r");//abro

    if(f!=NULL && pArrayListEmployee!=NULL)
    {
        //parseo
        controlCarga = parser_EmployeeFromText(f,pArrayListEmployee);
        if(controlCarga != -1)
        retorno = 0;
        printf("\nArchivo de TEXTO cargado correctamente.\n\n");
    }
    else
    {
        printf("\nNo se pudo abrir el archivo.\n");
        system("pause");
        //exit(EXIT_FAILURE);
    }

    fclose(f);//cierro

    //return 1;
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = -1;
    int controlCarga;
    f = fopen(path,"rb");//abro

    if(f!=NULL && pArrayListEmployee!=NULL)
    {
        //parseo
        controlCarga = parser_EmployeeFromBinary(f,pArrayListEmployee);
        if(controlCarga != -1)
        retorno = 0;
        printf("\nArchivo BINARIO cargado correctamente.\n\n");
    }
    else
    {
        printf("\nNo se pudo abrir el archivo.\n");
        system("pause");
        //exit(EXIT_FAILURE);
    }

    fclose(f);//cierro

    //return 1;
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmple;
    int len = ll_len(pArrayListEmployee);
    int auxId = 0;
    char auxNombre[50];
    int auxHorasTrabajadas = 0;
    int auxSueldo = 0;

    //for(int i=0;i<len;i++); para QUE ME MUESTRE TODO EL ARCHIVO
    for(int i=0;i<len;i++)
    {
        auxEmple = (Employee*) ll_get(pArrayListEmployee,i);//todo se va a guardar en auxEmple.
        if(auxEmple!=NULL)
        {
            employee_getId(auxEmple,&auxId);
            employee_getNombre(auxEmple,auxNombre);
            employee_getHorasTrabajadas(auxEmple,&auxHorasTrabajadas);
            employee_getSueldo(auxEmple,&auxSueldo);
            //printf("| %5d | %15s | %10d | %10d |\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            employee_ShowOneEmployee(auxEmple);
        }
        /*auxEmple = ll_get(pArrayListEmployee,i);
        //faltan validaciones.
        employee_getId(auxEmple,&id);
        employee_getNombre(auxEmple,nombre);
        employee_getHorasTrabajadas(auxEmple,&horasTrabajadas);
        employee_getSueldo(auxEmple,&sueldo);

        printf("%d %s %d %d",id,nombre,horasTrabajadas,sueldo);*/
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL && len>0 && path!=NULL)
    {
        f = fopen(path,"w");
        if(f==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return todoOk;
            //exit(EXIT_FAILURE); EN UNA FUNCION NUNCA HACEMOS UN EXIT.
        }

        //fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");//ESCRIBO EL ENCABEZADO (LA PRIMER FILA
        for(int i=0;i<len;i++)
        {
            fwrite(pArrayListEmployee,sizeof(LinkedList),len,f);
            todoOk = 1;
            printf("SE GUARDO EXCELENTE PAPU");
        }
        fclose(f);
    }

    return todoOk;
    //return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

