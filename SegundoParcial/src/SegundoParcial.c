/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Cachorros.h"
#include "utn.h"

int main(void) {

	int option;
	//int optionCarga;
	char seguir='S';
	char guardar;
	char path[128];
	LinkedList *listaCachorros = ll_newLinkedList();
	LinkedList *listaCachorrosMenores45;
	LinkedList *ListaCachorrosSinMachos;
	LinkedList *listaCachorrosCallejeros;

	do {
		printf("----------------------------------------------------------------------------------\n");
		printf("\tSegundo Parcial. Uso LinkedList || Juan Martin Dorso\n\n");
		printf("01. Cargar los datos de los cachorros desde el archivo cachorros.csv (modo texto).\n");
		printf("02. Imprimir lista.\n");
		printf("03. Filtrar menores de 45 dias.\n");
		printf("04. Filtrar machos.\n");
		printf("05. Generar Listado de 'callejeros'.\n");
		printf("06. Salir.\n\n");

		if (getInt(&option, "\tIngrese opcion: ", "\nError", 1, 6,CANT_REINTENTOS) == 0)
		{
			switch (option)
			{
			case 1:
				getString(path,"\n\nIngrese nombre Archivo: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS == 0);
				//getInt(&optionCarga, "\t\nIngrese opcion: [1]cachorrosOriginal [2]cachorrosModificado: ", "\nError", 1, 2,CANT_REINTENTOS);
				//if(optionCarga==1)
				if(strncmp(path,"cachorrosORIGINAL.csv",CANT_CARACTERES)==0)
				{
					controller_loadFromText("cachorrosORIGINAL.csv", listaCachorros);
				}
				//if(optionCarga==2)
				else if(strncmp(path,"cachorros.csv",CANT_CARACTERES)==0)
				{
					controller_loadFromText("cachorros.csv", listaCachorros);
				}
				else
				{
					printf("\n\nIngreso Nombre Incorrecto\n\n");
				}
				break;
			case 2:
				controller_ListCachorro(listaCachorros);
				break;
			case 3:
				listaCachorrosMenores45 = ll_filter(listaCachorros,cachorro_filtrarListaMenores45dias);
				controller_saveAsText("cachorrosMayores45.csv",listaCachorrosMenores45);
				break;
			case 4:
				ListaCachorrosSinMachos = ll_filter(listaCachorros,cachorro_filtrarListaPorMacho);
				controller_saveAsText("cachorrosSinMachos.csv",ListaCachorrosSinMachos);
				break;
			case 5:
				listaCachorrosCallejeros = ll_filter(listaCachorros,cachorro_filtrarListaPorCallejero);
				controller_ListCachorro(listaCachorrosCallejeros);
				break;
			case 6:
				getChar(&guardar,
				"\nDesea guardar antes de salir? Ingrese s o n (o cualquier tecla para seguir en el programa): ",
				"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
				'a',
				'z',
				CANT_REINTENTOS);
	           	if(guardar == 's' || guardar == 'S')
	           	{
	           		controller_saveAsText("cachorros.csv",listaCachorros);
	               	ll_deleteLinkedList(listaCachorros);
	               	printf("\n\n\tDatos guardados. El programa se cerrara...");
	               	seguir = 'n';
	    		}
	           	else if(guardar == 'n' || guardar == 'N')
	           	{
	           		ll_deleteLinkedList(listaCachorros);
	    			printf("\n\n\tNo se guardaran los datos. El programa se cerrara...\n");
	    			seguir='n';
	           	}
	           	else
	           	{
	           		printf("\n\n\tContinuar con el programa..\n");
	           	}
				break;
			}
		}
	} while (seguir == 'S');



	return EXIT_SUCCESS;
}
