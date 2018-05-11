#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int idPropietario;
    char nombreYApellido[20];
    char direccion[20];
    char tarjeta[20];
    int estado;
}ePropietario;

typedef struct
{
    int idPropietario;
    int idAutomovil;
    char patente[20];
    int marca;
    int horas;
    int estado;
}eAuto;

void eProp_cargar(ePropietario propietarios[], int limiteProp);

int eProp_init(ePropietario propietarios[],int limiteProp);

int eProp_buscarLugarLibre(ePropietario propietarios[],int limiteProp);

int eProp_siguienteId(ePropietario propietarios[],int limiteProp);

int eProp_alta(ePropietario propietarios[],int limiteProp);

int eProp_buscarPorId(ePropietario propietarios[] , int limiteProp, int id);

void eProp_mostrarUno(ePropietario propietarios);

int eProp_mostrarListado(ePropietario propietarios[],int limiteProp);

int eProp_modificacion(ePropietario propietarios[] ,int limiteProp);

void eAut_cargar(eAuto estacionados[], int limiteEst);

int eAut_init(eAuto estacionados[],int limiteEst);

void eProp_baja(ePropietario propietarios[] ,int limiteProp, eAuto estacionados[] , int limiteEst);

int eAut_baja(eAuto estacionados[] , int limiteEst, int id);

int eAut_alta(eAuto estacionados[], int limiteEst, ePropietario propietarios[], int limiteProp);

int eAut_buscarLugarLibre(eAuto estacionados[],int limiteEst);

int eAut_siguienteId(eAuto estacionados[],int limiteEst);

void eAut_mostrarUno(eAuto estacionados, ePropietario propietarios[], int id);

int eAut_mostrarListado(eAuto estacionados[],int limiteEst, ePropietario propietarios[]);

#endif // LIB_H_INCLUDED
