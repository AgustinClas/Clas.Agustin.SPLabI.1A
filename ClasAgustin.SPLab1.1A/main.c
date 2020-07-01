#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controllerPaises.h"
#include "UTN.h"
#include "time.h"

int menu();

int main()
{
    LinkedList* listaInicial = ll_newLinkedList();
    LinkedList* listaEstadisticas = ll_newLinkedList();
    int opcion;
    srand(time(NULL));

    do{
        opcion = menu();

        switch(opcion){
            case 1:
                if(controller_loadFromText("pandemia.csv", listaInicial)){
                    system("cls");
                    printf("Datos cargados con exito\n");
                }else{
                    system("cls");
                    printf("No se pudieron cargar los datos\n");
                }
                break;
            case 2:
                if(ll_isEmpty(listaEstadisticas)){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo y generar la lista de estadisticas\n");
                }else{
                    controller_listarPais(listaEstadisticas);
                }
                break;
            case 3:
                if(ll_isEmpty(listaInicial) ){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo\n");
                }else{
                    listaEstadisticas = controller_mapDatos(listaInicial);
                    if(listaEstadisticas != NULL){
                        system("cls");
                        printf("Lista generada con exito\n");
                    }
                }
                break;
            case 4:
                if(ll_isEmpty(listaEstadisticas)){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo y generar la lista de estadisticas\n");
                }else{
                    if(controller_paisesExitosos(listaEstadisticas)){
                        printf("Archivo generado con exito\n");
                    }else{
                        printf("No se pudo generar el archivo\n");
                    }
                }
                break;
            case 5:
                if(ll_isEmpty(listaEstadisticas)){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo y generar la lista de estadisticas\n");
                }else{
                    system("cls");
                    if(controller_paisesEnElHorno(listaEstadisticas)){
                        printf("Archivo generado con exito\n");
                    }else{
                        printf("No se pudo generar el archivo\n");
                    }
                }
                break;
            case 6:
                if(ll_isEmpty(listaEstadisticas)){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo y generar la lista de estadisticas\n");
                }else{
                    controller_ordenarInfectados(listaEstadisticas);
                }
                break;
            case 7:
                if(ll_isEmpty(listaEstadisticas)){
                    system("cls");
                    printf("Primero debe cargar los datos desde el archivo y generar la lista de estadisticas\n");
                }else{
                    controller_paisMasCastigado(listaEstadisticas);
                }
                break;
        }




    }while(opcion != 8);
}

int menu(){

    int opcion;

    printf("*******PANDEMIA**********\n");
    printf("1. Cargar archivo\n");
    printf("2. Mostrar lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Generar archivo de paises exitosos\n");
    printf("5. Generar archivo de paises en el horno\n");
    printf("6. Mostrar paises ordenados por cantidad de infectados\n");
    printf("7. Pais mas castigado\n");
    printf("8. Salir\n");

    utn_getNumeroEntero(&opcion, "Elija una opcion: ", "Error. ",1,8, 10);

    return opcion;
}


