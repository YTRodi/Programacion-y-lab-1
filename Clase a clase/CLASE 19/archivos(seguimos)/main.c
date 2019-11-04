#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
-getters y setters: usar para el TP3
**/

typedef struct
{
    int id;//entre 1000 y 2000.
    char marca[32];
    int modelo;
    float precio;
} eAuto;

//Constructores
eAuto* new_Auto();
eAuto* new_Auto_Param(int id,char* marca,int modelo, float precio);

//setters y getters
int setIdAuto(eAuto* unAuto,int id);
int setMarcaAuto(eAuto* unAuto,char* marca);
int setModeloAuto(eAuto* unAuto,int modelo);
int setPrecioAuto(eAuto* unAuto,float precio);

int getIdAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto,char* marca);
int getModeloAuto(eAuto* unAuto);
float getPrecioAuto(eAuto* unAuto);

//imprimir
int mostrarAuto(eAuto* unAuto);
int imprimirAutos(eAuto** autos,int tam);

//comparison



//Escritura/Lectura archivos
int guardarAutosBinario(eAuto** lista,int tam, char* path);
int guardarAutosCsv(eAuto** lista,int tam, char* path);



int main()
{
    int tam = 0;//tamaño que tengo reservado en el array.
    //dos funciones: 1 lugar libre
    int cant = 0;
    char buffer[4][30];//tengo que tener una fila pora cada campo de la estructura//30 = nombre del auto (es el mas largo)
    FILE* f = NULL;
    eAuto* auxAuto = NULL;//BUENA PRACTICA. INICIALIZARLO EN NULL.
    eAuto** auxLista = NULL;
    eAuto** lista = (eAuto**)malloc(sizeof(eAuto*)); /***LEVANTA DESDE UN ARCHIVO CSV.**/
    //MIN 35:30
    //eAuto** lista = (eAuto**)malloc(sizeof(eAuto*));//PARA LEER EN BINARIO

    if(lista==NULL)
    {
        printf("\nNo se pudo conseguir memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    /**ABRIMOS**/
    //f = fopen("autos.csv","r");//r = lectura de texto.
    f = fopen("listaAutos.csv","r");//ESTE ES EL ARCHIVO COPIADO.

    if(f==NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//esto es para saltear el encabezado.


    /************************* --LEVANTAR DESDE UN ARCHIVO CSV--*************************/

    while(!feof(f))//1 = llego al final del archivo,
    {
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//esto es para saltear el encabezado.
        if(cant < 4)//significa que esta todo mal.
        {
            break;
        }
        else
        {
            /***
            buffer[0] es el id;
            buffer[1] es el marca;
            buffer[2] es el modelo;
            buffer[3] es el precio;
            ***/
            auxAuto = new_Auto_Param(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atof(buffer[3]));//parseamos

            if(auxAuto!=NULL)
            {
                //*(lista+tam);
                *(lista+tam) = auxAuto;//le copio el contenido de auxauto a la lista .
                tam++;//porque ahora aumento, tengo 1 (ejemplo)
                //tam es la cantidad de punteros ocupados. 1:00:00 min
                auxLista = (eAuto**)realloc(lista,sizeof(eAuto*)*(tam+1));

                if(auxLista != NULL)
                {
                    lista = auxLista;
                    //printf("Se cargo un auto");
                }
            }
        }
    }
    fclose(f);
    imprimirAutos(lista,tam);

    /************************* --PARA LEVANTARLO EN BINARIO--*************************/

    if(guardarAutosBinario(lista,tam,"autos.bin"))
    {
        printf("\nAutos guardados con exito en --ARCHIVO BINARIO--.\n\n");
    }
    else
    {
        printf("\nNo se pudieron guardar los autos.\n");
    }

    //printf("%d",sizeof(eAuto));//el sistema operativo





    /************** PARA LEER EN BINARIO **************/

    int tam2 = 0;//tamaño de la lista 2.
    eAuto** lista2 = (eAuto**)malloc(sizeof(eAuto*));/***LEVANTA DESDE UN BINARIO.**/
    //PARA LEER EN BINARIO

    if(lista2==NULL)
    {
        printf("\nNo se pudo conseguir memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("autos.bin","rb");//rb = lectura binaria.

    if(f==NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


    while(!feof(f))//1 = llego al final del archivo,
    {
        auxAuto = new_Auto();//CONSIGO UN ESPACIO EN MEMORIA PARA UNA ESTRUCTURA QUE ESTA VACIA
        //GUARDO EL PUNTERO EN AUXAUTO.
        if(auxAuto == NULL)
        {
            break;//si no consigo lugar, salgo del archivo.
        }

        //TENGO QUE HACER LO MISMO QUE COMO HACIMOS EN NEWEMPLEADOPARAM.
        cant = fread(auxAuto,sizeof(eAuto),1,f);
        //1 param = puntero al destino. en FWRITE es al reves.
        if(cant < 1)//significa que esta todo mal.
        {
            break;
        }
        else
        {
            //*(lista+tam);
            *(lista2+tam2) = auxAuto;//le copio el contenido de auxauto a la lista .
            tam2++;//porque ahora aumento, tengo 1 (ejemplo)
            //tam es la cantidad de punteros ocupados. 1:00:00 min
            auxLista = (eAuto**)realloc(lista,sizeof(eAuto*)*(tam2+1));

            if(auxLista != NULL)
            {
                lista2 = auxLista;
                //printf("Se cargo un auto");
            }
        }
    }
    fclose(f);
    imprimirAutos(lista2,tam2);

    /***GUADAR AUTOS EN CSV**/

    if(guardarAutosCsv(lista2,tam2,"listaAutos.csv"))
    {
        printf("\nAutos guardados con exito en --ARCHIVO CSV(texto)--.\n\n");
    }
    else
    {
        printf("\nNo se pudieron guardar los autos.\n");
    }


    return 0;
}

eAuto* new_Auto()
{
    eAuto* nuevoAuto =(eAuto*)malloc(sizeof(eAuto));

    if(nuevoAuto!=NULL)
    {
        nuevoAuto->id = 0;
        strcpy(nuevoAuto->marca," ");
        nuevoAuto->modelo = 0;
        nuevoAuto->precio = 0;
    }
    return nuevoAuto;
}

eAuto* new_Auto_Param(int id,char* marca,int modelo, float precio)
{
    eAuto* nuevoAuto = new_Auto();//consigo espacio para un auto

    if(nuevoAuto!=NULL)
    {
        if(setIdAuto(nuevoAuto,id)
        && setMarcaAuto(nuevoAuto,marca)
        && setModeloAuto(nuevoAuto,modelo)
        && setPrecioAuto(nuevoAuto,precio) == 0)
        {
            free(nuevoAuto);
            nuevoAuto = NULL;
        }
    }
    return nuevoAuto;
}

//id
int setIdAuto(eAuto* unAuto,int id)
{
    int todoOk = 0;
    if(unAuto!=NULL && id>=1000 && id<=2000)
    {
        unAuto->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int getIdAuto(eAuto* unAuto)//lo que retorna es lo mismo que yo estoy getteando.
{
    int id = -1;
    if(unAuto!=NULL)
    {
        id = unAuto->id;
    }
    return id;
}

//marca
int setMarcaAuto(eAuto* unAuto,char* marca)
{
    int todoOk = 0;
    if(unAuto!=NULL && marca!=NULL && strlen(marca)>=3)
    {
        strcpy(unAuto->marca,marca);
        todoOk = 1;
    }
    return todoOk;
}

int getMarcaAuto(eAuto* unAuto,char* marca)
{
    int todoOk = 0;
    if(unAuto!=NULL && marca!=NULL)
    {
        strcpy(marca,unAuto->marca);
        todoOk = 1;
    }
    return todoOk;
}

//modelo
int setModeloAuto(eAuto* unAuto,int modelo)
{
    int todoOk = 0;
    if(unAuto!=NULL && modelo>=1980 && modelo<=2020)
    {
        unAuto->modelo = modelo;
        todoOk = 1;
    }
    return todoOk;
}

int getModeloAuto(eAuto* unAuto)
{
    int modelo = -1;
    if(unAuto!=NULL)
    {
        modelo = unAuto->modelo;
    }
    return modelo;
}

//precio
int setPrecioAuto(eAuto* unAuto,float precio)
{
    int todoOk = 0;
    if(unAuto!=NULL && precio>=400 && precio<=1500)
    {
        unAuto->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

float getPrecioAuto(eAuto* unAuto)//lo que retorna es lo mismo que yo estoy getteando.
{
    float precio = -1;
    if(unAuto!=NULL)
    {
        precio = unAuto->id;
    }
    return precio;
}


int mostrarAuto(eAuto* unAuto)
{
    int todoOk = 0;
    if(unAuto!=NULL)
    {
        printf("%5d %15s %10d    %10f\n",unAuto->id,unAuto->marca,unAuto->modelo,unAuto->precio);
        todoOk = 1;
    }
    return todoOk;
}

int imprimirAutos(eAuto** autos,int tam)
{
    //eAuto** flota;//guarda la dire de memo de algo que gurda una dire de memoria
    //eAuto* auxAuto;//sabe donde esta la estructura nueva creada, mando a guardar esa dire memoria al array.

    int todoOk = 0;
    if(autos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            /*** MIN 20 ***/
            mostrarAuto(*(autos+i));//la dire de memo del elemento. (dire de memo donde esta el auto)
        }
        todoOk = 1;
    }
    return todoOk;
}

int guardarAutosBinario(eAuto** lista,int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(lista!=NULL && tam>0 && path!=NULL)
    {
        f = fopen(path,"wb");

        if(f==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return todoOk;
            //exit(EXIT_FAILURE); EN UNA FUNCION NUNCA HACEMOS UN EXIT.
        }

        /**Podria guardar todo de una. QUIERO GUARDAR LAS ESTRUCTURAS (NO LAS DIRECCIONES)**/
        for(int i=0;i<tam;i++)
        {
            fwrite(*(lista+i),sizeof(eAuto),1,f);
            //fwrite le paso la direccion de memoria de cadas estructuras
            //*(lista+i) es el contenido.
            //lista + 1, lista + 2, lista + 3... tam.
        }

        //fwrite(*lista,sizeof(eAuto),tam,f);
        //SI FUERA UN VECTOR DE ESTRUCTURA SI. PERO COMO TENEMOS UN VECTOR DE PUNTEROS NO.
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

int guardarAutosCsv(eAuto** lista,int tam, char* path)
{
    int todoOk = 0;
    FILE* f = NULL;

    if(lista!=NULL && tam>0 && path!=NULL)
    {
        f = fopen(path,"w");

        if(f==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return todoOk;
            //exit(EXIT_FAILURE); EN UNA FUNCION NUNCA HACEMOS UN EXIT.
        }

        /****/

        fprintf(f,"id,marca,modelo,precio\n");//ESCRIBO EL ENCABEZADO (LA PRIMER FILA
        for(int i=0;i<tam;i++)
        {
            fprintf(f,"%d,%s,%d,%.2f\n",(*(lista+i))->id,(*(lista+i))->marca,(*(lista+i))->modelo,(*(lista+i))->precio);
        }

        //fwrite(*lista,sizeof(eAuto),tam,f);
        //SI FUERA UN VECTOR DE ESTRUCTURA SI. PERO COMO TENEMOS UN VECTOR DE PUNTEROS NO.
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}
