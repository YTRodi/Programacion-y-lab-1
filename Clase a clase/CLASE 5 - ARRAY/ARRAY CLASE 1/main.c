#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];
    int acumulador = 0;

    for(int i = 0; i < 5; i ++)//CARGAR
    {
        printf("ingrese numero:");
        scanf("%d",&numeros[i]);
    }

    printf("los numeros ingresados son: %d %d %d %d %d \n\n",numeros[0],
           numeros[1],numeros[2], numeros[3], numeros[4]);//LOS MUESTRO

    for(int i = 0 ; i < 5 ; i ++)//LOS SUMO
    {
        acumulador += numeros[i];
    }

    printf("la suma es de los numeros ingresados es: %d",acumulador);//MUESTRO LA SUMA




    return 0;
}
