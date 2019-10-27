#include <stdio.h>
#include "alumnos.h"
/***ESTA EN EL CAMPUS MEMORIA DINAMICA
CLASE 17 PEOPLE.C (GETTERS Y SETTERS)Y CONSTRUCTORES**/

eAlumno* newAlumno()//construyo una entidad en el heap
{
    eAlumno* unAlumno;

    unAlumno = (eAlumno*) malloc(sizeof(eAlumno));

    return unAlumno;
}


eAlumno* newAlumnoParametros(int id,char* nombre, char* apellido, int nota)
{
    eAlumno* unAlumnoParametro = newAlumno();
    //no hace falta el atoi ni el atof, porque ya los recibos como enteros y float.
    unAlumnoParametro->id = id;//atoi por el INT
    strcpy(unAlumnoParametro->nombre,nombre);
    strcpy(unAlumnoParametro->apellido,apellido);
    unAlumnoParametro->nota = nota;

    return unAlumnoParametro;
}

int getId(eAlumno* unAlumno)//devuelve el dato.
{
    int id;

    if(unAlumno != NULL)
    {
        id = unAlumno->id;
    }
    return id;
}


void setId(eAlumno* unAlumno,int id)
{
    unAlumno->id = id;//lo pone adentro de la estructura.
}




















