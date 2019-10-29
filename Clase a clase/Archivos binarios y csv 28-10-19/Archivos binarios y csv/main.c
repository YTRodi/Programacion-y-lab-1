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
        {100,"Carlitos",12000},
        {101,"Luis",20000},
        {102,"Facu",51000},
        {103,"Joaco",65000}
    };
    FILE* miArchivo;//devuelve un puntero a FILE
    int i = 0;

    //PATH es la dire del archivo
    //Hay que usar doble barra "d:\\..."
    //.bin o .dat para archivos binarios.
    //wb de escritura binaria.
    miArchivo = fopen(path,"wb");
    int len = 4;

    if(miArchivo != NULL)
    {
        fwrite(&len,sizeof(int),1,miArchivo);
        //1:dire de memoria,2.sizeof de la estructura,3.cantidad de datos que voy a guardar,4.El archivo
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
    eEmpleado bEmpleado[4];
    FILE* miArchivo;
    int i = 0;
    int len;

    miArchivo = fopen(path,"rb");


    fread(&len,sizeof(int),1,miArchivo);//guardo en el len el valor 2
    printf("\nLen : %d\n\n",len);

    fread(bEmpleado,sizeof(eEmpleado),len,miArchivo);//borro el &, leo 2 empleados

    /*while(!feof(miArchivo))
    {
        //1.a donde guardo los datos que leo desde el archivo
        //2.
        //3.no sabemos cuantos empleados guarde...(por ahora 1)
        //fread(&bEmpleado,sizeof(eEmpleado),1,miArchivo);
        fread(bEmpleado+i,sizeof(eEmpleado),1,miArchivo);//borro el &, leo 2 empleados
        i++;

    }*/

    //fread(bEmpleado,sizeof(eEmpleado),2,miArchivo);

    fclose(miArchivo);

    //mostrarEmpleado
    printf(" ================================= \n");
    printf("| Legajo|    Nombre  | Salario($) |\n");
    printf(" ================================= \n");
    for(i = 0;i<4;i++)
    {
        printf("| %5d | %10s | %10.2f |\n",
           bEmpleado[i].legajo,
           bEmpleado[i].nombre,
           bEmpleado[i].salario);
        //getch();//es como un system pause
    }
    printf(" ================================= \n");

}
