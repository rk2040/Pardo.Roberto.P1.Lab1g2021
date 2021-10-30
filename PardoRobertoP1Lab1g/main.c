#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "dataWarehouse.h"

#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "viaje.h"
#include "destino.h"
#include "fecha.h"
#include "chofer.h"


#define TAM_MICRO 1000
#define TAM_EMPRESA 4
#define TAM_TIPO 4
#define TAM_VIAJE 1000
#define TAM_DESTINO 4
#define TAM_CHOFER 100



int main()
{

    char confirmarSalir = 'n';
    char continuarOpciones;
    eMicro micros[TAM_MICRO];
    int nextIdMicro = 1;
    eViaje viajes[TAM_VIAJE];
    int nextIdViaje = 1;
//    eEmpresa empresas[TAM_EMPRESA];
//    int nextIdEmpresa = 1000;
//    eTipo tipos[TAM_TIPO];
//    int nextIdTipo = 5000;
//    eDestino destinos[TAM_DESTINO];
//    int nextIdDestino = 20000;


//----- Harcodeo de estructuras -----
    eEmpresa empresas[TAM_EMPRESA] = {
        {1000, "Plusmar"},
        {1001, "Flecha Bus"},
        {1002, "Tas"},
        {1003, "El Rapido"}
    };

    eTipo tipos[TAM_TIPO] = {
        {5000, "Comun"},
        {5001, "Coche Cama"},
        {5002, "Doble"},
        {5003, "Vip"}
    };

    eDestino destinos[TAM_DESTINO] = {
        {20000, "Calafate", 22250.00},
        {20001, "Bariloche", 103000.00},
        {20002, "Iguazu", 84400.00},
        {20003, "Mendoza", 95600.00}
    };

    eChofer choferes[TAM_CHOFER] = {
        {1, "Franco Armani", 'm'},
        {2, "Marcelo Gallardo", 'm'},
        {3, "Angela Perez", 'f'},
        {4, "Natalia Soto", 'f'},
        {5, "Julian Alvarez", 'm'},
        {6, "Julian Alvarez", 'm'},
        {7, "Eduardo Fernandez", 'm'},
        {8, "Marcela Hernandez", 'f'},
        {9, "Rodolfo Donofrio", 'm'},
        {10, "Micaela Gutierrez", 'f'}
    };


    if(!(inicializarMicros(micros, TAM_MICRO) && inicializarViajes(viajes, TAM_VIAJE))){
        printf("Hubo algun problema al inializar \n");
    }
    else{
		printf("Inicializacion exitosa \n");
    }



    harcodearMicros(micros, TAM_MICRO, 10, &nextIdMicro);

    harcodearViajes(viajes, TAM_VIAJE, 10, &nextIdViaje);



    do{
        switch(menu()){
            case 'A':
                continuarOpciones = opcionConfirmar("Continuar con el Alta? s/n ", "Error, vuelva a intentarlo. Continuar con el Alta? s/n ");
                if(continuarOpciones == 's'){
                    if(!altaMicro(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER, &nextIdMicro)){
                        printf("No se pudo realizar el alta \n");
                    }
                    else{
                        printf("Alta exitosa\n");
                    }
                }
                break;

            case 'B':
                continuarOpciones = opcionConfirmar("Continuar con la Modificacion? s/n ", "Error, vuelva a intentarlo. Continuar con la Modificacion? s/n ");
                if(continuarOpciones == 's'){
                    if(!modificarMicro(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER)){
                        printf("No se pudo realizar la Modificacion \n");
                    }
                    else{
                        printf("Modificacion exitosa\n");
                    }
                }
                break;

            case 'C':
                continuarOpciones = opcionConfirmar("Continuar con la Baja? s/n ", "Error, vuelva a intentarlo. Continuar con la Baja? s/n ");
                if(continuarOpciones == 's'){
                    if(!(bajaMicro(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER))){
                        printf("No se pudo realizar la baja\n");
                    }
                    else{
                        printf("Baja exitosa\n");
                    }
                }
                break;

            case 'D':
                system("cls");
                //ordenarMicrosEmpresaCapacidad(micros, TAM_MICRO, empresas, TAM_EMPRESA);
                    if(!mostrarListadosMicros(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER)){
                        printf("No hay micros para mostrar \n");
                    }

                break;

            case 'E':
                system("cls");
                if(!mostrarEmpresas(empresas, TAM_EMPRESA)){
                        printf("No hay empresas para mostrar.\n");
                    }
                break;

            case 'F':
                system("cls");
                if(!mostrarTipos(tipos, TAM_TIPO)){
                    printf("No hay tipos para  mostrar. \n");
                }
                break;

            case 'G':
                system("cls");
                if(!mostrarDestinos(destinos, TAM_DESTINO)){
                    printf("No hay destinps para mostrar. \n");
                }
                break;

            case 'H':
                continuarOpciones = opcionConfirmar("Continuar con el Alta de Viaje? s/n ", "Error, vuelva a intentarlo. Continuar con el Alta de Viaje? s/n ");
                if(continuarOpciones == 's'){
                    if(!altaViaje(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO, choferes, TAM_CHOFER, &nextIdViaje)){
                        printf("No se pudo realizar el alta \n");
                    }
                    else{
                        printf("Alta exitosa\n");
                    }
                }
                break;

            case 'I':
                system("cls");
                if(!mostrarViajes(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO)){
                    printf("No hay viajes para mostrar. \n");
                }
                break;

            case 'X':
                confirmarSalir = opcionConfirmar("Seguro que quiere salir? s/n: ", "Error. Seguro que quiere salir? s/n: ");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente. \n");
        }
        system("pause");


    }while(confirmarSalir == 'n');




    return 0;
}
