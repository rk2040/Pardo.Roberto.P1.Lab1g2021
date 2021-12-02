#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED


#include "destino.h"
#include "micro.h"
#include "fecha.h"
#include "chofer.h"

typedef struct{
    int id;
    int idMicro;
    int idDestino;
    int idEmpresa;
    int idTipo;
    eFecha fecha;
    int idChofer;
    int isEmpty;
}eViaje;


int inicializarViajes(eViaje viajes[], int tamViaje);

int buscarLibreViaje(eViaje viajes[], int tamViaje);

int altaViaje(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer, int* pId);

void mostrarViaje(eViaje unViaje,eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer);

int mostrarViajes(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer);



#endif // VIAJE_H_INCLUDED
