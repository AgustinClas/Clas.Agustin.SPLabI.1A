#ifndef PARSERPAISES_H_INCLUDED
#define PARSERPAISES_H_INCLUDED

#include "LinkedList.h"

#endif // PARSERPAISES_H_INCLUDED

/** \brief Parsea los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param archivo de donde leera los datos
 * \param Linkedlist donde se almacenan los datos
 * \return 1 en caso de exito y 0 en caso de error
 *
 */

int parser_paisFromText(FILE* pFile , LinkedList* this);
