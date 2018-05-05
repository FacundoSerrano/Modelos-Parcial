#ifndef USUARIOSERIE_H_INCLUDED
#define USUARIOSERIE_H_INCLUDED

typedef struct{
    int idUsuario;
    int idSerie;
}eUsuarioSerie;

void CrearListadoUsuariosYSeries(eUsuarioSerie misRelaciones[], int cantidad);


#endif // USUARIOSERIE_H_INCLUDED


