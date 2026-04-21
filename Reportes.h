#ifndef REPORTES_H
#define REPORTES_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
#include"registros.h"

//Archivo para imprimir historiales de pacientes

//funcion para imprimir historial de pacientes por vacunacion
void Historial_Vacunacion(FichaVacunacion **temp,FichaVacunacion **historial_V,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp) = *historial_V;
    //realiza la busqueda mientras que el puntero temporal tenga datos
    printf("Lista de pacientes para consulta de vacunacion\n");

    for((*temp) = *historial_V; *temp != NULL; (*temp) = (*temp) -> sig) {
        if((*temp) -> atendido == 1){
            printf("Paciente no. %d\nNombre: %s %s\nEdad: %d\nNo. Ficha %d (atendido)\n",*No_lista, (*temp)->nombre, (*temp)->apellidos,(*temp) -> edad,(*temp) -> no_Ficha);
            (*encontrado)++;
            (*No_lista)++;
        }
        printf("\n");
    }

    if (*encontrado == 0) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }
    printf("\n\n");
}

//historial de pacientes por Control prenatal
void Historial_Prenatal(FichaControlPrenatal **temp_P ,FichaControlPrenatal **historial_P,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_P) = *historial_P;

    //Si hay pacientes atendidos entonces los imprime
    printf("Lista de pacientes para consulta de control prenatal\n");
    for((*temp_P) = *historial_P; *temp_P != NULL; (*temp_P) = (*temp_P) -> sig) {
        if((*temp_P) -> atendido == 1){
            printf("Paciente no. %d\nNombre: %s %s\nEdad: %d\nNo. Ficha %d (atendido)\n",*No_lista, (*temp_P)->nombre, (*temp_P)->apellidos,(*temp_P) -> edad,(*temp_P) -> no_Ficha);
            (*encontrado)++;
            (*No_lista)++;
        }
        printf("\n");
    }
    if (*encontrado == 0) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }
    printf("\n\n");
}

//Historial de presion arterial
void Historial_Arterial(FichaPresionArterial **temp_PA,FichaPresionArterial **historial_PA,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_PA) = *historial_PA;

    //Si hay pacientes atendidos entonces los imprime
    printf("Lista de pacientes para presion arterial\n");
    for((*temp_PA) = *historial_PA; *temp_PA != NULL; (*temp_PA) = (*temp_PA) -> sig) {
        if((*temp_PA) -> atendido == 1){
            printf("Paciente no. %d\nNombre: %s %s\nEdad: %d\nNo. Ficha %d (atendido)\n",*No_lista, (*temp_PA)->nombre, (*temp_PA)->apellidos,(*temp_PA) -> edad,(*temp_PA) -> no_Ficha);
            (*encontrado)++;
            (*No_lista)++;
        }
        printf("\n");
    }
    if (*encontrado == 0) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }

    printf("\n\n");
}

//Historial de enfermedades cronicas
void Historial_EnferCronica(FichaEnferCronica **temp_EC,FichaEnferCronica **historial_EC,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_EC) = *historial_EC;

    //Si hay pacientes atendidos entonces los imprime
    printf("Lista de pacientes para enfermedades cronicas\n");
    for((*temp_EC) = *historial_EC; *temp_EC != NULL; (*temp_EC) = (*temp_EC) -> sig) {
        if((*temp_EC) -> atendido == 1){
            printf("Paciente no. %d\nNombre: %s %s\nEdad: %d\nNo. Ficha %d (atendido)\n",*No_lista, (*temp_EC)->nombre, (*temp_EC)->apellidos,(*temp_EC) -> edad,(*temp_EC) -> no_Ficha);
            (*encontrado)++;
            (*No_lista)++;
        }
        printf("\n");
    }
        
    if (*encontrado == 0) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }
    printf("\n\n");
}

void Historial_OtroServicio(OtroServicios **temp_OS,OtroServicios **historial_OS,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_OS) = *historial_OS;

    //Si hay pacientes atendidos entonces los imprime
    printf("Lista de pacientes para enfermedades cronicas\n");
    for((*temp_OS) = *historial_OS; *temp_OS != NULL; (*temp_OS) = (*temp_OS) -> sig) {
        if((*temp_OS) -> atendido == 1){
            printf("Paciente no. %d\nNombre: %s %s\nSintomas/causas: %s\nEdad: %d\nNo. Ficha %d (atendido)\n",*No_lista, (*temp_OS)->nombre, (*temp_OS)->apellidos,(*temp_OS) ->sintomas,(*temp_OS) -> edad,(*temp_OS) -> no_Ficha);
            (*encontrado)++;
            (*No_lista)++;
        }
        printf("\n");
    }
        
    if (*encontrado == 0) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }
    printf("\n\n");
}
#endif