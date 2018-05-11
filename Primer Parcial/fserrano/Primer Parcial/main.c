#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define TAMPROP 20
#define TAMLUG 20

#define LIBRE 1
#define OCUPADO 0

int main()
{

    int opcion;
    int id;

    ePropietario propietarios[TAMPROP];
    eAuto estacionados[TAMLUG];

    eProp_init(propietarios, TAMPROP);
    eAut_init(estacionados, TAMLUG);

    eProp_cargar(propietarios, TAMPROP);
    eAut_cargar(estacionados, TAMLUG);

    do
    {
        printf("\n\nIngrese una opcion: \n");
        printf("\n1. Listar propietario");
        printf("\n2. Listar autos estacionados");
        printf("\n3. Alta de propietario");
        printf("\n4. Modificar datos del propietario");
        printf("\n5. Baja del propietario");
        printf("\n6. Alta de auto");
        printf("\n\n7. Salir\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                eProp_mostrarListado(propietarios, TAMPROP);
                break;
            case 2:
                eAut_mostrarListado(estacionados, TAMLUG, propietarios);
                break;
            case 3:
                eProp_alta(propietarios, TAMPROP);
                break;
            case 4:
                eProp_modificacion(propietarios, TAMPROP);
                break;
            case 5:
                eProp_baja(propietarios, TAMPROP, estacionados, TAMLUG);
                break;
            case 6:
                eAut_alta(estacionados, TAMLUG, propietarios, TAMPROP);
                break;
        }
    }

    while(opcion != 7);

    return 0;
}
