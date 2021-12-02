#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"
#include "dataWarehouse.h"

#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "viaje.h"
#include "destino.h"
#include "fecha.h"
#include "chofer.h"
#include "informes.h"

#define TAM_MICRO 100
#define TAM_EMPRESA 4
#define TAM_TIPO 4
#define TAM_VIAJE 100
#define TAM_DESTINO 4
#define TAM_CHOFER 10



int main()
{

    char confirmarSalir = 'n';
    char continuarOpciones;
    eMicro micros[TAM_MICRO];
    int nextIdMicro = 1;
    eViaje viajes[TAM_VIAJE];
    int nextIdViaje = 100;
    char salirInforme = 'n';
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


    if(!inicializarMicros(micros, TAM_MICRO)){
        printf("Hubo algun problema al inializar los micro\n");
    }
    else{
		printf("Inicializacion de micros exitosa \n");
    }
    if(!inicializarViajes(viajes, TAM_VIAJE)){
        printf("Hubo algun problema al inializar los viajes\n");
    }
    else{
		printf("Inicializacion de viajes exitosa \n");
    }


    harcodearMicros(micros, TAM_MICRO, 10, &nextIdMicro);

    harcodearViajes(viajes, TAM_VIAJE, 20, &nextIdViaje);


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
                    if(!ordenarMicrosEmpresaCapacidad(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER)){
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
                    printf("No hay destinos para mostrar. \n");
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
                if(!mostrarViajes(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO, choferes, TAM_CHOFER)){
                    printf("No hay viajes para mostrar. \n");
                }
                break;

            case 'J':   // Inicio de los informes complementarios
                do{
                    switch(menuInformes()){
                    case 1:
                        if(!mostrarMicrosSoloIdEmpresa(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER) )
                        {
                            printf("No se pudo mostrar la lista seleccionada.");
                        }
                        break;

                    case 2:
                        if(!mostrarMicrosSoloIdTipo(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, choferes, TAM_CHOFER))
                        {
                            printf("No se pudo mostrar la lista seleccionada.");
                        }
                        break;

                    case 3:
                        if(!porcentajeMicrosVip(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO) )
                        {
                            printf("No hay micros del tipo Vip para mostrar\n");
                        }
                        break;

                    case 4:
                        if(!mostrarMicrosPorEmpresa(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 5:
                        if(!mostrarEmpresaMayorcapacidad(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 6:
                        if(!mostrarEmpresaMenorMicros(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 7:
                        if(!mostrarViajesDeUnMicros(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO, choferes, TAM_CHOFER) )
                        {
                            printf("No hay viajes de este micros para mostrar");
                        }
                        break;

                    case 8:
                        if(!precioTotalPorMicro(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO, choferes, TAM_CHOFER) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 9:
                        if(!mostrarDestinosFechasDeUnMicro(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 10:
                        if(!mostrarViajesEnUnaFecha(viajes, TAM_VIAJE, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPO, destinos, TAM_DESTINO) )
                        {
                            printf("No hay micros para mostrar");
                        }
                        break;

                    case 0:
                        salirInforme = opcionConfirmar("Seguro que quiere salir? s/n: ", "Error. Seguro que quiere salir? s/n: ");
                        break;

                    default:
                        printf("Opcion invalida. Intente nuevamente. \n");
                        break;
                    }
                    system("pause");

                }while(salirInforme == 'n');    // Terminan los informes complementarios

                break;  // break del case J (donde entrarn todos los informes)

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
