#include <stdio.h>
#include <stdlib.h>

typedef struct{

int id;
char nombre[20];
char sexo;
float sueldo;

}ePersona;

int main()
{
    ePersona p1 = {123, "Juan", 'm', 50000};


    ePersona* p = &p1;

    printf("%.2f\n", (*p).sueldo );
    printf("%.2f", p->sueldo);

    printf("\n%s\n", (*p).nombre );
    printf("%s", p->nombre);


    return 0;
}
