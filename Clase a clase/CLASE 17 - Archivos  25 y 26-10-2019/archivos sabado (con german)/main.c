#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"

/**
-USAMOS MOCKAROO PARA GENERAR DATOS
-lo abrimos
-lo usamos (fprintf
**/


int main()
{
    //eAlumnos lista[20];
    eAlumno* lista[20];

    //eAlumnos unAlumno;//se va a crar en el stack, es un dato.
    //si hago un un malloc afuera de un while, creo solamente un dato.
    //al crear un while, genero distintos espacios de memoria para ir apuntandolos en cada iteracion del while

    eAlumno* unAlumno;

    FILE* archivo;

    //char mensaje[50];//creo un buffer
    //char aux;//la inicializo en 0?
    /**OTRA FORMA..***/
    int i = 0;


    char id[10];
    char nombre[50];
    char apellido[50];
    char nota[10];

    //archivo = fopen("texto.txt","w");//w = escritura
    //archivo = fopen("texto.txt","r");//r = lectura
    archivo = fopen("MOCK_DATA (2).csv","r");//r = lectura

    //fgets(mensaje,49,archivo);

    if(archivo == NULL)
    {
        printf("\n\nNo se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fgets(mensaje,49,archivo);//me exluye la primer linea pq hace un falta lectura

    fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);
    //lee la fila con los titulos, falsa lectura(lee la primera linea del archivo.)
    //en el ultimo lee hasta el salto de linea y lo excluye
    //alt + 94. //"%[^,]," que lea hasta la coma y la excluya


    while(!feof(archivo))//CON CONTRUCTOR
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);//PRIMERO LAS VARIBLES, DESP LOS GUARDO EN ESTRUCTUARAS

        unAlumno = newAlumno();

        unAlumno = newAlumnoParametros(atoi(id),nombre,apellido,atof(nota));

        setId(unAlumno,7);//solamente setea los id.


        *(lista+i) = unAlumno;
        i++;//para ir iterando
    }


    //CON PUNTEROS (CONVIENE CREAR UN CONSTRUCTOR)
    /*while(!feof(archivo))
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);//PRIMERO LAS VARIBLES, DESP LOS GUARDO EN ESTRUCTUARAS

        unAlumno = newAlumno();
        //unAlumno = malloc(sizeof(eAlumnos));//ACA HAGO EL MALLOC, pido memoria adentro de un while.
        **SETEO LOS CAMPOS**
        //hay que PARSEAR los int. un tipo de dato de cadena a un tipo de dato numerico.
        unAlumno->id = atoi(id);//atoi por el INT
        strcpy(unAlumno->nombre,nombre);
        strcpy(unAlumno->apellido,apellido);
        unAlumno->nota = atof(nota);//atof por el FLOAT

        *(lista+i) = unAlumno;
        i++;//para ir iterando
    }*/

    for(i= 0;i<20;i++)
    {
        //(lista+i) es el vector.
        //(*(lista+i)) necesito el astericos, devuelve el contenido de esta dire de memoria.
        //con la fecha acceso al campo
        //printf("%d--%s--%s--%.2f\n",(*(lista+i))->id,(*(lista+i))->nombre,(*(lista+i))->apellido,(*(lista+i))->nota);
        printf("%d--%s--%s--%.2f\n",getId(*(lista+i)),(*(lista+i))->nombre,(*(lista+i))->apellido,(*(lista+i))->nota);

    }

    //SIN PUNTEROS.
    /*while(!feof(archivo))
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);//PRIMERO LAS VARIBLES, DESP LOS GUARDO EN ESTRUCTUARAS

        ***SETEO LOS CAMPOS**
        //hay que PARSEAR los int. un tipo de dato de cadena a un tipo de dato numerico.
        unAlumno.id = atoi(id);//atoi por el INT
        strcpy(unAlumno.nombre,nombre);
        strcpy(unAlumno.apellido,apellido);
        unAlumno.nota = atof(nota);//atof por el FLOAT

        lista[i] = unAlumno;
        i++;//para ir iterando
    }*/

    /*while(!feof(archivo))//FUNCIONA
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,nota);
        printf("%s--%s--%s--%s\n",id,nombre,apellido,nota);


    }*/

    /*while(!feof(archivo))//feof si encontro el final del archivo
    {
        if(feof(archivo))
            break;
        fgets(mensaje,49,archivo);
        printf("%s",mensaje);
        i++;
    }*/


    /*while(!feof(archivo))//usamos while pq vamos a forzar lo que vamos a leer
    {
        //fread(,,)
        fread(mensaje,sizeof(char),50,archivo);
        printf("%s\n",mensaje);
    }*/


    fclose(archivo);


    //SIN PUNTEROS.
    /*for(i= 0;i<20;i++)
    {
        printf("%d--%s--%s--%.2f\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].nota);

    }*/

    //printf("%s",mensaje);//leemos el archivo, creamos el archivo y escbrimios sobre el
    //con todo esto lo leemos(de aca para arriba).

    /*
    if(archivo != NULL)
    {
        printf("\nLo creo.\n");
    }
    else
    {
        printf("\nNo lo creo.\n");
    }

    //fprintf(archivo,"El dia esta lindo");
    fprintf(archivo,"Hola a todos");
    **va al archivo y en la consola imprime en el texto ete archivo***

    fclose(archivo);*/

    return 0;
}


