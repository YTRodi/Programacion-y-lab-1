#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**
    -Es buena practica inicializarlos en NULL.
    -NULL = posicion nula o invalida.
    -Sino van a arrancar con un valor cualquiera (basura en esa posicion de memoria).

    -Operador de direccion (&):
    -Permite obtener la direccion de memoria de una variable.

    -Operador de indireccion (*):
    -Devuelve el contenido en la posicion apuntada por el puntero.

    **/

    int* punteroInt = NULL; //nombre del variable del tipo puntero a int
    char* punteroChar = NULL;
    float* punteroFloat = NULL;


    int auxInt = 10;
    char auxChar = 'a';
    float auxFloat = 3.14;


    /**
    -Obtenemos su direccion de memoria anteponiendo el &.
    -Y son guardadas en la variable tipo puntero.

    **/
    //punteroInt deja de tener el valor NULL y tiene la posicion de memoria de auxInt.
    punteroInt = &auxInt;
    punteroChar = &auxChar;
    punteroFloat = &auxFloat;

    printf("\nValor de auxInt asignada a punteroInt: %i\n",*punteroInt);
    printf("Posicion de memoria de auxInt: %p\n",punteroInt);//dire de memoria de auxint;

    printf("\nValor de auxChar asignada a punteroChar: %i\n",*punteroChar);
    printf("Posicion de memoria de auxChar: %p\n",punteroChar);

    //PORQUE NO ME TOMA EL %i ?????
    printf("\nValor de punteroFloat asignada a punteroFloat: %.2f\n",*punteroFloat);
    printf("Posicion de memoria de auxFloat: %p\n",punteroFloat);

    /**
    -Ejemplo:
    **/
    int variableInt = 44;//asigno valor a varibleInt.
    punteroInt = &variableInt;//obtengo la posicion de memoria.
    printf("\nValor de variableInt: %i\n",*punteroInt);//imprimos el valor de la variable apuntada por punteroInt.


    /**
    -Asignando directamente algo a *puntero, se pisa lo anterior.
    -Con esto pisamos lo que estaba ya asignado en punteroInt (&auxInt);
    **/
    *punteroInt = 22;
    *punteroChar = 'b';
    *punteroFloat = 22.55;

    printf("\nValor de punteroInt asignado manualmente(pisado): %i\n",*punteroInt);
    printf("Valor de punteroChar asignado manualmente(pisado): %i\n",*punteroChar);
    printf("Valor de punteroFloat asignado manualmente(pisado): %.2f\n",*punteroFloat);





    return 0;
}
