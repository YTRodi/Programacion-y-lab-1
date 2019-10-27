#include <stdio.h>
#include <stdlib.h>
#define TAM 1

int main()
{
    int leg[TAM];//legajo
    int edad[TAM];
    char sexo[TAM];
    int nota1[TAM];
    int nota2[TAM];
    int nota3[TAM];
    int suma[TAM];
    float promedio[TAM];
    int i; //variable de control

    for(i=0;i<TAM;i++)
    {
        printf("\nIngrese legajo del alumno:");
        scanf("%d",&leg[i]);
        printf("\nIngrese edad del alumno:");
        scanf("%d",&edad[i]);
        printf("\nIngrese sexo <f-m> del alumno:");
        fflush(stdin);
        scanf("%c",&sexo[i]);
        printf("\nIngrese 1ra nota:");
        scanf("%d",&nota1[i]);
        printf("\nIngrese 2da nota:");
        scanf("%d",&nota2[i]);
        printf("\nIngrese 3ra nota:");
        scanf("%d",&nota3[i]);

        suma[i] = nota1[i]+nota2[i]+nota3[i];// la suma de las notas
        promedio[i] = (float) suma[i]/TAM;
    }

    for(i = 0; i < TAM; i++)
    {
        printf("%d\t %d\t %c\t %d\t %d\t %d\t %.2f\n",
               leg[i],
               edad[i],
               sexo[i],
               nota1[i],
               nota2[i],
               nota3[i],
               promedio[i]
               );

    }
    return 0;
}
