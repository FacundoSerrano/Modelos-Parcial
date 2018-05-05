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

void eCat_init(eCategoria categorias[]);

int eProg_init(eProgramador programadores[],int limite);

int eProg_buscarLugarLibre(eProgramador programadores[],int limite);

int eProg_siguienteId(eProgramador programadores[],int limite);

int eProg_alta(eProgramador programadores[],int limite);

int eCat_buscarPorId(eCategoria categorias[] , int limite, int id);

void eProg_mostrarUno(eProgramador programadores);

void eCat_mostrarUno(eCategoria categorias);

int eProg_mostrarListado(eProgramador programadores[],int limite, eCategoria categorias[]);

#endif // LIB_H_INCLUDED
