#ifndef REPORTES_H
#define REPORTES_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
#include"registros.h"

//Archivo para imprimir historiales de pacientes

//funcion para imprimir historial de pacientes por vacunacion
void Historial_Vacunacion(FichaVacunacion **nuevo_V,FichaVacunacion **frente_V,FichaVacunacion **temp,FichaVacunacion **historial_V,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp) = *historial_V;
    //realiza la busqueda mientras que el puntero temporal tenga datos
    printf("Lista de pacientes para consulta de vacunacion\n");
    while ((*temp) != NULL) {
        if((*temp) -> no_Ficha == -1){
            printf("Paciente no. %d\nNombre: %s %s (atendido)\n",*No_lista, (*temp)->nombre, (*temp)->apellidos);
            }else{
            printf("Paciente no. %d\nNombre: %s %s \nNo. Ficha %d\n",*No_lista, (*temp) ->nombre, (*temp) ->apellidos,(*temp) -> no_Ficha);
            }
        (*No_lista)++;
        (*encontrado)++;
        (*temp) = (*temp)->sig;   
    }
    if (!encontrado) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }
    //sino tiene temporal entonces imprime a los pacientes pendientes por antender
    if((*frente_V) != NULL){
        printf("Imprimiendo lista de pacientes pendientes para vacunacion\n");
        for((*nuevo_V) = (*frente_V); (*nuevo_V) != NULL; (*nuevo_V) = (*nuevo_V) -> sig){
        printf("Paciente no. %d\nNombre: %s %s\n\n",*No_lista,(*nuevo_V) -> nombre,(*nuevo_V) -> apellidos);
        (*No_lista)++;
        }
    }
    system("pause");
    system("cls");
}

//historial de pacientes por Control prenatal
void Historial_Prenatal(FichaControlPrenatal **nuevo_P ,FichaControlPrenatal **frente_P,FichaControlPrenatal **temp_P,FichaControlPrenatal **historial_P,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_P) = *historial_P;

    printf("Lista de pacientes para consulta de control prenatal\n");
    while ((*temp_P) != NULL) {
        if((*temp_P) -> no_Ficha == -1){
            printf("Paciente no. %d\nNombre: %s %s (atendido)\n",*No_lista, (*temp_P)->nombre, (*temp_P)->apellidos);
            }else{
            printf("Paciente no. %d\nNombre: %s %s \nNo. Ficha %d\n",*No_lista, (*temp_P) ->nombre, (*temp_P) ->apellidos,(*temp_P) -> no_Ficha);
            }
        (*No_lista)++;
        (*encontrado)++;
        (*temp_P) = (*temp_P)->sig;   
    }
    if (!encontrado) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }

    if((*frente_P) != NULL){
        printf("Imprimiendo lista de pacientes pendientes para control prenatal\n");
        for((*nuevo_P) = (*frente_P); (*nuevo_P) != NULL; (*nuevo_P) = (*nuevo_P) -> sig){
        printf("Paciente no. %d\nNombre: %s %s\n\n",*No_lista,(*nuevo_P) -> nombre,(*nuevo_P) -> apellidos);
        (*No_lista)++;
        }
    }
    system("pause");
    system("cls");
}

//Historial de presion arterial
void Historial_Arterial(FichaPresionArterial **nuevo_PA, FichaPresionArterial **frentePA,FichaPresionArterial **temp_PA,FichaPresionArterial **historial_PA,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_PA) = *historial_PA;

    printf("Lista de pacientes para presion arterial\n");
    while ((*temp_PA) != NULL) {
        if((*temp_PA) -> no_Ficha == -1){
            printf("Paciente no. %d\nNombre: %s %s (atendido)\n",*No_lista, (*temp_PA)->nombre, (*temp_PA)->apellidos);
            }else{
            printf("Paciente no. %d\nNombre: %s %s \nNo. Ficha %d\n",*No_lista, (*temp_PA) ->nombre, (*temp_PA) ->apellidos,(*temp_PA) -> no_Ficha);
            }
        (*No_lista)++;
        (*encontrado)++;
        (*temp_PA) = (*temp_PA)->sig;   
    }
    if (!encontrado) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }

    if((*frentePA) != NULL){
        printf("Imprimiendo lista de pacientes pendientes para presion arterial\n");
        for((*nuevo_PA) = (*frentePA); (*nuevo_PA) != NULL; (*nuevo_PA) = (*nuevo_PA) -> sig){
            printf("Paciente no. %d\nNombre: %s %s\n\n",*No_lista,(*nuevo_PA) -> nombre,(*nuevo_PA) -> apellidos);
            (*No_lista)++;
        }
    }
    system("pause");
    system("cls");
}

//Historial de enfermedades cronicas
void Historial_EnferCronica(FichaEnferCronica **nuevoEC,FichaEnferCronica**frenteEC,FichaEnferCronica **temp_EC,FichaEnferCronica **historial_EC,int *No_lista,int *encontrado){
    (*No_lista) = 1;
    (*encontrado) = 0;
    (*temp_EC) = *historial_EC;

    printf("Lista de pacientes para enfermedades cronicas\n");
    while ((*temp_EC) != NULL) {
        if((*temp_EC) -> no_Ficha == -1){
            printf("Paciente no. %d\nNombre: %s %s (atendido)\n",*No_lista, (*temp_EC)->nombre, (*temp_EC)->apellidos);
            }else{
            printf("Paciente no. %d\nNombre: %s %s \nNo. Ficha %d\n",*No_lista, (*temp_EC) ->nombre, (*temp_EC) ->apellidos,(*temp_EC) -> no_Ficha);
            }
        (*No_lista)++;
        (*encontrado)++;
        (*temp_EC) = (*temp_EC)->sig;   
    }
    if (!encontrado) {
        printf("No hay pacientes atendidos en el dia\n\n");
    }

    if((*frenteEC) != NULL){
        printf("Imprimiendo lista de pacientes pendientes para enfermendades cronicas\n");
        for((*nuevoEC) = (*frenteEC); (*nuevoEC) != NULL; (*nuevoEC) = (*nuevoEC) -> sig){
            printf("Paciente no. %d\nNombre: %s %s\n\n",*No_lista,(*nuevoEC) -> nombre,(*nuevoEC) -> apellidos);
            (*No_lista)++;
        }
    }
    system("pause");
    system("cls");
}
#endif