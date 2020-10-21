#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "trabajos.h"
#include "informes.h"
#include "hardcod.h"

#define TAMTIPO 5
#define TAMAUTOS 11
#define TAMCOLORES 5
#define TAMSERVICIOS 4
#define TAMTRABAJOS 11
#define TAMHARDCODEOAUTOS 11
#define TAMHARDCODEOTRABAJOS 11

void hardcodAuto(eAuto vec[], int tam);
void hardcodearTrabajos(eTrabajo vec[], int tam);


int main()
{
    int opcion;
    int flag = 0;
    eAuto listaAutos[TAMAUTOS];
    eTrabajo listaTrabajos[TAMTRABAJOS];


    int proximoIdAuto = 1;
    int proximoIdTrabajo = 21000;



    eMarca tipoMarca[TAMTIPO]= {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"},{1003, "Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMCOLORES] = {{5000, "Negro"}, {5001, "Blanco"},{5002, "Gris"},{5003,"Rojo"},{5004, "Azul"}};
    eServicio servicios[TAMSERVICIOS] = {{20000, "Lavado",250}, {20001, "Pulido",300}, {20002, "Encerado",400},{20003, "Completo",600}};

    eMarcaME marcaMasElegida[TAMTIPO];

    InicializarAutos(listaAutos,TAMAUTOS);
    inicializarTrabajos(listaTrabajos,TAMTRABAJOS);
    inicializarMME(marcaMasElegida,TAMTIPO);

    //HARDCODEO
    proximoIdAuto += TAMHARDCODEOAUTOS;
    proximoIdTrabajo += TAMHARDCODEOTRABAJOS;
    hardcodAuto(listaAutos,TAMHARDCODEOAUTOS);
    hardcodearTrabajos(listaTrabajos,TAMHARDCODEOTRABAJOS);


    do
    {
        printf("\n****** MENU DE OPCIONES ******\n");
        printf("-------------------------------------------------------------|");
        printf("\n1. Alta                                                      |\n");
        printf("2. Modificar auto                                            |\n");
        printf("3. Baja de auto                                              |\n");
        printf("4. Listar autos por patente y marcas                         |\n");//los ordena de acuerdo a sus respectivos ids(ej: primero los renault, despues los fiat, despues los ford etc)
        printf("5. Listar marcas                                             |\n");
        printf("6. Listar colores                                            |\n");
        printf("7. Listar servicios                                          |\n");
        printf("8. Alta trabajo                                              |\n");
        printf("9. Listar trabajos                                           |\n");
        printf("10. Informes                                                 |\n");
        printf("11. Salir                                                    |\n");
        printf("-------------------------------------------------------------|");
        printf("\nElija una opcion\n");
        scanf("%d", &opcion);



        switch(opcion)
        {
        case 1://ALTA

            system("cls");


            if(altaAuto(proximoIdAuto,listaAutos,TAMAUTOS,tipoMarca,TAMTIPO,colores,TAMCOLORES)== 0)
            {
                proximoIdAuto++;
                printf("\n");
                mostrarAutos(listaAutos, TAMAUTOS, tipoMarca, TAMTIPO, colores,TAMCOLORES);

            }
            flag = 1;


            break;

        case 2://MODIFICACION
            if(flag == 1)
            {
                mostrarAutos(listaAutos, TAMAUTOS, tipoMarca, TAMTIPO, colores,TAMCOLORES);
                printf("\n");
                modificarAuto(listaAutos,TAMAUTOS,tipoMarca,TAMTIPO,colores,TAMCOLORES);

            }
            else
            {
                printf("\nNo hay autos cargados\n");


            }
            break;

        case 3://BAJA
            if(flag == 1)
            {
                system("cls");
                printf("\n");
                bajaAuto(listaAutos, TAMAUTOS,tipoMarca,TAMTIPO,colores,TAMCOLORES);
                mostrarAutos(listaAutos, TAMAUTOS, tipoMarca, TAMTIPO, colores,TAMCOLORES);

            }
            else
            {
                printf("\nNo hay autos cargados\n");


            }
            break;

        case 4://listar autos ordenadas por marca y patente
            if(flag == 1)
            {

                listarAutos(listaAutos,TAMAUTOS,tipoMarca,TAMAUTOS,colores,TAMCOLORES);

            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;

        case 5://listar marca
            if(flag == 1)
            {

                mostrarDescripcionMarca(tipoMarca,TAMTIPO);

            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;

        case 6://listar colores
            if(flag == 1)
            {

                mostrarDescripcionColores(colores,TAMCOLORES);

            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;

        case 7://listar servicios
            if(flag == 1)
            {

                mostrarDescripcionServicios(servicios,TAMSERVICIOS);

            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;


        case 8://alta trabajos
            if(flag)
            {
                if(altaTrabajo(proximoIdTrabajo,listaTrabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,listaAutos,TAMAUTOS,tipoMarca,TAMTIPO,colores,TAMCOLORES))
                {
                    proximoIdTrabajo++;
                    printf("\n");
                    //mostrarAutos(listaAutos, TAMAUTOS, tipoMarca, TAMTIPO, colores,TAMCOLORES);
                    flag = 1;
                }

            }


            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;


        case 9://listar trabajos
            if(flag == 1)
            {

                mostrarTrabajos(listaTrabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);

            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;

        case 10://informes
            if(flag == 1)
            {
                informar(listaAutos, TAMAUTOS, colores, TAMCOLORES, tipoMarca, TAMTIPO, listaTrabajos, TAMTRABAJOS, servicios, TAMSERVICIOS, marcaMasElegida);


            }
            else
            {
                printf("\nPara poder listar, primero tiene que hacer un alta\n");


            }
            break;

        case 11://Salir
            opcion=11;
            printf("Saliendo... \n");
            break;

        default:
            printf("Error. Por favor elija una opcion valida.\n");
            break;

        }
        system("pause");//pone pausa
        system("cls");//limpia la consola


    }
    while(opcion != 11);




    return 0;



}

void hardcodAuto(eAuto vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].id = idAutos[i];
        vec[i].idMarca = idMarca[i];
        vec[i].idColor = idColor[i];
        vec[i].modelo = modelos[i];
        strcpy(vec[i].patente, patentes[i]);
		vec[i].isEmpty = 0;
	}
}

void hardcodearTrabajos(eTrabajo vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
        vec[i].id = idsTrabajos[i];
        strcpy(vec[i].patente, patentes1[i]);
        vec[i].idServicio = idsServicios[i];
        vec[i].fecha.dia = dias[i];
        vec[i].fecha.mes = meses[i];
        vec[i].fecha.anio = anios[i];
		vec[i].isEmpty = 0;
	}
}

