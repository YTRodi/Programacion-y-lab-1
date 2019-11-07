
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

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id>=1 && id<=1500)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/*int employee_setId(Employee* this, int id)
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
}*/


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
        printf(" | %5d | %15s | %10d | %10d |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int employee_ListEmployees(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("  ===================================================\n");
        printf("||   ID  |     NOMBRE      |   HORAS T. |   SUELDO   ||\n");
        printf("  ===================================================\n");

        for(int i=0;i<len;i++)
        {
            employee_ShowOneEmployee((Employee*)ll_get(pArrayListEmployee,i));
            todoOk = 1;
        }

    }
    if(todoOk == 0)
    {
        printf("  ===================================================\n");
        printf("||  Error: No se pudo cargar la lista.               ||\n");
        printf("  ===================================================\n");
    }

    return todoOk;
}


int generateId(void* this)
{
    int value = -1;

    value = ll_len(this) + 1;

    return value;
}

int menuModificacion()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||  (1)  Modificar nombre.                           ||\n");
    printf("||  (2)  Modificar horas trabajadas.                 ||\n");
    printf("||  (3)  Modificar sueldo.                           ||\n");
    printf("||  (4)  Salir.                                      ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,4,3);
    return option;
}

int menuOrder()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||  (1)  Ordenar por id.                             ||\n");
    printf("||  (2)  Ordenar por nombre.                         ||\n");
    printf("||  (3)  Ordenar por horas trabajadas.               ||\n");
    printf("||  (4)  Ordenar por sueldo.                         ||\n");
    printf("||  (5)  Salir.                                      ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,5,3);
    return option;
}


int menuHowDoYouWantToOrder()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||            Como desea ordenarlos?                 ||\n");
    printf("||  (1)  Ascendente. <a-z> o <min-max>.              ||\n");
    printf("||  (2)  Descendente. <z-a> o <max-min>.             ||\n");
    printf("||                                                   ||\n");
    printf("||  Nota: los ordenamientos pueden llegar a demorar  ||\n");
    printf("||  unos segundos.                                   ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,2,3);
    return option;
}




//ESTO RECIBE LA FUNCION LL_SORT.
//ll_sort(LinkedList* this,int(*pFunc)(void*)(void*),int order);

int employee_compareById(void* employee1,void* employee2)
{
    int retorno;

    //debo castear cada employee, debido a que es un puntero a void.
    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->id > emp2->id)
    {
        retorno = -1; //si el primero es mayor al segundo.
    }
    else if(emp1->id < emp2->id)
    {
        retorno = 1;
    }
    else
    {
        //son iguales
        retorno = 0;
    }

    return retorno;
}

int employee_compareByName(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(strcmpi(emp1->nombre,emp2->nombre)>0)
    {
        retorno = -1;
    }
    else if(strcmpi(emp1->nombre,emp2->nombre)<0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int employee_compareByHT(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->horasTrabajadas > emp2->horasTrabajadas)
    {
        retorno = -1;
    }
    else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int employee_compareBySalary(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->sueldo > emp2->sueldo)
    {
        retorno = -1;
    }
    else if(emp1->sueldo < emp2->sueldo)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/*int employee_comparteByIdAndName(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->id > emp2->id)
    {

    }
    return retorno;
}*/








//MESSAGES
void errorPosterFile()
{
    printf("  ===================================================\n");
    printf("||  Error: No se pudo abrir el archivo.            ||\n");
    printf("  ===================================================\n");
}

void errorPosterId()
{
    printf("  ===================================================\n");
    printf("||  Error: No existe empleado con ese ID,            ||\n");
    printf("||         sera redireccionado al menu.              ||\n");
    printf("  ===================================================\n");
}

void warningPosterFile()
{
    printf("  ===================================================\n");
    printf("||  Advertencia: No puede abrirse mas de un archivo  ||\n");
    printf("||               a la vez.                           ||\n");
    printf("  ===================================================\n");
}

void errorUploadFileBefore()
{
    printf("  ===================================================\n");
    printf("||  Advertencia: Debe cargar algun archivo antes.    ||\n");
    printf("  ===================================================\n");
}

void errorOptionInvalid()
{
    printf("  ===================================================\n");
    printf("||  Error: usted ingreso una opcion invalida,        ||\n");
    printf("||         sera redireccionado al menu.              ||\n");
    printf("  ===================================================\n");
}

void operationCancelled()
{
    printf("  ===================================================\n");
    printf("||  Aviso: La operacion fue cancelada,               ||\n");
    printf("||         redireccionando al menu.                  ||\n");
    printf("  ===================================================\n");
}

/*  POSTER BOCETO:

    printf("  ===================================================\n");
    printf("||                                                   ||\n");
    printf("||                                                   ||\n");
    printf("  ===================================================\n");
*/

