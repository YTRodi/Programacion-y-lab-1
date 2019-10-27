#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct
{
    //campos o atributos.
    int leg;
    char name[25];//porque es un solo nombre;
    float prom;//promedio.
    int estado;

    /*LA ESTRUCTURA:
    -NO es un vector.
    -guarda la direccion de memoria del primer elemento.
    -son datos por valor.

    */
} sAlumno;//alias

sAlumno cargarAlumno(void);
void mostrarUnAlumno(sAlumno);

void cargarListadoAlumnos(sAlumno vec [], int tam);
void mostrarListadoAlumnos(sAlumno vec[], int tam);


int main()
{
    sAlumno miAlumno[TAM];//local del main
    for(int i = 0; i < TAM; i++)
    {
        miAlumno[i].estado = 0;

    }

    //miAlumno[TAM] = cargarAlumno();
    //mostrarUnAlumno(miAlumno);
    cargarListadoAlumnos(miAlumno,TAM);
    mostrarListadoAlumnos(miAlumno,TAM);
    //mostrarAlumnos(miAlumno,TAM);
    /*
    //sAlumno es el tipo de dato
    //miAlumno es la variable
    sAlumno miAlumno;//= {1000,"Yago",7,66};//EN ORDEN A COMO ESTA LA ESTRUCTURA.
    sAlumno otroAlumno;

    printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.leg);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]",&miAlumno.name); //^ = ALT + 94

    printf("Ingrese promedio: ");
    scanf("%f",&miAlumno.prom);


    //otroAlumno = miAlumno;
    //SE PUEDE ASIGNAR

    USAMOS EL OPERADOR PUNTO
    me permite acceder a cada campo


    //printf("%d--%s--%.2f",otroAlumno.leg,otroAlumno.name,otroAlumno.prom);
    mostrarUnAlumno(miAlumno);


    //printf("%d",sizeof(sAlumno));//te dice cuanto pesa una variable del tipo sAlumno en esta arquitectura.
    */


    return 0;
}


void mostrarUnAlumno(sAlumno miAlumno)//SI LE PASO UNA ESTRUCTURA A UN FUNCION LA COPIA.
{
    printf("%d--%s--%.2f\n",miAlumno.leg,miAlumno.name,miAlumno.prom);


}

sAlumno cargarAlumno(void)
{
    sAlumno miAlumno;//= {1000,"Yago",7,66};//EN ORDEN A COMO ESTA LA ESTRUCTURA.
    //variable local a la funcion.

    printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.leg);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]",&miAlumno.name); //^ = ALT + 94

    printf("Ingrese promedio: ");
    scanf("%f",&miAlumno.prom);

    return miAlumno;
}

void cargarListadoAlumnos(sAlumno vec [], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i] = cargarAlumno();
    }

}


void mostrarListadoAlumnos(sAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].estado != 0)
        {
            mostrarUnAlumno(vec[i]);
        }
    }





}
