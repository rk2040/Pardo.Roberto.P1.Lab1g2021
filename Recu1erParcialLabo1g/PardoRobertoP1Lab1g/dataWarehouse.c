#include<string.h>
#include"dataWarehouse.h"
#include "micro.h"
#include "destino.h"
#include "viaje.h"
#include "chofer.h"


//int idMicro[20] = {1,2,3,4,5,6,7,8,9,10};

int idMicro[20] = {1,2,3,4,5,6,7,8,9,10,3,3,5,7,9,10,9,2,5,8};

int idEmpresa[20] = {1000,1002,1000,1001,1001,1003,1000,1002,1003,1001,1002,1000,1001,1001,1003,1002,1000,1001,1001,1003};

int idTipo[20] = {5000,5002,5003,5001,5001,5003,5002,5002,5000,5003,5001,5003,5002,5002,5001,5003,5002,5002,5003,5003};

int capacidad[20] = {25,50,23,21,33,41,17,19,30,11,35,44,20,30,40,50,47,24,16,20};

int idDestino[20] = {20003,20000,20001,20003,20002,20001,20000,20003,20002,20000,20000,20001,20003,20002,20001,20000,20001,20003,20002,20001};

//int idViaje[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int idViaje[20] = {4,2,1,6,7,10,3,1,10,5,9,3,1,6,8,9,10,3,4,7};

int dia[20] = {13,22,1,31,2,15,17,5,30,11,1,4,31,29,17,22,30,18,5,2};

int mes[20] = {1,4,12,3,2,11,10,9,6,7,4,6,12,11,3,8,10,9,6,12};

int anio[20] = {2019,2021,2007,2010,2021,2021,2020,2015,2021,2020,2021,2021,2021,2021,2020,2019,2021,2021,2020,2020};

int idChofer[20] = {1,2,3,4,5,6,7,8,9,10,5,6,7,8,9,10,3,6,10,5};



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
            viajes[i].idChofer = idChofer[i];
            viajes[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
