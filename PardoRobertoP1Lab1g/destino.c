#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"



int cargarDescripcionDestino(eDestino destinos[], int tamDestino, int iddestino, char descripcion[]){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(destinos != NULL && tamDestino > 0 && descripcion != NULL){
        todoOk = 1;
        for(int i=0; i<tamDestino; i++){
            if(destinos[i].id == iddestino){
                strcpy(descripcion, destinos[i].descripcion);

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

int cargarPrecioDestino(eDestino destinos[], int tamDestino, int iddestino, float* precioDestino){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(destinos != NULL && tamDestino > 0 && precioDestino >= 0){
        todoOk = 1;
        for(int i=0; i<tamDestino; i++){
            if(destinos[i].id == iddestino){
                (*precioDestino) = destinos[i].precio;

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



int mostrarDestinos(eDestino destinos[], int tamDestino){
    int todoOk = 0;

    printf(" ============================================\n");
    printf("               Destinos                  \n");
    printf("    id Destino     Destinos       Precio \n");
    printf(" ============================================\n");

    if(destinos != NULL && tamDestino > 0){
        for(int i=0; i<tamDestino; i++){
            printf("    %d          %-10s   $%10.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        printf("\n\n");

    todoOk = 1;
    }

    return todoOk;
}




int validarDestino(int id, eDestino destinos[], int tamDestino){
    int esValido = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.

    if(destinos != NULL && tamDestino > 0){

        for(int i=0; i<tamDestino; i++){
            if(destinos[i].id == id){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}
