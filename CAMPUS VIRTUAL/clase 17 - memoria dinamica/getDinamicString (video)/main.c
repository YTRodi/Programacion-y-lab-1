#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getDinamicString(char* mensaje);

int main()
{
    char* pName = getDinamicString("Ingresa tu nombre: ");
    printf("\nTu nombre es: %s\n",pName);
    free(pName);
    return 0;
}

/** \brief Permite al usuario ingresar un texto y lo devuelve
 *         en un nuevo espacio de memoria.
 *
 * \param mensaje Mensaje a ser mostrado.
 * \return Puntero a cadena de caracteres con texto ingresado. Se debe liberar con free().
 *
 */
char* getDinamicString(char* mensaje)
{
    printf(mensaje);//imprimimos el mensaje por pantalla que recibo por argumento.

    char* pData = (char*)malloc(sizeof(char)*1024);//construimos un espacio en memoria para 1k
    //para usar en el scanf, para tener un espacio donde se va a guardar lo que el usuario ingrese.

    scanf("%1023s",pData);//1023 letras.

    int len = strlen(pData);//con esto averiguamos cuanto escribio el usuario.

    pData = (char*)realloc(pData,sizeof(char)*(len+1));
    //con realloc achicamos el espacio de memoria
    //con esto devolvemos un solo espacio en memoria(lo que el usuario ingreso) y no sobra ningun byte.

    //len+1 = hay que tener en cuenta el caracter terminador que strlen no lo cuenta

    return pData;
}
