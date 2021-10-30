#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

#include "viaje.h"
#include "fecha.h"
#include "micro.h"
#include "destino.h"
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"


//----- Inicializo Viajes -----   0 lleno / 1 vacio
int inicializarViajes(eViaje viajes[], int tamViaje){
    int todoOk = 0;

    if(viajes != NULL && tamViaje > 0){
        for(int i=0; i<tamViaje; i++){
            viajes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


//----- Busco la primer posicion ID libre -----   0 lleno / 1 vacio
int buscarLibreViaje(eViaje viajes[], int tamViaje){     // -1 si no hay lugar libre, sino devuelve el indice de la primer estructura vacia
    int indice = -1;

    if(viajes != NULL && tamViaje > 0){
        for(int i=0; i<tamViaje; i++){
            if(viajes[i].isEmpty){   // no hace falta poner == 1, porque sin poner nada equivale a TRUE osea a 1
            indice = i;
            break;  // para romper y detener en el primer lugar libre que encuentre y devuelva esa posicion
            }
        }
    }

    return indice;
}




int cargarDescripcionMicroViaje(eViaje unViaje, eMicro micros[], int tamMicro, int idMicro, char descripcion[], eEmpresa empresas[], int tamEmpresa){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;
    int indiceEmpresa;

    if(micros != NULL && tamMicro > 0 && descripcion != NULL){
        todoOk = 1;
        for(int i=0; i<tamMicro; i++){
            if(micros[i].id == idMicro){
                indiceEmpresa = micros[i].idEmpresa;
                strcpy(descripcion, empresas[indiceEmpresa].descripcion);

                flag = 0;
                break;
            }
        }
        if(flag){
            todoOk = -1;
        }
    }

    return todoOk;
}

//----- Alta de Viaje -----
int altaViaje(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer, int* pId){
    int todoOk = 0;
    int indice;
    eViaje auxViaje;
 //   eMicro auxMicro;

    if(viajes!= NULL && tamViaje >0 && micros != NULL && tamMicro > 0 && empresas != NULL && tamEmpresa > 0 && tipos != NULL && tamTipo >0){
        system("cls");
        printf(" ======================================\n");
        printf("        *** Alta Viaje ***          \n");
        printf(" ======================================\n");

        indice = buscarLibreViaje(viajes, tamViaje);
        if(indice == -1){
            printf("No hay lugar disponible \n");
        }
        else{
            auxViaje.id = *pId;   // primero asignamos el valor actual de ID, despues lo aumentamos para el proximo
                                    //*pId porque tomamos el valor que tenga el pId y se lo asignamos al auxiliar de la
                                    // estructura que estamos usando con el operador de indireccion *
            (*pId)++;   // va entre () porque tiene que operar sobre lo que esta adentro, en este caso aumentar + 1 al ID



            ordenarMicroPorId(micros, tamMicro);
            mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);
            utn_getNumero(&auxViaje.idMicro, "Ingrese id micro: \n", "Error. Reingrese id Micro: \n", 1, 1000, 5);
          /*  printf("Ingrese id micro: ");
            scanf("%d", &auxViaje.idMicro); */
    // Valido ID Micro
            while(!validarMicro(auxViaje.idMicro, micros, tamMicro)){
                printf("Error. Reingrese id Micro: ");
                scanf("%d", &auxViaje.idMicro);
            }

            mostrarDestinos(destinos, tamDestino);
            printf("Ingrese id Destino: ");
            scanf("%d", &auxViaje.idDestino);
    // Valido ID Destino
            while(!validarDestino(auxViaje.idDestino, destinos, tamDestino)){
                printf("Error. Reingrese id Destino: ");
                scanf("%d", &auxViaje.idDestino);
            }



   // Ingreso la fecha
            utn_getNumero(&auxViaje.fecha.anio, "Ingrese anio: aaaa ", "\nError. Reingrese anio: aaaa", 1990, 2021,5);

            utn_getNumero(&auxViaje.fecha.mes, "Ingrese mes: mm ", "\nError. Reingrese mes: mm", 1, 12, 5);

            if(auxViaje.fecha.mes == 1 || auxViaje.fecha.mes == 3 || auxViaje.fecha.mes == 5 || auxViaje.fecha.mes == 7 ||
               auxViaje.fecha.mes == 8 || auxViaje.fecha.mes == 10 || auxViaje.fecha.mes == 12){
                utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 31, 5);
               }
            else if(auxViaje.fecha.mes == 4 || auxViaje.fecha.mes == 6 || auxViaje.fecha.mes == 9 || auxViaje.fecha.mes == 11){
                utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 30, 5);
               }
            else{
                utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 28, 5);
            }



            auxViaje.isEmpty = 0;

            viajes[indice] = auxViaje;

            todoOk = 1;
        }
    }

    return todoOk;
}


//----- Muestra un Viaje -----
void mostrarViaje(eViaje unViaje,eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino){
    char descEmpresa[20];
    char descTipo[20];
    char descDestino[20];
    float precioDestino;
    int indice;

    for(int i=0; i<tamMicro; i++){
        if(unViaje.idMicro == micros[i].id){
            indice = i;



            if(cargarDescripcionEmpresa(empresas, tamEmpresa, micros[indice].idEmpresa, descEmpresa) == 1 &&
               cargarDescripcionTipo(tipos, tamTipo, micros[indice].idTipo, descTipo) == 1 &&
               cargarDescripcionDestino(destinos, tamDestino, unViaje.idDestino, descDestino) == 1 &&
               cargarPrecioDestino(destinos, tamDestino, unViaje.idDestino, &precioDestino) == 1){

                printf(" %2d       %-20s %-20s%-20s $%10.2f     %02d/%02d/%d\n",
                       unViaje.id,
                       descEmpresa,
                       descTipo,
                       descDestino,
                       precioDestino,
                       unViaje.fecha.dia,
                       unViaje.fecha.mes,
                       unViaje.fecha.anio
                       );
           }
        }
    }


}


//----- Muestra lista de Viajes -----
int mostrarViajes(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino){
    int todoOk = 0;
    int flag = 1;

    if(viajes != NULL && tamViaje > 0){
        //system("cls");
        printf("             --- Lista de Viajes ---           \n");
        printf(" ===================================================================================================\n");
        printf("  Id      Empresa Micro        Tipo Micro          Destino                 Precio       Fecha viaje\n");
        printf(" ===================================================================================================\n");
        for(int i=0; i<tamViaje; i++){
            if(!viajes[i].isEmpty){
                mostrarViaje(viajes[i], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, destinos, tamDestino);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay viajes para mostrar \n");
        }
        todoOk = 1;
    }
    return todoOk;
}

