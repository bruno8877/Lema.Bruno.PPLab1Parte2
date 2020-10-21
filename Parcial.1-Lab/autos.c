#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "autos.h"

int InicializarAutos(eAuto* lista, int tam)
{
    int TODOok = 1;
    if(lista !=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty =1;

        }
        TODOok =0;
    }

    return TODOok;
}
//----------------------------------------------------------------------------------------------------------
int buscarLibre(eAuto* lista, int tam)
{
    int indice = -1;

    for(int i =0; i< tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//----------------------------------------------------------------------------------------------------------
//alta
int altaAuto(int idX,eAuto* lista, int tam,eMarca* marca, int tamMarca,eColor* colores,int tamColores)
{
    int TODOok = 1;
    int indice;
    eAuto auxAuto;

    indice = buscarLibre(lista, tam);

    if(indice == -1)
    {
        printf("Sistema Completo...\n\n");
    }
    else
    {
        auxAuto.id = idX;
        printf("Ingrese patente: ");
        fflush(stdin);
        scanf("%s", auxAuto.patente);

        printf("\n");
        mostrarDescripcionMarca(marca,tamMarca);
        utn_getEntero(&auxAuto.idMarca,2, "Ingrese la marca (1000-1004): ", "\nError. Reingrese la marca\n", 1000, 1004);

        printf("\n");
        mostrarDescripcionColores(colores,tamColores);
        utn_getEntero(&auxAuto.idColor,2, "Ingrese el color (5000-5004): ", "\nError. Reingrese el color\n", 5000, 5004);

        utn_getEntero(&auxAuto.modelo,2,"ingrese el modelo del auto (1990-2020):", "\nError. Reingrese el modelo del auto\n", 1990,2020);

        auxAuto.isEmpty = 0;

        lista[indice] = auxAuto;
        TODOok = 0;

        printf("\n*Alta excitosa*\n\n");
    }


    return TODOok;
}
//----------------------------------------------------------------------------------------------------------
int cargarDescripcionMarca(char tipo[],int id, eMarca* tiposMarca, int tamMarca)
{
    int todoOK = 0;

    for(int i=0; i<tamMarca; i++)
    {
        if(tiposMarca[i].id==id)
        {
            strcpy(tipo,tiposMarca[i].nombreMarca);
            todoOK = 1;
        }
    }

    return todoOK;
}

void mostrarDescripcionMarca(eMarca* tiposMarca,int tamMarca)
{

    printf("\n**** Listado de Marcas ****\n");
    printf("---------------------------");
    printf("\nid        Descripcion\n");

    for(int i=0; i<tamMarca; i++)
    {
        printf("%d      %10s\n",tiposMarca[i].id,tiposMarca[i].nombreMarca);
    }

}
//----------------------------------------------------------------------------------------------------------

int cargarDescripcionColor(char color[],int id, eColor* colores, int tamColores)
{
    int todoOK = 0;

    for(int i=0; i<tamColores; i++)
    {
        if(colores[i].id==id)
        {
            strcpy(color,colores[i].nombreColor);
            todoOK = 1;
        }
    }

    return todoOK;
}

void mostrarDescripcionColores(eColor* colores,int tamColores)
{

    printf("\n**** Listado de colores ****\n");
    printf("-----------------------------");
    printf("\nid          Descripcion\n");

    for(int i=0; i<tamColores; i++)
    {
        printf("%d      %10s\n",colores[i].id,colores[i].nombreColor);
    }

}

//----------------------------------------------------------------------------------------------------------
//muestro autos

void mostrarAuto(eAuto x,eMarca* marca,int tamMarcas,eColor* colores, int tamColores)
{
    char nombreTipoMarca[21];
    char nombreColor[21];

    cargarDescripcionMarca(nombreTipoMarca,x.idMarca,marca,tamMarcas);
    cargarDescripcionColor(nombreColor,x.idColor,colores,tamColores);

    printf("%2d     %10s      %10s     %10s        %6d   \n",x.id,x.patente,nombreTipoMarca,nombreColor,x.modelo);

}

void mostrarAutos(eAuto x[],int tamAutos,eMarca* marca,int tamMarca,eColor* colores, int tamColores)
{
    int flag=0;
    system("cls");
    printf("\n***** LISTADO DE AUTOS *****\n");
    printf("------------------------------------------------------------");
    printf("\n ID       PATENTE           MARCA          COLOR          MODELO \n");

    for(int i=0; i<tamAutos; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarAuto(x[i],marca,tamMarca,colores,tamColores);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay auto que listar...\n\n");
    }

}
//----------------------------------------------------------------------------------------------------------
int buscarAutoXpatente(char patente[], eAuto* vec, int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if((strcmp(vec[i].patente, patente)) == 0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
//----------------------------------------------------------------------------------------------------------
//modificar auto

void modificarAuto(eAuto* vec,int tamAutos,eMarca* marcas,int tamTipos,eColor* colores, int tamColores)
{
    int indice;
    char patente[20];
    char confirma;
    int auxInt;
    int opcion;

    system("cls");
    mostrarAutos(vec, tamAutos, marcas, tamTipos, colores,tamColores);
    printf("\n***** MODIFICAR AUTO *****\n");

    printf("Ingrese patente : ");
    scanf("%s", patente);

    indice = buscarAutoXpatente(patente,vec,tamAutos);

    if(indice == -1)
    {
        printf("Error. No hay registro de un auto con esa patente: %s\n", patente);

    }
    else
    {
        printf("\n");
        printf("El auto a modificar es: ");
        mostrarAuto(vec[indice], marcas, tamTipos,colores,tamColores);
        printf("\nEsta seguro de modificar? (s para si/ n para no)\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            do
            {
                system("cls");
                mostrarAutos(vec, tamAutos, marcas, tamTipos, colores,tamColores);
                printf("\n*** Que desea modificar? ***  \n");
                printf("    1. Color\n");
                printf("    2. Modelo\n");
                printf("    3. Volver al menu inicial \n");
                printf("\nElija una opcion\n");
                scanf("%d", &opcion);

                switch(opcion)
                {
                    case 1:
                    mostrarDescripcionColores(colores,tamColores);
                    utn_getEntero(&auxInt,2, "Ingrese el nuevo color (5000-5004): ", "\nError. Reingrese el tipo\n", 5000, 5004);
                    vec[indice].idColor=auxInt;
                    printf("\nSe ha actualizado el color con exito...\n\n");
                    system("pause");
                    break;
                case 2:
                    utn_getEntero(&auxInt,2,"Ingrese el nuevo modelo (1990-2020):", "\nError. Reingrese el nuevo modelo\n", 1990,2020);
                    vec[indice].modelo=auxInt;
                    printf("\nSe ha actualizado el modelo con exito..\n\n");
                    system("pause");
                    break;
                case 3:
                    opcion=3;
                    printf("Volviendo al menu inicial... \n");
                    break;

                default:
                    printf("No es una opcion valida.\n\n");
                }

            }while(opcion != 3);
        }
    }
}
//----------------------------------------------------------------------------------------------------------

//baja de auto
void bajaAuto(eAuto* vec,int tamAutos,eMarca* marcas,int tamTiposMarca,eColor* colores, int tamColores)
{
    int indice;
    char patente[20];
    char confirma;


    system("cls");
    mostrarAutos(vec, tamAutos, marcas, tamTiposMarca, colores,tamColores);
    printf("\n***** BAJA AUTO *****\n");

     printf("Ingrese patente : ");
    scanf("%s", patente);


    indice = buscarAutoXpatente(patente,vec,tamAutos);

    if(indice == -1)
    {
        printf("Error. No hay registro de un auto con esa patente: %s\n", patente);

    }
    else
    {
        printf("\n");
        printf("El auto a dar de baja es: ");
        mostrarAuto(vec[indice],marcas,tamTiposMarca,colores,tamColores);

        printf("Confirma la baja?(s para si/ n para no): ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }
}
//----------------------------------------------------------------------------------------------------------
//listar autos por marca y patente
void listarAutos(eAuto* vec,int tamAutos,eMarca* marcas,int tamTiposMarca,eColor* colores, int tamColores)
{
    eAuto auxAuto;

    for(int i=0; i<tamAutos; i++)
    {
        for(int j=i+1; j<tamAutos; j++)
        {
            if(vec[i].idMarca>vec[j].idMarca)
            {
                auxAuto=vec[i];
                vec[i]=vec[j];
                vec[j]=auxAuto;
            }
            else
            {
                if(vec[i].idMarca==vec[j].idMarca && strcmp(vec[i].patente, vec[j].patente) > 0)
                {
                    auxAuto=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxAuto;
                }
            }

        }
    }
    system("cls");
    mostrarAutos(vec,tamAutos,marcas,tamTiposMarca,colores,tamColores);
}
