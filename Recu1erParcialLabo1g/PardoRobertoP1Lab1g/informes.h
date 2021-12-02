#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"
#include "destino.h"
#include "fecha.h"
#include "chofer.h"


int menuInformes();

int mostrarMicrosSoloIdEmpresa(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);

int mostrarMicrosSoloIdTipo(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);

int porcentajeMicrosVip(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo);

int mostrarMicrosPorEmpresa(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo);

void mostrarMicroEmpresa(eMicro unMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo);

int mostrarEmpresaMayorcapacidad(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo);

int mostrarEmpresaMenorMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo);

int mostrarViajesDeUnMicros(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer);

int precioTotalPorMicro(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer);

int mostrarDestinosFechasDeUnMicro(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino);

void mostrarViajeDestinoFecha(eViaje unViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino);

int mostrarViajesEnUnaFecha(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino);

void mostrarFechas(eViaje viajes[], int tamViaje);

void ordenoFechas(eViaje viajes[], int tamViaje);


#endif // INFORMES_H_INCLUDED


