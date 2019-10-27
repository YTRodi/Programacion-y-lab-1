#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 4
#define CAN 50

void cargarNumerosTest(int datosNumericos[] , int cant);
void mostrarNumeros(int datosNumericos[], int cant);

void cargarPalabrasTest(char palabra[] [50], int cant);
void mostrarPalabras(char palabra[] [50], int cant);

void cargarNombresTest(char array [] [50], int cant);
void cargarApellidosTest(char array[] [50], int cant);
void cargarEdadesTest(int array[], int cant);
void ordenarPorEdades(char nombre [] [50], char apellido [] [50], int edad[], int tam);
void listar(char nombre [] [50], char apellido [] [50], int edad[], int cant);

int main()
{
    /*int datoNumericos[T];// = {22,33,44};
    char letra;
    char palabra[T];
    char listadoDePalabras[T] [CAN];

    //cargarNumerosTest(datoNumericos,T);
    //mostrarNumeros(datoNumericos,T);

    //cargarPalabrasTest(palabra,T);
    //mostrarPalabras(palabra,T);
    */

    char apellidos[T] [CAN];
    char nombres[T] [CAN];
    int edades[T];

    cargarApellidosTest(apellidos,T);
    cargarNombresTest(nombres,T);
    cargarEdadesTest(edades,T);
    ordenarPorEdades(nombres,apellidos,edades,T);
    listar(nombres,apellidos,edades,T);

    return 0;
}

void cargarNumerosTest(int datosNumericos[], int cant)//cargar los numeros
{
    int i;
    int aux [] = {22,33,44};

    for(i=0; i<cant; i++)
    {
        datosNumericos[i] = aux[i];
    }

}

void mostrarNumeros(int datosNumericos[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        printf("%d\n",datosNumericos[i]);
    }
}

void cargarPalabrasTest(char palabra[] [50], int cant)
{
    char aux [] [50] = {"Joaquin", "Facundo", "Yago"};
    int i;
    for(i = 0; i<cant;i++)
    {
        strcpy(palabra[i],aux[i]);
    }
}

void mostrarPalabras(char palabra[] [50], int cant)
{
    //el [50] es el maximo de caracatres que puedo ingresar.
    int i;

    for(i=0; i<cant;i++)
    {
        printf("%s\n",palabra[i]);
    }

}




//(INICIO) CARGO NOMBRES, APELLIDOS Y EDADES.
void cargarNombresTest(char array [] [50], int cant)
{
    char aux [] [50] = {"Joaquin", "Facundo", "Fulanito", "Yago"};
    int i;
    for(i = 0; i<cant;i++)
    {
        strcpy(array[i],aux[i]);
    }
}

void cargarApellidosTest(char array[] [50], int cant)
{
    char aux [] [50] = {"rojas", "rocha","perez", "rodi"};
    int i;
    for(i = 0; i<cant;i++)
    {
        strcpy(array[i],aux[i]);
    }
}

void cargarEdadesTest(int array[], int cant)
{
    int i;
    int aux [] = {22,33,18,55};

    for(i=0; i<cant; i++)
    {
        array[i] = aux[i];
    }
}
//FIN

//(INICIO) MUESTRO TODOS NOMBRES,APELLIDOS Y EDADES.
void listar(char nombre [] [50], char apellido [] [50], int edad[], int cant)
{
    int i;

    for(i=0 ; i<cant ; i++)
    {
        printf("Nombre: %s\nApellido: %s\nEdad: %d\n\n",nombre[i],apellido[i],edad[i]);
    }

}
//FIN


void ordenarPorEdades(char nombre [] [50], char apellido [] [50], int edad[], int tam)
{
    //por string
    int i;
    int j;

    int auxEdades;
    char auxApellidos [50];//lo hago un array con los []
    //se deja el 50 solo porque es la cantidad de caracteres que va a sp
    char auxNombres [50];

    for(i = 0 ; i<tam-1 ; i++)
    {
        for(j = i+1; j<tam ; j++)
        {
            if(edad[i]>edad[j])//tengo que swapear todo asi se actualiza y ordena  todo
            {
                //swap para arrays
                auxEdades = edad[i];
                edad[i] = edad[j];
                edad[j] = auxEdades;

                //swap para string
                strcpy(auxNombres,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxNombres);


                strcpy(auxApellidos,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j],auxApellidos);
            }
        }
    }



}

