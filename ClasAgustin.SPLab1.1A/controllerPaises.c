#include <stdio.h>
#include <stdlib.h>
#include "parserPaises.h"
#include "controllerPaises.h"
#include "Pais.h"

//documentacion correspondiente en "controllerPaises.h"

int controller_loadFromText(char* path , LinkedList* this)
{
    int retorno = 0;
    FILE* pFile;

    system("cls");

    if(this != NULL){
        pFile = fopen(path, "r");

        if(pFile != NULL){
                //Si se pudo abrir el archivo llamamos a parser para que cargue los archivos desde el texto
                if(parser_paisFromText(pFile, this)){
                    retorno = 1;
                }
            }
        fclose(pFile);
        }


    return retorno;
}

void controller_listarPais(LinkedList* this){

    if(this != NULL){
        listarPaises(this);
    }
}

int cargarDatos(void* auxPais){

    int retorno = 0;
    int recuperados = rand()% (950000) + 50000;
    int infectados = rand()% (1960000) + 40000;
    int muertos = rand()% (49000) + 1000;

    if(auxPais != NULL){
        pais_setRecuperados((ePais*)auxPais, recuperados);
        pais_setInfectados((ePais*)auxPais, infectados);
        pais_setMuertos((ePais*)auxPais, muertos);

        retorno = 1;
    }

    return retorno;
}

LinkedList* controller_mapDatos(LinkedList* listaInicial){

    LinkedList* nuevaLista = NULL;

    if(listaInicial != NULL){
        nuevaLista = ll_map(listaInicial, cargarDatos);
    }

    return nuevaLista;
}

int paisesExitosos(void* auxPais){

    int muertes;
    int retorno = 0;

    if(auxPais != NULL){
        pais_getMuertos((ePais*) auxPais, &muertes);

        if(muertes < 5000){
            retorno = 1;
        }
    }

    return retorno;
}

int controller_paisesExitosos(LinkedList* this){

    LinkedList* nuevaLista;
    int retorno = 0;

    if(this != NULL){
        nuevaLista = ll_filter(this, paisesExitosos);

        if(controller_saveAsText("PaisesExitosos.csv", nuevaLista)){
            retorno = 1;
        }

        ll_deleteLinkedList(nuevaLista);
    }

    return retorno;

}

int paisesEnElHorno(void* auxPais){

    int infectados;
    int recuperados;
    int retorno = 0;

    if(auxPais != NULL){
        pais_getRecuperados((ePais*) auxPais, &recuperados);
        pais_getInfectados((ePais*) auxPais, &infectados);

        if(infectados >= (recuperados * 3)){
            retorno = 1;
        }
    }
    return retorno;
}

int controller_paisesEnElHorno(LinkedList* this){

    LinkedList* nuevaLista;
    int retorno = 0;

    if(this != NULL){
        nuevaLista = ll_filter(this, paisesEnElHorno);

        if(nuevaLista != NULL){
            if(controller_saveAsText("PaisesEnElHorno.csv", nuevaLista)){
                retorno = 1;
            }
            if(ll_isEmpty(nuevaLista)){
                printf("No hay paises en el horno!! Que alegria!!\n");
            }
        }

        ll_deleteLinkedList(nuevaLista); // Una vez generado el archivo borramos la linkedlist creada
    }

    ll_deleteLinkedList(nuevaLista);

    return retorno;

}

int sortInfectados(void* pais1, void* pais2){

    int retorno;
    int infectados1;
    int infectados2;

    if(pais_getInfectados((ePais*)pais1, &infectados1) && pais_getInfectados((ePais*) pais2, &infectados2)){
        if(infectados1 > infectados2){
            retorno = 1;
        }else if(infectados1 < infectados2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int sortId(void* pais1, void* pais2){

    int retorno;
    int id1;
    int id2;

    if(pais_getId((ePais*)pais1, &id1) && pais_getId((ePais*)pais2, &id2)){
        if(id1 > id2){
            retorno = 1;
        }else if(id1 < id2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

void controller_ordenarInfectados(LinkedList* this){

    if(this != NULL){
        ll_sort(this, sortInfectados, 0);
        listarPaises(this);
        ll_sort(this, sortId, 1); //despues de imprimir por pantalla la lista volvemos a ordenarla por id
    }

}

void controller_paisMasCastigado(LinkedList* this){

    int muertosMax;
    int auxMuertos;
    ePais* auxPais;
    char nombrePais[50];

    pais_getMuertos((ePais*) ll_get(this, 0), &muertosMax);
    if(this != NULL){
        system("cls");

        for(int i=1;i<ll_len(this);i++){
            pais_getMuertos((ePais*) ll_get(this, i), &auxMuertos);

            if(muertosMax < auxMuertos){
                muertosMax = auxMuertos;
            }
        }

        printf("****Paises con mas muertos****\n");
        for(int i=0; i<ll_len(this); i++){
            auxPais = (ePais*) ll_get(this, i);
            pais_getMuertos(auxPais, &auxMuertos);

            if(muertosMax == auxMuertos){
                pais_getNombre(auxPais, nombrePais);
                printf(" %s\n", nombrePais);
            }
        }
        printf("Cantidad de muertos: %d\n", muertosMax);

    }

}


int controller_saveAsText(char* path , LinkedList* this)
{
    FILE* file;
    ePais* auxPais;
    int id;
    char nombre[50];
    int recuperados;
    int infectados;
    int muertos;
    int retorno = 0;


    if(this != NULL){
        file = fopen(path, "w");
        if(file != NULL){
                fprintf(file,"id,nombre,recuperados,infectados,muertos\n");
            for(int i = 0; i< ll_len(this); i++){
                auxPais = ll_get(this, i);

                pais_getId(auxPais, &id);
                pais_getNombre(auxPais, nombre);
                pais_getRecuperados(auxPais, &recuperados);
                pais_getInfectados(auxPais, &infectados);
                pais_getMuertos(auxPais, &muertos);

                fprintf(file,"%d,%s,%d,%d,%d\n", id, nombre, recuperados, infectados, muertos);
            }
            retorno = 1;
        }
        fclose(file);
    }
    return retorno;
}
