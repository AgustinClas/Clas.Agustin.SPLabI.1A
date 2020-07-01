#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Pais.h"

//documentacion correspondiente en "Pais.h"

ePais* pais_new(){
    ePais* this = (ePais*) malloc (sizeof(ePais));

    return this;
}

ePais* pais_newParametrosStr(char* id, char* nombre,char* recuperados, char* infectados, char* muertos){

    ePais* auxPais;

    auxPais = pais_newParametros(atoi(id),nombre, atoi(recuperados), atoi(infectados), atoi(muertos));

    return auxPais;
}

ePais* pais_newParametros(int id, char* nombre,int recuperados, int infectados, int muertos){

    ePais* this = pais_new();

    if(this != NULL ){
            //en caso de que algun set devuelva 0(errpr) le asignamos el valor NULL a la estructura que devolvera la funcion
            if(!(pais_setId(this, id) &&
                 pais_setNombre(this, nombre) &&
                 pais_setRecuperados(this, recuperados) &&
                 pais_setInfectados(this, infectados) &&
                 pais_setMuertos(this, muertos))){
                this = NULL;
            }
    }


    return this;
}

int pais_setId(ePais* this,int id){

    int todoOk = 0;

    if(this != NULL && id > 0){
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int pais_getId(ePais* this,int* id){

    int todoOk = 0;

    if(this != NULL && id != NULL){
        *id = this->id;
        todoOk=1;
    }

    return todoOk;
}

int pais_setNombre(ePais* this,char* nombre){

    int todoOk = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) > 1 && strlen(nombre) < 50){

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int pais_getNombre(ePais* this,char* nombre){

    int todoOk = 0;

    if(this != NULL && nombre != NULL ){

        strcpy(nombre,this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int pais_setRecuperados(ePais* this,int recuperados){

    int todoOk = 0;

    if(this != NULL ){
        this->recuperados = recuperados;
        todoOk = 1;
    }

    return todoOk;
}


int pais_getRecuperados(ePais* this,int* recuperados){

    int todoOk = 0;

    if(this != NULL && recuperados != NULL){
        *recuperados = this->recuperados;
        todoOk=1;
    }

    return todoOk;
}

int pais_setInfectados(ePais* this,int infectados){

    int todoOk = 0;

    if(this != NULL ){
        this->infectados = infectados;
        todoOk = 1;
    }

    return todoOk;
}


int pais_getInfectados(ePais* this,int* infectados){

    int todoOk = 0;

    if(this != NULL && infectados != NULL){
        *infectados = this->infectados;
        todoOk=1;
    }

    return todoOk;
}

int pais_setMuertos(ePais* this,int muertos){

    int todoOk = 0;

    if(this != NULL){
        this->muertos = muertos;
        todoOk = 1;
    }

    return todoOk;
}


int pais_getMuertos(ePais* this,int* muertos){

    int todoOk = 0;

    if(this != NULL && muertos != NULL){
        *muertos = this->muertos;
        todoOk=1;
    }

    return todoOk;
}

void listarPaises(LinkedList* this){

    ePais* auxPais;

    system("cls");

    //no es necesario verificar que this sea distinto de null (lo hace el controller)

    printf("Id          Nombre        Recuperados       Infectados       Muertos\n");
    for(int i=0; i<ll_len(this);i++){
        auxPais = (ePais*) ll_get(this, i);
        if(auxPais != NULL){
        listarPais(auxPais);
        }
    }

}


void listarPais(ePais* auxPais){

    int id;
    char nombre[50];
    int recuperados;
    int infectados;
    int muertos;

    pais_getId(auxPais, &id);
    pais_getNombre(auxPais, nombre);
    pais_getRecuperados(auxPais, &recuperados);
    pais_getInfectados(auxPais, &infectados);
    pais_getMuertos(auxPais, &muertos);

    printf("%2d   %15s         %d            %d        %d\n", id, nombre, recuperados, infectados, muertos);
}


