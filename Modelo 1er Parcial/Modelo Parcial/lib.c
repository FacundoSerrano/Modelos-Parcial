#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LIBRE 1
#define OCUPADO 0


void eProy_hard(eProyecto proyectos[])
{
    proyectos[0].idProyecto = 1;
    strcpy(proyectos[0].nombre, "Half Life 3");
    proyectos[0].estado = OCUPADO;

    proyectos[1].idProyecto = 2;
    strcpy(proyectos[1].nombre, "Squad 2");
    proyectos[1].estado = OCUPADO;

    proyectos[2].idProyecto = 3;
    strcpy(proyectos[2].nombre, "PUBG 2");
    proyectos[2].estado = OCUPADO;

    proyectos[3].idProyecto = 4;
    strcpy(proyectos[3].nombre, "Subnautica 2");
    proyectos[3].estado = OCUPADO;

    proyectos[4].idProyecto = 5;
    strcpy(proyectos[4].nombre, "Rome 3 Total War");
    proyectos[4].estado = OCUPADO;

    proyectos[5].idProyecto = 6;
    strcpy(proyectos[5].nombre, "The last of us 2");
    proyectos[5].estado = OCUPADO;

    proyectos[6].idProyecto = 7;
    strcpy(proyectos[6].nombre, "Helldivers 2");
    proyectos[6].estado = OCUPADO;

}

void eProg_hard(eProgramador programadores[])
{
    programadores[0].idProgramador = 1;
    strcpy(programadores[0].nombre, "Facundo");
    strcpy(programadores[0].apellido, "Serrano");
    programadores[0].idCategoria = 2;
    programadores[0].estado = OCUPADO;

    programadores[1].idProgramador = 2;
    strcpy(programadores[1].nombre, "Santiago");
    strcpy(programadores[1].apellido, "Diaz");
    programadores[1].idCategoria = 1;
    programadores[1].estado = OCUPADO;

    programadores[2].idProgramador = 3;
    strcpy(programadores[2].nombre, "Hernan");
    strcpy(programadores[2].apellido, "Becerra");
    programadores[2].idCategoria = 3;
    programadores[2].estado = OCUPADO;
}

void eProgProy_hard(eProgramadorProyecto asignados[])
{
    asignados[0].idProgramador = 1;
    asignados[0].idProyecto = 1;
    asignados[0].horasProyecto = 10;
    asignados[0].estado = OCUPADO;

    asignados[1].idProgramador = 1;
    asignados[1].idProyecto = 2;
    asignados[1].horasProyecto = 20;
    asignados[1].estado = OCUPADO;

    asignados[2].idProgramador = 1;
    asignados[2].idProyecto = 3;
    asignados[2].horasProyecto = 30;
    asignados[2].estado = OCUPADO;

    asignados[3].idProgramador = 2;
    asignados[3].idProyecto = 2;
    asignados[3].horasProyecto = 20;
    asignados[3].estado = OCUPADO;

    asignados[4].idProgramador = 2;
    asignados[4].idProyecto = 3;
    asignados[4].horasProyecto = 30;
    asignados[4].estado = OCUPADO;

    asignados[5].idProgramador = 3;
    asignados[5].idProyecto = 3;
    asignados[5].horasProyecto = 30;
    asignados[5].estado = OCUPADO;
}

void eCat_init(eCategoria categorias[])
{
    categorias[0].idCategoria = 1;
    strcpy(categorias[0].descripcion, "Junior");
    categorias[0].sueldoXHora = 100;

    categorias[1].idCategoria = 2;
    strcpy(categorias[1].descripcion, "SemiSenior");
    categorias[1].sueldoXHora = 200;

    categorias[2].idCategoria = 3;
    strcpy(categorias[2].descripcion, "Senior");
    categorias[2].sueldoXHora = 300;
}


int eProg_init(eProgramador programadores[],int limite) //Inicializa vacios los structs
{
    int retorno = -1;
    int i;
    if(limite > 0 && programadores != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            programadores[i].estado = LIBRE;
            programadores[i].idProgramador = 0;
        }
    }
    return retorno;
}

int eProy_init(eProyecto proyectos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && proyectos != NULL)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            proyectos[i].estado = LIBRE;
            proyectos[i].idProyecto = 0;
        }
    }
    return retorno;
}

int eProgProy_init(eProgramadorProyecto asignados[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && asignados != NULL)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            asignados[i].estado = LIBRE;
            asignados[i].idProgramador = 0;
            asignados[i].idProyecto = 0;
            asignados[i].horasProyecto = 0;
        }
    }
    return retorno;
}

int eProg_buscarLugarLibre(eProgramador programadores[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && programadores != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(programadores[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProg_siguienteId(eProgramador programadores[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && programadores != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(programadores[i].estado == OCUPADO)
            {
                    if(programadores[i].idProgramador > retorno)
                    {
                         retorno = programadores[i].idProgramador;
                    }
            }
        }
    }

    return retorno + 1;
}

int eProg_alta(eProgramador programadores[],int limite)
{
    int retorno = -1;
    int id;
    int indice;
    int opcion = 0;

    if(limite > 0 && programadores != NULL)
    {
        retorno = -2;
        indice = eProg_buscarLugarLibre(programadores,limite);
        if(indice >= 0)
        {
            id = eProg_siguienteId(programadores,limite);
            retorno = 0;
            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(programadores[indice].nombre);
            printf("\nIngrese el apellido: ");
            fflush(stdin);
            gets(programadores[indice].apellido);
            printf("\nSeleccione categoria: ");
            printf("\n\n1. Junior");
            printf("\n2. SemiSenior");
            printf("\n3. Senior\n\n");
            fflush(stdin);

            while(opcion < 1 || opcion > 3)
            {
                scanf("%d", &opcion);
                if(opcion < 1 || opcion > 3)
                {
                    printf("Por favor ingrese una opcion valida");
                }
            }
            programadores[indice].idCategoria = opcion;
            programadores[indice].idProgramador = id;
            programadores[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eCat_buscarPorId(eCategoria categorias[] , int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && categorias != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(categorias[i].idCategoria == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProg_buscarPorId(eProgramador programadores[] , int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && programadores != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(programadores[i].idProgramador == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eProg_mostrarUno(eProgramador programadores)
{
     printf("\n\n- %d\n- %s\n- %s", programadores.idProgramador, programadores.nombre, programadores.apellido);
}

void eCat_mostrarUno(eCategoria categorias)
{
     printf("\n- %s", categorias.descripcion);
}

int eProg_mostrarListado(eProgramador programadores[],int limite, eCategoria categorias[])
{
    int retorno = -1;
    int i;
    int j;
    if(limite > 0 && programadores != NULL)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            if(programadores[i].estado == OCUPADO)
            {
                j = eCat_buscarPorId(categorias, 3, programadores[i].idCategoria);
                eProg_mostrarUno(programadores[i]);
                eCat_mostrarUno(categorias[j]);
            }
        }
    }
    return retorno;
}

int eProg_modificacion(eProgramador programadores[] ,int limite, int id, eCategoria categorias[])
{
    int i;
    int opcion = 0;
    int seguir = 0;
    while(seguir == 0)
    {
        eProg_mostrarListado(programadores,limite, categorias);
        printf("\n\nIngrese el id del programador a modificar\n");
        scanf("%d",&id);
        i = eProg_buscarPorId(programadores, limite, id);
        if(i==-2||i==-3)
        {
            printf("El numero ingresado no pertenece a un id existente");
        }
        else
        {
            printf("El usuario a modificar es: %s %s.", programadores[i].nombre, programadores[i].apellido);
            printf("\nIngrese el nuevo nombre: ");
            fflush(stdin);
            gets(programadores[i].nombre);
            printf("\nIngrese el nuevo apellido: ");
            fflush(stdin);
            gets(programadores[i].apellido);
            printf("\nSeleccione categoria: ");
            printf("\n\n1. Junior");
            printf("\n2. SemiSenior");
            printf("\n3. Senior\n\n");
            fflush(stdin);
            while(opcion < 1 || opcion > 3)
            {
                scanf("%d", &opcion);
                if(opcion < 1 || opcion > 3)
                {
                    printf("Por favor ingrese una opcion valida");
                }
            }
            programadores[i].idCategoria = opcion;
            seguir=1;
        }
    }
   i = eProg_buscarPorId(programadores,limite,id);
}

int eProgProy_buscarLugarLibre(eProgramadorProyecto asignados[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && asignados != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(asignados[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProy_buscarLugarLibre(eProyecto proyectos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && proyectos != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(proyectos[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProy_siguienteId(eProyecto proyectos[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && proyectos != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            if(proyectos[i].estado == OCUPADO)
            {
                    if(proyectos[i].idProyecto > retorno)
                    {
                         retorno = proyectos[i].idProyecto;
                    }
            }
        }
    }

    return retorno + 1;
}

int eProy_alta(eProyecto proyectos[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && proyectos != NULL)
    {
        retorno = -2;
        indice = eProy_buscarLugarLibre(proyectos,limite);
        if(indice >= 0)
        {
            id = eProy_siguienteId(proyectos,limite);
            retorno = 0;
            printf("\nIngrese el nombre del proyecto: ");
            fflush(stdin);
            gets(proyectos[indice].nombre);

            proyectos[indice].idProyecto = id;
            proyectos[indice].estado = OCUPADO;
            retorno = id;
        }
    }
    return retorno;
}

void eProy_mostrarUno(eProyecto proyectos)
{
     printf("\n\n- %d\n- %s", proyectos.idProyecto, proyectos.nombre);
}

int eProy_mostrarListado(eProyecto proyectos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && proyectos != NULL)
    {
        retorno = 0;
        for(i = 0; i < limite; i++)
        {
            if(proyectos[i].estado == OCUPADO)
            {
                eProy_mostrarUno(proyectos[i]);
            }
        }
    }
    return retorno;
}

int eProgProy_asignar(eProgramadorProyecto asignados[], int limiteProgProy, eProgramador programadores[], int limiteProg, eProyecto proyectos[], int limiteProy, eCategoria categorias[])
{
    int i = eProgProy_buscarLugarLibre(asignados, limiteProgProy);
    int opcion = 0;
    int seguir = 0;
    int id = 0;
    while (seguir == 0)
    {
        eProg_mostrarListado(programadores, limiteProg, categorias);
        printf("\n\nIngrese el id del programador a asignar\n");
        scanf("%d", &asignados[i].idProgramador);
        do
        {
            printf("\nSeleccione una opcion: ");
            printf("\n\n1. Seleccionar proyecto existente");
            printf("\n2. Crear nuevo proyecto\n\n");
            printf("\n9. Salir\n\n");
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    while(id < 1 || id > eProy_buscarLugarLibre(proyectos, limiteProy))
                    {
                        eProy_mostrarListado(proyectos, limiteProy);
                        printf("\n\n1. Seleccione un proyecto por su id: ");
                        scanf("%d", &id);

                        asignados[i].idProyecto = id;
                        asignados[i].estado = OCUPADO;
                    }
                    break;

                case 2:
                    asignados[i].idProyecto = eProy_alta(proyectos, limiteProy);
                    asignados[i].estado = OCUPADO;
                    break;
            }

        printf("\n\nIngrese cuantas horas debera trabajar: ");
        scanf("%d", &asignados[i].horasProyecto);
        }
        while(opcion != 1 && opcion != 2);
        seguir = 1;
    }
}

int eProgProy_mostrarProyectos(eProgramadorProyecto asignados[], int limite, eProyecto proyectos[], int id)
{
    int retorno = -1;
    int i;
    int cantidadAsignados = 0;
    if(limite > 0 && asignados != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(asignados[i].idProgramador == id)
            {
                eProy_mostrarUno(proyectos[asignados[i].idProyecto - 1]);
                cantidadAsignados++;
            }
        }
    }
    return cantidadAsignados;
}

void eProgProy_listar(eProyecto proyectos[], int limiteProy, eProgramador programadores[], int limiteProg, eCategoria categorias[], eProgramadorProyecto asignados[], int limiteProgProy)
{
    int indice = 0;

    while(indice < 1 || indice > eProy_buscarLugarLibre(proyectos, limiteProy))
    {
        eProg_mostrarListado(programadores, limiteProg, categorias);
        printf("\n\nSeleccione un id para ver sus proyectos asignados\n");
        scanf("%d", &indice);
    }
    printf("El programador %s %s participa de los siguientes proyectos: ", programadores[indice - 1].nombre, programadores[indice - 1].apellido);
    eProgProy_mostrarProyectos(asignados, limiteProgProy, proyectos, indice);
}

void eProgProy_demandante(eProgramadorProyecto asignados[], int limiteProgProy, eProyecto proyectos[])
{
    int i;
    int cantidad = 0;
    int mayor = 0;
    int indice;

    for(i = 0; i < limiteProgProy; i++)
    {
        cantidad = eProgProy_mostrarProyectos(asignados, limiteProgProy, proyectos, i + 1);
        if(cantidad > mayor)
        {
            mayor = cantidad;
            indice = i;
        }
    }
    printf("\n\nEl proyecto mas demandante es %s con %d asignaciones", proyectos[indice].nombre, mayor);
}
