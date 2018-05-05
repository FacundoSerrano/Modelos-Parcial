#include "serie.h"


void CrearListadoSeries(eSerie array[],int cantidad)
{
    for (int i = 0; i < cantidad; i ++)
    {
        array[i].idSerie = i;

        if (i%2 == 0)
        {
            strcpy(array[i].genero, "Terror");
        }
        else
        {
            strcpy(array[i].genero, "Humor");
        }
    }
    strcpy(array[0].nombre, "El amanecer de los muertos");
    strcpy(array[1].nombre, "Zombieland");
    strcpy(array[2].nombre, "La llamada");
    strcpy(array[3].nombre, "La familia de mi novia");
    strcpy(array[4].nombre, "Scream");
}
