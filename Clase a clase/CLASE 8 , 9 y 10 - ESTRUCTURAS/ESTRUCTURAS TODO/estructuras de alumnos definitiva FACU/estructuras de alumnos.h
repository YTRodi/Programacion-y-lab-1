#include <stdio.h>

typedef struct
{
    int legajo;
    char nombre[50];
    char apellido[50];
    int nota1;
    int nota2;
    int nota3;
    float promedio;

}eAlumno;

void mostrarAlumno(eAlumno);
eAlumno cargarAlumno(void);

void cargarListaAlumnos(eAlumno[],int);
void mostrarListaAlumnos(eAlumno[],int);
void ordenarAlumnos(eAlumno[],int);


