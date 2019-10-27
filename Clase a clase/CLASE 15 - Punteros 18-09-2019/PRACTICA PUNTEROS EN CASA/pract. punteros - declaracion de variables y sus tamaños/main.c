#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**** Declaracion de variables y sus tamaños *****/

    int auxInt = 10;
    char auxChar = 'a';
    char auxString[5] = "hola";

    printf("\nNumero que imprime (int): %d\n",auxInt);
    printf("Direccion de memoria: %p\n",&auxInt); // "%p" -> la mascara para imprimir punteros.
                                                  //Con el "&" accedemos la posicion de memoria.
    printf("Tamanio que ocupa: %d\n",sizeof(auxInt)); //imprime el tamaño que ocupa un int.

    printf("\nLetra que imprime (char): %c\n",auxChar);
    printf("Direccion de memoria: %p\n",&auxChar);
    printf("Tamanio que ocupa: %d\n",sizeof(auxChar)); //imprime el tamaño que ocupa un char.

    printf("\nString que imprime (char): %s\n",auxString); //guarda 1 espacio para el "\0".
    printf("Direccion de memoria: %p\n",auxString);
    printf("Tamanio que ocupa: %d\n",sizeof(auxString));

    //auxInt = (int) &auxChar;
    //printf("\nque muestro aca? %p\n",&auxChar);



    return 0;
}
