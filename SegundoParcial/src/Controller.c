#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"

#include "Cachorros.h"
#include "parser.h"

#define CRITERIO_ASCENDENTE 1
#define CRITERIO_DESCENDENTE 0

/** \brief Carga los datos de los cachorros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	FILE* pFile;

	pFile = fopen(path,"r");
	if(pFile != NULL && pArrayListCachorro != NULL)
	{
		if(ll_len(pArrayListCachorro) == 0)
		{
			if(parser_CachorroFromText(pFile,pArrayListCachorro)==EXIT_SUCCESS)
			{
				printf("\nCarga Exitosa. Tamaño linkedList %d\n",ll_len(pArrayListCachorro));
				retorno=EXIT_SUCCESS;
			}
			else
			{
				printf("\nNo se pudo cargar el archivo.\n");
			}
		}
		else
		{
			printf("\nLa Lista ya se encuentra cargada.\n");
		}
	}

	fclose(pFile);

    return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
/*int controller_addCachorro(LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int id;
	char nombre[1000];
	int horasTrabajadas;
	int sueldo;
	Cachorro* this;

	if(pArrayListCachorro != NULL)
	{
		id=buscarUltimoIdGenerandoSiguiente(pArrayListCachorro);
		getString(nombre,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
		retorno = esNombreOApellido(nombre,"No es un nombre valido");
		if(retorno==EXIT_SUCCESS)
		{
			if(getValidIntFromString(&horasTrabajadas,"\nIngrese Cant. Horas Trabajadas: ","\nError",1,CANT_HORAS,CANT_REINTENTOS)==EXIT_SUCCESS)
			{
				if(getValidIntFromString(&sueldo,"\nIngrese Sueldo: ","\nError",1,CANT_SUELDO,CANT_REINTENTOS)==EXIT_SUCCESS)
				{
					this = cachorro_new();
					if(this != NULL)
					{
						cachorro_setId(this,id);
						cachorro_setNombre(this,nombre);
						cachorro_setHorasTrabajadas(this,horasTrabajadas);
						cachorro_setSueldo(this,sueldo);
						ll_add(pArrayListCachorro,this);
						retorno = EXIT_SUCCESS;
					}
					else
					{
						cachorro_delete(this);
						printf("\nNo fue posible agregar empleado\n");
					}
				}
			}
		}

	}

    return retorno;
}*/

/** \brief Busca el ultimo ID y genera el siguiente
 *
 * \param pArrayListCachorro LinkedList*
 * \return int EXIT_ERROR (-1) si el llist es NULL o el siguiente ID a utilizar
 *
 */

int buscarUltimoIdGenerandoSiguiente(LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int i;
	int ultId = 0;
	Cachorro* this;

	if(pArrayListCachorro != NULL)
	{
		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			this = ll_get(pArrayListCachorro,i);
			if(this->id > ultId)
			{
				ultId=this->id;
			}
		}
		retorno = ultId+1;
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
/*int controller_editCachorro(LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int opcion;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[1000];
	char confirmarModif;
	Cachorro* this;

	if(pArrayListCachorro!=NULL)
	{
		getValidIntFromString(&id,"\nIngrese ID a modificar: ","\nError",1,buscarUltimoIdGenerandoSiguiente(pArrayListCachorro)-1,CANT_REINTENTOS);
		this = cachorro_buscaPorId(pArrayListCachorro,id);
		if(this != NULL)
		{
			printf("Quiere Modificar el siguiente empleado: \n");
			printf("\nID: %d\n",this->id);
			printf("Nombre: %s\n",this->nombre);
			printf("Horas Trabajadas: %d\n",this->horasTrabajadas);
			printf("Sueldo: %d\n",this->sueldo);
			getChar(&confirmarModif,
			"\nSeguro desea Modificar? Ingrese s (o cualquier tecla para continuar sin modificar): ",
			"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
			'a',
			'z',
			CANT_REINTENTOS);
			if(confirmarModif == 's')
			{
				if(getInt(&opcion, "\n\nQue desea modificar: [1]Nombre [2]HorasTrabajadas [3]Sueldo: ", "\nError", 1, 3,CANT_REINTENTOS) == 0)
				{
					switch(opcion)
					{
					case 1:
						getString(nombre,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
						retorno = esNombreOApellido(nombre,"No es un nombre valido");
						if(retorno==EXIT_SUCCESS)
						{
							cachorro_setNombre(this,nombre);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					case 2:
						if(getValidIntFromString(&horasTrabajadas,"\nIngrese Cant. Horas Trabajadas: ","\nError",1,CANT_HORAS,CANT_REINTENTOS)==EXIT_SUCCESS)
						{
							cachorro_setHorasTrabajadas(this,horasTrabajadas);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					case 3:
						if(getValidIntFromString(&sueldo,"\nIngrese Sueldo: ","\nError",1,CANT_SUELDO,CANT_REINTENTOS)==EXIT_SUCCESS)
						{
							cachorro_setSueldo(this,sueldo);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					}
				}
			}
			else
			{
				printf("\n\nMODIFICACION CANCELADA\n\n");
			}
		}
		else
		{
			printf("\nNo hay datos en el empleado\n\n");
		}
	}
    return retorno;
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
/*int controller_removeCachorro(LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int id;
	int indice;
	char confirmarBaja;
	Cachorro* this;

	if(pArrayListCachorro!=NULL)
	{
		getValidIntFromString(&id,"\nIngrese ID a dar de baja: ","\nError",1,buscarUltimoIdGenerandoSiguiente(pArrayListCachorro)-1,CANT_REINTENTOS);
		this = cachorro_buscaPorId(pArrayListCachorro,id);
		if(this != NULL)
		{
			printf("Quiere Modificar el siguiente empleado: \n");
			printf("\nID: %d\n",this->id);
			printf("Nombre: %s\n",this->nombre);
			printf("Horas Trabajadas: %d\n",this->horasTrabajadas);
			printf("Sueldo: %d\n",this->sueldo);
			getChar(&confirmarBaja,
			"\nSeguro desea dar de Baja? Ingrese s (o cualquier tecla para continuar sin eliminar): ",
			"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
			'a',
			'z',
			CANT_REINTENTOS);
			if(confirmarBaja == 's')
			{
				indice = ll_indexOf(pArrayListCachorro,this);
				ll_remove(pArrayListCachorro,indice);
				retorno = EXIT_SUCCESS;
				printf("\n\nBaja exitosa. Tamaño del Array %d\n\n",pArrayListCachorro->size);
			}
			else
			{
				printf("\n\nBAJA CANCELADA\n\n");
			}
		}
		else
		{
			printf("\nNo hay datos en el empleado\n\n");
		}
	}
    return retorno;
}*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
	int i;
	Cachorro* aux;

	if(pArrayListCachorro!=NULL)
	{
		printf("\n%4s %15s %10s %15s %10s %10s\n","ID","NOMBRE","DIAS","RAZA","RESERVADO","GENERO");
		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			aux = ll_get(pArrayListCachorro,i);
			printf("%4d %15s %10d %15s %10s %10s\n",aux->id,aux->nombre,aux->dias,aux->raza,aux->reservado,aux->genero);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
/*int controller_sortCachorro(LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int opcion;
	int criterio;

	if(pArrayListCachorro != NULL)
	{
		if(getInt(&opcion, "\n\nComo desea ordenar: [1]Id [2]Nombre [3]HorasTrabajadas [4]Sueldo: ", "\nError", 1, 4,CANT_REINTENTOS) == 0)
		{
			switch(opcion)
			{
			case 1:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorId,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorId,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 2:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorNombre,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorNombre,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 3:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorHorasTrabajadas,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorHorasTrabajadas,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 4:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorSueldo,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListCachorro,cachorro_ordenoPorSueldo,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			retorno = EXIT_SUCCESS;
			}
		}
	}

    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCachorro)
{
	int retorno = EXIT_ERROR;
	int i;
	Cachorro* this;
	FILE* pFile = NULL;

	pFile = fopen(path,"w");
	if(pFile != NULL && pArrayListCachorro != NULL && ll_len(pArrayListCachorro)>0)
	{
		fprintf(pFile,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			this = ll_get(pArrayListCachorro,i);
			if(this != NULL)
			{
				fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",this->id,this->nombre,this->dias,this->raza,this->reservado,this->genero);
			}
		}
		printf("\nEl archivo se guardo correctamente\n");
		retorno=EXIT_SUCCESS;
	}
	fclose(pFile);


    return retorno;
}



