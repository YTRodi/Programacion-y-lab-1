#include <stdio.h>
#include <stdlib.h>

int main()
{

    //INGRESAR NOMBRE NOTA Y SEXO. de no se sabe cuantos alumnos.
    //mostrar:
    //-todos los datos del alumno con mayor nota.
    //-el promedio total de notas.
    //-promedio de notas de las mujeres.(solo mujeres)

    char nombre[30];
    int nota;
    char sexo;
    char respuesta = 's';
    int contador;

    char nombreMaximo;
    char sexoMaximo;
    int notaMaxima;


    contador = 0;


    while(respuesta == 's')
    {
        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese nota:");
        scanf("%d", &nota);

        printf("Ingrese sexo:");
        fflush(stdin);
        scanf("%c", &sexo);


        if(contador ==0)
        {
            nombreMaximo = nombre;
            notaMaxima = nota;
            //sexoMaximo = sexo;
        }
        else if(nombreMaximo>nombre)
        {
            nombreMaximo = nombre;
            notaMaxima = nota;
        }


        printf("Ingrese s para continuar o n para terminar\n");// para terminar la funcion
        fflush(stdin);
        scanf("%c", &respuesta);


    }

    printf("1.Nombre del alumno maximo: %s , nota del alumnmo maximo: %d", nombreMaximo, notaMaxima);

    return 0;
}
