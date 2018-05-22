#include <stdio.h>
#include <stdlib.h>

int main()
{
    funcion1();
    return 0;
}

void funcion1()
{
    FILE* miArchivo;
    int numero = 64;

    /*miArchivo = fopen("prueba1.txt","w");

    fwrite(&numero, sizeof(int), 1, miArchivo);

    fclose(miArchivo);*/

    miArchivo = fopen("prueba1.txt","r");

    fread(&numero, sizeof(int), 1, miArchivo);
    fclose(miArchivo);
    printf("NUMERO: %d", numero);
}

void funcion2()
{
    FILE* miArchivo;
    int i = 0;
    int numero;
    int lista[5];

    /*miArchivo = fopen("prueba1.txt","w");

    fwrite(&numero, sizeof(int), 1, miArchivo);

    fclose(miArchivo);*/

    miArchivo = fopen("prueba1.txt","r");

    fread(&numero, sizeof(int), 1, miArchivo);
    fclose(miArchivo);
    printf("NUMERO: %d", numero);
}

void funcion3()
{
    eDato d[2] = {{3,'A'},{4,'C'}};
    eDato d3 = {1,'D'};
    eDato d2[2];

    FILE* miArchivo;

    miArchivo = fopen("Numero.dat","wb");
    fwrite(&d3, sizeof(eDato), 1, miArchivo);
    fclose(miArchivo);

    miArchivo = fopen("Numero.dat", "rb");
    fread(&d3, sizeof(eDato), 1, miArchivo);
    printf("%d -- %", d3.a, d3.b);
}
