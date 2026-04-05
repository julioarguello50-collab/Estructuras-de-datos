#ifndef LISTA_ESPERA_H
#define LISTA_ESPERA_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
//codigo por hacer

//Funcion para listas de espera por tipo de consulta

void LISTA_ESPERA_VACUNACION(FichaVacunacion **nuevo_V,FichaVacunacion **frente_V){
    for((*nuevo_V) = *frente_V; (*nuevo_V) != NULL; (*nuevo_V) = (*nuevo_V) -> sig){
        printf("Nombre completo: %s %s\n",(*nuevo_V) -> nombre, (*nuevo_V) -> apellidos);
        printf("Numero de ficha %d\n\n",(*nuevo_V) -> no_Ficha);
    }
}

void LISTA_ESPERA_PRENATAL(FichaControlPrenatal **nuevo_P,FichaControlPrenatal **frente_P){
    for((*nuevo_P) = *frente_P; (*nuevo_P) != NULL; (*nuevo_P) = (*nuevo_P) -> sig){
        printf("Nombre completo: %s %s\n",(*nuevo_P) -> nombre, (*nuevo_P) -> apellidos);
        printf("Numero de ficha: %d\n\n",(*nuevo_P) -> no_Ficha);
    }
}

void LISTA_ESPERA_PREARTERIAL(FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA){
    for((*nuevoPA) = *frentePA; (*nuevoPA) != NULL; (*nuevoPA) = (*nuevoPA) -> sig){
        printf("Nombre completo: %s %s\n",(*nuevoPA) -> nombre,(*nuevoPA) -> apellidos);
        printf("Numero de fichas: %d\n\n",(*nuevoPA) -> no_Ficha);
    }
}

void LISTA_ESPERA_CRONICOS(FichaEnferCronica **nuevoEC, FichaEnferCronica **frenteEC){
    for((*nuevoEC) = *frenteEC; (*nuevoEC) != NULL; (*nuevoEC) = (*nuevoEC) -> sig){
        printf("Nombre completo: %s %s\n",(*nuevoEC) -> nombre,(*nuevoEC) -> apellidos);
        printf("Numero de fichas: %d\n\n",(*nuevoEC) -> no_Ficha);
    }
}
#endif