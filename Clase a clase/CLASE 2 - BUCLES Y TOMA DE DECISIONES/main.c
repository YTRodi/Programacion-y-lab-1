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

    char maximo;
    char nombreMaximo;
    char sexoMaximo;
    int notaMaxima;

    maximo = 0;
    nombreMaximo = 0;
    sexoMaximo = 0;
    notaMaxima = 0;

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
            maximo = nombre;
            nombreMaximo = nombre;
            sexoMaximo = sexo;
            notaMaxima = nota;
        }
        else if(maximo>nombre)
        {
            maximo = nombre;
            nombreMaximo = nombre;
            sexoMaximo = sexo;
            notaMaxima = nota;
        }


        printf("Ingrese s para continuar o n para terminar\n");// para terminar la funcion
        fflush(stdin);
        scanf("%c", &respuesta);

    }
    printf("datos mejor alumno: nombre: %s , nota: %d y sexo:%c", nombreMaximo, notaMaxima, sexoMaximo);


    return 0;
}
