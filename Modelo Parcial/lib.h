#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int idProgramador;
    int idCategoria;
    char nombre[25];
    char apellido[25];
    int estado;
}eProgramador;

typedef struct
{
    int idCategoria;
    char descripcion[25];
    float sueldoXHora;
}eCategoria;

typedef struct
{
    int idProyecto;
    char nombre[25];
    int estado;
}eProyecto;

typedef struct
{
    int idProgramador;
    int idProyecto;
    int horasProyecto;
    int estado;
}eProgramadorProyecto;

void eProy_hard(eProyecto proyectos[]);

void eProg_hard(eProgramador programadores[]);

void eProgProy_hard(eProgramadorProyecto asignados[]);

void eCat_init(eCategoria categorias[]);

int eProy_init(eProyecto proyectos[],int limite);

int eProgProy_init(eProgramadorProyecto asignados[],int limite);

int eProg_init(eProgramador programadores[],int limite);

int eProg_buscarLugarLibre(eProgramador programadores[],int limite);

int eProg_siguienteId(eProgramador programadores[],int limite);

int eProg_alta(eProgramador programadores[],int limite);

int eCat_buscarPorId(eCategoria categorias[] , int limite, int id);

int eProg_buscarPorId(eProgramador programadores[] , int limite, int id);

void eProg_mostrarUno(eProgramador programadores);

void eCat_mostrarUno(eCategoria categorias);

int eProg_mostrarListado(eProgramador programadores[],int limite, eCategoria categorias[]);

int eProg_modificacion(eProgramador programadores[] ,int limite, int id, eCategoria categorias[]);

int eProgProy_buscarLugarLibre(eProgramadorProyecto asignados[],int limite);

int eProy_buscarLugarLibre(eProyecto proyectos[],int limite);

int eProy_siguienteId(eProyecto proyectos[],int limite);

int eProy_alta(eProyecto proyectos[],int limite);

void eProy_mostrarUno(eProyecto proyectos);

int eProy_mostrarListado(eProyecto proyectos[],int limite);

int eProgProy_asignar(eProgramadorProyecto asignados[], int limiteProgProy, eProgramador programadores[], int limiteProg, eProyecto proyectos[], int limiteProy, eCategoria categorias[]);

int eProgProy_mostrarProyectos(eProgramadorProyecto asignados[], int limite, eProyecto proyectos[], int id);

void eProgProy_listar(eProyecto proyectos[], int limiteProy, eProgramador programadores[], int limiteProg, eCategoria categorias[], eProgramadorProyecto asignados[], int limiteProgProy);

void eProgProy_demandante(eProgramadorProyecto asignados[], int limiteProgProy, eProyecto proyectos[]);

#endif // LIB_H_INCLUDED
