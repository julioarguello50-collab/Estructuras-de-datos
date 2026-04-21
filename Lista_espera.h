#ifndef LISTA_ESPERA_H
#define LISTA_ESPERA_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"

//Funcion para listas de espera por tipo de consulta

void LISTA_ESPERA_VACUNACION(FichaVacunacion **nuevo_V,FichaVacunacion **frente_V){
    for((*nuevo_V) = *frente_V; (*nuevo_V) != NULL; (*nuevo_V) = (*nuevo_V) -> sig){
        printf("Nombre completo: %s %s\nEdad: %d\n",(*nuevo_V) -> nombre, (*nuevo_V) -> apellidos,(*nuevo_V) -> edad);
        printf("Numero de ficha %d\n\n",(*nuevo_V) -> no_Ficha);
    }
}

void LISTA_ESPERA_PRENATAL(FichaControlPrenatal **nuevo_P,FichaControlPrenatal **frente_P){
    for((*nuevo_P) = *frente_P; (*nuevo_P) != NULL; (*nuevo_P) = (*nuevo_P) -> sig){
        printf("Nombre completo: %s %s\nEdad: %d\n",(*nuevo_P) -> nombre, (*nuevo_P) -> apellidos,(*nuevo_P) -> edad);
        printf("Numero de ficha: %d\n\n",(*nuevo_P) -> no_Ficha);
    }
}

void LISTA_ESPERA_PREARTERIAL(FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA){
    for((*nuevoPA) = *frentePA; (*nuevoPA) != NULL; (*nuevoPA) = (*nuevoPA) -> sig){
        printf("Nombre completo: %s %s\nEdad: %d\n",(*nuevoPA) -> nombre,(*nuevoPA) -> apellidos,(*nuevoPA) -> edad);
        printf("Numero de fichas: %d\n\n",(*nuevoPA) -> no_Ficha);
    }
}

void LISTA_ESPERA_CRONICOS(FichaEnferCronica **nuevoEC, FichaEnferCronica **frenteEC){
    for((*nuevoEC) = *frenteEC; (*nuevoEC) != NULL; (*nuevoEC) = (*nuevoEC) -> sig){
        printf("Nombre completo: %s %s\nEdad: %d\n",(*nuevoEC) -> nombre,(*nuevoEC) -> apellidos,(*nuevoEC) -> edad);
        printf("Numero de fichas: %d\n\n",(*nuevoEC) -> no_Ficha);
    }
}

void LISTA_ESPERA_OTROSSERVICIOS(OtroServicios **nuevoOS,OtroServicios **frenteOS){
    for((*nuevoOS) = *frenteOS;(*nuevoOS) != NULL;(*nuevoOS) = (*nuevoOS) -> sig){
            printf("Nombre completo: %s %s\nSintomas/Causas: %s",(*nuevoOS) -> nombre,(*nuevoOS) -> apellidos,(*nuevoOS) -> sintomas);
            printf("\nEdad: %d\nNumero de fichas: %d\n\n",(*nuevoOS) -> edad,(*nuevoOS) -> no_Ficha);
    }
}
#endif