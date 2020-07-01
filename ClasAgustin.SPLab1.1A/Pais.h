#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{

    int id;
    char nombre[50];
    int recuperados;
    int infectados;
    int muertos;

}ePais;

#include "LinkedList.h"

#endif // PAIS_H_INCLUDED

ePais* pais_new();

/** \brief crea una estructura tipo ePais y le asigna los valores pasados por parametros a sus campos
 *
 * \param id (tipo char*)
 * \param nombre (tipo char*)
 * \param recuperados (tipo char*)
 * \param infectados (tipo char*)
 * \param muertos (tipo char*)

 * \return estructura ePais con los datos asignados a sus campos o NULL(en caso de que los datos pasados sean erroneos)
 *
 */
ePais* pais_newParametrosStr(char* id, char* nombre,char* recuperados, char* infectados, char* muertos);

/** \brief crea una estructura tipo ePais y le asigna los valores pasados por parametros a sus campos
 *
 * \param id (tipo int)
 * \param nombre (tipo char*)
 * \param recuperados (tipo int)
 * \param infectados (tipo int)
 * \param muertos (tipo int)

 * \return estructura ePais con los datos asignados a sus campos o NULL(en caso de que los datos pasados sean erroneos)
 *
 */
ePais* pais_newParametros(int id, char* nombre,int recuperados, int infectados, int muertos);

int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_setInfectados(ePais* this,int infectados);
int pais_getInfectados(ePais* this,int* infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_getMuertos(ePais* this,int* muertos);

/** \brief muestra los paises cargados en el linkedlist de manera encolumnada
 *
 * \param linkedlist que contiene los datos a mostrar
 *
 */
void listarPaises(LinkedList* this);

/** \brief muestra los datos de la estructura ePais pasada por parametro
 *
 * \param estructura ePais
 *
 */
void listarPais(ePais* auxPais);
