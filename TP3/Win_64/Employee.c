#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
    Employee* nuevoEmp = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmp!=NULL)
    {
        nuevoEmp->id = 0;
        strcpy(nuevoEmp->nombre," ");
        nuevoEmp->horasTrabajadas = 0;
        nuevoEmp->sueldo = 0;
    }
    return nuevoEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpParam = employee_new();

    if(nuevoEmpParam!=NULL)
    {
        if(employee_setId(nuevoEmpParam,atoi(idStr))
                &&employee_setNombre(nuevoEmpParam,nombreStr)
                &&employee_setHorasTrabajadas(nuevoEmpParam,atoi(horasTrabajadasStr))
                &&employee_setSueldo(nuevoEmpParam,atoi(sueldoStr)) == 0)
        {
            /*free(nuevoEmpParam);
            nuevoEmpParam = NULL;*/
            employee_delete(nuevoEmpParam);
        }

    }
    return nuevoEmpParam;
}

void employee_delete(Employee* this)
{
    //HACERRRRRRRRRR
    if(this!=NULL)
    {
        free(this);
    }
}

/*int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id>=1 && id<=1500)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}*/

int employee_setId(Employee* this, int id)
{
    //ULTIMO CAMBIO CAMBIE RETORNO 0 POR 1.
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 1;
        if(id < 0)
        {
            maximoId++;
            this->id = maximoId;
        }
        else
        {
            if(id > maximoId)
                maximoId = id;
            this->id = id;
        }
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *id = this->id;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre !=NULL && strlen(nombre)>=2)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL && horasTrabajadas>=1 && horasTrabajadas<=1500)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if(this!=NULL && sueldo>=500 && sueldo<=200000)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
    }
    return retorno;
}

int employee_ShowOneEmployee(Employee* auxEmployee)
{
    int todoOk = 0;
    if(auxEmployee!=NULL)
    {
        printf("| %5d | %15s | %10d | %10d |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

