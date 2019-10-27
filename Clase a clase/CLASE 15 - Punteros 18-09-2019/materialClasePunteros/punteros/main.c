#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int y = 10;

    printf("\n\tValor en el main: x = %d -- y = %d\n", x, y);

    swap( &x, &y);

    printf("\n\tValor en el main despues del swapeo: x = %d --  y = %d\n", x, y);

    return 0;
}

//le damos acceso a la funcion swap a un espacio de memoria de nuestra funcion main.
void swap( int* p, int* q)
{
    int aux;

    aux = *p; //guardamos en aux el contenido apuntado por *p
    *p = *q;
    *q = aux;

    printf("\n\tValor en el swap: x = %d -- y = %d\n", *p, *q);
}

