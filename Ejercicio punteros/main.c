#include <stdio.h>
#include <stdlib.h>
#define OCUPADO 0
#define LIBRE 1
#define TAMMON 10

typedef struct
{
    int id;
    char pais[10];
    char nombre[10];
    int estado;
}eMoneda;

void eMoneda_mostrarListado(eMoneda *lista, int limite);
void eMoneda_init(eMoneda *lista, int limite);
int eMoneda_buscarLugarLibre(eMoneda *lista,int limite);
void eMoneda_alta(eMoneda *lista,int limite);
int eMoneda_buscarPorId(eMoneda *lista ,int limite, int id);
void eGen_baja(eMoneda *lista ,int limite, int id);

int main()
{
    eMoneda lista[TAMMON] = {{1,"Argentina","Peso",OCUPADO},{2,"Brasil","Real",OCUPADO},{3,"EEUU","Dolar",OCUPADO}};
    eMoneda* p;

    p = lista;

    eMoneda_init(p, TAMMON);

    eMoneda_mostrarListado(p, TAMMON);

    eMoneda_alta(p, TAMMON);

    eMoneda_mostrarListado(p, TAMMON);

    return 0;
}

void eMoneda_init(eMoneda *lista, int limite)
{
    int i;

    for(i = 3; i < limite; i++)
    {
        (lista+i)->estado = LIBRE;
    }
}

void eMoneda_mostrarListado(eMoneda *lista, int limite)
{
    int i;

    if(lista != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if((lista+i)->estado == OCUPADO)
            {
                printf("%d -- %s -- %s -- %d\n", (lista+i)->id, (lista+i)->pais, (lista+i)->nombre, (lista+i)->estado);
            }
        }
    }
}

int eMoneda_buscarLugarLibre(eMoneda *lista,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if((lista+i)->estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eMoneda_alta(eMoneda *lista,int limite)
{
    int libre;

    libre = eMoneda_buscarLugarLibre(lista, limite);

    printf("\nIngrese un ID: ");
    scanf("%d", &((lista+libre)->id));
    eMoneda_baja(lista, limite, (lista+libre)->id);
    printf("Ingrese el Pais: ");
    fflush(stdin);
    gets((lista+libre)->pais);
    printf("Ingrese el nombre de la moneda: ");
    fflush(stdin);
    gets((lista+libre)->nombre);
    (lista+libre)->estado = OCUPADO;
}

int eMoneda_buscarPorId(eMoneda *lista ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if((lista+i)->estado == OCUPADO && (lista+i)->id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eMoneda_baja(eMoneda *lista ,int limite, int id)
{
    int i;
    i = eMoneda_buscarPorId(lista, limite, id);
    (lista+i)->estado = LIBRE;
}

void eMoneda_aArchivo(int argc, char **argv)
{
    char bufferIn[100];

    fp = fopen("C:\\Users\\capacita_mecon\\Desktop\\Monedas Serrano.txt", "w");
}
