/*
 * utn.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				__fpurge(stdin); //fflush en windows
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			__fpurge(stdin); //fflush en windows
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getFloat(	float *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			__fpurge(stdin); //fflush en windows
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getChar(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			__fpurge(stdin); //fflush en windows
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int esNombreOApellido(char *pResultado,char *pMensajeError)
{
	int retorno = EXIT_ERROR;
	int posArray=0;

	while(pResultado[posArray] != '\0')
	{
		if((pResultado[posArray] != ' ') && (pResultado[posArray] < 'a' || pResultado[posArray] > 'z') &&
			(pResultado[posArray] < 'A' || pResultado[posArray] > 'Z'))
		{
			printf("%s",pMensajeError);
			retorno = EXIT_ERROR;
			break;
		}
		posArray++;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

int esSoloNumeros(char *pResultado,char *pMensajeError)
{
	int retorno = EXIT_ERROR;
	int posArray=0;

	while(pResultado[posArray] != '\0')
	{
		if(posArray == 0 && pResultado[posArray] == '-')
		{
			posArray++;
			continue;
		}
		if(pResultado[posArray] < '0' || pResultado[posArray] > '9')
		{
			printf("%s",pMensajeError);
			retorno = EXIT_ERROR;
			break;
		}
		posArray++;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

int esSoloNumerosPositivos(char *pResultado,char *pMensajeError)
{
	int retorno = EXIT_ERROR;
	int posArray=0;

	while(pResultado[posArray] != '\0')
	{
		if(posArray == 0 && pResultado[posArray] == '-')
		{
			printf("%s",pMensajeError);
			break;
		}
		if(pResultado[posArray] < '0' || pResultado[posArray] > '9')
		{
			printf("%s",pMensajeError);
			retorno = EXIT_ERROR;
			break;
		}
		posArray++;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

int esSoloNumerosFlotantes(char *pResultado,char *pMensajeError)
{
	int retorno = EXIT_ERROR;
	int posArray=0;
	int cantPuntos = 0;

	while(pResultado[posArray] != '\0')
	{
		if(posArray == 0 && pResultado[posArray] == '-')
		{
			posArray++;
			continue;
		}
		if((pResultado[posArray] == '.' || pResultado[posArray] == ',') && cantPuntos == 0)
		{
			pResultado[posArray] = '.';
			cantPuntos++;
			posArray++;
			continue;
		}
		if(pResultado[posArray] < '0' || pResultado[posArray] > '9')
		{
			printf("%s",pMensajeError);
			retorno = EXIT_ERROR;
			break;
		}
		posArray++;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

int esAlfaNumerico(char *pResultado,char *pMensajeError)
{
	int retorno = EXIT_ERROR;
	int posArray=0;

	while(pResultado[posArray] != '\0')
	{
		if((pResultado[posArray] != ' ') && (pResultado[posArray] < 'a' || pResultado[posArray] > 'z') &&
			(pResultado[posArray] < 'A' || pResultado[posArray] > 'Z') && (pResultado[posArray] < '0' || pResultado[posArray] > '9'))
		{
			printf("%s",pMensajeError);
			retorno = EXIT_ERROR;
			break;
		}
		posArray++;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

int getValidIntFromString(	int *pResultado,
							char *pMensaje,
							char *pMensajeError,
							int minimo,
							int maximo,
							int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[4096];
	int auxInt;
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			if(getString(buffer,pMensaje,pMensajeError,1,50,reintentos)==EXIT_SUCCESS)
			{
				if(esSoloNumeros(buffer,pMensajeError)==EXIT_SUCCESS)
				{
					auxInt = atoi(buffer);
					if(auxInt >= minimo && auxInt <= maximo)
					{
						*pResultado = auxInt;
						retorno = EXIT_SUCCESS;
						break;
					}
					else
					{
						printf("%s","El numero no esta dentro del rango");
					}
				}
			}
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getValidFloatFromString(	float *pResultado,
								char *pMensaje,
								char *pMensajeError,
								int minimo,
								int maximo,
								int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[4096];
	float auxFloat;
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			if(getString(buffer,pMensaje,pMensajeError,1,50,reintentos)==EXIT_SUCCESS)
			{
				if(esSoloNumerosFlotantes(buffer,pMensajeError)==EXIT_SUCCESS)
				{
					auxFloat = atof(buffer);
					if(auxFloat >= minimo && auxFloat <= maximo)
					{
						*pResultado = auxFloat;
						retorno = EXIT_SUCCESS;
						break;
					}
					else
					{
						printf("%s","El numero no esta dentro del rango");
					}
				}
			}
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
