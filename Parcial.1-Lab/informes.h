#include <stdio.h>

typedef struct
{
    int idMarca;
    int cantidad;
    int isEmpty;

}eMarcaME;


/** \brief se inicializa las marcas mas elegidas
 *
 * \param listaME eMarcaME*
 * \param tamME int
 * \return void
 *
 */
void inicializarMME(eMarcaME* listaME,int tamME);

/** \brief imprime las opciones para los informes
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuInformes();

/** \brief Menu que permite llamar a las funciones de los informes
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \param trabajos eTrabajo*
 * \param tamT int
 * \param servicios eServicio*
 * \param tamSer int
 * \param marcaElegida eMarcaME*
 * \return void
 *
 */
void informar(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer, eMarcaME* marcaElegida);

/** \brief Muestra los autos del color seleccionado por el usuario
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \return void
 *
 */
void informarAutosColor(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM);

/** \brief Muestra autos de una marca seleccionada
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \return void
 *
 */
void informarAutosMarcas(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM);

/** \brief Muestra el o los modelos de autos mas antiguos
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \return void
 *
 */
void informarAutoMasViejo(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM);

/** \brief Muestra un listado de los autos agrupados por marca
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \return void
 *
 */
void informarAutosXMarca(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM);

/** \brief Se da a elegir al usuario un color y una marca y cuenta cuantos autos hay de ese color y esa marca
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \return void
 *
 */
void informarAutosPorColorYMarca(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM);

/** \brief Muestra la o las marcas mas elegidas
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \param listaME eMarcaME*
 * \return void
 *
 */
void informarMarcaMasElegida(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eMarcaME* listaME);

/** \brief Recorre las marcas y las imprime
 *
 * \param idMarca int
 * \param marcas eMarca*
 * \param tamMarcas int
 * \return int
 *
 */
int buscarMarca(int idMarca, eMarca* marcas, int tamMarcas);

/** \brief Imprime una marca
 *
 * \param marca eMarca
 * \return void
 *
 */
void mostrarMarca(eMarca marca);

/** \brief Muestra los trabajos que se le realizaron al auto
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \param trabajos eTrabajo*
 * \param tamT int
 * \param servicios eServicio*
 * \param tamSer int
 * \return void
 *
 */
void informarTrabajosAuto(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer);

/** \brief Muestra el importe total de los servicios que se le realizaron al auto
 *
 * \param autos eAuto*
 * \param tam int
 * \param colores eColor*
 * \param tamC int
 * \param marcas eMarca*
 * \param tamM int
 * \param trabajos eTrabajo*
 * \param tamT int
 * \param servicios eServicio*
 * \param tamSer int
 * \return void
 *
 */
void informarImporteAuto(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer);

/** \brief Muestra un servicio realizado en una fecha seleccionada
 *
 * \param trabajos eTrabajo*
 * \param tamT int
 * \param servicios eServicio*
 * \param tamSer int
 * \return void
 *
 */
void informarFechaServicio(eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer);


/** \brief se pide servicio y se muestra el servicio y la flecha en la que se realizo
 *
 * \param autos eAuto*
 * \param tam int
 * \param trabajos eTrabajo*
 * \param tamT int
 * \param servicios eServicio*
 * \param tamSer int
 * \return void
 *
 */
void informarServicioyFecha(eAuto* autos, int tam, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer);
