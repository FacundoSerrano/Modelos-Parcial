#include <stdio.h>
#include <stdlib.h>

void cargarValores(int* vector, int t);
void mostrarValores(int* vector, int t);

int main()
{
    int vec[3];
    //int i;
    //int* pEntero = NULL; //el * determina que es un puntero, también puede ir antes del nombre de la variable. (Tiene que estar asociado al tipo de dato al que va a apuntar.
    //int* otroPuntero;
    //printf("%d", sizeof(int*)); //sizeof te dice el tamaño del entero. el tamaño de un puntero siempre será 4, porque solo es donde se guarda la dirección de memoria de la variable apuntada.

    //int miEntero = 7;

    //pEntero = &miEntero;

    cargarValores(vec, 3);

    mostrarValores(vec, 3);

    /*for(i = 0; i < 3; i++)
    {
        printf("Ingrese los valores del vector\n");
        scanf("%d", pEntero+i);
    }

    for(i = 0; i < 3; i++)
    {
        printf("%d\n", *(pEntero+i));//el parentesis es para que se refiera a la dirección de memoria de pEntero+1 y no a el valor de pEntero+1
    }*/

    /*printf("%d\n", pEntero);
    printf("%d\n", pEntero + 0);
    printf("%d\n", pEntero + 1);
    printf("%d\n", pEntero + 2);
    printf("%d\n", pEntero + 3);
    printf("%d\n", pEntero - 1);*/

    //pEntero = &miEntero; //le paso la dirección de memoria

    //otroPuntero = pEntero;

    //x para mostrar en hexadecimal

    /*if(pEntero != NULL)//para comprobar que esté apuntando a algo
    {
        printf("%d", *pEntero);
    }
    else
    {
        printf("El puntero no esta incializado");
    }*/

    /*printf("El valor apuntado es: %d\n", *pEntero);
    printf("El valor del segundo puntero es: %d\n", *otroPuntero);
    printf("El valor de la variable es: %d\n", miEntero);
    printf("El valor del puntero: %d\n", pEntero);
    printf("El valor de la direccion de memoria de la variable es: %x\n", &miEntero);
    printf("El valor de la direccion de memoria del puntero es: %x\n", &pEntero);*/

    return 0;
}

void cargarValores(int* vector, int t)
{
    int i;

    for(i = 0; i < t; i++)
    {
        printf("Ingrese los valores del vector\n");
        scanf("%d", vector+i);
    }
}

void mostrarValores(int* vector, int t)
{
    int i;

    printf("Los valores son: \n");
    for(i = 0; i < t; i++)
    {
        printf("%d\n", *(vector + i));//el parentesis es para que se refiera a la dirección de memoria de pEntero+1 y no a el valor de pEntero+1
    }
}


/*

TAREA

Para carga y muestra

1) Recibe el array y lo maneja con notación de array (con los corchetes)
2) Recibe el array con notación de array, y en la función trabaja con punteros
3) Recibe el puntero, y lo manejo con notación de array
4) Recibe el puntero, y trabaja con notación de puntero

*/
