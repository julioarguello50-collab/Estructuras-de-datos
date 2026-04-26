#ifndef INCIDENCIA_CONSULTORIO_H
#define INCIDENCIA_CONSULTORIO_H
#include<stdio.h>
#include<string.h>
#include"estructuras.h"

void Incidencia_Consultorio_Anterior_Vacunacion(incidencia **nuevo_Incidencia,incidencia **inicio_incidencia,incidencia **temp_incidencia,incidencia **historial_incidencia,PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa,FichaVacunacion **frente_V){
    getchar();
    strcpy((*nuevoBase) -> nombre,(*nuevo_Incidencia) -> nombre_Anterior);
    strcpy((*nuevoBase) -> apellidos,(*nuevo_Incidencia) -> apellidos_anteriores);

    strcpy((*inicio_incidencia) -> Nuevo_nombre,(*nuevo_Incidencia) -> nombre_Anterior);
    strcpy((*inicio_incidencia) ->nuevos_apellidos ,(*nuevo_Incidencia) -> apellidos_anteriores);
    
    (*nuevoBase) ->edad = (*nuevo_Incidencia) -> edad_Original;
    (*inicio_incidencia) -> edad_nueva = (*nuevo_Incidencia) -> edad_Original;
    (*inicio_incidencia) -> no_Ficha = (*nuevo_Incidencia) -> no_Ficha;
    (*nuevoBase) ->consultorioAnterior = 1;

    if(*inicio == NULL){
        *inicio = *nuevoBase;
        *final = *nuevoBase;
    }else{
        (*final) -> sig = *nuevoBase;
        *final = *nuevoBase;
    }
    (*nuevoBase) -> sig = NULL;
    *tempBa = *nuevoBase;

    *frente_V = (*frente_V)->sig;

    printf("Describa brevemente el motivo de la correccion: ");
    fgets((*inicio_incidencia)->modificacion,50,stdin);
    (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion,"\n")] = '\0';
    (*nuevo_Incidencia)->sig = *inicio_incidencia;
    *inicio_incidencia = *nuevo_Incidencia;
    printf("\nPara hacer cambio de consultorio dirigase al caso 4 del menu principal\n");

    *temp_incidencia = *inicio_incidencia;
    (*inicio_incidencia) = (*inicio_incidencia) -> sig;

    (*temp_incidencia) ->  sig = *historial_incidencia;
    *historial_incidencia = *temp_incidencia;
}

void Incidencia_Consultorio_Anterior_ControlPrenatal(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, PacienteBase **nuevoBase, PacienteBase **inicio, PacienteBase **final, PacienteBase **tempBa,FichaControlPrenatal **frente_P){
    getchar();
    strcpy((*nuevoBase)->nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*nuevoBase)->apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    (*nuevoBase)->edad = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia)->edad_nueva = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia) -> no_Ficha = (*nuevo_Incidencia) -> no_Ficha;
    (*nuevoBase)->consultorioAnterior = 2;

    if(*inicio == NULL){
        *inicio = *nuevoBase;
        *final = *nuevoBase;
    }else{
        (*final)->sig = *nuevoBase;
        *final = *nuevoBase;
    }
    (*nuevoBase)->sig = NULL;
    *tempBa = *nuevoBase;

    *frente_P = (*frente_P) -> sig;
    printf("Describa brevemente el motivo de la correccion: ");
    fgets((*inicio_incidencia)->modificacion, 50, stdin);
    (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';
    (*nuevo_Incidencia)->sig = *inicio_incidencia;
    *inicio_incidencia = *nuevo_Incidencia;
    printf("\nPara hacer cambio de consultorio dirigase al caso 4 del menu principal\n");

    *temp_incidencia = *inicio_incidencia;
    (*inicio_incidencia) = (*inicio_incidencia)->sig;

    (*temp_incidencia)->sig = *historial_incidencia;
    *historial_incidencia = *temp_incidencia;
}

void Incidencia_Consultorio_Anterior_PresionArterial(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, PacienteBase **nuevoBase, PacienteBase **inicio, PacienteBase **final, PacienteBase **tempBa,FichaPresionArterial **frentePA){
    getchar();
    strcpy((*nuevoBase)->nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*nuevoBase)->apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    (*nuevoBase)->edad = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia)->edad_nueva = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia) -> no_Ficha = (*nuevo_Incidencia) -> no_Ficha;
    (*nuevoBase)->consultorioAnterior = 3;

    if(*inicio == NULL){
        *inicio = *nuevoBase;
        *final = *nuevoBase;
    }else{
        (*final)->sig = *nuevoBase;
        *final = *nuevoBase;
    }
    (*nuevoBase)->sig = NULL;
    *tempBa = *nuevoBase;

    *frentePA = (*frentePA) -> sig;
    printf("Describa brevemente el motivo de la correccion: ");
    fgets((*inicio_incidencia)->modificacion, 50, stdin);
    (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';
    (*nuevo_Incidencia)->sig = *inicio_incidencia;
    *inicio_incidencia = *nuevo_Incidencia;
    printf("\nPara hacer cambio de consultorio dirigase al caso 4 del menu principal\n");

    *temp_incidencia = *inicio_incidencia;
    (*inicio_incidencia) = (*inicio_incidencia)->sig;

    (*temp_incidencia)->sig = *historial_incidencia;
    *historial_incidencia = *temp_incidencia;
}

void Incidencia_Consultorio_Anterior_EnferCronica(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, PacienteBase **nuevoBase, PacienteBase **inicio, PacienteBase **final, PacienteBase **tempBa,FichaEnferCronica **frenteEC){
    getchar();
    strcpy((*nuevoBase)->nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*nuevoBase)->apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    (*nuevoBase)->edad = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia)->edad_nueva = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia) -> no_Ficha = (*nuevo_Incidencia) -> no_Ficha;
    (*nuevoBase)->consultorioAnterior = 4;

    if(*inicio == NULL){
        *inicio = *nuevoBase;
        *final = *nuevoBase;
    }else{
        (*final)->sig = *nuevoBase;
        *final = *nuevoBase;
    }
    (*nuevoBase)->sig = NULL;
    *tempBa = *nuevoBase;

    *frenteEC = (*frenteEC) -> sig;
    printf("Describa brevemente el motivo de la correccion: ");
    fgets((*inicio_incidencia)->modificacion, 50, stdin);
    (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';
    (*nuevo_Incidencia)->sig = *inicio_incidencia;
    *inicio_incidencia = *nuevo_Incidencia;
    printf("\nPara hacer cambio de consultorio dirigase al caso 4 del menu principal\n");

    *temp_incidencia = *inicio_incidencia;
    (*inicio_incidencia) = (*inicio_incidencia)->sig;

    (*temp_incidencia)->sig = *historial_incidencia;
    *historial_incidencia = *temp_incidencia;
}

void Incidencia_Consultorio_Anterior_OtrosServicios(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, PacienteBase **nuevoBase, PacienteBase **inicio, PacienteBase **final, PacienteBase **tempBa,OtroServicios **frenteOS){
    getchar();
    strcpy((*nuevoBase)->nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*nuevoBase)->apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_Incidencia)->nombre_Anterior);
    strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_Incidencia)->apellidos_anteriores);

    (*nuevoBase)->edad = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia)->edad_nueva = (*nuevo_Incidencia)->edad_Original;
    (*inicio_incidencia) -> no_Ficha = (*nuevo_Incidencia) -> no_Ficha;
    (*nuevoBase)->consultorioAnterior = 5;

    if(*inicio == NULL){
        *inicio = *nuevoBase;
        *final = *nuevoBase;
    }else{
        (*final)->sig = *nuevoBase;
        *final = *nuevoBase;
    }
    (*nuevoBase)->sig = NULL;
    *tempBa = *nuevoBase;

    *frenteOS =(*frenteOS) -> sig;
    printf("Describa brevemente el motivo de la correccion: ");
    fgets((*inicio_incidencia)->modificacion, 50, stdin);
    (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';
    (*nuevo_Incidencia)->sig = *inicio_incidencia;
    *inicio_incidencia = *nuevo_Incidencia;
    printf("\nPara hacer cambio de consultorio dirigase al caso 4 del menu principal\n");

    *temp_incidencia = *inicio_incidencia;
    (*inicio_incidencia) = (*inicio_incidencia)->sig;

    (*temp_incidencia)->sig = *historial_incidencia;
    *historial_incidencia = *temp_incidencia;
}
#endif