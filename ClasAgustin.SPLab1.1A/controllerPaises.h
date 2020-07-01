#ifndef CONTROLLERPAISES_H_INCLUDED
#define CONTROLLERPAISES_H_INCLUDED

#include "LinkedList.h"

#endif // CONTROLLERPAISES_H_INCLUDED



/** \brief Parsea los datos de los paises desde el archivo (modo texto).
 *
 * \param nombre del archivo de donde leera los datos
 * \param Linkedlist donde se almacenan los datos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_loadFromText(char* path , LinkedList* this);

/** \brief lista los paises en forma encolumnada
 *
 * \param linkedlist donde estan cargados los paises
 *
 */

void controller_listarPais(LinkedList* this);

/** \brief agrega a los campos muertos, infectados y recuperados de la estructura pais un valor aleatorio
 *
 * \param linkedlist con los id y nombres de los paises
 * \return linkedlist con todos los campos completos o NULL en caso de error
 *
 */

LinkedList* controller_mapDatos(LinkedList* listaInicial);

/** \brief guarda la linkedlist en el archivo (modo texto)
 *
 * \param nombre del archivo
 * \param linkedlist que contiene los datos que seran guardados
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_saveAsText(char* path , LinkedList* this);

/** \brief genera un archivo con los paises con menos de 5000 muertos
 *
 * \param linkedlist de paises
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int controller_paisesExitosos(LinkedList* this);

/** \brief genera un archivo con los paises que su cantidad de infectados triplica la cantidad de recuperados
 *
 * \param linkedlist de paises
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int controller_paisesEnElHorno(LinkedList* this);

/** \brief ordena los paises por cantidad de infectados de manera descendente, los imprime por pantalla y los vuelve a ordenar por id(ascendente)
 *
 * \param linkedlist de paises
 *
 */

void controller_ordenarInfectados(LinkedList* this);

/** \brief muestra el o los paises con mayor cantidad de muertes
 *
 * \param linkedlist de paises
 *
 */

void controller_paisMasCastigado(LinkedList* this);
