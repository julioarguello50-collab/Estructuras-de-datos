#ifndef Consultorios_H
#define Consultorios_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
#include"registros.h"

//funciones para imprimir pacientes por consultas

//funcion para imprimir pacientes por consulta de vacunacion

void Consulta_Vacunacion(FichaVacunacion **frente_V,FichaVacunacion **historial_V,FichaVacunacion **temp,FichaVacunacion **historial_ultimoV){
    printf("\nFicha: %d\n",(*frente_V) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frente_V) -> nombre,(*frente_V) -> apellidos);
    (*frente_V) -> atendido = 1;
     *temp = *frente_V;
    *frente_V = (*frente_V) -> sig;

    if(*historial_V == NULL){
        *historial_V = *temp;
        *historial_ultimoV = *temp;
    }else{
        (*historial_ultimoV) -> sig = *temp;
    }

    (*temp) -> sig = NULL;
    (*historial_ultimoV)  = *temp;
}

void Consulta_Prenatal(FichaControlPrenatal **frente_P,FichaControlPrenatal **historial_P,FichaControlPrenatal **temp_P,FichaControlPrenatal **historial_ultimoP){
    printf("\nFicha: %d\n",(*frente_P) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frente_P) -> nombre,(*frente_P) -> apellidos);
    (*frente_P) -> atendido = 1;
    (*temp_P) = *frente_P;
    *frente_P = (*frente_P) -> sig;

    if(*historial_P == NULL){
        *historial_P = *temp_P;
        *historial_ultimoP = *temp_P;
    }else{
        (*historial_ultimoP) -> sig = *temp_P;
    }

    (*temp_P) -> sig = NULL;
    *historial_ultimoP = *temp_P;
}

void Consulta_PreArterial(FichaPresionArterial **frentePA,FichaPresionArterial **historial_PA,FichaPresionArterial **temp_PA,FichaPresionArterial **historial_ultimoPA){
    printf("\nFicha: %d\n",(*frentePA) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frentePA) -> nombre,(*frentePA) -> apellidos);
    (*frentePA) -> atendido = 1;
    (*temp_PA) = *frentePA;
    *frentePA = (*frentePA) -> sig;

    if(*historial_PA == NULL){
        *historial_PA = *temp_PA;
        *historial_ultimoPA = *temp_PA;
    }else{
        (*historial_ultimoPA) -> sig = *temp_PA;
    }

    (*temp_PA) -> sig = NULL;
    *historial_ultimoPA = *temp_PA;
}

void Consulta_EnferCronica(FichaEnferCronica **frenteEC,FichaEnferCronica **historial_EC,FichaEnferCronica **temp_EC,FichaEnferCronica ** historial_ultimoEC){
    printf("\nFicha: %d\n",(*frenteEC) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frenteEC) -> nombre,(*frenteEC) -> apellidos);
    (*frenteEC) -> atendido = 1;
    (*temp_EC) = *frenteEC;
    *frenteEC = (*frenteEC) -> sig;

    if(*historial_EC == NULL){
        *historial_EC = *temp_EC;
        *historial_ultimoEC = *temp_EC;
    }else{
        (*historial_ultimoEC) -> sig = *temp_EC;
    }

    (*temp_EC) -> sig = NULL;
    *historial_ultimoEC = *temp_EC;

}
#endif