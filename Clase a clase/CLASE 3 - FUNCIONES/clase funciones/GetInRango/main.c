#include <stdio.h>
#include <stdlib.h>

int getInRango(int min, int max);

int main()
{
    int min;
    int max;
    //int rango;

    printf("Ingrese minimo:");
    scanf("%d",&max);

    printf("Ingrese maximo");
    scanf("%d",&min);

    printf(getInRango(max,min));


    //printf("%d\n", getInRango(18,65)); //ejemplo

    return 0;
}
int getInRango(int min, int max)
{
    int num;
    printf("Su rango es de %d a %d",min,max);
    scanf("%d",&num);

    while(num < min || num > max)
    {
        printf("ERROR. Reingrese");
        scanf("%d", &num);
    }
    return num;
}
