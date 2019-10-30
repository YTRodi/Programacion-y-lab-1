#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* aux;//para agrandar con realloc

    //pido y cargo el vector de manera secuencial
    int* numeros = (int*) malloc(sizeof(int)*5);//tengo lugar para 5 numeros(20 bytes).

    for(int i = 0; i<5; i++)//lo cargo
    {
        printf("\n\nIngrese un numero: ");
        scanf("%d",numeros + i);
        //numeros es la dire de memoria
        //i es aritmetica de punteros, cyanto me tengo que desplazar en la memoria(cuantos bytes)
    }

    for(int i = 0; i<5; i++)
    {
        printf(" %d ", *(numeros + i));//Si no pongo el +i, me sale la primera posicion siempre.
    }


    /**quiero 5 mas**/

    //numeros = (int*) realloc(numeros,sizeof(int) *10); //son los 5 que tengo mas 5 que necesito.
    aux = (int*) realloc(numeros,sizeof(int) *10);

    if(aux != NULL)
    {
        numeros = aux;//esto es para no perder lo que ya tenia si realloc no consiguio lugar
    }

    //pido 5 numeros mas
    for(int i = 5; i<10; i++)
    {
        printf("\n\nIngrese un numero: ");
        scanf("%d",numeros + i);//i es aritmetica de punteros, cianto me tengo que desplazar en la memoria
    }

    for(int i = 5; i<10; i++)
    {
        printf(" %d ", *(numeros + i));
    }

    numeros = (int*) realloc(numeros,sizeof(int) * 6);//libere 4

    for(int i = 5; i<5; i++)
    {
        printf(" %d ", *(numeros + i));
    }

    free(numeros);//liberamos la memoria antes de irnos.

    return 0;
}
