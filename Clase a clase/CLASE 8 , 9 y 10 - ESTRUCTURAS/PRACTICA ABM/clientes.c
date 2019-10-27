#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "utn.h"
#include "clientes.h"

int menuCustomer()
{
    int opcion;

    system("cls");
    printf("----ABM Yago----\n\n");
    opcion = getInt("1 - ALTA cliente\n2 - BAJA cliente: \n3 - MODIFICAR cliente: \n4 - LISTAR clientes: \n5 - ORDENAR clientes: \n6 - INFORMES clientes: \n7 - SALIR \nIngrese opcion: ");
    /*printf("1.ALTA cliente: \n");
    printf("2.BAJA cliente: \n");
    printf("3.MODIFICAR cliente: \n");
    printf("4.LISTAR clientes: \n");
    printf("5.ORDENAR clientes: \n");
    printf("6.INFORMES clientes: \n");
    printf("7.SALIR \n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);*/

    return opcion;
}

void show_Customer(sCustomer x)
{
    printf("\n%d %s %d %c %d %d %.2f %d/%d/%d\n\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void show_Customers(sCustomer vec[], int tam)
{
    int flag = 0;
    system("cls");

    //ESTO VA ACA O ADENTRO DEL FOR????
    //printf("Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");

    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0) //si hay clientes dados de alta, sube la bandera y muestro un cliente
        {
            //printf("Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
            show_Customer(vec[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay clientes que mostrar.\n");
    }

    printf("\n\n");

}

void initialize_Customers(sCustomer vec[], int tam)//Cuando isEmpty esta en 1, esta vacio.
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int search_FreePosition(sCustomer vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
            //Si ya encuentro un lugar vacio:
            //-ROMPO el for,(para que no siga iterando).
        }
    }
    return indice;
}

int search_Customer(int legajo, sCustomer vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        //si el legajo guardado en la estructura es igual al ingresado por el usuario
        //y el lugar vacio del vector estructura es 0 (esta vacio)
        if(vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int highCustomer(sCustomer vec[], int tam) //deuelve 1 da de alta exitosamente, si devuelve 0 algo anduvo mal.
{
    int todoOk = 0;
    int indice;
    int esta;

    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    int nt1;//nota1
    int nt2;//nota2.
    sDate fecha;

    system("cls");

    printf("---ALTA CLIENTE---\n\n");

    indice = search_FreePosition(vec,tam);

    if(indice == -1)//Si no hay un lugar vacio.
    {
        printf("-Sistema completo-\n\n");
    }
    else//si hay lugar vacio, deejo que ingrese legajo para despues evaluar
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo);

        esta = search_Customer(legajo,vec,tam);

        if(esta != -1)
        {
            /*si ya esta ese legajo, mensaje de error
            y muestrro el legajo existente*/
            printf("\n-Legajo existente-\n\n");
            printf("Usuario:");
            show_Customer(vec[esta]);
        }
        else//si no esta el legajo, prosigo pidiendo los datos
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad: ");
            scanf("%d",&edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c",&sexo);

            printf("Ingrese nota 1: ");
            scanf("%d",&nt1);

            printf("Ingrese nota 2: ");
            scanf("%d",&nt2);

            printf("Ingrese fecha de ingreso\n<seguidas con un slash '/' >:");
            scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);

            //donde se guardan todos estos datos?
            //para eso creo una funcion que devuelva una estructura y tome como parametros dichos datos

            vec[indice] = newCustomer(legajo,nombre,edad,sexo,nt1,nt2,fecha);

            todoOk = 1;
            printf("\n!!Alta exitosa!!\n\n");
        }

    }
    return todoOk;
}

sCustomer newCustomer(int leg, char nombre[], int edad, char sexo, int n1, int n2, sDate fecha)
{
    sCustomer containerCustomer;
    /*cliente contenedor de datos que
    devuelve una estructura.*/

    containerCustomer.legajo = leg;
    strcpy(containerCustomer.nombre,nombre);
    containerCustomer.edad = edad;
    containerCustomer.sexo = sexo;
    containerCustomer.nota1 = n1;
    containerCustomer.nota2 = n2;
    containerCustomer.promedio = (float) (n1 + n2)/2;//CASTEO
    containerCustomer.fechaIngreso = fecha;
    containerCustomer.isEmpty = 0;

    return containerCustomer;
}

int downCustomer(sCustomer vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");

    printf("---BAJA CLIENTE---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice = search_Customer(legajo,vec,tam);

    if(indice == -1)
    {
        printf("No existe un cliente con ese legajo.\n");
    }
    else
    {
        show_Customer(vec[indice]);

        printf("Confirma la baja?:");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("\n!!Baja exitosa!!\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
    return todoOk;
}


int modifyCustomer(sCustomer vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    //char confirma = 'n';
    int opcion;

    system("cls");
    printf("---MODIFICAR CLIENTE---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice = search_Customer(legajo,vec,tam);

    if(indice == -1)
    {
        printf("No existe cliente con este legajo.\n");
    }
    else
    {
        printf("\nUsuario: ");
        show_Customer(vec[indice]);

        printf("1.Modificar nombre: \n");
        printf("2.Modificar sexo: \n");
        printf("3.Modificar nota1: \n");
        printf("4.Modificar nota2: \n");
        printf("5.Cancelar: \n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(vec[indice].nombre);
                printf("\nModificacion exitosa!!\n\n");
                break;
            case 2:
                printf("Ingrese nuevo sexo: ");
                fflush(stdin);
                scanf("%c",&vec[indice].sexo);
                printf("\nModificacion exitosa!!\n\n");
                break;
            case 3:
                printf("Ingrese nueva nota: ");
                scanf("%d",&vec[indice].nota1);
                vec[indice].promedio = (float) (vec[indice].nota1 + vec[indice].nota2)/2;
                printf("\nModificacion exitosa!!\n\n");
                break;
            case 4:
                printf("Ingrese nueva nota: ");
                scanf("%d",&vec[indice].nota2);
                vec[indice].promedio = (float) (vec[indice].nota1 + vec[indice].nota2)/2;
                printf("\nModificacion exitosa!!\n\n");
                break;
            case 5:
                printf("Se ha cancelado la operacion.\n\n");
                break;
            default:
                printf("ERROR: Ingrese una opcion valida.\n");

        }


    }
    return todoOk;
}
