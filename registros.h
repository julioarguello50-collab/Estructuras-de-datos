#ifndef REGISTROS_H
#define REGISTROS_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"

//Funcion para registrar pacientes del tipo de vacunacion
void registrarPacienteVacunacion(FichaVacunacion **nuevo, FichaVacunacion **frente, FichaVacunacion **ultimo,int *num_v,int *pacientes_Vacunacion){
    (*num_v)++;
    (*pacientes_Vacunacion)++;
    printf("\nDigite el nombre del paciente\n");
    scanf("%s",(*nuevo) -> nombre );
    printf("\nDigite los apellidos del paciente\n");
    scanf("%s",(*nuevo) -> apellidos);
    (*nuevo) -> no_Ficha = (*num_v);
    if(*frente == NULL){
        *frente = *nuevo;
    }else{
        (*ultimo) -> sig = *nuevo;
    }
    (*nuevo) -> sig = NULL;
    *ultimo = *nuevo;
                
    printf("\n\nVacunacion\nNombre completo: %s %s\n",(*nuevo) -> nombre,(*nuevo) -> apellidos);
    printf("Numero de ficha: %d\n\n",(*nuevo) -> no_Ficha);
}

//Funcion para registrar pacientes del tipo de control prenatal
void registrarPacienteConPrenatal(FichaControlPrenatal **nuevo_P, FichaControlPrenatal **frente_P, FichaControlPrenatal **ultimo_P,int *num_P,int *pacientes_Prenatal){
    (*num_P)++;
    (*pacientes_Prenatal)++;
    printf("\nDigite el nombre del paciente\n");
    scanf("%s",(*nuevo_P) -> nombre);
    printf("\nDigite los apellidos del paciente\n");
    scanf("%s",(*nuevo_P) -> apellidos);
    (*nuevo_P) -> no_Ficha = (*num_P);
    if(*frente_P == NULL){
        *frente_P = *nuevo_P;
    }else{
        (*ultimo_P) -> sig = *nuevo_P;
    }
    (*nuevo_P) -> sig = NULL;
    *ultimo_P = *nuevo_P;

    printf("\n\nControl Prenatal\nNombre completo: %s %s\n",(*nuevo_P) -> nombre,(*nuevo_P) -> apellidos);
    printf("Numero de ficha: %d\n\n",(*nuevo_P) ->no_Ficha);
}

//Funcion para regsitrar pacientes del tipo presion arterial
void registrarPaciente_PresionAr(FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA,FichaPresionArterial **ultimoPA,int *num_PA,int *pacientes_Arterial){
    (*num_PA)++;
    (*pacientes_Arterial)++;
    printf("\nDigite el nombre del paciente\n");
    scanf("%s",(*nuevoPA) -> nombre);
    printf("\nDigite los apellidos del paciente\n");
    scanf("%s",(*nuevoPA) -> apellidos);
    (*nuevoPA) -> no_Ficha = (*num_PA);
    if(*frentePA == NULL){
        *frentePA = *nuevoPA;
    }else{
        (*ultimoPA) -> sig = *nuevoPA;
    }
    (*nuevoPA) -> sig = NULL;
    *ultimoPA = *nuevoPA;

    printf("\n\nPresion arterial\nNombre completo: %s %s\n",(*nuevoPA) -> nombre,(*nuevoPA) -> apellidos);
    printf("Numero de ficha: %d\n\n",(*nuevoPA) -> no_Ficha);
}

//Funcion para registrar pacientes del tipo de enfermedades cronicas
void registrarPaciente_Cronico(FichaEnferCronica **nuevoEC,FichaEnferCronica **frenteEC,FichaEnferCronica **ultimoEC,int *num_EC,int *pacientes_Cronicos){
    (*num_EC)++;
    (*pacientes_Cronicos)++;
    printf("\nDigite el nombre del paciente\n");
    scanf("%s",(*nuevoEC) -> nombre);
    printf("\nDigite los apellidos del paciente\n");
    scanf("%s",(*nuevoEC) -> apellidos);
    (*nuevoEC) -> no_Ficha = (*num_EC);
    if(*frenteEC == NULL){
        *frenteEC = *nuevoEC;
        (*nuevoEC) -> sig = NULL;
    }else{
        (*ultimoEC) -> sig = *nuevoEC;
        (*nuevoEC) -> sig = NULL;
    }
    
    *ultimoEC = *nuevoEC;

    printf("\n\nEnfermedades cronicas\nNombre completo: %s %s\n",(*nuevoEC) -> nombre,(*nuevoEC) -> apellidos);
    printf("Numero de ficha: %d\n\n",(*nuevoEC) -> no_Ficha);
}

#endif
