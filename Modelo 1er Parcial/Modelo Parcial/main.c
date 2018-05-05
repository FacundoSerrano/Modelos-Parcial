#include <stdio.h>
#include <stdlib.h>
#define TAMPROG 50
#define TAMCAT 3
#include "lib.h"

int main()
{

    int opcion;

    eProgramador programadores[TAMPROG];
    eCategoria categorias[TAMCAT];


    eProg_init(programadores, TAMPROG);
    eCat_init(categorias);

    do
    {
        printf("\n\nIngrese una opcion: \n");
        printf("\n1. Alta de programador");
        printf("\n2. Modificar datos del programador");
        printf("\n3. Baja del programador");
        printf("\n4. Asignar programador a proyecto");
        printf("\n5. Listado de programadores: ");
        printf("\n6. Listado de todos los proyectos: ");
        printf("\n7. Listar proyectos de programador: ");
        printf("\n8. Proyecto demandante: ");
        printf("\n\n9. Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                eProg_alta(programadores, TAMPROG);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                eProg_mostrarListado(programadores, TAMPROG, categorias);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
        }
    }

    while(opcion != 9);

    return 0;
}
