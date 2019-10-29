#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    float b;

}eDato;

eDato* constructor();

int main()
{
    eDato* p;

    p = constructor();
    printf("\n");//si agrego esto se corre y me muestra basura.
    printf("\n| %d | %.2f |\n",p->a,p->b);

    return 0;
}

eDato* constructor()
{
    eDato d = {1,2.58};
    return &d;
}
