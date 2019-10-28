#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int id;//5 bytes
    char nombre[20];//guarda 20 bytes
    float sueldo;//4 bytes para el sueldo
    int estado;//4 bytes para el estado.

}eEmpleado;

/**PROTIPOS (INICIO)**/
eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* unEmpleado);
eEmpleado* newEmpleadoParam(int id,char* nombre, float sueldo);
int inicializarEmpleados(eEmpleado* vec, int tam);

/**PROTIPOS (FIN)**/

/**
-SIEMPRE HAY QUE VALIDAR EN CADA FUNCION QUE SEA != NULL
-NO EXISTEN LAS FUNCIONES QUE DEVUELVAN VOID, SIEMPRE TIENE QUE DEVOLVER ALGO

**/

/****HACER UN ABM DINAMICO***/

int main()
{
    int tam = 0;//cumple dos funciones
    //tam me dice el indice libre y me dice la cantidad de elementos que tengo en el array.
    eEmpleado* aux;

    /****HACER UN ABM DINAMICO***/
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)* (tam + 1));
    //puntero en la memoria estatica que se llama lista
    //lista guardaria la memoria del primer elemento
    //tendria espacio para 5 empleados... un vector dinamico de tamaño
    //tam + 1 va entre parentesis

    /*if(inicializarEmpleados(lista,tam))
    {
        printf("\nEmpleados inicializados.\n");
    }
    else
    {
        printf("\nProblemas para inicializar empleados.\n");
    }*/


    //eEmpleado emp1;
    //emp2  es el puntero
    //eEmpleado* emp2 = newEmpleado();

    /**Dos maneras de cargar el id
    -Podria hacer alta cliente asi...
    **/
    //emp2 ->id = 1234; //-> solamente par econtrar la variable id entera
    //printf("Ingrese id: ");
    //scanf("%d",&emp2->id);
    //hace falta el & porque necesto la dire de memoria de esa variale
    //la dire de mmeroia de la variable necesita scanf

    //mostrarEmpleado(emp2);
    //printf("%d",sizeof(eEmpleado));//PEDIMOS 32 BYTES DE MEMORIA
    eEmpleado* emp3 =  newEmpleadoParam(3322,"Yago",34000);


    *(lista + tam) = *emp3;//lo agrego
    //(lista + tam) es una direccion de memoria

    //mostrarEmpleado(emp3);

    mostrarEmpleado(lista+tam);//verifico si esta un empleado
    tam++;

    aux = (eEmpleado*) realloc(lista,sizeof(eEmpleado) * (tam + 1));


    return 0;
}


/***FUNCION CONSTRUCTORA DE MANERA DINAMICA***/
/**
-TODO ESTO PARA CONSEGUIR UN EMPLEADO, ES COMO --INICIALIZAR-- EMPLEADO.
-CREA UN NUEVO ESPACIO EN MEMORIA.
-LO CONSIGO EN TIEMPO DE EJECUCION.
-LO CONSIGO PERO NO CON TODOS LOS DATOS CARGADOS, LO RETORNO VACIO.
-NULL = La no direccion de memoria**/
eEmpleado* newEmpleado()
{
    eEmpleado* nuevoEmpleado;

    //Recien cuando haga malloc se me asigna un empleado a mi.
    nuevoEmpleado = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(nuevoEmpleado != NULL)
    {
        /**Inicializo y los limpio los campos en 0***/
        nuevoEmpleado ->id = 0;
        strcpy(nuevoEmpleado->nombre,"");//cadena vacia
        nuevoEmpleado ->sueldo = 0;
        nuevoEmpleado ->estado = 0;
    }
    return nuevoEmpleado;
}


/**NO SE USA MAS LOS CORCHETES
PUNTERO A CHAR NOMBRE(cuando usemos un vector de caracteres)
-Parametrizado.
-Le paso el id,nombre y sueldo y me lo devuelve todo cargado.
-***/
eEmpleado* newEmpleadoParam(int id,char* nombre, float sueldo)
{
    eEmpleado* e = newEmpleado();//consigue malloc, consigue todo y me lo devuelve

    /**
    -Pido los datos, getstring getint etc etc
    -A la hora de asignar ACA ADENTRO VALIDO EL id, nombre, sueldo, etc etc
    Recien ahi cargo y lo devuelvo.**/
    if(e != NULL)
    {
        /**Inicializo los campos en 0***/
        e ->id = id;
        strcpy(e->nombre,nombre);
        e ->sueldo = sueldo;
        e ->estado = 0;
    }

    return e;
}

/**AHORA TODAS LAS FUNCIONES TIENE QUE DEVOLVER ALGO Y SE USA TOODS PUNTEROS**/
int mostrarEmpleado(eEmpleado* unEmpleado)
{
    int todoOk = 0;
    if(unEmpleado != NULL)
    {
        printf("\n\n|  %d  |  %s  |  %2.f  |\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->sueldo);
        todoOk = 1;
    }
    return todoOk;
}


/**
-
***/
int inicializarEmpleados(eEmpleado* vec, int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam >=0)
    {
        for(int i = 0; i<tam;i++)
        {
            /**ADENTRO DEL FOR NO PUEDO PONER LA FLECHITA**/
            //VEC es un puntero a Lista
            //tiene que hacer la cuenta entre vec + i para que recorra todas las posiciones.
            //i = sizeof de estructura de empleados(de 32 bytes(con uno solo), 64 bytes (con dos cargados)y asi sucesivamente)
            (vec + i)->estado = 0;
            //(*(vec+i)).estado = 0;//ESTO ES EXACTAMENTE LO MISMO
            //vec+i es la dire de memoria de esas estructuras
            //pero si lo encierro con un y pongo asterisc es la variable estructura
            //y si ya tengo la estructura puedo acceder con el punto...
        }
        todoOk = 1;

    }

    return todoOk;
}




