#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chofer.h"
#include "micro.h"
#include "viaje.h"
#include "informes.h"


int cargarNombreChofer(eChofer choferes[], int tamChofer, int idChofer, char nombre[]){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(choferes != NULL && tamChofer > 0 && nombre != NULL){
        todoOk = 1;
        for(int i=0; i<tamChofer; i++){
            if(choferes[i].id == idChofer){
                strcpy(nombre, choferes[i].nombre);
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




int mostrarChofer(eChofer choferes[], int tamChofer){
    int todoOk = 0;

    printf(" ======================================\n");
    printf("             Choferes               \n");
    printf("    id Chofer     Nombre       \n");
    printf(" ======================================\n");

    if(choferes != NULL && tamChofer > 0){
        for(int i=0; i<tamChofer; i++){
            printf("    %d           %-10s \n", choferes[i].id, choferes[i].nombre);
        }
        printf("\n\n");

    todoOk = 1;
    }

    return todoOk;
}
