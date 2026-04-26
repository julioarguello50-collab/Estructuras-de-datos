#ifndef INCIDENCIAS_DATOS_H
#define INCIDENCIAS_DATOS_H
#include<stdio.h>
#include<string.h>
#include"estructuras.h"
//funciones para corregir incidencias por datos de la ficha

void Incidencia_Datos_Vacunacion(incidencia **inicio_incidencia,incidencia **temp_incidencia,incidencia **historial_incidencia,FichaVacunacion **nuevo_V,FichaVacunacion **frente_V){
    for((*nuevo_V) = (*frente_V);(*nuevo_V) != NULL;(*nuevo_V) = (*nuevo_V)->sig){
        if((*nuevo_V)->no_Ficha == (*inicio_incidencia)->no_Ficha){
            getchar();

            printf("Correcion de datos de la Ficha del paciente\n");
            printf("Digite el nombre: ");
            fgets((*nuevo_V)->nombre,50,stdin);
            (*nuevo_V)->nombre[strcspn((*nuevo_V)->nombre,"\n")] = '\0';

            printf("Digite los apellidos: ");
            fgets((*nuevo_V)->apellidos,50,stdin);
            (*nuevo_V)->apellidos[strcspn((*nuevo_V)->apellidos,"\n")] = '\0';

            printf("Digite la edad: ");
            scanf("%d",&(*nuevo_V)->edad);
            getchar();

            printf("Describa brevemente el motivo de la correccion: ");
            fgets((*inicio_incidencia)->modificacion,50,stdin);
            (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion,"\n")] = '\0';

            strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_V)->nombre);
            strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_V)->apellidos);
            (*inicio_incidencia)->edad_nueva = (*nuevo_V)->edad;

            *temp_incidencia = *inicio_incidencia;
            (*inicio_incidencia) = (*inicio_incidencia)->sig;

            (*temp_incidencia)->sig = *historial_incidencia;
            *historial_incidencia = *temp_incidencia;

            printf("Incidencia corregida y enviada al historial de incidencias\n");
            break;
        }
    }
}

void Incidencia_Datos_ControlPrenatal(incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, FichaControlPrenatal **nuevo_P, FichaControlPrenatal **frente_P){
    for((*nuevo_P) = (*frente_P); (*nuevo_P) != NULL; (*nuevo_P) = (*nuevo_P)->sig){
        if((*nuevo_P)->no_Ficha == (*inicio_incidencia)->no_Ficha){
            getchar();

            printf("Correcion de datos de la Ficha del paciente\n");
            printf("Digite el nombre: ");
            fgets((*nuevo_P)->nombre, 50, stdin);
            (*nuevo_P)->nombre[strcspn((*nuevo_P)->nombre, "\n")] = '\0';

            printf("Digite los apellidos: ");
            fgets((*nuevo_P)->apellidos, 50, stdin);
            (*nuevo_P)->apellidos[strcspn((*nuevo_P)->apellidos, "\n")] = '\0';

            printf("Digite la edad: ");
            scanf("%d", &(*nuevo_P)->edad);
            getchar();

            printf("Describa brevemente el motivo de la correccion: ");
            fgets((*inicio_incidencia)->modificacion, 50, stdin);
            (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';

            strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevo_P)->nombre);
            strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevo_P)->apellidos);
            (*inicio_incidencia)->edad_nueva = (*nuevo_P)->edad;

            *temp_incidencia = *inicio_incidencia;
            (*inicio_incidencia) = (*inicio_incidencia)->sig;

            (*temp_incidencia)->sig = *historial_incidencia;
            *historial_incidencia = *temp_incidencia;

            printf("Incidencia corregida y enviada al historial de incidencias\n");
            break;
        }
    }
}

void Incidencia_Datos_PresionArterial(incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, FichaPresionArterial **nuevoPA, FichaPresionArterial **frentePA){
    for((*nuevoPA) = (*frentePA); (*nuevoPA) != NULL; (*nuevoPA) = (*nuevoPA)->sig){
        if((*nuevoPA)->no_Ficha == (*inicio_incidencia)->no_Ficha){
            getchar();

            printf("Correcion de datos de la Ficha del paciente\n");
            printf("Digite el nombre: ");
            fgets((*nuevoPA)->nombre, 50, stdin);
            (*nuevoPA)->nombre[strcspn((*nuevoPA)->nombre, "\n")] = '\0';

            printf("Digite los apellidos: ");
            fgets((*nuevoPA)->apellidos, 50, stdin);
            (*nuevoPA)->apellidos[strcspn((*nuevoPA)->apellidos, "\n")] = '\0';

            printf("Digite la edad: ");
            scanf("%d", &(*nuevoPA)->edad);
            getchar();

            printf("Describa brevemente el motivo de la correccion: ");
            fgets((*inicio_incidencia)->modificacion, 50, stdin);
            (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';

            strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevoPA)->nombre);
            strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevoPA)->apellidos);
            (*inicio_incidencia)->edad_nueva = (*nuevoPA)->edad;

            *temp_incidencia = *inicio_incidencia;
            (*inicio_incidencia) = (*inicio_incidencia)->sig;

            (*temp_incidencia)->sig = *historial_incidencia;
            *historial_incidencia = *temp_incidencia;

            printf("Incidencia corregida y enviada al historial de incidencias\n");
            break;
        }
    }
}

void Incidencia_Datos_EnferCronica(incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, FichaEnferCronica **nuevoEC, FichaEnferCronica **frenteEC){
    for((*nuevoEC) = (*frenteEC); (*nuevoEC) != NULL; (*nuevoEC) = (*nuevoEC)->sig){
        if((*nuevoEC)->no_Ficha == (*inicio_incidencia)->no_Ficha){
            getchar();

            printf("Correcion de datos de la Ficha del paciente\n");
            printf("Digite el nombre: ");
            fgets((*nuevoEC)->nombre, 50, stdin);
            (*nuevoEC)->nombre[strcspn((*nuevoEC)->nombre, "\n")] = '\0';

            printf("Digite los apellidos: ");
            fgets((*nuevoEC)->apellidos, 50, stdin);
            (*nuevoEC)->apellidos[strcspn((*nuevoEC)->apellidos, "\n")] = '\0';

            printf("Digite la edad: ");
            scanf("%d", &(*nuevoEC)->edad);
            getchar();

            printf("Describa brevemente el motivo de la correccion: ");
            fgets((*inicio_incidencia)->modificacion, 50, stdin);
            (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';

            strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevoEC)->nombre);
            strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevoEC)->apellidos);
            (*inicio_incidencia)->edad_nueva = (*nuevoEC)->edad;

            *temp_incidencia = *inicio_incidencia;
            (*inicio_incidencia) = (*inicio_incidencia)->sig;

            (*temp_incidencia)->sig = *historial_incidencia;
            *historial_incidencia = *temp_incidencia;

            printf("Incidencia corregida y enviada al historial de incidencias\n");
            break;
        }
    }
}

void Incidencia_Datos_OtrosServicios(incidencia **inicio_incidencia, incidencia **temp_incidencia, incidencia **historial_incidencia, OtroServicios **nuevoOS, OtroServicios **frenteOS){
    for((*nuevoOS) = (*frenteOS); (*nuevoOS) != NULL; (*nuevoOS) = (*nuevoOS)->sig){
        if((*nuevoOS)->no_Ficha == (*inicio_incidencia)->no_Ficha){
            getchar();

            printf("Correcion de datos de la Ficha del paciente\n");
            printf("Digite el nombre: ");
            fgets((*nuevoOS)->nombre, 50, stdin);
            (*nuevoOS)->nombre[strcspn((*nuevoOS)->nombre, "\n")] = '\0';

            printf("Digite los apellidos: ");
            fgets((*nuevoOS)->apellidos, 50, stdin);
            (*nuevoOS)->apellidos[strcspn((*nuevoOS)->apellidos, "\n")] = '\0';

            printf("Digite la edad: ");
            scanf("%d", &(*nuevoOS)->edad);
            getchar();

            printf("Describa brevemente el motivo de la correccion: ");
            fgets((*inicio_incidencia)->modificacion, 50, stdin);
            (*inicio_incidencia)->modificacion[strcspn((*inicio_incidencia)->modificacion, "\n")] = '\0';

            strcpy((*inicio_incidencia)->Nuevo_nombre, (*nuevoOS)->nombre);
            strcpy((*inicio_incidencia)->nuevos_apellidos, (*nuevoOS)->apellidos);
            (*inicio_incidencia)->edad_nueva = (*nuevoOS)->edad;

            *temp_incidencia = *inicio_incidencia;
            (*inicio_incidencia) = (*inicio_incidencia)->sig;

            (*temp_incidencia)->sig = *historial_incidencia;
            *historial_incidencia = *temp_incidencia;

            printf("Incidencia corregida y enviada al historial de incidencias\n");
            break;
        }
    }
}
#endif