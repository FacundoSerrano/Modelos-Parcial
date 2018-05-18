#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char end;
    char end2;

    FILE *fp;

    char bufferIn[100];

    char buffer[100] = "\nEsto es un texto dentro del fichero.";

    fp = fopen("C:\\Users\\capacita_mecon\\Desktop\\Archivo Serrano.txt", "w");

    fprintf(fp,"Hola");
    fprintf(fp,buffer);

    fclose(fp);

    do
    {
        printf("Desea leer?\n");
        scanf("%c", &end);

        if(end == 's')
        {
            fp = fopen("C:\\Users\\capacita_mecon\\Desktop\\Archivo Serrano.txt", "r");

            fgets(bufferIn,100,fp);
            puts(bufferIn);

            fgets(bufferIn,100,fp);
            puts(bufferIn);
            fclose(fp);
        }
    }
    while(end != 's');

    do
    {
        printf("Desea terminar?\n");
        scanf("%c", &end2);

        if(end2 == 's')
        {
            remove("C:\\Users\\capacita_mecon\\Desktop\\Archivo Serrano.txt");
        }
    }
    while(end2 != 's');

    return 0;
}
