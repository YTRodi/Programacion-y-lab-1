#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Que es un csv??? es un archivo de texto, los textos que voy a escribir se van a separar por comas

/**
-Split de una cadena : cortar una cadena en pedazos
-con delimitadorr te orientas para el cambio
-strtok(va avanzando por la cadena y cortando el pedacitos).
-fscanf(FILE,"%s",variable); hay que delimitar alggo en el %s.
hace lo mismo que el scanf PERO desde un archivo.
Puedo traer una linea y trerla al archivo.
-PARSEAR ES PASAR DE UN STRING A UN DATO NUMERICO.
***/

typedef struct
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float sueldo;

}eEmpleado;

eEmpleado* new_Empleado();


int main()
{
    //creo un archivo y lo abro como escritura de texto(mockaroo).

    //creo un vector.
    eEmpleado* lista[50];
    //una array que adentro va a guardar punteros a la estructura empleados.
    //eEmpleado* emple = new_Empleado();
    int i = 0;
    eEmpleado* emple;


    FILE* miArchivo;
    //creo una variable de cada dato
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[10];

    //eEmpleado emple;//esto se carga en la pila.

    miArchivo = fopen("datos.csv","r");

    //fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);//afuera del while es una falsa lectura

    while(!feof(miArchivo))
    {
        //EXPRESION REGULAR "%[^,],"
        fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

        emple = new_Empleado();
        //LO CREO ACA PORQUE NECESITO QUE VAYA CREANDO EN DISTINTAS INSTANCIAS LOS EMPLEADOS.

        /**Esto se crea en la pila(NO QUEREMOS ESO)**/
        /**Puedo hacer una funcion parametrizada que use a new_Empleado y haga estas asignaciones...***/
        emple->legajo = atoi(legajo);
        strcpy(emple->nombre,nombre);
        strcpy(emple->apellido,apellido);
        emple->sueldo = atof(sueldo);

        *(lista+i) = emple;//otra forma --> lista[i]=emple;
        i++;
    }

    fclose(miArchivo);

    for(i = 0;i<50;i++)
    {

        printf("| %7d | %15s | %15s | %15f |\n",
               lista[i]->legajo,
               lista[i]->nombre,
               lista[i]->apellido,
               lista[i]->sueldo);
    }

    return 0;
}

eEmpleado* new_Empleado()//constructor por defecto
{
    eEmpleado* e = (eEmpleado*)malloc(sizeof(eEmpleado));



    return e;
}
