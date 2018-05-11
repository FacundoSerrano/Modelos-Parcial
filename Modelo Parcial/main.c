#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define TAMPROG 50
#define TAMCAT 3
#define TAMPROY 1000
#define TAMPROGPROY 50000
#define LIBRE 1
#define OCUPADO 0

int main()
{

    int opcion;
    int id;


    eProgramador programadores[TAMPROG];
    eCategoria categorias[TAMCAT];
    eProyecto proyectos[TAMPROY];
    eProgramadorProyecto asignados[TAMPROGPROY];


    eProg_init(programadores, TAMPROG);
    eCat_init(categorias);
    eProy_init(proyectos, TAMPROY);
    eProgProy_init(asignados, TAMPROGPROY);

    eProy_hard(proyectos);
    eProg_hard(programadores);
    eProgProy_hard(asignados);

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
        printf("\n\n9. Salir\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                eProg_alta(programadores, TAMPROG);
                break;
            case 2:
                eProg_modificacion(programadores, TAMPROG, id, categorias);
                break;
            case 3:
                break;
            case 4:
                eProgProy_asignar(asignados, TAMPROGPROY, programadores, TAMPROG, proyectos, TAMPROY, categorias);
                break;
            case 5:
                eProg_mostrarListado(programadores, TAMPROG, categorias);
                break;
            case 6:
                break;
            case 7:
                eProgProy_listar(proyectos, TAMPROY, programadores, TAMPROG, categorias, asignados, TAMPROGPROY);
                break;
            case 8:
                eProgProy_demandante(asignados, TAMPROGPROY, proyectos);
                break;
        }
    }

    while(opcion != 9);

    return 0;
}
