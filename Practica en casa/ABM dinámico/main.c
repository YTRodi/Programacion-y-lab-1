#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#define TAM 2

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    float salario;
    int estado;
}eCliente;

/**Prototipos**/
int menuGeneral();

eCliente* new_Cliente();
eCliente* newClienteParam(int id,char* nombre,char* apellido,float salario);
int inicializarClientes(eCliente* listC,int tam);
int buscarLibreCliente(eCliente* listCli,int tamCli);
int mostrarUnCliente(eCliente* unCliente);



int main()
{
    eCliente* arrayCliente[1] = {101,"Yago","Rodi",25000};



    int exit;

    do
    {
        switch(menuGeneral())
        {
            case 1:
                printf("Alta\n");
                break;
            case 2:
                printf("Modificar\n");
                break;
            case 3:
                printf("Baja\n");
                break;
            case 4:
                printf("Listar\n");
                break;
            case 5:
                printf("Confirma salir? <s/n>: ");
                fflush(stdin);
                exit = getche();
                printf("\n\n");
                break;
        }
        system("pause");

    }while(exit != 's');

    return 0;
}


/**Desarrollos**/

int menuGeneral()
{
    int option;
    system("cls");
    printf("  =================================================\n");
    printf("||               ABM DINAMICO (NUM 1)              ||\n");
    printf("  =================================================\n");
    printf("||  (1) Alta cliente.                              ||\n");
    printf("||  (2) Modificar cliente.                         ||\n");
    printf("||  (3) Baja cliente.                              ||\n");
    printf("||  (4) Listar cliente.                            ||\n");
    printf("||  (5) Salir.                                     ||\n");
    printf("  =================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,5,2);
    return option;
}


eCliente* new_Cliente()
{
    eCliente* nuevoCliente = (eCliente*) malloc(sizeof(eCliente));

    //Primero que nada, verifico si es distinto a NULL.
    if(nuevoCliente != NULL)
    {
        //Inicializo y limpio todos los campos(para que no contengan basura).
        /**ESTO ES SETEAR!!!!!!***/
        nuevoCliente->id = 0;
        strcpy(nuevoCliente->nombre,"");//Le asigno una cadena vacia.
        strcpy(nuevoCliente->apellido,"");
        nuevoCliente->salario = 0;
        nuevoCliente->estado = 1;
    }
    return nuevoCliente;//retorno el cliente.
}


eCliente* newClienteParam(int id,char* nombre,char* apellido,float salario)
{
    eCliente* nuevoClienteParam = = newCliente();//esto ya me va a devolver el cliente con un espacio en memoria e inicializado

    //Recibe los datos por parametro y los asigna al id,nombre,apellido,salario,estado a la lista.
    if(nuevoClienteParam != NULL)
    {
        /**ESTO ES GETTEAR!!!!!!***/
        nuevoClienteParam->id = id;
        strcpy(nuevoClienteParam->nombre,nombre);
        strcpy(nuevoClienteParam->apellido,apellido);
        nuevoClienteParam->salario = salario;
        nuevoClienteParam->estado = 0;
    }
    return nuevoClienteParam;
}


//No seria setEstado?
int inicializarClientes(eCliente* listCli,int tamCli)
{
    int todoOk = 0;

    if(listCli != NULL && tamCli>0)
    {
        for(int i=0;i<tamCli;i++)
        {
            (listCli+i)->estado = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreCliente(eCliente* listCli,int tamCli)
{
    int indice = -1;

    if(listCli != NULL && tamCli>0)
    {
        for(int i=0;i<tamCli;i++)
        {
            if(listCli[i].estado == 1)//va con los corchetes [i]?????
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


int mostrarUnCliente(eCliente* unCliente)
{
    int todoOk = 0;
    if(unCliente != NULL)
    {
        printf("|%d|%s|%s|%f|",
               unCliente->id,
               unCliente->nombre,
               unCliente->apellido,
               unCliente->salario);
        todoOk = 1;
    }
    return todoOk;
}

//int imprimirClientes(eCliente* listCli,int tamCli)


int altaCliente(eCliente* listCli,int tamCli)
{
    eCliente* emp;
    int todoOk= 0;
    int index;

    system("cls");
    printf("  =================================================\n");
    printf("||               ALTA CLIENTE                      ||\n");
    printf("  =================================================\n");

    return todoOk;
}

























