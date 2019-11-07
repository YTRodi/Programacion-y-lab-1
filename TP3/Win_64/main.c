#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menuGeneral();

int main()
{
    char exit;
    int flag1 = 0;
    int flag2 = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menuGeneral())
        {
            case 1:
                if(flag2 == 1)
                {
                    printf("\n--Ya se encuentra cargado el archivo BINARIO.--\n");
                    warningPosterFile();
                }
                else
                {
                    if(controller_loadFromText("data.csv",listaEmpleados)==0)
                    {
                        printf("\nArchivo de TEXTO cargado correctamente.\n\n");
                        flag1 = 1;
                    }
                    else
                    {
                        printf("\nNombre del archivo inexistente.\n\n");
                    }
                }

                break;

            case 2:
                if(flag1 == 1)
                {
                    printf("\n--Ya se encuentra cargado el archivo de TEXTO.--\n");
                    warningPosterFile();
                }
                else
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
                    {
                        printf("\nArchivo BINARIO cargado correctamente.\n\n");
                        flag2 = 1;
                    }
                    else
                    {
                        printf("\nNombre del archivo inexistente.\n\n");
                    }
                }

                break;

            case 3:
                if(flag1==1 || flag2==1)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 4:
                if(flag1==1 || flag2==1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 5:
                if(flag1==1 || flag2==1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 6:
                if(flag1==1 || flag2==1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 7:
                if(flag1==1 || flag2==1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 8:
                if(flag1 == 1 || flag2 == 1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    printf("  ===================================================\n");
                    printf("||  Datos guardados con exito en el archivo de     ||\n");
                    printf("||        TEXTO.                                   ||\n");
                    printf("  ===================================================\n");
                }
                else
                {
                    errorUploadFileBefore();
                }
                break;

            case 9:
                if(flag1 == 1 || flag2 == 1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);

                    printf("  ===================================================\n");
                    printf("||  Datos guardados con exito en el archivo        ||\n");
                    printf("||        BINARIO.                                 ||\n");
                    printf("  ===================================================\n");
                }
                else
                {
                    errorUploadFileBefore();
                }
                break;

            case 10:
                printf("\nConfirma salir? <s/n>: ");
                fflush(stdin);
                scanf("%c",&exit);
                exit = tolower(exit);
                printf("\n\n");
                break;

            default:
                errorOptionInvalid();

        }
        system("pause");
    }
    while(exit != 's');
    return 0;
}

int menuGeneral()
{
    int option;
    system("cls");
    printf("  ======================================================================================\n");
    printf("||                                 ABM EMPLEADOS                                        ||\n");
    printf("  ======================================================================================\n");
    printf("||  (1)  Cargar los datos de los empleados desde el archivo data.csv (modo texto).      ||\n");
    printf("||  (2)  Cargar los datos de los empleados desde el archivo data.bin (modo binario).    ||\n");
    printf("||  (3)  Alta de empleado.                                                              ||\n");
    printf("||  (4)  Modificar datos de empleado                                                    ||\n");
    printf("||  (5)  Baja de empleado.                                                              ||\n");
    printf("||  (6)  Listar empleados.                                                              ||\n");
    printf("||  (7)  Ordenar empleados.                                                             ||\n");
    printf("||  (8)  Guardar los datos de los empleados en el archivo data.csv (modo texto).        ||\n");
    printf("||  (9)  Guardar los datos de los empleados en el archivo data.bin (modo binario).      ||\n");
    printf("||  (10) Salir.                                                                         ||\n");
    printf("  ======================================================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,10,2);
    return option;
}


