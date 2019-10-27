#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
int obtenerMayor(int vec[],int tam);
void cargarVectorInt(int vec[], int tam);
//void mostrarIndics(vec[],int tam, int num);//mostrar los indices en donde esta el numero.

int main()
{
    int numeros[5];
    int numeroMaximo = 0;
    int flag = 0;

    //mostrarVectorInt(numeros,3);

    for(int i = 0; i < 5 ; i++)//TOMO/CARGAR EL VECTOR.
    {
        printf("Ingrese NUMERO:");
        scanf("%d",&numeros[i]);
    }

    printf("Los numeros ingresados son %d %d %d %d %d",numeros[0],numeros[1],numeros[2],
           numeros[3],numeros[4]);
    printf("\n\n");

    for(int i = 0; i < 5; i++)//TOMO EL MAYOR
    {
        if(numeros[i] > numeroMaximo || flag == 0)//tomo el mayor
        {
            numeroMaximo = numeros[i];
            flag = 1;
        }
    }

    printf("El numero mayor ingresado es : %d",numeroMaximo);

    /*for(int i = 0; i < 5; i++)//EN QUE INDICE ESTA EL MAYOR.
    {
        if(numeros[i])
    }*/


    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        printf("%d",vec[i]);
    }
    printf("\n\n");

}

/*int obtenerMayor(int vec[],int tam)
{


}*/
