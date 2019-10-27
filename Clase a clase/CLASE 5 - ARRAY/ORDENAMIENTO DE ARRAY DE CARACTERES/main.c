#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 3

int obtenerMayor(int mayor);

int main()
{
    char letras[TAM] = {'e','a','z','b'};
    char aux

    for(int i = 0; i<TAM-1;i++)
    {
        for(int j = i+1;j<TAM,j++)
        {
            if(strcmp(letras[i],letras[j])>0)
            {
                aux = letras[i];
                letras[i] = letras[j];
                letras[j] = aux;
            }
        }
    }



    /*int i;
    int vec[10];
    int mayor;

    mayor = vec[0];

    for(i = 0; i<TAM; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d",&vec[i]);


    }
    if(vec[i]>mayor)
        {
            mayor = vec[i];
        }

    printf("El mayor es %d",mayor);*/




    /*
    6--
    int numero;

    printf("Ingrese numero: ");
    scanf("%d",&numero);

    if(numero>=200 && numero<=500)
    {
        printf("numero agregado con exito");
    }
    else
    {
        printf("ERROr");
    }*/





    /*int a = 0;
    int b = 1;
    if(a&&b)
    {
        printf("Hola");
    }
    else
    {
        printf("Chau");
    }*/


    /*char nombre[20] = {"joooJuan"};

    //strupr(nombre[0]);
    //nombre[0] = toupper(nombre[0]);

    nombre[0] = toupper(nombre[0]);

    printf("%s",nombre);*/



    /*int i;

    for(i=0;i<10;i++)
    {
        if(!(i%2))
        {
            printf("%d\n",i);
        }
    }*/


    //int vec[10] = {10,15,78,98,45,12,45,78,98,100};

    /*int vec[10];
    int posicion;
    char seguir;

    for(int i = 0; i < 3; i++)
    {
        vec[i] = 0;//INICIALIZO
        do
        {
            printf("Ingrese posicion: ");
            scanf("%d",&posicion);

            printf("Ingrese numero: ");
            scanf("%d",&vec[posicion]);

            rintf("Desea ingresar otro dato: ");
            scanf("%c",&seguir);


        }while(seguir == 's');

    }*/







    return 0;
}

/*int obtenerMayor(int mayor)
{
    int mayor;



}*/
