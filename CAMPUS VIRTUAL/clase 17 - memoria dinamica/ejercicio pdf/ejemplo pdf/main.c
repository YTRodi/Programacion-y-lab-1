#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nombre[50];
    int edad;

} ePersona;


int main()
{
    int seguirCargando;
    int auxNuevaLongitud;
    int longitudPersonas = 1;
    ePersona* pArrayPersona;
    ePersona* pAuxPersona;


    //creamos el array de personas
    pArrayPersona = malloc(sizeof(ePersona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }

    while(1)
    {
        printf("\nIngrese nombre: ");
        scanf("%s",(pArrayPersona+longitudPersonas-1)->nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&((pArrayPersona+longitudPersonas-1)->edad));
        printf("\nSi desea cargar otra persona ingrese (1): ");
        scanf("%d",&seguirCargando);
        if(seguirCargando == 1)
        {
            //Calculamos el nuevo tamaño del array.
            auxNuevaLongitud = sizeof(ePersona)*longitudPersonas;

            //Redimencionamos la lista.
            pAuxPersona = realloc(pArrayPersona,auxNuevaLongitud);

            if(pAuxPersona == NULL)
            {
                printf("\no hay mas memoria.\n");
                break;
            }
            longitudPersonas++;
            pArrayPersona = pAuxPersona;
        }
        else
        {
            break;
        }
    }


    for(int i = 0; i < longitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }
    free(pArrayPersona); // Liberamos la memoria


    return 0;
}

