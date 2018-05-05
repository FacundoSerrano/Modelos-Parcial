#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LIBRE 1
#define OCUPADO 0



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


int eProg_init(eProgramador programadores[],int limite) //Inicializa vacios los srtucts
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
            printf("\n3. Senior\n");
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
