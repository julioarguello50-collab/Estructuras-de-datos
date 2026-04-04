#ifndef DEMANDA_SERVICIOS_H
#define DEMANDA_SERVICIOS_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
void Mayor_Demanda(int *pacientes_Vacunacion,int *pacientes_Prenatal,int *pacientes_Arterial,int *pacientes_Cronicos){
    int max = 0,m;
    int array[4]  = {*pacientes_Vacunacion,*pacientes_Prenatal,*pacientes_Arterial,*pacientes_Cronicos};
    char tipos[4][40] = {"Vacunacion","Control Prenatal","Presion Arterial","Enfermedades Cronicas"};
    max = array[0];

    for(m = 0; m<4;m++){
        if(array[m] > max){
            max = array[m];
        }
    }
    printf("\n\n");
    for(m = 0 ; m < 4; m++){
        if(max == array[m]){
            printf("El servicio con mayor demanda es %s con %d pacientes\n",tipos[m],array[m]);
        }
    }
    printf("\n\n");
}

void Menor_Demanda(int *pacientes_Vacunacion,int *pacientes_Prenatal,int *pacientes_Arterial,int *pacientes_Cronicos){
    int min = 999,m;
    int array[4]  = {*pacientes_Vacunacion,*pacientes_Prenatal,*pacientes_Arterial,*pacientes_Cronicos};
    char tipos[4][40] = {"Vacunacion","Control Prenatal","Presion Arterial","Enfermedades Cronicas"};

    for(m = 0; m<4;m++){
        if(array[m] < min){
            min = array[m];
        }
    }
    printf("\n\n");
    for(m = 0; m<4;m++){
        if(min == array[m]){
            printf("El servicio con menor demanda es %s con %d pacientes\n",tipos[m],array[m]);
        }
    }
    printf("\n\n");
}
#endif