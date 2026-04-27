#ifndef ALTA_INCIDENCIAS_H
#define ALTA_INCIDENCIAS_H
#include<stdio.h>
#include<string.h>
#include"estructuras.h"

//funciones para declarar incidencias de los tipos de consultorios
void Alta_incidenciaVacunacion(incidencia **nuevo_Incidencia,incidencia **inicio_incidencia,FichaVacunacion **nuevo_V,FichaVacunacion **frente_V,int *encontrado,int *buscar_ficha){
    printf("Digite el numero de la ficha del paciente: ");
    scanf("%d",&(*buscar_ficha));
    *encontrado = 0;
    for((*nuevo_V) = (*frente_V); (*nuevo_V) != NULL; (*nuevo_V) = (*nuevo_V)->sig){
        if((*nuevo_V)->no_Ficha == *buscar_ficha){
            *encontrado = 1;
            (*nuevo_Incidencia)-> no_Ficha = (*nuevo_V)-> no_Ficha;
            (*nuevo_Incidencia)->tipoConsultorio = 1;

            strcpy((*nuevo_Incidencia)->nombre_Anterior, (*nuevo_V)->nombre);
            strcpy((*nuevo_Incidencia)->apellidos_anteriores, (*nuevo_V)->apellidos);

            (*nuevo_Incidencia)->edad_Original = (*nuevo_V)->edad;

            (*nuevo_Incidencia)->sig = *inicio_incidencia;
            *inicio_incidencia = *nuevo_Incidencia;

            printf("Incidencia registrada correctamente\n");
            break;
        }
    }
    if((*encontrado) == 0){
        printf("No se encontro la ficha\n");
        free(*nuevo_Incidencia);
    }
}

void Alta_incidenciaControlPrenatal(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, FichaControlPrenatal **nuevo_P, FichaControlPrenatal **frente_P, int *encontrado, int *buscar_ficha){
    printf("Digite el numero de la ficha del paciente: ");
    scanf("%d", &(*buscar_ficha));
    *encontrado = 0;
    for((*nuevo_P) = (*frente_P); (*nuevo_P) != NULL; (*nuevo_P) = (*nuevo_P)->sig){
        if((*nuevo_P)->no_Ficha == *buscar_ficha){
            *encontrado = 1;
            (*nuevo_Incidencia)->no_Ficha = (*nuevo_P)->no_Ficha;
            (*nuevo_Incidencia)->tipoConsultorio = 2;

            strcpy((*nuevo_Incidencia)->nombre_Anterior, (*nuevo_P)->nombre);
            strcpy((*nuevo_Incidencia)->apellidos_anteriores, (*nuevo_P)->apellidos);

            (*nuevo_Incidencia)->edad_Original = (*nuevo_P)->edad;

            (*nuevo_Incidencia)->sig = *inicio_incidencia;
            *inicio_incidencia = *nuevo_Incidencia;

            printf("Incidencia registrada correctamente\n");
            break;
        }
    }
    if((*encontrado) == 0){
        printf("No se encontro la ficha\n");
        free(*nuevo_Incidencia);
    }
}

void Alta_incidenciaPresionArterial(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, FichaPresionArterial **nuevoPA, FichaPresionArterial **frentePA, int *encontrado, int *buscar_ficha){
    printf("Digite el numero de la ficha del paciente: ");
    scanf("%d", &(*buscar_ficha));
    *encontrado = 0;
    for((*nuevoPA) = (*frentePA); (*nuevoPA) != NULL; (*nuevoPA) = (*nuevoPA)->sig){
        if((*nuevoPA)->no_Ficha == *buscar_ficha){
            *encontrado = 1;
            (*nuevo_Incidencia)->no_Ficha = (*nuevoPA)->no_Ficha;
            (*nuevo_Incidencia)->tipoConsultorio = 3;

            strcpy((*nuevo_Incidencia)->nombre_Anterior, (*nuevoPA)->nombre);
            strcpy((*nuevo_Incidencia)->apellidos_anteriores, (*nuevoPA)->apellidos);

            (*nuevo_Incidencia)->edad_Original = (*nuevoPA)->edad;

            (*nuevo_Incidencia)->sig = *inicio_incidencia;
            *inicio_incidencia = *nuevo_Incidencia;

            printf("Incidencia registrada correctamente\n");
            break;
        }
    }
    if((*encontrado) == 0){
        printf("No se encontro la ficha\n");
        free(*nuevo_Incidencia);
    }
}

void Alta_incidenciaEnferCronica(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, FichaEnferCronica **nuevoEC, FichaEnferCronica **frenteEC, int *encontrado, int *buscar_ficha){
    printf("Digite el numero de la ficha del paciente: ");
    scanf("%d", &(*buscar_ficha));
    *encontrado = 0;
    for((*nuevoEC) = (*frenteEC); (*nuevoEC) != NULL; (*nuevoEC) = (*nuevoEC)->sig){
        if((*nuevoEC)->no_Ficha == *buscar_ficha){
            *encontrado = 1;
            (*nuevo_Incidencia)->no_Ficha = (*nuevoEC)->no_Ficha;
            (*nuevo_Incidencia)->tipoConsultorio = 4;

            strcpy((*nuevo_Incidencia)->nombre_Anterior, (*nuevoEC)->nombre);
            strcpy((*nuevo_Incidencia)->apellidos_anteriores, (*nuevoEC)->apellidos);

            (*nuevo_Incidencia)->edad_Original = (*nuevoEC)->edad;

            (*nuevo_Incidencia)->sig = *inicio_incidencia;
            *inicio_incidencia = *nuevo_Incidencia;

            printf("Incidencia registrada correctamente\n");
            break;
        }
    }
    if((*encontrado) == 0){
        printf("No se encontro la ficha\n");
        free(*nuevo_Incidencia);
    }
}

void Alta_incidenciaOtrosServicios(incidencia **nuevo_Incidencia, incidencia **inicio_incidencia, OtroServicios **nuevoOS, OtroServicios **frenteOS, int *encontrado, int *buscar_ficha){
    printf("Digite el numero de la ficha del paciente: ");
    scanf("%d", &(*buscar_ficha));
    *encontrado = 0;
    for((*nuevoOS) = (*frenteOS); (*nuevoOS) != NULL; (*nuevoOS) = (*nuevoOS)->sig){
        if((*nuevoOS)->no_Ficha == *buscar_ficha){
            *encontrado = 1;
            (*nuevo_Incidencia)->no_Ficha = (*nuevoOS)->no_Ficha;
            (*nuevo_Incidencia)->tipoConsultorio = 5;

            strcpy((*nuevo_Incidencia)->nombre_Anterior, (*nuevoOS)->nombre);
            strcpy((*nuevo_Incidencia)->apellidos_anteriores, (*nuevoOS)->apellidos);

            (*nuevo_Incidencia)->edad_Original = (*nuevoOS)->edad;

            (*nuevo_Incidencia)->sig = *inicio_incidencia;
            *inicio_incidencia = *nuevo_Incidencia;

            printf("Incidencia registrada correctamente\n");
            break;
        }
    }
    if((*encontrado) == 0){
        printf("No se encontro la ficha\n");
        free(*nuevo_Incidencia);
    }
}


#endif