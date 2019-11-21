#ifndef cachorro_H_INCLUDED
#define cachorro_H_INCLUDED

#include "LinkedList.h"
#include "utn.h"

#define CANT_CARACTERES 128


typedef struct
{
    int id;
    char nombre[128];
    int dias;
    char raza[128];
    char reservado[128];
    char genero[128];
}Cachorro;

Cachorro* cachorro_new();
void cachorro_delete();

int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* id);
int cachorro_setIdString(Cachorro *this,char *id);

int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* nombre);

int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* dias);
int cachorro_setDiasString(Cachorro *this,char *dias);

int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_getRaza(Cachorro* this,char* raza);

int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* reservado);

int cachorro_setGenero(Cachorro* this,char* genero);
int cachorro_getGenero(Cachorro* this,char* genero);

Cachorro* cachorro_buscaPorId(LinkedList* pArrayListCachorro,int id);
int cachorro_ordenoPorId(void* pElementUno,void* pElementDos);
int cachorro_ordenoPorDias(void* pElementUno,void* pElementDos);
int cachorro_ordenoPorNombre(void* pElementUno,void* pElementDos);
int cachorro_filtrarListaMenores45dias(void* p);
int cachorro_filtrarListaPorMacho(void* p);
int cachorro_filtrarListaPorCallejero(void* p);

#endif // cachorro_H_INCLUDED
