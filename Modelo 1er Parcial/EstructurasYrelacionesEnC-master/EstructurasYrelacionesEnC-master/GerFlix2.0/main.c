#include <stdio.h>
#include <stdlib.h>

#include "serie.h"
#include "usuario.h"
#include "usuarioSerie.h"

/**
*
    1. mostrar cada usuario con las series que ve
    2. mostrar por cada serie todos los usuarios que la ven
    3. por cada serie cuantos usuarios la ven
    4. mostrar la/s series menos populares
    5. ingresar usuario y listar sus series
    6. ingresar serie y listar sus usuarios
    7. top 3 de series
*
*/

int main()
{
    int opcion;

    eSerie series[5]; // declaro mi array de series "vacio"
    CrearListadoSeries(series, 5); // relleno el array de series

    eUsuario usuarios[3];
    CrearListadoDeUsuarios(usuarios, 3);


    eUsuarioSerie usuarioserie[X];
    CrearListadoUsuariosYSeries(usuarioserie, X);

    do
    {
        printf("Ingrese una opción\n");
        printf("1. Mostrar usuarios y que ve\n");
        printf("2. Mostrar que usuarios ven cada serie\n");
        printf("3. Mostrar cuantos usuarios ven cada serie\n");
        printf("4. Mostrar la/s series/s menos popular/es\n");
        printf("5. Ingresar usuario y listar sus series\n");
        printf("6. Ingresar serie y listar usuarios\n");
        printf("7. Mostrar top 3 series\n");
        printf("8. Salir\n");
        scanf("%d",&opcion);

        switch (opcion)
        {
            case 1:

                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;


        }
    }
    while (opcion != 8);

}



