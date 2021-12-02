#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "informes.h"
#include "utn.h"



int menuInformes()
{

    int opcion;
    int num;

    system("cls");
    printf(" ======================================\n");
    printf("  *** ABM Informes Complementarios ***  \n");
    printf(" ======================================\n\n");
    printf("  1- Mostrar micros de la empresa seleccionadapor el usuario \n");
    printf("  2- Mostrar micros de un tipo seleccionado \n");
    printf("  3- Informar Promedio de micros de tipo Vip \n");
    printf("  4- Mostrar listado de los micros separados por empresa \n");
    printf("  5- Informar la o las empresas que puedan transportar mas pasajeros (mayor acumulador de capacidades de sus micros) \n");
    printf("  6- Mostrar la empresa con menor cantidad de micros \n");
    printf("  7- Pedir un micro y mostrar todos los viajes que hizo el mismo \n");
    printf("  8- Pedir un micro e informar la suma de los precios (costo) de todos los viajes que realizo \n");
    printf("  9- Pedir un destino y mostrar los micros que viajaron a ese destino y en que fecha \n");
    printf(" 10- Pedir una fecha y mostrar todos los viajes realizados en la misma \n");
    printf("  0- Salir \n");
    //printf("  Ingrese opcion: ");
    //scanf("%d", &opcion);
    if(utn_getNumero(&num, "Ingrese opcion : ", "Error. ", 0, 10, 5))
    {
        opcion = num;
    }
    return opcion;
}






// 1- Mostrar micros de la empresa seleccionadapor el usuario
int mostrarMicrosSoloIdEmpresa(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer)
{
    int todoOk = 0;
    int idEmpresa;
    int flag = 1;
    char descripcion[20];

    system("cls");

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && choferes != NULL && tamChofer >0){
        mostrarEmpresas(empresas, tamEmpresa);

            do
            {                                                                         // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
                utn_getNumero(&idEmpresa, "Ingrese id Empresa: ", "Error. ", empresas[0].id, empresas[tamEmpresa-1].id, 10); // ID empresa 1000 al 1003
            // Valido ID empresa
            }while(!validarEmpresa(idEmpresa, empresas, tamEmpresa));


        printf("                            --- Lista de Micros ---           \n");
        printf(" =============================================================================================\n");
        printf("  Id           Empresa                Tipo              Capacidad       Nombre Chofer\n");
        printf(" =============================================================================================\n");

        for(int i=0; i<tamMicro; i++){
            if(!micros[i].isEmpty && micros[i].idEmpresa == idEmpresa){
                mostrarMicro(micros[i], empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);
                flag = 0;
            }
        }
        if(flag){
            cargarDescripcionEmpresa(empresas, tamEmpresa, idEmpresa, descripcion);
            printf("No hay micros de la empresa %s \n", descripcion);
        }


        todoOk = 1;
    }

    return todoOk;
}

// 2- Mostrar micros de un tipo seleccionado
int mostrarMicrosSoloIdTipo(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer)
{
    int todoOk = 0;
    eMicro auxMicro;
    int flag = 1;

    system("cls");

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && choferes != NULL && tamChofer >0){
        mostrarTipos(tipos, tamTipo);

        do
        {                                                                               // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
            utn_getNumero(&auxMicro.idTipo, "Ingrese id Tipo de servicio: ", "Error. ", tipos[0].id, tipos[tamTipo-1].id, 10); // ID tipo 5000 al 5003
        // Valido ID tipo
        }while(!validarTipo(auxMicro.idTipo, tipos, tamTipo));


        printf("                            --- Lista de Micros ---           \n");
        printf(" =============================================================================================\n");
        printf("  Id           Empresa                Tipo              Capacidad       Nombre Chofer\n");
        printf(" =============================================================================================\n");

        for(int i=0; i<tamMicro; i++){
            if(micros[i].idTipo == auxMicro.idTipo){
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

// 3- Informar Promedio de micros de tipo Vip
int porcentajeMicrosVip(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int idEmpresa;
    int contVip = 0;
    int contMicros = 0;
    int flag = 1;
    float porcentaje;
    char descripcion[20];
   // eMicro auxMicro;


    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo >0)
    {
        mostrarEmpresas(empresas, tamEmpresa);
        do
        {                                                                         // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
            utn_getNumero(&idEmpresa, "Ingrese id Empresa: ", "Error. ", empresas[0].id, empresas[tamEmpresa-1].id, 10); // ID empresa 1000 al 1003
        // Valido ID empresa
        }while(!validarEmpresa(idEmpresa, empresas, tamEmpresa));

        cargarDescripcionEmpresa(empresas, tamEmpresa, idEmpresa, descripcion);

        for(int i=0; i<tamMicro; i++){
            if(!micros[i].isEmpty && micros[i].idEmpresa == idEmpresa){
                contMicros++;

                if(micros[i].idTipo == 5003){
                    contVip++;
                }
                flag = 0;
            }
        }
        if(!flag)
        {
            printf("\n La empresa %s tiene %d micros\n Del total de micros %d son Vip\n", descripcion, contMicros, contVip);
            porcentaje = (float) (contVip * 100) / contMicros;
            printf(" Del total de micros de la empresa, %.2f %% son de tipo Vip\n", porcentaje);
        }
        else
        {
            printf("No hay micros de tipo Vip en la empresa %s \n", descripcion);
        }

        todoOk = 1;
    }

    return todoOk;
}


// 4- Mostrar listado de los micros separados por empresa
int mostrarMicrosPorEmpresa(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0)
        system("cls");
    {
      printf("\n =======================================================================\n");
        printf("                Micros agrupados por empresas                           \n");
        printf("  Id           Empresa                Tipo              Capacidad       \n");
        printf(" =======================================================================\n");

        for(int i=0; i<tamEmpresa; i++)
        {
            printf("\nEmpresa: %s \n", empresas[i].descripcion);
            for(int j=0; j<tamMicro; j++)
            {
                if(empresas[i].id == micros[j].idEmpresa)
                {
                    mostrarMicroEmpresa(micros[j], empresas, tamEmpresa, tipos, tamTipo);
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

//  complemento informe 4
void mostrarMicroEmpresa(eMicro unMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo)
{
    char descEmpresa[20];
    char descTipo[20];

    if((cargarDescripcionEmpresa(empresas, tamEmpresa, unMicro.idEmpresa, descEmpresa)== 1) &&
       (cargarDescripcionTipo(tipos, tamTipo, unMicro.idTipo, descTipo) == 1) ){

        printf(" %2d            %-20s   %-20s  %2d\n",
               unMicro.id,
               descEmpresa,
               descTipo,
               unMicro.capacidad
               );
   }
}


// 5- Informar la o las empresas que puedan transportar mas pasajeros (mayor acumulador de capacidades de sus micros)
int mostrarEmpresaMayorcapacidad(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    int empresaMayor = 0;
    int acumCapasidad[tamEmpresa];

    for(int i=0; i<tamEmpresa; i++)
    {
        acumCapasidad[i] = 0;   // inicializo todos los acumuladores con 0
    }


    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0)
    {
        system("cls");
      printf("\n =======================================================================\n");
        printf("            Empresa con mayor capacidad de transporte                   \n");
        printf(" =======================================================================\n");

        for(int i=0; i<tamMicro; i++)
        {
            for(int j=0; j<tamEmpresa; j++)
            {
                if(!micros[i].isEmpty && micros[i].idEmpresa == empresas[j].id)
                {
                    acumCapasidad[j] += micros[i].capacidad;
                }
            }
        }   // con los 2 for calculamos la capasidad de cada empresa y ahora determinamos cual es la mayor

        for(int i=0; i<tamEmpresa; i++)
        {
            if(flag || acumCapasidad[i] > empresaMayor)
            {
                empresaMayor = acumCapasidad[i];
                flag = 0;
            }   // aca ya calculamos la mayor capacidad de las empresas
        }

        for(int i=0; i<tamEmpresa; i++)
        {
            if(acumCapasidad[i] == empresaMayor)
            {
                printf("\n %s : Es la empresa con mayor capasidad de pasajeros \n", empresas[i].descripcion);
                printf("\n %d : Es la capacidad maxima contando todos sus micros\n", empresaMayor);
            }
        }

        todoOk = 1;
    }

    return todoOk;
}


// 6- Mostrar la empresa con menor cantidad de micros
int mostrarEmpresaMenorMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    int empresaMenor = 0;
    int contMicros[tamEmpresa];

    for(int i=0; i<tamEmpresa; i++)
    {
        contMicros[i] = 0;   // inicializo todos los acumuladores con 0
    }


    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0)
    {
        system("cls");
      printf("\n =======================================================================\n");
        printf("            Empresa con menor cantidad de micros                        \n");
        printf(" =======================================================================\n");

        for(int i=0; i<tamMicro; i++)
        {
            for(int j=0; j<tamEmpresa; j++)
            {
                if(!micros[i].isEmpty && micros[i].idEmpresa == empresas[j].id)
                {
                    contMicros[j] ++;
                }
            }
        }   // con los 2 for calculamos la mayor cantidad de micros

        for(int i=0; i<tamEmpresa; i++)
        {
            if(flag || contMicros[i] < empresaMenor)
            {
                empresaMenor = contMicros[i];
                flag = 0;
            }   // aca ya calculamos la menor cantidad de micros
        }

        for(int i=0; i<tamEmpresa; i++)
        {
            if(contMicros[i] == empresaMenor)
            {
                printf("\n %s : Es la empresa con menor cantidad de micros \n", empresas[i].descripcion);
                printf("\n %d : Es la cantidad de micros disponibles que tiene \n", empresaMenor);
            }
        }

        todoOk = 1;
    }

    return todoOk;
}

// 7- Pedir un micro y mostrar todos los viajes que hizo el mismo
int mostrarViajesDeUnMicros(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer)
{
    int todoOk = 0;
    int idMicro;
    int flag = 1;
    char descripcion[20]; // descipcion empresa

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && destinos != NULL && tamDestino >0 && choferes != NULL && tamChofer >0)
    {
        system("cls");

        mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);

        do
        {                                                            // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
            utn_getNumero(&idMicro, "Ingrese id Micro: ", "Error. ", micros[0].id, micros[tamMicro-1].id, 10); // ID empresa 1000 al 1003
        // Valido ID empresa
        }while(!validarMicro(idMicro, micros, tamMicro));


        printf("                         --- Lista de Viajes por Micros ---           \n");
        printf(" ===================================================================================================================\n");
        printf("  Id      Empresa Micro        Tipo Micro          Destino                 Precio       Fecha viaje     Chofer      \n");
        printf(" ===================================================================================================================\n");

        for(int i=0; i<tamMicro; i++)
        {
            if(!micros[i].isEmpty && micros[i].id == idMicro)
            {
                for(int j=0; j<tamViaje; j++)
                {
                    if(!viajes[j].isEmpty && viajes[j].idMicro == micros[i].id)
                    {
                        mostrarViaje(viajes[j], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, destinos, tamDestino, choferes, tamChofer);
                        flag = 0;
                    }
                }
            }
        }
        if(flag)
        {
            cargarDescripcionEmpresa(empresas, tamEmpresa, micros[idMicro].idEmpresa, descripcion);
            printf("No hay viajes realizados por el micros de la empresa %s \n", descripcion);
        }

        todoOk = 1;
    }


    return todoOk;
}


// 8- Pedir un micro e informar la suma de los precios (costo) de todos los viajes que realizo
int precioTotalPorMicro(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino, eChofer choferes[], int tamChofer)
{
    int todoOk = 0;
    int idMicro;
    int flag = 1;
    float precioTotal = 0;
    char descripcion[20]; // descipcion micro

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && destinos != NULL && tamDestino >0 && choferes != NULL && tamChofer >0)
    {
        system("cls");

        mostrarMicros(micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, choferes, tamChofer);

        do
        {                                                            // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
            utn_getNumero(&idMicro, "Ingrese id Micro: ", "Error. ", micros[0].id, micros[tamMicro-1].id, 10); // ID empresa 1000 al 1003
        // Valido ID empresa
        }while(!validarMicro(idMicro, micros, tamMicro));


        printf("                         --- Lista de Viajes por Micros ---           \n");
        printf(" ===================================================================================================================\n");
        printf("  Id      Empresa Micro        Tipo Micro          Destino                 Precio       Fecha viaje     Chofer      \n");
        printf(" ===================================================================================================================\n");

        for(int i=0; i<tamMicro; i++)
        {
            if(!micros[i].isEmpty && micros[i].id == idMicro)
            {
                for(int j=0; j<tamViaje; j++)
                {
                    if(!viajes[j].isEmpty && viajes[j].idMicro == micros[i].id)
                    {
                        mostrarViaje(viajes[j], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, destinos, tamDestino, choferes, tamChofer);

                        for(int k=0; k<tamDestino; k++)
                        {
                            if(destinos[k].id == viajes[j].idDestino)
                            {
                                precioTotal =  precioTotal + destinos[k].precio;
                                flag = 0;
                            }
                        }


                        //mostrarViaje(viajes[j], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo, destinos, tamDestino, choferes, tamChofer);
                    }
                }
            }
        }
        printf("                                                                         ____________\n");
        printf("\n El monto total de los viajes del micro seleccionado es:                 $ %.2f \n", precioTotal);


        if(flag)
        {
            cargarDescripcionMicro(micros, tamMicro, idMicro, descripcion, empresas, tamEmpresa);
            printf("No hay viajes realizados por el micros de la empresa %s \n", descripcion);
        }
        todoOk = 1;
    }

    return todoOk;
}


// 9- Pedir un destino y mostrar los micros que viajaron a ese destino y en que fecha
int mostrarDestinosFechasDeUnMicro(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino)
{
    int todoOk = 0;
    int idDestino;

    if(viajes != NULL && tamViaje >0 && micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && destinos != NULL && tamDestino >0)
    {
        system("cls");

        mostrarDestinos(destinos, tamDestino);

        do
        {                                                            // mejorando codigo, de esta forma siempre llega hasta el ultimo Id auque se agreguen elementos
            utn_getNumero(&idDestino, "Ingrese id Destino: ", "Error. ", destinos[0].id, destinos[tamDestino-1].id, 10);
        // Valido ID empresa
        }while(!validarDestino(idDestino, destinos, tamDestino));
        //printf("No hay viajes realizados a %s \n", destinos[idDestino].descripcion);

        printf("                         --- Lista de Viajes por Destinos y Fechas ---           \n");
        printf(" ======================================================================================\n");
        printf("  Id      Empresa Micro        Tipo Micro           Destino               Fecha viaje  \n");
        printf(" ======================================================================================\n");

        for(int i=0; i<tamDestino; i++)
        {
            if(destinos[i].id == idDestino)
            {
                for(int j=0; j<tamViaje; j++)
                {
                    if(!viajes[j].isEmpty && viajes[j].idDestino == destinos[i].id)
                    {
                        mostrarViajeDestinoFecha(viajes[j], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo,destinos, tamDestino);
                    }
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

//  complemento informe 9
void mostrarViajeDestinoFecha(eViaje unViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino)
{
    char descEmpresa[20];
    char descTipo[20];
    char descDestino[20];
    int indice;

    for(int i=0; i<tamMicro; i++){
        if(unViaje.idMicro == micros[i].id){
            indice = i;



            if(cargarDescripcionEmpresa(empresas, tamEmpresa, micros[indice].idEmpresa, descEmpresa) == 1 &&
               cargarDescripcionTipo(tipos, tamTipo, micros[indice].idTipo, descTipo) == 1 &&
               cargarDescripcionDestino(destinos, tamDestino, unViaje.idDestino, descDestino) == 1 )
            {

                printf(" %2d       %-20s %-20s%-20s  %02d/%02d/%d\n",
                       unViaje.id,
                       descEmpresa,
                       descTipo,
                       descDestino,
                       unViaje.fecha.dia,
                       unViaje.fecha.mes,
                       unViaje.fecha.anio
                       );
           }
        }
    }


}

// 10- Pedir una fecha y mostrar todos los viajes realizados en la misma
int mostrarViajesEnUnaFecha(eViaje viajes[], int tamViaje, eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eDestino destinos[], int tamDestino)
{
    int todoOk = 0;
    eViaje auxViaje;

    if(micros != NULL && tamMicro >0 && empresas != NULL && tamEmpresa >0 && tipos != NULL && tamTipo>0 && destinos != NULL && tamDestino >0)
    {
        printf("    Fechas disponibles  \n");
        printf("   -------------------- \n");

        ordenoFechas(viajes, tamViaje);
        mostrarFechas(viajes, tamViaje);

        printf("Ingrese la fecha que quiere consultar \n\n");
   // Ingreso la fecha
        utn_getNumero(&auxViaje.fecha.anio, "Ingrese anio: aaaa ", "\nError. Reingrese anio: aaaa", 1990, 2021,5);

        utn_getNumero(&auxViaje.fecha.mes, "Ingrese mes: mm ", "\nError. Reingrese mes: mm", 1, 12, 5);

        if(auxViaje.fecha.mes == 1 || auxViaje.fecha.mes == 3 || auxViaje.fecha.mes == 5 || auxViaje.fecha.mes == 7 ||
            auxViaje.fecha.mes == 8 || auxViaje.fecha.mes == 10 || auxViaje.fecha.mes == 12)
        {
            utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 31, 5);
        }
        else if(auxViaje.fecha.mes == 4 || auxViaje.fecha.mes == 6 || auxViaje.fecha.mes == 9 || auxViaje.fecha.mes == 11)
        {
            utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 30, 5);
        }
        else
        {
            utn_getNumero(&auxViaje.fecha.dia, "Ingrese dia: dd ", "\nError. Reingrese dia: dd", 1, 28, 5);
        }

        printf("                         --- Lista de Viajes por Destinos y Fechas ---           \n");
        printf(" ======================================================================================\n");
        printf("  Id      Empresa Micro        Tipo Micro           Destino               Fecha viaje  \n");
        printf(" ======================================================================================\n");

        for(int i=0; i<tamViaje; i++)
        {
            if(viajes[i].fecha.anio == auxViaje.fecha.anio &&
               viajes[i].fecha.mes == auxViaje.fecha.mes &&
               viajes[i].fecha.dia == auxViaje.fecha.dia )
            {
                mostrarViajeDestinoFecha(viajes[i], micros, tamMicro, empresas, tamEmpresa, tipos, tamTipo,destinos, tamDestino);
            }

        }


        todoOk = 1;
    }

    return todoOk;
}


// complemento informe 10
void mostrarFechas(eViaje viajes[], int tamViaje)
{
    for(int i=0; i<tamViaje; i++)
    {
        if(!viajes[i].isEmpty)
            printf(" Fecha: %02d/%02d/%d \n", viajes[i].fecha.dia, viajes[i].fecha.mes, viajes[i].fecha.anio);
    }
}

// complemento informe 10
void ordenoFechas(eViaje viajes[], int tamViaje)
{
    eViaje aux;

    for(int i=0; i<tamViaje-1; i++)
    {
        for(int j=i+1; j<tamViaje; j++)
        {
            if(viajes[i].fecha.anio > viajes[j].fecha.anio)
            {
                aux = viajes[i];
                viajes[i] = viajes[j];
                viajes[j] = aux;


            }
        }
    }
}
