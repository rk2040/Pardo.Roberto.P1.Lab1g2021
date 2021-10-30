#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"





char menu()
{

    char opcion;

    system("cls");
    printf(" ======================================\n");
    printf("      *** ABM Viajes en Micro ***     \n");
    printf(" ======================================\n\n");
    printf("  A- Alta Micro \n");
    printf("  B- Modificar Micro \n");
    printf("  C- Baja Micro \n");
    printf("  D- Listar Micros \n");
    printf("  E- Listar Empresas \n");
    printf("  F- Listar Tipos \n");
    printf("  G- Listar Destinos \n");
    printf("  H- Alta Viaje \n");
    printf("  I- Listar Viajes \n");
    printf("  X- Salir \n");
    printf("  Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}


//----- Inicializo Micros -----   0 lleno / 1 vacio
int inicializarMicros(eMicro micros[], int tamMicro){
    int todoOk = 0;

    if(micros != NULL && tamMicro > 0){
        for(int i=0; i<tamMicro; i++){
            micros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

//----- Busco la primer posicion ID libre -----   0 lleno / 1 vacio
int buscarLibre(eMicro micros[], int tamMicro){     // -1 si no hay lugar libre, sino devuelve el indice de la primer estructura vacia
    int indice = -1;

    if(micros != NULL && tamMicro > 0){
        for(int i=0; i<tamMicro; i++){
            if(micros[i].isEmpty){   // no hace poner == 1, porque sin poner nada equivale a TRUE osea a 1
            indice = i;
            break;  // para romper y detener en el primer lugar libre que encuentre y devuelva esa posicion
            }
        }
    }

    return indice;
}



int cargarDescripcionMicro(eMicro micros[], int tamMicro, int idMicro, char descripcion[], eEmpresa empresas[], int tamEmpresa){
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



//----- Alta de Micro -----
int altaMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer, int* pId){
    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if(micros != NULL && tamMicro > 0 && empresas != NULL && tamEmpresa > 0 && tipos != NULL && tamTipo >0 && choferes != NULL && tamChofer >0){
        system("cls");
        printf(" ======================================\n");
        printf("        *** Alta Micro ***          \n");
        printf(" ======================================\n");

        indice = buscarLibre(micros, tamMicro);
        if(indice == -1){
            printf("No hay lugar disponible \n");
        }
        else{
            auxMicro.id = *pId;   // primero asignamos el valor actual de ID, despues lo aumentamos para el proximo
                                    //*pId porque tomamos el valor que tenga el pId y se lo asignamos al auxiliar de la
                                    // estructura que estamos usando con el operador de indireccion *
            (*pId)++;   // va entre () porque tiene que operar sobre lo que esta adentro, en este caso aumentar + 1 al ID


            utn_getNumero(&auxMicro.capacidad, "Ingrese capacidad: ", "Error. Reingrese capacidad: ", 1, 50, 5);


            mostrarEmpresas(empresas, tamEmpresa);
            printf("Ingrese id Empresa: ");
            scanf("%d", &auxMicro.idEmpresa);
    // Valido ID empresa
            while(!validarEmpresa(auxMicro.idEmpresa, empresas, tamEmpresa)){
                printf("Error. Reingrese id Empresa: ");
                scanf("%d", &auxMicro.idEmpresa);
            }


            mostrarTipos(tipos, tamTipo);
            printf("Ingrese id Tipo: ");
            scanf("%d", &auxMicro.idTipo);
    // Valido ID tipo
            while(!validarTipo(auxMicro.idTipo, tipos, tamTipo)){
                printf("Error. Reingrese id Tipo: ");
                scanf("%d", &auxMicro.idTipo);
            }

            mostrarChofer(choferes, tamChofer);
            utn_getNumero(&auxMicro.idChofer, "Ingrese id Chofer: ", "Error. Reingrese id Chofer: ", 1, 100, 5);


            auxMicro.isEmpty = 0;

            micros[indice] = auxMicro;

            todoOk = 1;
        }
    }

    return todoOk;
}


//----- Muestra un Micro -----
void mostrarMicro(eMicro unMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    char descEmpresa[20];
    char descTipo[20];
    char nombreChofer[30];

    if((cargarDescripcionEmpresa(empresas, tamEmpresa, unMicro.idEmpresa, descEmpresa)== 1) &&
       (cargarDescripcionTipo(tipos, tamTipo, unMicro.idTipo, descTipo) == 1) &&
       (cargarNombreChofer(choferes, tamChofer, unMicro.idChofer, nombreChofer))){

        printf(" %2d            %-20s   %-20s  %2d      %-20s \n",
               unMicro.id,
               descEmpresa,
               descTipo,
               unMicro.capacidad,
               nombreChofer
               );
   }
}


//----- Muestra lista de Micros -----
int mostrarMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    int todoOk = 0;
    int flag = 1;

    if(micros != NULL && tamMicro > 0){
        //system("cls");
        printf("                            --- Lista de Micros ---           \n");
        printf(" =============================================================================================\n");
        printf("  Id           Empresa                Tipo              Capacidad       Nombre Chofer\n");
        printf(" =============================================================================================\n");
        for(int i=0; i<tamMicro; i++){
            if(!micros[i].isEmpty){
                mostrarMicro(micros[i], empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay micros para mostrar \n");
        }
        todoOk = 1;
    }
    return todoOk;
}



//----- Menu Modificar Micro -----
char menuModificarMicro(){
    char opcion;

    printf(" ======================================\n");
    printf("        *** Modificar Micro ***        \n");
    printf(" ======================================\n");
    printf("  A- Tipo \n");
    printf("  B- Capacidad \n");
    printf("  X- Volver al menu anterior \n");
    printf("  Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}



int buscarMicroId(eMicro micros[], int tamMicro, int id){
    int todoOk = -1;

    if(micros != NULL && tamMicro > 0){
        for(int i=0; i<tamMicro; i++){
            if(micros[i].id == id && !micros[i].isEmpty){
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}



//----- Modifico Micro -----
int modificarMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    int todoOk = 0;
    int indice;
    int id;
    eMicro auxMicro;
    char confirmarSalir = 'n';

    if(micros != NULL && tamMicro > 0){
        system("cls");
        printf("        *** Modificar Micro ***        \n\n");
        mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);   //para mostrar lista para ver el id antes de elegir usuario

        utn_getNumero(&id, "Ingrese Id : ", "Error. Reingrese Id: ", 1, 1000, 5);

        indice = buscarMicroId(micros, tamMicro, id);

        if(indice == -1){   // -1 era lo que devolvia la funcion buscarMicroId cuando no encontraba el id en el sistema
            printf("No se encuentra el Id %d en el sistema \n", id);
        }
        else{
            system("cls");

            mostrarMicro(micros[indice], empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);

            auxMicro = micros[indice];  // copio todos los datos del usuario al Auxiliar, pera despues modificarlos

            do{
                switch(menuModificarMicro()){
                    case 'A':
                        mostrarTipos(tipos, tamTipo);
                        if(!utn_getNumero(&auxMicro.idTipo, "Ingrese tipo: ", "Error. Reingrese tipo: ", 5000, 5004, 5)){
                            micros[indice] = auxMicro;
                        }
                        break;

                    case 'B':
                        if(!utn_getNumero(&auxMicro.capacidad, "Ingrese capacidad: ", "Error. Reingrese capacidad: ", 1, 50, 5)){
                            micros[indice] = auxMicro;
                        }
                        break;

                    case 'X':
                        confirmarSalir = 's';
                        break;

                    default:
                        printf("Opcion invalida. Intente nuevamente. \n");
                }
                //system("pause");

            }while(confirmarSalir == 'n');

            micros[indice] = auxMicro;
            todoOk = 1;
        }

    }

    return todoOk;
}



//----- Baja de Micro -----
int bajaMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    int todoOk = 0;
    int indice;
    int id;

    if(micros != NULL && tamMicro > 0){
        system("cls");
        printf("        *** Baja Micro ***        \n\n");
        mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);   //para mostrar lista para ver el id antes de elegir usuario

        utn_getNumero(&id, "Ingrese Id : ", "Error. Reingrese Id: ", 1, 1000, 5);

        indice = buscarMicroId(micros, tamMicro, id);


        if(indice == -1){   // -1 era lo que devolvia la funcion buscarMicroId cuando no encontraba el id en el sistema
            printf("No se encuentra el Id %d en el sistema \n", id);
        }
        else{
            mostrarMicro(micros[indice], empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);

            if(opcionConfirmar("Confirma Baja?: s/n ", "Error. Confirma Baja?: s/n ") == 's'){
                micros[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("Baja cancelada por el usuario \n");
            }

        }
    }
    return todoOk;
}


int validarMicro(int id, eMicro micros[], int tamMicro){
    int esValido = 0; // devuelve 1 si esta todo bien. 0 si hubo un problema con los parametros  y  -1 si busco y no encontro.

    if(micros != NULL && tamMicro > 0){

        for(int i=0; i<tamMicro; i++){
            if(micros[i].id == id){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}


//----- Menu Mostrar Micros -----
char menuMostrarMicro(){
    char opcion;

    printf(" ======================================\n");
    printf("        *** Mostrar Micro ***        \n");
    printf(" ======================================\n");
    printf("  A- Por Empresa seleccionada \n");
    printf("  B- Por Tipo seleccionado \n");
    printf("  C- Porcentaje de Micros vip sobre el total \n");
    printf("  D- Por Empresa agrupada \n");
    printf("  E- Por Empresa agrupada \n");
    printf("  F- Empresa con mayor capacidad de transporte \n");
    printf("  G- Empresa con menor cantidad de Micros \n");
    printf("  X- Volver al menu anterior \n");
    printf("  Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}



int mostrarListadosMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    int todoOk = 0;
    //int indice;
    //int id;
    //eMicro auxMicro;
    char confirmarSalir = 'n';
    float porcentaje;



    do{
            system("cls");
                switch(menuMostrarMicro()){
                    case 'A':
                        if(!mostrarMicrosSoloIdEmpresa(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer)){
                            printf("No se pudo ordenar y mostarr la lista seleccionada.");
                        }
                        break;

                    case 'B':
                        printf("B");
                        break;

                    case 'C':
                        porcentaje = porcentajeMicrosVip(micros, tamMicro, tipos, tamTipo);
                        printf("El porcentaje de Micros Vip es %.2f ", porcentaje);
                        system("pause");
                        break;

                    case 'D':
                        if(!ordenarMicrosEmpresaCapacidad(micros, tamMicro, empresas, tamEmpresa)){
                            printf("No se pudo ordenar y mostar la lista seleccionada.");
                        }
                        else{
                            mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);
                            system("pause");
                        }
                        break;

                    case 'E':

                        porcentajeMicrosVip(micros, tamMicro, tipos, tamTipo);
                        printf("El porcentaje de Micros Vip es %.2f ", porcentaje);
                        break;

                    case 'F':
                        printf("F");
                        break;

                    case 'G':
                        printf("G");
                        break;

                    case 'X':
                        confirmarSalir = 's';
                        break;

                    default:
                        printf("Opcion invalida. Intente nuevamente. \n");
                }
                //system("pause");

            }while(confirmarSalir == 'n');



    return todoOk = 1;
}


//======================================= Ordenamientos y Listas varias =========================================================
int ordenarMicroPorId(eMicro micros[], int tamMicro){
    int todoOk = 0;
    eMicro auxMicro;

    if(micros != NULL && tamMicro >0){
        for(int i=0; i<tamMicro-1; i++){
            for(int j=i+1; j<tamMicro; j++){
                if(micros[i].id > micros[j].id){
                    auxMicro = micros[i];
                    micros[i] = micros[j];
                    micros[j] = auxMicro;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk = 1;
}


int ordenarMicrosEmpresaCapacidad(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa){
    int todoOk = 0;
    eMicro auxMicro;
    char descEmpresaI[26];
    char descEmpresaJ[26];

    if(micros != NULL && tamMicro >0){
        for(int i=0; i<tamMicro-1; i++){
            for(int j=i+1; j<tamMicro; j++){
                cargarDescripcionEmpresa(empresas, tamEmpresa, micros[i].idEmpresa, descEmpresaI);
                cargarDescripcionEmpresa(empresas, tamEmpresa, micros[j].idEmpresa, descEmpresaJ);
                if((strcmp(descEmpresaI, descEmpresaJ) == 0 &&
                    micros[i].capacidad > micros[j].capacidad) ||
                    (strcmp(descEmpresaI, descEmpresaJ) > 0)){
                        auxMicro = micros[i];
                        micros[i] = micros[j];
                        micros[j] = auxMicro;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}


int mostrarMicrosSoloIdEmpresa(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer){
    int todoOk = 0;



    return todoOk = 1;
}

float porcentajeMicrosVip(eMicro micros[], int tamMicro, eTipo tipos[], int tamTipo){
    int todoOk = 0;
    int id;
    int contVip = 0;
    int contMicros = 0;
    float porcentaje;
    eMicro auxMicro;


    if(micros != NULL && tamMicro >0)
        for(int i=0; i<tamMicro; i++){
            if(!micros[i].isEmpty){
                contMicros++;

            }
            else if(micros[i].idTipo == 5003){
                contVip++;
            }
        }

    porcentaje = (float) (contVip * 100) / contMicros;


    return porcentaje;
}
