#include <stdio.h>

typedef struct
{
    int id;
    char nombreMarca[21];

} eMarca;

typedef struct
{
    int id;
    char nombreColor[21];
} eColor;

typedef struct
{
    int id;
    char patente[21];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

} eAuto;


/** \brief inicializa los autos
 *
 * \param lista eAuto*
 * \param tam int
 * \return int
 *
 */
int InicializarAutos(eAuto* lista, int tam);

/** \brief busca un espacio libre donde no haya un auto
 *
 * \param lista eAuto*
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eAuto* lista, int tam);

/** \brief da el alta de un nuevo auto
 *
 * \param idX int
 * \param lista eAuto*
 * \param tam int
 * \param marca eMarca*
 * \param tamMarca int
 * \param colores eColor*
 * \param tamColores int
 * \return int
 *
 */
int altaAuto(int idX,eAuto* lista, int tam,eMarca* marca, int tamMarca,eColor* colores,int tamColores);

/** \brief recorre las marcas por id y cargar la descripcion
 *
 * \param tipo[] char
 * \param id int
 * \param tiposMarca eMarca*
 * \param tamMarca int
 * \return int
 *
 */
int cargarDescripcionMarca(char tipo[],int id, eMarca* tiposMarca, int tamMarca);

/** \brief recorre las marcas y las muestra
 *
 * \param tiposMarca eMarca*
 * \param tamMarca int
 * \return void
 *
 */
void mostrarDescripcionMarca(eMarca* tiposMarca,int tamMarca);

/** \brief recorre los colores por id y carga la descripcion
 *
 * \param color[] char
 * \param id int
 * \param colores eColor*
 * \param tamColores int
 * \return int
 *
 */
int cargarDescripcionColor(char color[],int id, eColor* colores, int tamColores);

/** \brief recorre los colores y los muestra
 *
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void mostrarDescripcionColores(eColor* colores,int tamColores);

/** \brief imprime los datos de un auto
 *
 * \param x eAuto
 * \param marca eMarca*
 * \param tamMarcas int
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void mostrarAuto(eAuto x,eMarca* marca,int tamMarcas,eColor* colores, int tamColores);

/** \brief imprime los datos de todos los autos
 *
 * \param x[] eAuto
 * \param tamAutos int
 * \param marca eMarca*
 * \param tamMarca int
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void mostrarAutos(eAuto x[],int tamAutos,eMarca* marca,int tamMarca,eColor* colores, int tamColores);

/** \brief busca un auto indicando la patente
 *
 * \param patente[] char
 * \param vec eAuto*
 * \param tam int
 * \return int
 *
 */
int buscarAutoXpatente(char patente[], eAuto* vec, int tam);

/** \brief modifica los datos de un auto, dichos datos pueden ser modificados ingresando la patente
 *
 * \param vec eAuto*
 * \param tamAutos int
 * \param marcas eMarca*
 * \param tamTipos int
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void modificarAuto(eAuto* vec,int tamAutos,eMarca* marcas,int tamTipos,eColor* colores, int tamColores);

/** \brief se da de baja a un auto, dicha baja se lleva al cabo indicando la patente del auto a dar de baja
 *
 * \param vec eAuto*
 * \param tamAutos int
 * \param marcas eMarca*
 * \param tamTiposMarca int
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void bajaAuto(eAuto* vec,int tamAutos,eMarca* marcas,int tamTiposMarca,eColor* colores, int tamColores);

/** \brief ordena por las respectivas id de las marcas y despues por patente
 *
 * \param vec eAuto*
 * \param tamAutos int
 * \param marcas eMarca*
 * \param tamTiposMarca int
 * \param colores eColor*
 * \param tamColores int
 * \return void
 *
 */
void listarAutos(eAuto* vec,int tamAutos,eMarca* marcas,int tamTiposMarca,eColor* colores, int tamColores);
