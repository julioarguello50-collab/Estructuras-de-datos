#ifndef Consultorios_H
#define Consultorios_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
#include"registros.h"

//funciones para imprimir pacientes por consultas

//funcion para imprimir pacientes por consulta de vacunacion

void Consulta_Vacunacion(FichaVacunacion **frente_V,FichaVacunacion **historial_V,int *num_V){
    printf("\nFicha: %d\n",(*frente_V) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frente_V) -> nombre,(*frente_V) -> apellidos);
    (*frente_V) -> no_Ficha = -1;
    FichaVacunacion *temp = *frente_V;
    *frente_V = (*frente_V) -> sig;

    temp -> sig = *historial_V;
    *historial_V = temp;
    
    (*num_V)--;
}

void Consulta_Prenatal(FichaControlPrenatal **frente_P,FichaControlPrenatal **historial_P,FichaControlPrenatal **temp_P,int *num_P){
    printf("\nFicha: %d\n",(*frente_P) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frente_P) -> nombre,(*frente_P) -> apellidos);
    (*frente_P) -> no_Ficha = -1;
    (*temp_P) = *frente_P;
    *frente_P = (*frente_P) -> sig;

    (*temp_P) -> sig = *historial_P;
    *historial_P = *temp_P;
    (*num_P)--;
}

void Consulta_PreArterial(FichaPresionArterial **frentePA,FichaPresionArterial **historial_PA,FichaPresionArterial **temp_PA,int *num_PA){
    printf("\nFicha: %d\n",(*frentePA) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frentePA) -> nombre,(*frentePA) -> apellidos);
    (*frentePA) -> no_Ficha = -1;
    (*temp_PA) = *frentePA;
    *frentePA = (*frentePA) -> sig;
    (*temp_PA) -> sig = *historial_PA;
    *historial_PA = *temp_PA;
    (*num_PA)--;
}

void Consulta_EnferCronica(FichaEnferCronica **frenteEC,FichaEnferCronica **historial_EC,FichaEnferCronica **temp_EC,int *num_EC){
    printf("\nFicha: %d\n",(*frenteEC) -> no_Ficha);
    printf("Nombre: %s %s\n\n",(*frenteEC) -> nombre,(*frenteEC) -> apellidos);
    (*frenteEC) -> no_Ficha = -1;
    (*temp_EC) = *frenteEC;
    *frenteEC = (*frenteEC) -> sig;
    (*temp_EC) -> sig = *historial_EC;
    *historial_EC = *temp_EC;
    (*num_EC)--;
}
#endif