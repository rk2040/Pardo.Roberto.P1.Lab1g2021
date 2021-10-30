#include<string.h>
#include"dataWarehouse.h"
#include "micro.h"
#include "destino.h"
#include "viaje.h"
#include "chofer.h"


int idMicro[10] = {1,2,3,4,5,6,7,8,9,10};

int idEmpresa[10] = {1000,1002,1000,1001,1001,1003,1000,1002,1003,1001};

int idTipo[10] = {5000,5002,5000,5001,5001,5003,5002,5002,5000,5001};

int capacidad[10] = {12,50,23,1,33,41,7,19,30,11};

int idDestino[10] = {20003,20000,20001,20003,20002,20001,20000,20003,20002,20000};

int idViaje[10] = {1,2,3,4,5,6,7,8,9,10};

int dia[10] = {13,22,1,31,2,15,17,5,30,11};

int mes[10] = {1,4,12,3,2,11,10,9,6,7};

int anio[10] = {2019,2021,2007,2010,2021,2021,2020,2015,2021,2020};

int idChofer[10] = {1,2,3,4,5,6,7,8,9,10};



int harcodearMicros(eMicro micros[], int tamMicro, int cant, int* pId){
    int contador = -1;

    if(micros != NULL && tamMicro > 0 && cant >= 0 && cant <= tamMicro && pId != NULL){
        contador = 0;
        for(int i=0; i<cant; i++){
            micros[i].id = *pId;
            (*pId)++;
            micros[i].idEmpresa = idEmpresa[i];
            micros[i].idTipo = idTipo[i];
            micros[i].capacidad = capacidad[i];
            micros[i].idChofer = idChofer[i];
            micros[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}


int harcodearViajes(eViaje viajes[], int tamViaje, int cant, int* pId){
    int contador = -1;

    if(viajes != NULL && tamViaje> 0 && cant >= 0 && cant <= tamViaje && pId != NULL){
        contador = 0;
        for(int i=0; i<cant; i++){
            viajes[i].id = *pId;
            (*pId)++;
            viajes[i].idMicro = idMicro[i];
            viajes[i].idDestino = idDestino[i];
            viajes[i].fecha.dia = dia[i];
            viajes[i].fecha.mes = mes[i];
            viajes[i].fecha.anio = anio[i];
            viajes[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
