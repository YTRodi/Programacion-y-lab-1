#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>//esta el getche


#define TAM 3


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;

    int isEmpty;
} eAlumno;

void mostrarUnAlumno(eAlumno miAlumno);
void mostrarAlumnos(eAlumno vec[], int tam);

void mostraListaAlumnos(eAlumno listadoDeAlumnos[], int tam);
void cargarListaAlumnos(eAlumno listadoDeAlumnos[], int tam);

void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);

int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(eAlumno vec[], int tam, int legajo);

eAlumno newAlumno(int legajo, int nombre, int edad, char sexo, int nota1, int nota2, float promedio);

int altaAlumno(eAlumno vec[], int tam);

int bajaAlumno(eAlumno vec[], int tam);
int modificarAlumno(eAlumno vec[], int tam);


int menu();


int main()
{
    eAlumno lista[TAM];
    char salir = 's';
    inicializarAlumnos(lista, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            //altaAlumno(lista,TAM);
            printf("Alta alumno\n");
            break;
        case 2:
            printf("Baja alumno\n");
            break;
        case 3:
            printf("Modificar alumno\n");
            break;
        case 4:
            printf("Listar alumno\n");
            mostrarAlumnos(lista, TAM);
            break;
        case 5:
            printf("Ordenar alumno\n");
            break;
        case 6:
            printf("Informes alumno\n");
            break;
        case 7:
            printf("Confirma salir?\n");
            fflush(stdin);
            salir = getche();
            break;
        default:
            printf("opcion invalida!\n");

        }
        system("pause");

    }
    while(salir == 'n');
    return 0;
}



int menu()
{
    int opcion;
    system("cls");
    printf("***** ABM ALUMNOS *****\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Salir\n");
    printf("Ingrese opcion:\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}

void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%d %s %d %s %d %d %f\n",miAlumno.legajo,miAlumno.nombre,miAlumno.edad,miAlumno.sexo,miAlumno.nota1,miAlumno.nota2,miAlumno.promedio);

}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;
    system("cls");
    printf("Legajo Nombre Edad Sexo Nota1 Nota2 Promedio\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarUnAlumno(vec[i]);
            flag = 1;//si entro una vez al if
        }
    }
    if(flag == 0)
    {
        printf("No hay alumnos que mostrar\n\n");
    }
}

void cargarListaAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i]; // =  ????? tengo que llawrma al alta alumno
    }


}

void mostraListaAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty!=0)
        {
            mostrarUnAlumno(vec[i]);
        }
    }

}


void inicializarAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
{
    int indice = -1;
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = 1;
            break;
        }
    }
    return indice;
}

int buscarAlumno(eAlumno vec[], int tam, int legajo)
{
    int indice = -1;
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].legajo = legajo && vec[i].isEmpty)
        {
            indice = 1;
            break;
        }
    }
    return indice;
}

eAlumno newAlumno(int legajo, int nombre, int edad, char sexo, int nota1, int nota2, float promedio)
{



}


int altaAlumno(eAlumno vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    char nombre[];
    char sexo;
    int edad;
    int n1;
    int n2;
    eFecha fecha;

    system("cls");

    printf("*****Alta alumno*****");

    indice = buscarLibre(vec,tam);

    if(indice == -1)//esta completo
    {
        printf("\nSistema completo\n\n");

    }
    else
    {
        printf("Ingrese legajo:");
        scanf("d",&legajo);

    }



    return todoOk;


}

int bajaAlumno(eAlumno vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma = 's';

    system("cls");
    printf("*****Baja Alumno*****");
    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice = buscarLibre(vec,tam);

    if(indice == -1)
    {

    }
    else
    {
        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {

        }
    }


    return todoOk;
}

int modificarAlumno(eAlumno vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;


    return todoOk;
}
