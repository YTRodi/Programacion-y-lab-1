#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras de alumnos.h"

#define CAN 3



int main()
{
    eAlumno listaAlumnos[CAN];


    cargarListaAlumnos(listaAlumnos,CAN);

    ordenarAlumnos(listaAlumnos,CAN);

    mostrarListaAlumnos(listaAlumnos,CAN);







    return 0;
}
