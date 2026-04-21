#ifndef DEMANDA_SERVICIOS_H
#define DEMANDA_SERVICIOS_H
#include<stdio.h>
#include<stdlib.h>
#include"estructuras.h"
void Mayor_Demanda(int *pacientes_Vacunacion,int *pacientes_Prenatal,int *pacientes_Arterial,int *pacientes_Cronicos,int *paciente_OtroServicio){
    int max = 0,m;
    int array[5]  = {*pacientes_Vacunacion,*pacientes_Prenatal,*pacientes_Arterial,*pacientes_Cronicos,*paciente_OtroServicio};
    char tipos[5][60] = {"Vacunacion","Control Prenatal","Presion Arterial","Enfermedades Cronicas","Paciente OtroServicio"};
    max = array[0];

    for(m = 0; m<5;m++){
        if(array[m] > max){
            max = array[m];
        }
    }
    printf("\n\n");
    for(m = 0 ; m < 5; m++){
        if(max == array[m]){
            printf("El servicio con mayor demanda es %s con %d pacientes\n",tipos[m],array[m]);
        }
    }
    printf("\n\n");
}

void Menor_Demanda(int *pacientes_Vacunacion,int *pacientes_Prenatal,int *pacientes_Arterial,int *pacientes_Cronicos,int *paciente_OtroServicio){
    int min = 999,m;
    int array[5]  = {*pacientes_Vacunacion,*pacientes_Prenatal,*pacientes_Arterial,*pacientes_Cronicos,*paciente_OtroServicio};
    char tipos[5][60] = {"Vacunacion","Control Prenatal","Presion Arterial","Enfermedades Cronicas","Paciente OtroServicio"};

    for(m = 0; m<5;m++){
        if(array[m] < min){
            min = array[m];
        }
    }
    printf("\n\n");
    for(m = 0; m<5;m++){
        if(min == array[m]){
            printf("El servicio con menor demanda es %s con %d pacientes\n",tipos[m],array[m]);
        }
    }
    printf("\n\n");
}
#endif