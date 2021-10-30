#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[26];
    float precio;
}eDestino;

#endif // DESTINO_H_INCLUDED

int cargarDescripcionDestino(eDestino destinos[], int tamDestino, int iddestino, char descripcion[]);

int cargarPrecioDestino(eDestino destinos[], int tamDestino, int iddestino, float* precioDestino);

int mostrarDestinos(eDestino destinos[], int tamDestino);

int validarDestino(int id, eDestino destinos[], int tamDestino);
