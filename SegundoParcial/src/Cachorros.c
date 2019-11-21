#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cachorros.h"


static int isValidId(int *id);
static int isValidIdString(char *id);
static int isValidNombre(char *nombre);
static int isValidDias(int *dias);
static int isValidDiasString(char *dias);
static int isValidRaza(char *raza);
static int isValidReservado(char *reservado);
static int isValidGenero(char *genero);


Cachorro* cachorro_new()
{
	return malloc(sizeof(Cachorro));
}

void cachorro_delete(Cachorro *this)
{
	free(this);
}

int cachorro_setId(Cachorro* this,int id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidId(&id) == EXIT_SUCCESS)
	{
		this->id=id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getId(Cachorro* this,int* id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidId(int *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		if(id > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int cachorro_setIdString(Cachorro *this,char *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidIdString(id)==EXIT_SUCCESS)
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidIdString(char *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		//if(esSoloNumerosPositivos(id,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
		//}
	}

	return retorno;
}

int cachorro_setNombre(Cachorro *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidNombre(nombre)==EXIT_SUCCESS)
	{
		strcpy(this->nombre,nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getNombre(Cachorro *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidNombre(char *nombre)
{
	int retorno = EXIT_ERROR;

	if(nombre != NULL)
	{
		//esNombreOApellido(nombre,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_setDias(Cachorro* this,int dias)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidDias(&dias) == EXIT_SUCCESS)
	{
		this->dias=dias;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getDias(Cachorro* this,int* dias)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && dias != NULL)
	{
		*dias=this->dias;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidDias(int *dias)
{
	int retorno = EXIT_ERROR;

	if(dias != NULL)
	{
		if(dias >= 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int cachorro_setDiasString(Cachorro *this,char *dias)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidDiasString(dias)==EXIT_SUCCESS)
	{
		this->dias=atoi(dias);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidDiasString(char *dias)
{
	int retorno = EXIT_ERROR;

	if(dias != NULL)
	{
		//if(esSoloNumerosPositivos(dias,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
			//}
	}

	return retorno;
}

int cachorro_setRaza(Cachorro *this,char *raza)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidRaza(raza)==EXIT_SUCCESS)
	{
		strcpy(this->raza,raza);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getRaza(Cachorro *this,char *raza)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza,this->raza);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidRaza(char *raza)
{
	int retorno = EXIT_ERROR;

	if(raza != NULL)
	{
		//esNombreOApellido(raza,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_setReservado(Cachorro *this,char *reservado)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidReservado(reservado)==EXIT_SUCCESS)
	{
		strcpy(this->reservado,reservado);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getReservado(Cachorro *this,char *reservado)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && reservado != NULL)
	{
		strcpy(reservado,this->reservado);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidReservado(char *reservado)
{
	int retorno = EXIT_ERROR;

	if(reservado != NULL)
	{
		//esNombreOApellido(reservado,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_setGenero(Cachorro *this,char *genero)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidGenero(genero)==EXIT_SUCCESS)
	{
		strcpy(this->genero,genero);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int cachorro_getGenero(Cachorro *this,char *genero)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && genero != NULL)
	{
		strcpy(genero,this->genero);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidGenero(char *genero)
{
	int retorno = EXIT_ERROR;

	if(genero != NULL)
	{
		//esNombreOApellido(genero,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}


Cachorro* cachorro_buscaPorId(LinkedList* pArrayListCachorro,int id)
{
	Cachorro* this = NULL;
	int i;

	if(pArrayListCachorro!=NULL && id>0)
	{
		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			this = ll_get(pArrayListCachorro,i);
			if(this->id == id)
			{
				return this;
			}
		}
	}
	return this;
}

int cachorro_ordenoPorId(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(((Cachorro*)pElementUno)->id > ((Cachorro*)pElementDos)->id)
	{
		retorno = 1;
	}
	if(((Cachorro*)pElementUno)->id < ((Cachorro*)pElementDos)->id)
	{
		retorno = -1;
	}

	return retorno;
}

int cachorro_ordenoPorDias(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(((Cachorro*)pElementUno)->dias > ((Cachorro*)pElementDos)->dias)
	{
		retorno = 1;
	}
	if(((Cachorro*)pElementUno)->dias < ((Cachorro*)pElementDos)->dias)
	{
		retorno = -1;
	}

	return retorno;
}

int cachorro_ordenoPorNombre(void* pElementUno,void* pElementDos)
{
	int retorno = 0;

	if(strncmp(((Cachorro *)pElementUno)->nombre,((Cachorro *)pElementDos)->nombre,CANT_CARACTERES)>0)
	{
		retorno = 1;
	}
	if(strncmp(((Cachorro *)pElementUno)->nombre,((Cachorro *)pElementDos)->nombre,CANT_CARACTERES)<0)
	{
		retorno = -1;
	}

	return retorno;
}

int cachorro_filtrarListaMenores45dias(void* p)
{
	int retorno = -1;

	if(p != NULL)
	{
		if(((Cachorro*)p)->dias >= 45)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}

int cachorro_filtrarListaPorMacho(void* p)
{
	int retorno = -1;

	if(p != NULL)
	{
		if(strncmp(((Cachorro *)p)->genero,"H",CANT_CARACTERES)==0)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}

int cachorro_filtrarListaPorCallejero(void* p)
{
	int retorno = -1;

	if(p != NULL)
	{
		if(strncmp(((Cachorro *)p)->raza,"Callejero",CANT_CARACTERES)==0)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}
