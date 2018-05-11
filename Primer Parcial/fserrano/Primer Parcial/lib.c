#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LIBRE 1
#define OCUPADO 0

    //int marca[]= {1,1,2,3,2,2,3,4,1,1};
    //float importe[]= {100,200,100,300,100,100,200,200,100,100};

void eProp_cargar(ePropietario propietarios[], int limiteProp)
{
    int i;
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    for(i = 0; i < 4; i++)
    {
        propietarios[i].idPropietario = id[i];
        strcpy(propietarios[i].nombreYApellido, nombre[i]);
        strcpy(propietarios[i].direccion, direccion[i]);
        strcpy(propietarios[i].tarjeta, tarjeta[i]);
        propietarios[i].estado = OCUPADO;
    }
}

void eAut_cargar(eAuto estacionados[], int limiteEst)
{
    int i;
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    for(i = 0; i < 10; i++)
    {
        estacionados[i].idPropietario = propietario[i];
        strcpy(estacionados[i].patente, patente[i]);
        estacionados[i].marca = marca[i];
        estacionados[i].idAutomovil = id[i];
        estacionados[i].estado = OCUPADO;
    }
}

int eAut_init(eAuto estacionados[], int limiteEst)
{
    int retorno = -1;
    int i;
    if(limiteEst > 0 && estacionados != NULL)
    {
        retorno = 0;
        for(i = 0; i < limiteEst; i++)
        {
            estacionados[i].estado = LIBRE;
            estacionados[i].idPropietario = 0;
            estacionados[i].idAutomovil = 0;
        }
    }
    return retorno;
}

int eProp_init(ePropietario propietarios[], int limiteProp)
{
    int retorno = -1;
    int i;
    if(limiteProp > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i = 0; i < limiteProp; i++)
        {
            propietarios[i].estado = LIBRE;
            propietarios[i].idPropietario = 0;
        }
    }
    return retorno;
}

int eProp_buscarLugarLibre(ePropietario propietarios[],int limiteProp)
{
    int retorno = -1;
    int i;
    if(limiteProp > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i = 0; i < limiteProp; i++)
        {
            if(propietarios[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProp_siguienteId(ePropietario propietarios[],int limiteProp)
{
    int retorno = 0;
    int i;
    if(limiteProp > 0 && propietarios != NULL)
    {
        for(i = 0; i < limiteProp; i++)
        {
            if(propietarios[i].estado == OCUPADO)
            {
                    if(propietarios[i].idPropietario > retorno)
                    {
                         retorno = propietarios[i].idPropietario;
                    }
            }
        }
    }

    return retorno + 1;
}

int eProp_alta(ePropietario propietarios[],int limiteProp)
{
    int retorno = -1;
    int id;
    int indice;
    int opcion = 0;

    if(limiteProp > 0 && propietarios != NULL)
    {
        retorno = -2;
        indice = eProp_buscarLugarLibre(propietarios,limiteProp);
        if(indice >= 0)
        {
            id = eProp_siguienteId(propietarios,limiteProp);
            retorno = 0;
            printf("\nIngrese el nombre y apellido: ");
            fflush(stdin);
            gets(propietarios[indice].nombreYApellido);
            printf("\nIngrese la direccion: ");
            fflush(stdin);
            gets(propietarios[indice].direccion);
            printf("\nIngrese el numero de tarjeta: ");
            fflush(stdin);
            gets(propietarios[indice].tarjeta);

            propietarios[indice].idPropietario = id;
            propietarios[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eProp_buscarPorId(ePropietario propietarios[] , int limiteProp, int id)
{
    int retorno = -1;
    int i;
    if(limiteProp > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i = 0; i < limiteProp; i++)
        {
            if(propietarios[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eProp_mostrarUno(ePropietario propietarios)
{
     printf("\n\n - Propietario:  %d - Nombre y apellido: %s - Direccion: %s - Tarjeta: %s", propietarios.idPropietario, propietarios.nombreYApellido, propietarios.direccion, propietarios.tarjeta);
}

int eProp_mostrarListado(ePropietario propietarios[],int limiteProp)
{
    int retorno = -1;
    int i;
    if(limiteProp > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i = 0; i < limiteProp; i++)
        {
            if(propietarios[i].estado == OCUPADO)
            {
                eProp_mostrarUno(propietarios[i]);
            }
        }
    }
    return retorno;
}

int eProp_modificacion(ePropietario propietarios[] ,int limiteProp)
{
    int id;
    int i;
    int opcion = 0;
    int seguir = 0;
    while(seguir == 0)
    {
        eProp_mostrarListado(propietarios, limiteProp);
        printf("\n\nIngrese el id del propietario a modificar\n");
        scanf("%d",&id);
        i = eProp_buscarPorId(propietarios, limiteProp, id);
        if(i < 0 || i > eProp_buscarLugarLibre(propietarios, limiteProp))
        {
            printf("El numero ingresado no pertenece a un id existente");
        }
        else
        {
            printf("El usuario a modificar es: %s.", propietarios[i].nombreYApellido);
            printf("\nIngrese el nuevo nombre y apellido: ");
            fflush(stdin);
            gets(propietarios[i].nombreYApellido);
            printf("\nIngrese la nueva direccion: ");
            fflush(stdin);
            gets(propietarios[i].direccion);
            printf("\nIngrese la nueva tarjeta: ");
            fflush(stdin);
            gets(propietarios[i].tarjeta);
        }
        seguir = 1;
    }
   i = eProp_buscarPorId(propietarios, limiteProp, id);
}

void eProp_baja(ePropietario propietarios[] ,int limiteProp, eAuto estacionados[] , int limiteEst)
{
    int i;
    int id;
    char confirmacion;

    eProp_mostrarListado(propietarios, limiteProp);
    printf("\n\nIngrese el id del propietario a dar de baja\n");
    scanf("%d",&id);
    i = eProp_buscarPorId(propietarios, limiteProp, id);
    printf("\n\nEsta seguro de que desea realizar la baja?\n");
    fflush(stdin);
    gets(confirmacion);
    if(confirmacion == 'S')
    {
    propietarios[i].estado = LIBRE;
    //eAut_baja(estacionados, limiteEst, id);
    }
}

int eAut_baja(eAuto estacionados[] , int limiteEst, int id)
{
    int i;
    for(i = 0; i = limiteEst; i++)
    {
        if(estacionados[i].idPropietario == id)
        {
            estacionados[i].estado = LIBRE;
        }
    }
}

int eAut_listar(eAuto estacionados[] , int limiteEst, int id)
{
    int i;
    for(i = 0; i = limiteEst; i++)
    {
        if(estacionados[i].idPropietario == id)
        {
            printf("Tiene estacionado al auto %d", estacionados[i].idAutomovil);
        }
    }
}

int eProp_devolverHorasEstadia()
{
    int horas;
    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;
}

int eAut_alta(eAuto estacionados[], int limiteEst, ePropietario propietarios[], int limiteProp)
{
    int retorno = -1;
    int id;
    int indice;
    int opcion = 0;

    if(limiteEst > 0 && estacionados != NULL)
    {
        retorno = -2;
        indice = eAut_buscarLugarLibre(estacionados, limiteEst);
        if(indice >= 0)
        {
            id = eAut_siguienteId(estacionados, limiteEst);
            retorno = 0;
            printf("\nIngrese la patente: ");
            fflush(stdin);
            gets(estacionados[indice].patente);
            eProp_mostrarListado(propietarios, limiteProp);
            printf("\nIngrese el id del propietario: ");
            scanf("%d", &estacionados[indice].idPropietario);
            printf("\nSeleccione una marca: ");
            printf("\n\n1. Alfa Romeo");
            printf("\n2. Ferrari");
            printf("\n3. Audi");
            printf("\n4. Otro\n\n");
            scanf("%d", &opcion);

            while(opcion < 1 || opcion > 4)
            {
                scanf("%d", &opcion);
                if(opcion < 1 || opcion > 4)
                {
                    printf("Por favor ingrese una opcion valida");
                }
            }
            estacionados[indice].marca = opcion;
            estacionados[indice].idAutomovil = id;
            estacionados[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eAut_buscarLugarLibre(eAuto estacionados[],int limiteEst)
{
    int retorno = -1;
    int i;
    if(limiteEst > 0 && estacionados != NULL)
    {
        retorno = -2;
        for(i = 0; i < limiteEst; i++)
        {
            if(estacionados[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAut_siguienteId(eAuto estacionados[],int limiteEst)
{
    int retorno = 0;
    int i;
    if(limiteEst > 0 && estacionados != NULL)
    {
        for(i = 0; i < limiteEst; i++)
        {
            if(estacionados[i].estado == OCUPADO)
            {
                    if(estacionados[i].idAutomovil > retorno)
                    {
                         retorno = estacionados[i].idAutomovil;
                    }
            }
        }
    }

    return retorno + 1;
}

int eAut_mostrarListado(eAuto estacionados[],int limiteEst, ePropietario propietarios[])
{
    int retorno = -1;
    int i;
    if(limiteEst > 0 && estacionados != NULL)
    {
        retorno = 0;
        for(i = 0; i < limiteEst; i++)
        {
            if(estacionados[i].estado == OCUPADO)
            {
                eAut_mostrarUno(estacionados[i]);
            }
        }
    }
    return retorno;
}

void eAut_mostrarUno(eAuto estacionados)
{
    int caso = estacionados.marca;

    printf("\n\n- Auto: %d - Propietario: %s - Patente: %s", estacionados.idAutomovil, propietarios[id - 1].nombreYApellido, estacionados.patente);

    switch(caso)
    {
            case 1:
                printf(" - Marca: Alfa Romeo");
                break;
            case 2:
                printf(" - Marca: Ferrari");
                break;
            case 3:
                printf(" - Marca: Audi");
                break;
            case 4:
                printf(" - Marca: Otro");
                break;
        }
}
