#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "autos.h"
#include "trabajos.h"

//----------------------------------------------------------------------------------------------------------
void mostrarDescripcionServicios(eServicio* servicios,int tamServicio)
{

    printf("\n***** Listado de servicios *****\n");
    printf("id        Descripcion     Precio \n");

    for(int i=0; i<tamServicio; i++)
    {
        printf("%d      %10s      $%2.f \n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }

}

float cargarDescripcionServicio(char servicio[],float* precio,int id, eServicio servicios[], int tamServicios)
{
    int todoOK = 0;

    for(int i=0; i<tamServicios; i++)
    {
        if(servicios[i].id==id)
        {
            strcpy(servicio,servicios[i].descripcion);
            *precio=servicios[i].precio;
            todoOK = 1;
        }
    }

    return todoOK;
}
//----------------------------------------------------------------------------------------------------------
void inicializarTrabajos(eTrabajo* vec,int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarLibreTrabajo(eTrabajo* vec,int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

//----------------------------------------------------------------------------------------------------------

//alta trabajo
int altaTrabajo(int idX,eTrabajo* vec, int tamTrabajo,eServicio* servicios,int tamServicios,eAuto* list, int tamAutos,eMarca* marcas,int tamMarcas,eColor* colores,int tamColores)
{
     int TODOok = 1;
    int indice;

    eTrabajo auxTrabajo;
    indice = buscarLibreTrabajo(vec, tamTrabajo);

    if(indice == -1)
    {
        printf("Sistema Completo...\n\n");
    }
    else
    {
        auxTrabajo.id = idX;

        mostrarAutos(list, tamAutos, marcas,tamMarcas,colores,tamColores);

        printf("Ingrese patente : ");
        fflush(stdin);
        scanf("%s", auxTrabajo.patente);

        indice = buscarAutoXpatente(auxTrabajo.patente,list,tamAutos);
        if(indice == -1)
        {
            printf("No hay registro de un auto con esa patente\n");
        }
        else
        {
        mostrarDescripcionServicios(servicios,tamServicios);
        utn_getEntero(&auxTrabajo.idServicio,2, "Ingrese servicio (20000-20003): ", "\nError. Reingrese el servicio\n", 20000, 20003);

        utn_getEntero(&auxTrabajo.fecha.dia,2,"Ingrese el dia(del 1 al 31) :", "\nError. Reingrese el dia\n", 1,31);

        utn_getEntero(&auxTrabajo.fecha.mes,2,"Ingrese el mes(del 1 al 12) :", "\nError. Reingrese el mes\n", 1,12);

        utn_getEntero(&auxTrabajo.fecha.anio,2,"Ingrese el anio(del 2019 al 2023) :", "\nError. Reingrese el anio\n", 2019,2023);

        printf("\n");

        auxTrabajo.isEmpty = 0;

        vec[indice] = auxTrabajo;
        TODOok = 0;

        printf("\n*Alta excitosa*\n\n");

        }

    }


    return TODOok;
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajo(eTrabajo x,eServicio servicios[], int tamServicios)
{
    char nombreServicio[21];
    float precioServicio;

    cargarDescripcionServicio(nombreServicio,&precioServicio,x.idServicio,servicios,tamServicios);

    printf(" %d      %s       %10s      $%.2f       %d/%d/%d \n",x.idServicio,x.patente,nombreServicio,precioServicio,x.fecha.dia,x.fecha.mes,x.fecha.anio);
}

void mostrarTrabajos(eTrabajo x[],int tamTrabajos,eServicio servicios[],int tamServicios)
{
    int flag=0;
    system("cls");
    printf("\n*****LISTADO DE TRABAJOS *****\n");
    printf("ID SERV     PATENTE        SERVICIO       PRECIO         FECHA \n");

    for(int i=0; i<tamTrabajos; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarTrabajo(x[i],servicios,tamServicios);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay trabajos que listar\n\n");
    }
}
