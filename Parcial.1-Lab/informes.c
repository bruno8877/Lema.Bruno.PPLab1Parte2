#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "autos.h"
#include "trabajos.h"
#include "informes.h"

void inicializarMME(eMarcaME listaME[],int tamME)
{
    for(int i=0; i<tamME; i++)
    {
        listaME[i].isEmpty = 1;
    }
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n***** INFORMES AUTOS *****\n");
    printf("-----------------------------------------------------------------------------------------------------|\n");
    printf("1. Informar autos de un color seleccionado                                                           |\n");
    printf("2. Informar autos de una marca seleccionado                                                          |\n");
    printf("3. Informar auto/s mas viejos                                                                        |\n");
    printf("4. Informar autos por marca                                                                          |\n");
    printf("5. Informar autos por marca y color seleccionados                                                    |\n");
    printf("6. Informar la o las marcas mas elegidas                                                             |\n");
    printf("7. Informar todos los trabajos que se le realizaron a un auto seleccionado                           |\n");
    printf("8. Informar la suma de los importes de los trabajos que se le hicieron a un auto seleccionado        |\n");
    printf("9. Informar los autos a los que se realizo un servicio seleccionado y la fecha del mismo             |\n");
    printf("10. Informar todos los servicios realizados en una fecha seleccionada                                |\n");
    printf("11. Salir                                                                                            |\n");
    printf("-----------------------------------------------------------------------------------------------------|");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void informar(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer, eMarcaME* marcaElegida)
{
    char seguir = 's';
    char confirma;

    do
    {
        switch(menuInformes())
        {
        case 1:
            informarAutosColor(autos, tam, colores, tamC, marcas, tamM);
            break;
        case 2:
            informarAutosMarcas(autos, tam, colores, tamC, marcas, tamM);
            break;
        case 3:
            informarAutoMasViejo(autos, tam, colores, tamC, marcas, tamM);
            break;
        case 4:
            informarAutosXMarca(autos, tam, colores, tamC, marcas, tamM);
            break;
        case 5:
            informarAutosPorColorYMarca(autos, tam, colores, tamC, marcas, tamM);
            break;
        case 6:
            informarMarcaMasElegida(autos, tam, colores, tamC, marcas, tamM, marcaElegida);
            break;
        case 7:
            informarTrabajosAuto(autos, tam, colores,tamC,marcas,tamM,trabajos,tamT,servicios,tamSer);
            break;
        case 8:
            informarImporteAuto(autos, tam, colores,tamC,marcas,tamM,trabajos,tamT,servicios,tamSer);
            break;
        case 9:
            informarServicioyFecha(autos,tam,trabajos,tamT,servicios,tamSer);
            break;
        case 10:
            informarFechaServicio(trabajos,tamT,servicios,tamSer);
            break;

        case 11:
            printf("Confirme salida (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');

}

void informarAutosColor(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM)
{
    int flag;
    int auxColor;

    system("cls");
    printf("***** Autos por color especifico *****\n");

    mostrarDescripcionColores(colores, tamC);
    utn_getEntero(&auxColor, 2, "\nIngrese el ID del color de los autos a listar(5000-5004): ", "Error, re-ingrese el id del color", 5000, 5004);

    printf("\nID Auto    Patente          Marca          Color         Modelo    \n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0 ; i < tam; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idColor == auxColor)
        {

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay autos con ese color\n\n");
    }

}

void informarAutosMarcas(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM)
{
    int flag;
    int auxMarca;

    system("cls");
    printf("***** Autos por marca especifica *****\n\n");

    mostrarDescripcionMarca(marcas,tamM);
    utn_getEntero(&auxMarca, 2, "\nIngrese el ID de la marca del auto a listar(1000-1004): ", "Error, re-ingrese el id de la marca", 1000, 1004);

    printf("\nID Auto    Patente          Marca          Color         Modelo    \n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0 ; i < tam; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idMarca == auxMarca)
        {

            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay autos con esa marca\n\n");
    }

}

void informarAutoMasViejo(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM)
{
    int flag = 0;
    int autoMayor =0;

    system("cls");

    for(int i=0; i<tam; i++)
    {
        if(autos[i].isEmpty == 0)
        {
            if(autos[i].modelo<autoMayor || flag==0)
            {
                autoMayor=autos[i].modelo;
                flag=1;
            }
        }

    }

    printf("***** INFORMAR AUTOS MAS VIEJOS *****\n");
    printf("\nID Auto    Patente          Marca          Color         Modelo    \n");
    printf("-----------------------------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        if(autos[i].modelo == autoMayor)
        {
            mostrarAuto(autos[i], marcas, tamM, colores, tamC);
        }
    }
}
void informarAutosXMarca(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM)
{
    int flag=0;

    system("cls");
    printf("***** INFORME AUTOS POR MARCA *****\n");

    printf("\nID Auto    Patente          Marca          Color         Modelo    \n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0 ; i < tamM; i++)
    {
        printf("\nMarca: %s\n",marcas[i].nombreMarca);
        printf("-----------\n");
        for(int j=0; j<tam; j++)
        {
            if(autos[j].isEmpty == 0 && autos[j].idMarca == marcas[i].id)
            {

                mostrarAuto(autos[j], marcas, tamM, colores, tamC);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay autos con esa marca\n\n");
        }
        printf("-----------------------------------------------------------------\n");
    }

}

void informarAutosPorColorYMarca(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM)
{
    int flag=0;
    int auxMarca;
    int color;
    int contAutos = 0;

        mostrarDescripcionMarca(marcas,tamM);
        utn_getEntero(&auxMarca,2,"Ingrese la marca: ","Error. Reingrese la marca\n",1000,1004);

        mostrarDescripcionColores(colores,tamC);
        utn_getEntero(&color,2,"Ingrese el color: ","Error. Reingrese el color\n",5000,5004);

            system("cls");
            printf("***** INFORMAR AUTOS POR COLOR Y MARCA *****\n");
            printf("\nID Auto    Patente          Marca          Color         Modelo    \n");
            printf("-----------------------------------------------------------------\n");

            for(int i=0; i<tam; i++)
            {
                if(autos[i].isEmpty == 0 && autos[i].idMarca == auxMarca && autos[i].idColor ==color)
                {
                    mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                    flag=1;
                    contAutos++;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay autos que listar con ese color y marca\n\n");
            }





    if(flag)
    {
        printf("\n\nLa cantidad de autos del color y marca ingresada son: %d\n\n",contAutos);
    }
}

void informarMarcaMasElegida(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eMarcaME* listaME)
{
    int contadorM;
	int mActual = 0;
	int flag = 0;
	int indice;
	eMarcaME auxMME;

	for(int m = 0; m < tamM; m++)
	{
		contadorM = 0;

		for(int a = 0; a < tam; a++)
		{
			if(!(autos[a].isEmpty) && autos[a].idMarca == marcas[m].id)
			{
				contadorM++;
			}
		}


        //listaME[mActual].isEmpty = 0;
		listaME[mActual].idMarca = marcas[m].id;
		listaME[mActual].cantidad = contadorM;

		mActual++;

	}

	for(int j = 0; j < tamM; j++)
	{
		if(!flag)
		{
			auxMME = listaME[j];
			flag = 1;
		}
		else if(listaME[j].cantidad > auxMME.cantidad && listaME[j].idMarca > 0)
		{
			auxMME = listaME[j];
		}
	}

    system("cls");
	printf("***** INFORMAR MARCA/S MAS ELEGIDA/S *****");
	printf("\n-------------------------------------------\n");
	printf("Listado de marcas mas elegidas: \n");
	printf("ID Marcas    Descripcion\n");

	for(int i = 0; i < tamM; i++)
	{
		if(auxMME.cantidad == listaME[i].cantidad && listaME[i].idMarca > 0)
		{
			indice = buscarMarca(listaME[i].idMarca, marcas, tamM);
			mostrarMarca(marcas[indice]);
		}
	}
}

int buscarMarca(int idMarca, eMarca* marcas, int tamMarcas)
{
	int indice = -1;

	for(int i = 0; i < tamMarcas; i++)
	{
		if(marcas[i].id == idMarca)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

void mostrarMarca(eMarca marca)
{

    printf(" %d     %10s     \n",marca.id,marca.nombreMarca);

}

void informarTrabajosAuto(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer)
{
    char auxPatente[20];
    int indice;

    system("cls");

    printf("\n **** Trabajos que se hicieron al auto ****\n\n");
    mostrarAutos(autos, tam, marcas, tamM, colores, tamC);
    printf("\n");

    //Se pide la patente
    printf("Ingrese patente(Mayusculas): ");
    scanf("%s", auxPatente);

    indice = buscarAutoXpatente(auxPatente, autos, tam);

    if(indice == -1)
    {
        printf("Error, no hay registro de un auto con la patente ingresada\n");
    }
    else
    {
        printf("\n**** Trabajos que se le realizaron al auto ****\n");
        printf("-------------------------------------------\n");
        printf("ID SERV     PATENTE        SERVICIO      PRECIO        FECHA\n");

        for(int i=0; i<tamT; i++)
        {
            if(!(strcmp(trabajos[i].patente, auxPatente)))
            {
                mostrarTrabajo(trabajos[i], servicios, tamSer);
            }
        }
    }
}

void informarImporteAuto(eAuto* autos, int tam, eColor* colores, int tamC, eMarca* marcas, int tamM, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer)
{
    char auxPatente[20];
    int indice;
    float precioTotal = 0;

    system("cls");

    printf("**** Importe de los trabajos hechos a un auto ****\n");
    mostrarAutos(autos, tam, marcas, tamM, colores, tamC);
    printf("\n");

    //Se pide la patente
    printf("Ingrese patente (Mayusculas): ");
    scanf("%s", auxPatente);

    indice = buscarAutoXpatente(auxPatente, autos, tam);

    if(indice == -1)
    {
        printf("*** No hay registro de un auto con la patente ingresada ***\n");
    }
    else
    {
        for(int i=0; i<tamT; i ++)
        {
            for(int j=0; j<tamSer; j++)
            {
                if(trabajos[i].idServicio == servicios[j].id && !(strcmp(trabajos[i].patente, autos[indice].patente)))
                {
                    precioTotal = precioTotal + servicios[j].precio;
                }
            }
        }

        printf("El importe total de ese auto es: $%.2f\n", precioTotal);
    }

}

void informarServicioyFecha(eAuto* autos, int tam, eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer)
{
    int auxIdS;
    int flag=0;

    system("cls");

    mostrarDescripcionServicios(servicios,tamSer);

    printf("\n");

    utn_getEntero(&auxIdS,2, "Ingrese servicio (20000-20003): ", "\nError. Reingrese el servicio\n", 20000, 20003);

    printf("**** Informe del servicio seleccionado ****\n");
    printf("ID SERV     PATENTE        SERVICIO      PRECIO        FECHA\n");
    printf("-----------------------------------------------------------------\n");

    for(int i =0;i<tamSer;i++)
    {
        for(int j=0;j<tamT;j++)
        {
            if(auxIdS == servicios[i].id && trabajos[j].idServicio == auxIdS)
            {
                mostrarTrabajo(trabajos[j],servicios,tamSer);
                flag =1;
            }
        }
    }
    if(flag == 0)
    {
        printf(" *** No hay registro de un auto con el servicio ingresado ***\n");
    }


}


void informarFechaServicio(eTrabajo* trabajos, int tamT, eServicio* servicios, int tamSer)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    int flag = 0;

    system("cls");

    printf("**** Servicios realizados en una fecha especifica ****\n");

    mostrarTrabajos(trabajos, tamT, servicios, tamSer);

    printf("Ingrese fecha del servicio dd/mm/aaaa\n");
    utn_getEntero(&auxDia,2,"Ingrese Dia: ","Error. Dia invalido.", 1, 31);
    utn_getEntero(&auxMes,2,"Ingrese Mes: ","Error. Mes invalido", 1, 12);
    utn_getEntero(&auxAnio,2,"Ingrese Anio: ","Error. Anio invalido.", 2019, 2023);

    system("cls");

    printf(" \n*** Los servicios realizados en la fecha %d/%d/%d son: ***\n", auxDia, auxMes, auxAnio);
    printf("ID SERV     PATENTE        SERVICIO      PRECIO        FECHA\n");
    printf("-----------------------------------------------------------------\n");

    for(int i=0; i<tamT; i++)
    {
        if(auxDia == trabajos[i].fecha.dia && auxMes == trabajos[i].fecha.mes && auxAnio == trabajos[i].fecha.anio)
        {
            mostrarTrabajo(trabajos[i], servicios, tamSer);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf(" ***No hay registro de un trabajo realizado en la fecha ingresada***\n");
    }

}
