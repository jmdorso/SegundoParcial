#include <stdio.h>
#include <stdlib.h>

#include "Cachorros.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los cachorros desde el archivo cachorros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_CachorroFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int contVar;
	char id[256];
	char nombre[256];
	char dias[256];
	char raza[256];
	char reservado[256];
	char genero[256];
	int flag=0;
	Cachorro* this;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			contVar = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			if(flag==0)
			{
				flag=1;
			}
			else if(contVar == 6 && flag == 1)
			{
				this = cachorro_new();
				if(this != NULL)
				{
					cachorro_setIdString(this, id);
					cachorro_setNombre(this,nombre);
					cachorro_setDiasString(this,dias);
					cachorro_setRaza(this,raza);
					cachorro_setReservado(this,reservado);
					cachorro_setGenero(this,genero);
					ll_add(pArrayListEmployee,this);
					//printf("\nCARGA EXITOSA\n");
					retorno = EXIT_SUCCESS;
				}

			}
		}
	}

    return retorno;
}

