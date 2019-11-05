#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
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
    int retorno = -1;
    //int controlAgrego;
    int auxId = 0;
    char auxNombre[40];
    int auxHorasTrabajadas = 0;
    int auxSueldo = 0;
    Employee* auxEmple = employee_new();

    printf("\nALTA EMPLEADO\n");

    if(auxEmple!=NULL)
    {
        if(IdAleatorio(pArrayListEmployee)!=-1)
        {
            auxId = IdAleatorio(pArrayListEmployee);

            if(getNombreOApellido(auxNombre,"\n<2-40 caract>\nIngrese nombre:","Error.Reingrese",2,40,2)!=-1)
            {
                if(getInt(&auxHorasTrabajadas,"\n<1-1500>\nIngrese horas trabajadas:","Error.Reingrese",1,1500,2)!=-1)
                {
                    if(getInt(&auxSueldo,"\n<500-200000>\nIngrese sueldo:","Error.Reingrese",500,200000,2)!=-1)
                    {
                        employee_setId(auxEmple,auxId);
                        employee_setNombre(auxEmple,auxNombre);
                        employee_setHorasTrabajadas(auxEmple,auxHorasTrabajadas);
                        employee_setSueldo(auxEmple,auxSueldo);
                        //controlAgrego = ll_add(pArrayListEmployee,auxEmple);

                        if(!ll_add(pArrayListEmployee,auxEmple))//los agrego al final del linkedlist.
                        {
                            printf("\nAlta exitosa\n\n");
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
    //return 1;
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
    int retorno = -1;
    int idABajar;
    Employee* this;
    int len = ll_len(pArrayListEmployee);
    char confirma;

    printf("\n--Baja Cliente--\n");


    if(pArrayListEmployee!=NULL)
    {
        getInt(&idABajar,"\nIngrese id a dar de baja: ","Error.Reingrese",1,1500,2);

        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i); //como consigo el elemento, lo casteo a Employee.

            if(this->id == idABajar)
            {
                //Muestro el empleado a dar de baja...
                employee_ShowOneEmployee(this);

                printf("confirma baja? <s/n>: ");
                fflush(stdin);
                scanf("%c",&confirma);

                if(confirma == 's')
                {
                    if(!ll_remove(pArrayListEmployee,i))
                    {
                        printf("\n..Baja exitosa..\n\n");
                        retorno = 0;
                        break;
                    }
                    else
                    {
                        printf("\nqueondapai???\n");
                    }
                    //ll_remove(pArrayListEmployee,i);
                    //HACE FALTA USAR EL EMPLOYEE_DELETE DESPUES DE ESTO?

                }
                else if(confirma == 'n')
                {
                    printf("\nSe ha cancelado la operacion.\n\n");
                }
            }

        }
    }
    if(retorno == -1)
    {
        printf("\nNo existe cliente con ese ID\n\n..::Redireccionando al menu::..\n\n");
    }

    return retorno;
    //return 1;
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
    /*int auxId = 0;
    char auxNombre[50];
    int auxHorasTrabajadas = 0;
    int auxSueldo = 0;*/

    //for(int i=0;i<len;i++); para QUE ME MUESTRE TODO EL ARCHIVO
    for(int i=0; i<len; i++)
    {
        auxEmple = (Employee*) ll_get(pArrayListEmployee,i);//todo se va a guardar en auxEmple.
        if(auxEmple!=NULL)
        {
            /*employee_getId(auxEmple,&auxId);
            employee_getNombre(auxEmple,auxNombre);
            employee_getHorasTrabajadas(auxEmple,&auxHorasTrabajadas);
            employee_getSueldo(auxEmple,&auxSueldo);*/
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
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    //int todoOk = 0;
    FILE* auxText;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmple;

    if(pArrayListEmployee!=NULL && len>0 && path!=NULL)
    {
        auxText = fopen(path,"w");
        if(auxText==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return retorno;
            //exit(EXIT_FAILURE); EN UNA FUNCION NUNCA HACEMOS UN EXIT.
        }


        /**** --PARA IMPRIMIR EL ENCABEZADO DESTILDO ESTO.-- ****/
        //fprintf(auxText,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<len; i++)
        {

            auxEmple = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxEmple!=NULL)
            {
                fprintf(auxText,"%d,%s,%d,%d\n",auxEmple->id,auxEmple->nombre,auxEmple->horasTrabajadas,auxEmple->sueldo);
                retorno = 0;
            }

            /*fwrite(pArrayListEmployee,sizeof(LinkedList),len,auxText);
            fprintf(auxText,"%d,%s,%d,%d\n",ll_get(pArrayListEmployee,i));*(pArrayListEmployee+i))->id,(*(lista+i))->marca,(*(lista+i))->modelo,(*(lista+i))->precio);
            retorno = 0;*/
        }
        fclose(auxText);
    }

    return retorno;
    //return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* auxBin;
    int len = ll_len(pArrayListEmployee);


    if(len>0 && path!=NULL && pArrayListEmployee!=NULL)
    {
        auxBin = fopen(path,"wb");
        if(auxBin!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,auxBin);
            }
        }


        fclose(auxBin);
        retorno = 0;
    }
    return retorno;
    //return 1;
}

