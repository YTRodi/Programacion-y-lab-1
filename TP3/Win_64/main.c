#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menuGeneral();

int main()
{
    char exit = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    //LinkedList* listaEmpleadosBinarios = ll_newLinkedList();
    do{
        switch(menuGeneral())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
                controller_loadFromBinary("data2.bin",listaEmpleados);
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

            case 8:
                controller_saveAsText("data.csv",listaEmpleados);//NO FUNCA
                break;

            case 9:
                controller_saveAsBinary("data2.bin",listaEmpleados);
                break;

            case 10:
                printf("\nConfirma salir? <s/n>: ");
                fflush(stdin);
                exit = getche();
                printf("\n\n");
                break;

        }
        system("pause");
    }while(exit == 's');
    return 0;
}

int menuGeneral()
{
    int option;
    system("cls");
    printf("  ======================================================================================\n");
    printf("||                                 ABM EMPLEADOS                                       ||\n");
    printf("  ======================================================================================\n");
    printf("||  (1)  Cargar los datos de los empleados desde el archivo data.csv (modo texto).     ||\n");
    printf("||  (2)  Cargar los datos de los empleados desde el archivo data.csv (modo binario).   ||\n");
    printf("||  (3)  Alta de empleado.                                                             ||\n");
    printf("||  (4)  Modificar datos de empleado                                                   ||\n");
    printf("||  (5)  Baja de empleado.                                                             ||\n");
    printf("||  (6)  Listar empleados.                                                             ||\n");
    printf("||  (7)  Ordenar empleados.                                                            ||\n");
    printf("||  (8)  Guardar los datos de los empleados en el archivo data.csv (modo texto).       ||\n");
    printf("||  (9)  Guardar los datos de los empleados en el archivo data.csv (modo binario).     ||\n");
    printf("||  (10) Salir.                                                                        ||\n");
    printf("  ======================================================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,10,2);
    return option;
}


