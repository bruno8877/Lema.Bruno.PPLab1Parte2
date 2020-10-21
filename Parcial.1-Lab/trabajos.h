#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[26];
    float precio;

} eServicio;

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

/** \brief recorre los servicios y los muestra
 *
 * \param servicios eServicio*
 * \param tamServicio int
 * \return void
 *
 */
void mostrarDescripcionServicios(eServicio* servicios,int tamServicio);

/** \brief recorre los servicios por id y cargar la descripcion
 *
 * \param servicio[] char
 * \param precio float*
 * \param id int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return float
 *
 */
float cargarDescripcionServicio(char servicio[],float* precio,int id, eServicio servicios[], int tamServicios);

/** \brief inicializa los trabajos
 *
 * \param vec eTrabajo*
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo* vec,int tam);

/** \brief busca un espacio libre donde
 *
 * \param vec eTrabajo*
 * \param tam int
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo* vec,int tam);

/** \brief se da de alta un nuevo trabajo que se le realizara al auto
 *
 * \param idX int
 * \param vec eTrabajo*
 * \param tamTrabajo int
 * \param servicios eServicio*
 * \param tamServicios int
 * \param list eAuto*
 * \param tamAutos int
 * \param marcas eMarca*
 * \param tamMarcas int
 * \param colores eColor*
 * \param tamColores int
 * \return int
 *
 */
int altaTrabajo(int idX,eTrabajo* vec, int tamTrabajo,eServicio* servicios,int tamServicios,eAuto* list, int tamAutos,eMarca* marcas,int tamMarcas,eColor* colores,int tamColores);

/** \brief se muestra un trabajo realizado al auto
 *
 * \param x eTrabajo
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo x,eServicio servicios[], int tamServicios);

/** \brief se muestra los trabajos que se realizaron a los auto/s
 *
 * \param x[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo x[],int tamTrabajos,eServicio servicios[],int tamServicios);
