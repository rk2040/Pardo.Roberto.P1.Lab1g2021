#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "informes.h"


int cargarDescripcionEmpresa(eEmpresa empresas[], int tamEmpresa, int idEmpresa, char descripcion[]){
    int todoOk = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.
    int flag = 1;

    if(empresas != NULL && tamEmpresa > 0 && descripcion != NULL){
        todoOk = 1;
        for(int i=0; i<tamEmpresa; i++){
            if(empresas[i].id == idEmpresa){
                strcpy(descripcion, empresas[i].descripcion);
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



int mostrarEmpresas(eEmpresa empresas[], int tamEmpresa){
    int todoOk = 0;

    printf(" ======================================\n");
    printf("             Empresas               \n");
    printf("    id Empresa     Empresas       \n");
    printf(" ======================================\n");

    if(empresas != NULL && tamEmpresa > 0){
        for(int i=0; i<tamEmpresa; i++){
            printf("    %d           %-10s \n", empresas[i].id, empresas[i].descripcion);
        }
        printf("\n\n");

    todoOk = 1;
    }

    return todoOk;
}




int validarEmpresa(int id, eEmpresa empresas[], int tamEmpresa){
    int esValido = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.

    if(empresas != NULL && tamEmpresa > 0){

        for(int i=0; i<tamEmpresa; i++){
            if(empresas[i].id == id){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}
