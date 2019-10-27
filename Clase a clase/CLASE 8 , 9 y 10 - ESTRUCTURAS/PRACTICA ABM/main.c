#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "utn.h"
#include "clientes.h"

#define TAM 3

//FALTA ORDENAMIENTO POR CRITERIOS...

void hardCodearCustomers(sCustomer[], int);

int main()
{
    sCustomer lista[TAM];

    char salir = 'n';


    initialize_Customers(lista,TAM);

    do
    {
        switch(menuCustomer())
        {
        case 1:
            highCustomer(lista,TAM);
            //printf("Alta cliente...");
            break;
        case 2:
            downCustomer(lista,TAM);
            //printf("Baja cliente...");
            break;
        case 3:
            modifyCustomer(lista,TAM);
            //printf("Modificar cliente...");
            break;
        case 4:
            hardCodearCustomers(lista,TAM);
            show_Customers(lista,TAM);
            //printf("Listar clientes...");
            break;
        case 5:
            printf("Ordenar clientes...");
            break;
        case 6:
            printf("Informes clientes...");
            break;
        case 7:
            printf("\nConfirma salir?");
            fflush(stdin);
            salir = getche();
            printf("\n\n");
            break;
        default:
            printf("\nIngrese una opcion valida.\n\n");

        }
        system("pause");



    }
    while(salir == 'n');


    return 0;
}


void hardCodearCustomers(sCustomer vec[], int tam)
{
    /*sCustomer legajo[tam] = {100,105,200};
    sCustomer edad[tam] = {100,105,200};*/


    int legajo[] = {100,205,150};
    char nombre[] [20] = {"yago","camila","facundo"};
    int edad[] = {21,20,25};
    char sexo[] = {'m','f','m'};
    int nota1[] = {10,5,3};
    int nota2[] = {7,10,8};
    float promedio[] = {6.66,4,7,66};

    //POR QUE ME SALE TODO 0/0/0 A LA HORA DE MOSTRAR LA FECHA DE INGRESO
    sDate fechaIngreso[] = {{7/9/1998},{4/2/1999},{10/5/1995}};

    int isEmpty[] = {0,0,0};

    for(int i = 0; i<3; i++)
    {
        vec[i].legajo = legajo[i];
        strcpy(vec[i].nombre,nombre[i]);
        vec[i].edad = edad[i];
        vec[i].sexo = sexo[i];
        vec[i].nota1 = nota1[i];
        vec[i].nota2 = nota2[i];
        vec[i].promedio = promedio[i];
        vec[i].fechaIngreso = fechaIngreso[i];
        vec[i].isEmpty = isEmpty[i];
    }

}
