#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"
#include "empresa.h"
#include "micro.h"
#include "informes.h"


int cargarDescripcionTipo(eTipo tipos[], int tamTipo, int idTipo, char descripcion[]){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(tipos != NULL && tamTipo > 0 && descripcion != NULL){
        todoOk = 1;
        for(int i=0; i<tamTipo; i++){
            if(tipos[i].id == idTipo){
                strcpy(descripcion, tipos[i].descripcion);
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



int mostrarTipos(eTipo tipos[], int tamTipo){
    int todoOk = 0;

    printf(" ======================================\n");
    printf("          Tipo de Servicio             \n");
    printf("    id Tipo        Tipo        \n");
    printf(" ======================================\n");

    if(tipos != NULL && tamTipo > 0){
        for(int i=0; i<tamTipo; i++){
            printf("    %d           %-10s \n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");

    todoOk = 1;
    }

    return todoOk;
}




int validarTipo(int id, eTipo tipos[], int tamTipo){
    int esValido = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.

    if(tipos != NULL && tamTipo > 0){

        for(int i=0; i<tamTipo; i++){
            if(tipos[i].id == id){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}

/*
int buscarTipoId(eTipo tipos[], int tamTipo, int id){
    int todoOk = -1;

    if(tipos != NULL && tamTipo > 0){
        for(int i=0; i<tamTipo; i++){
            if(tipos[i].id == id && !tipos[i].isEmpty){
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}
*/
