#include "estructuras de alumnos.h"


void mostrarAlumno(eAlumno miAlumno)
{


    printf("%d    %s    %s    %d  %d   %d   %f\n",miAlumno.legajo,miAlumno.nombre,miAlumno.apellido,miAlumno.nota1,miAlumno.nota2,miAlumno.nota3,miAlumno.promedio);

}

eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;



    printf("ingrese legajo:\n");
    scanf("%d",&miAlumno.legajo);

    printf("ingrese nombre:\n");
    fflush(stdin);
    gets(miAlumno.nombre);


    printf("ingrese apellido:\n");
    fflush(stdin);
    gets(miAlumno.apellido);


    printf("ingrese nota 1:\n");
    scanf("%d",&miAlumno.nota1);

    printf("ingrese nota 2:\n");
    scanf("%d",&miAlumno.nota2);

    printf("ingrese nota 3:\n");
    scanf("%d",&miAlumno.nota3);

    miAlumno.promedio=(float) (miAlumno.nota1+miAlumno.nota2+miAlumno.nota3)/3;

    system("cls");



    return miAlumno;

}

void cargarListaAlumnos(eAlumno listaAlumnos[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        listaAlumnos[i]= cargarAlumno();
    }

}

void mostrarListaAlumnos(eAlumno listaAlumnos[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        mostrarAlumno(listaAlumnos[i]);
    }

}

void ordenarAlumnos(eAlumno listaAlumnos[],int tam)
{

    eAlumno auxAlumno;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(listaAlumnos[i].legajo<listaAlumnos[j].legajo)
            {
            auxAlumno=listaAlumnos[i];
            listaAlumnos[i]=listaAlumnos[j];
            listaAlumnos[j]=auxAlumno;

            }

        }
    }
}


