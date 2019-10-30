#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[50];
    float salario;

}eEmpleado;

void escribrirBinario(char* path);
void leerBinario(char* path);
void mostrarEmpleado(eEmpleado vec[],int tam);

int main()
{
    /**Esto es lecto escritura de archivos binarios.**/
    escribrirBinario("miEmpleado.dat");
    leerBinario("miEmpleado.dat");

    return 0;
}

void escribrirBinario(char* path)
{
    /**fprintf funcion para imprimir un archivo de texto***/
    /***fwrite funcion para imprimir archivos de un binario***/

    //eEmpleado miEmpleado = {100,"Carlitos",1000};
    //Que pasa si escribo un array?
    eEmpleado miEmpleado[4] = {
        {100,"Jorge",12000},
        {101,"Luis",20000},
        {102,"Facu",51000},
        {103,"Joaco",65000}
    };
    FILE* miArchivo;//devuelve un puntero a FILE
    int i = 0;

    //Hay que usar doble barra "d:\\..."
    //PATH es la dire del archivo
    //.bin o .dat para archivos binarios.
    //wb de escritura binaria.
    miArchivo = fopen(path,"wb");
    int len = 4;//mcuantos datos utiles hay dentro del array?


    if(miArchivo != NULL)
    {
        //fwrite puede guardar cualquier cosa que le pida.
        fwrite(&len,sizeof(int),1,miArchivo);
        /*1:dire de memoria,
        2.sizeof de la estructura(tamaño del dato),
        3.cantidad de datos que voy a guardar(si fuera un string hago un strlen),
        4.El archivo*/
        //fwrite(&miEmpleado,sizeof(eEmpleado),1,miArchivo);

        for(i = 0;i<4;i++)
        {
            fwrite(miEmpleado+i,sizeof(eEmpleado),1,miArchivo);
        }

        fclose(miArchivo);
    }

}

void leerBinario(char* path)
{
    //necesito una estructura que guarde el dato
    //eEmpleado bEmpleado;
    eEmpleado bEmpleado[4];//guarda el dato.
    FILE* miArchivo;
    int i = 0;
    int len;

    miArchivo = fopen(path,"rb");


    fread(&len,sizeof(int),1,miArchivo);//guardo en el len el valor 2.
    printf("\nLen : %d\n\n",len);

    //este bloque lee desde a partir de la primera posicion del array
    fread(bEmpleado,sizeof(eEmpleado),len,miArchivo);//borro el &, leo 2 empleados

    /*while(!feof(miArchivo))//mientras no pueda leer el archivo leer.
    {
        //1.a donde guardo los datos que leo desde el archivo
        //2.
        //3.no sabemos cuantos empleados guarde...(por ahora 1)
        //fread(&bEmpleado,sizeof(eEmpleado),1,miArchivo);
        fread(bEmpleado+i,sizeof(eEmpleado),1,miArchivo);//borro el &, leo 2 empleados
        i++;

    }*/

    fclose(miArchivo);
    //fread(bEmpleado,sizeof(eEmpleado),2,miArchivo);

    mostrarEmpleado(bEmpleado,4);
    /*for(i = 0;i<4;i++)
    {
        printf("| %5d | %10s | %10.2f |\n",
           bEmpleado[i].legajo,
           bEmpleado[i].nombre,
           bEmpleado[i].salario);
        //getch();//es como un system pause
    }*/

}

void mostrarEmpleado(eEmpleado vec[],int tam)
{
    printf(" ================================= \n");
    printf("| Legajo|    Nombre  | Salario($) |\n");
    printf(" ================================= \n");
    for(int i = 0;i<tam;i++)
    {
        printf("| %5d | %10s |$%10.2f |\n",
               vec[i].legajo,
               vec[i].nombre,
               vec[i].salario);
    }
    printf(" ================================= \n");
}
