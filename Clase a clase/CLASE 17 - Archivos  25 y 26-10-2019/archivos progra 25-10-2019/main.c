#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f;//puntero a file

    //char nombre[] = "Juan";
    char nombre[] = "Juan Carlos";
    char x;

    char nombre2[20] = "Juan Carlos";




    /*** 1er paso: abrirlo ***/
    //abrir la ubicacion y cargarlo en memoria.

    //cargar el archivo en memoria y me deuelve un punto a esa posicion de memoria del puntero
    ///fopen(archivo.txt,"modo de como quiero abrirlo")
    //w,r,wb,rb,a(para escribir al final),ab(escribir en ... )
    //f = fopen("archivo.txt","a");//w = escritura texto (si lo abro en escritura me lo crea el archivo, si ya existia te lo pisa)

    f = fopen("archivo.txt","r");

    if(f == NULL)
    {
        printf("\n\nNo se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    /**fprintf funcion para imprimir un archivo de texto***/
    //fprintf(f,"Hola mundo");
    //fprintf(f,"%s",nombre);

    /***fwrite funcion para imprimir archivos de un binario***/
    //fwrite(nombre,sizeof(char),strlen(nombre),f);
    //1, el taamño de lo que quiero escribir, la cantidad de lo que quiero escribir



    /*while( !feof(f))//mientras no llegue al final del archivo //!= 'EOF')//file end of file
    {
        fread(nombre2,sizeof(char),20,f);//leo la cantidad que entra en nombre 2.
        printf("%s",nombre2);
    }*/

    while( !feof(f))
    {
        //file get character
        fgets(nombre2,19,f);
        x = fgetc(f);//leo a un caracter
        printf("%c",x);
    }


    /*** SIEMPRE HAY QUE CERRAR EL ARCHIVO AL FINAL DEL PROGRAMA. ***/


    fclose(f);


    return 0;
}
