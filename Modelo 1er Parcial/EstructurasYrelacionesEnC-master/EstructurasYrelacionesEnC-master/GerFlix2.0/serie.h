#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED

typedef struct{
    int idSerie;
    char nombre[50];
    char genero[50];
}eSerie;

void CrearListadoSeries(eSerie array[], int cantidad);

#endif // SERIE_H_INCLUDED


