#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

#include "empresa.h"
#include "tipo.h"
#include "chofer.h"

typedef struct{
    int id;         // es el Primary Key de esta estructura.
    int capacidad;  // entre 1 y 50
    int idEmpresa;    // es la Foreing Key de esta estructura, que es la Primary Key de la otra estructura con la que se va a relacionar
    int idTipo;    // es la Foreing Key de esta estructura, que es la Primary Key de la otra estructura con la que se va a relacionar
    int idChofer;
    int isEmpty;    // 1 esta vacio, 0 esta lleno
}eMicro;





char menu();

/** \brief  inicializa el aray de micros
 *
 * \param micros[] eMicro   Array a inicializar, coloca 1 en el campo isEmpty de la estructura para indicar que esta vacia
 * \param tamMicro int      Tamaño del array
 * \return int              Devuelve 1 si inicializo bien, 0 si hubo algun problema
 *
 */
int inicializarMicros(eMicro micros[], int tamMicro);


/** \brief  Busca la primer posicion del array libre. la primera que en su campo isEmpty tenga 0
 *
 * \param micros[] eMicro
 * \param tamMicro int      Tamaño del array
 * \return int              Devuelve 1 si encontro espacio libre, 0 si no hay espacio libre
 *
 */
int buscarLibre(eMicro micros[], int tamMicro);


/** \brief  Toma la el valor del campo descripcion de la estructura
 *
 * \param micros[] eMicro   Array de la que tomamos el valor
 * \param tamMicro int      Tamaño del array
 * \param idMicro int       id que nos marca el indice del array para tomar la descripcion
 * \param descripcion[] char    donde guardamos el valor tomado
 * \param empresas[] eEmpresa   array donde se encuentra la descripcion a copiar
 * \param tamEmpresa int        Tamaño del array
 * \return int                  Devuelve 1 si pudo cargar, 0 si no pudo
 *
 */
int cargarDescripcionMicro(eMicro micros[], int tamMicro, int idMicro, char descripcion[], eEmpresa empresas[], int tamEmpresa);


/** \brief
 *
 * \param micros[] eMicro       Array a dar de alta
 * \param tamMicro int          Tamaño del array
 * \param empresas[] eEmpresa   Array con datos usado por el array a dar de alta
 * \param tamEmpresa int        Tamaño del array
 * \param tipos[] eTipo         Array con datos usado por el array a dar de alta
 * \param tamTipo int           Tamaño del array
 * \param pId int*              puntero entero con valor de Id que se le asignara a cada posicion del array
 * \return int                  Devuelve 1 si pudo hacer el alta, 0 si no pudo
 *
 */
int altaMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer, int* pId);


/** \brief      muestra los valores de un solo micro
 *
 * \param unMicro eMicro        estructura de la que se tomaran los valores
 * \param empresas[] eEmpresa   estructura de la cual se toman valores
 * \param tamEmpresa int        tamaño del array
 * \param tipos[] eTipo         estructura de la cual se toman valores
 * \param tamTipo int           tamaño del array
 * \return void
 *
 */
void mostrarMicro(eMicro unMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);


/** \brief      muestra todos los indices del array de micros
 *
 * \param micros[] eMicro   array a mostrar
 * \param tamMicro int      tamaño array
 * \param empresas[] eEmpresa   estructura de la que se tomaran los valores
 * \param tamEmpresa int        tamaño del array
 * \param tipos[] eTipo         estructura de la que se tomaran los valores
 * \param tamTipo int           tamaño del array
 * \return int          devuelve 1 si todo se cargo bien, 0 si hubo algun problema
 *
 */
int mostrarMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);


/** \brief      muestra un menu de opciones
 *
 * \return char     devuelve un caracter como la opcion elegida
 *
 */
char menuModificarMicro();


/** \brief      toma volores de un micro por id para cambiar valores
 *
 * \param micros[] eMicro   array a modificar
 * \param tamMicro int      tamaño array
 * \param empresas[] eEmpresa   estructura con datos de la estructura principal
 * \param tamEmpresa int        tamaño array
 * \param tipos[] eTipo         estructura con datos de la estructura principal
 * \param tamTipo int           tamaño array
 * \return int          devuelve 1 si pudo modificar, 0 si hubo algun error
 *
 */
int modificarMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);


/** \brief      genera una baja loginca cambiando el campo de la estructura isEmpty de 0 lleno a 1 vacio
 *
 * \param micros[] eMicro       estructura a dar de baja
 * \param tamMicro int          tamaño array
 * \param empresas[] eEmpresa   estructura con datos de la estructura principal
 * \param tamEmpresa int        tamaño array
 * \param tipos[] eTipo         estructura con datos de la estructura principal
 * \param tamTipo int           tamaño array
 * \return int              devuelve 1 si pudo realizar la baja, 0 si hubo algun problema
 *
 */
int bajaMicro(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);


/** \brief      busca la existencia por id
 *
 * \param id int            id que va a buscar
 * \param micros[] eMicro   array donde se va a buscar
 * \param tamMicro int      tamaño array
 * \return int              devuelve 1 si encontro por id, 0 si no encontro
 *
 */
int validarMicro(int id, eMicro micros[], int tamMicro);


/** \brief      ordena el array por id de forma ascendente
 *
 * \param micros[] eMicro       array a ordenar
 * \param tamMicro int          tamaño array
 * \return int              devuelve 1 si pudo ordenar, 0 si hubo algun problema
 *
 */
int ordenarMicroPorId(eMicro micros[], int tamMicro);


/** \brief      ordena el array por nombre de empresa y por capacidad de forma ascendente
 *
 * \param micros[] eMicro       array a ordenar
 * \param tamMicro int          tamaño array
 * \param empresas[] eEmpresa   estructura con datos de la estructura principal
 * \param tamEmpresa int        tamaño array
 * \return int              devuelve 1 si pudo ordenar, 0 si hubo algun problema
 *
 */
int ordenarMicrosEmpresaCapacidad(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);


char menuModificarMicro();


int mostrarMicrosSoloIdTipo(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);

//float porcentajeMicrosVip(eMicro micros[], int tamMicro, eTipo tipos[], int tamTipo);

int mostrarListadosMicros(eMicro micros[], int tamMicro, eEmpresa empresas[], int tamEmpresa, eTipo tipos[], int tamTipo, eChofer choferes[], int tamChofer);



#endif // MICRO_H_INCLUDED
