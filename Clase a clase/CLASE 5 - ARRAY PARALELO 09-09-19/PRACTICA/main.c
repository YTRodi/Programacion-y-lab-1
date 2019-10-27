#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define T 3
#define NOTAS 3

int main()
{
    //Cargar alumno
    int legajo[T] = {50,65,80};//HARDCODEO PARA NO CARGAR DATOS
    int edad[T] = {21,15,18};
    char sexo[T] = {'f','m','m'};
    int nota1[T] = {10,8,6};
    int nota2[T] = {5,9,8};
    int nota3[T] = {8,4,2};
    float promedio[T];
    int i;//variable de control

    for(i = 0; i < T; i++)//CARGAR ALUMNOS.
    {
        /*legajo[i] = getInt("Ingrese legajo: ");
        edad[i] = getInt("Ingrese edad: ");
        sexo[i] = getChar("Ingrese sexo: ");
        nota1[i] = getInt("Ingrese nota1: ");
        nota2[i] = getInt("Ingrese nota2: ");
        nota3[i] = getInt("Ingrese nota3: ");*/

        promedio[i] = (float) (nota1[i]+nota2[i]+nota3[i]) / NOTAS;


        /*printf("Ingrese legajo: ");
        scanf("%d",&legajo[i]);

        printf("\Ingrese edad: ");
        scanf("%d",&edad[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c",&sexo[i]);

        printf("Ingrese nota1: ");
        scanf("%d",&nota1[i]);

        printf("Ingrese 2da nota: ");
        scanf("%d",&nota2[i]);

        printf("Ingrese 3er nota: ");
        scanf("%d",&nota3[i]);

        promedio[i] = (float) (nota1[i]+nota2[i]+nota3[i]) / NOTAS;*/



        printf("%d\t %d\t %c\t %d\t %d\t %d\t %.2f\n",//MOSTRAR ALUMNOS
               legajo[i],
               edad[i],
               sexo[i],
               nota1[i],
               nota2[i],
               nota3[i],
               promedio[i]);

    }



    return 0;
}
