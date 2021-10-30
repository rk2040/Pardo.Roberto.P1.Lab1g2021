#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "fecha.h"
#include "destino.h"
#include "micro.h"

typedef struct{
    int id;
    int idMicro;
    int idDestino;
    int idEmpresa;
    int idTipo;
    eFecha fecha;
    int isEmpty;
}eViaje;

#endif // VIAJE_H_INCLUDED

int inicializarViajes(eViaje viajes[], int tamViaje);

int buscarLibreViaje(eViaje viajes[], int tamViaje);

int altaViaje(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer, int* pId);

void mostrarViaje(eViaje unViaje,eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino);

int mostrarViajes(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino);
