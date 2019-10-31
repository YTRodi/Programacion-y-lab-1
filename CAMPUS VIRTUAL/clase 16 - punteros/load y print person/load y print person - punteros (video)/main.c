#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

typedef struct
{
    char nombre[32];
    int edad;
    int id;

}ePersona;

int loadPerson(ePersona* pPersona);
void printPerson(ePersona* pPersona);

int main()
{
    ePersona p;

    /*usamos "&" porque tenemos que pasar la direccion de
    memoria donde esta esta variable que esu an estructura.*/
    if(loadPerson(&p)==0)
    {
        printf("\nDatos correctos\n");
        printPerson(&p);
    }
    else
    {
        printf("\nDatos incorrectos\n");
    }

    return 0;
}

int loadPerson(ePersona* pPersona)
{
    if(getNombreOApellido(pPersona->nombre,"\n<2-32 caract>Ingrese nombre: ","Error.Reingrese",2,32,2)!=-1)
    {
        if(getInt(&pPersona->edad,"\n<1-100>Ingrese edad: ","Error.Reingrese",1,100,2)!=-1)
        {
            if(getInt(&pPersona->id,"\n<1-100000>Ingrese id: ","Error.Reingrese",1,100000,2)!=-1)
            {
                return 0;
            }
        }
    }

    return 1;
}

void printPerson(ePersona* pPersona)
{
    printf("\nNombre: %s \nEdad: %d \nId:%d\n",pPersona->nombre,pPersona->edad,pPersona->id);
}


