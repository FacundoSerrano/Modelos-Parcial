#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
    char c[10];
}dato;

int main()
{
    dato datito = {1,'c',"mecon"};
    dato* p;

    p = &datito;

    printf("%d--%c--%s", p->a, p->b, (*p).c); // p->a reemplaza a (*p).a (es lo mismo) | (p+i)->a reemplaza a ((p+i).a)

    /*
    printf("%d\n", p);

    printf("%d\n", &datito.a);

    printf("%d\n", &datito);
    */

    //para acceder a un campo de estructura mediante un puntero se usa (*p).a | Si no se usa el parentesis entra a p.a.

    return 0;
}
