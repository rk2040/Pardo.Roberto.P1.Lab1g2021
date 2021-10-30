#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eTipo;

#endif // TIPO_H_INCLUDED

int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int idTipo, char descripcion[]);

int mostrarTipos(eTipo tipos[], int tamTipo);

int validarTipo(int id, eTipo tipos[], int tamTipo);

int buscarTipoId(eTipo tipos[], int tamTipo, int id);
