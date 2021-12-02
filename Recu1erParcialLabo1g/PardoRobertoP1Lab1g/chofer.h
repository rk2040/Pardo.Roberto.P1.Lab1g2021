#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct{
    int id;
    char nombre[26];
    char sexo;
}eChofer;

#endif // CHOFER_H_INCLUDED

int cargarNombreChofer(eChofer choferes[], int tamChofer, int idChofer, char nombre[]);

int mostrarChofer(eChofer choferes[], int tamChofer);
