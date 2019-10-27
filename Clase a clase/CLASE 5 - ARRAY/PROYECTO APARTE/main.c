#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int vec[], int tam, int numero);

int main()
{
    int numeros[] = (23, 12 ,32 ,45,33 ,43 ,53, 21, 15, 65);
    int esta;

    esta = buscarNumero(numeros, 10, 100);

    if (esta)
    {
        printf("esta\n");
    }
    else
    {
        printf("no esta\n");
    }

    return 0;
}

int buscarNumero(int vec[], int tam, int numero)
{
    int esta = 0;//me conviene cargarla
    for(int i = 0; i < tam, i++)
    {
        if ( numero == vec[i])
        {
            esta = 1;
            break;//BREAK Y ME FUI, no hago que la maquina recorra todo para leer esto.
            //encuentro que hubo una coincidencia y me voy.
        }
    }
    return esta;
}
/*int buscarNumero(int vec[], int tam, int numero)
{

}*/
