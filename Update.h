#ifndef UPDATE_H
#define UPDATE_H
#include<stdio.h>
#include <string.h>
#include"estructuras.h"
#include "Consultorios.h"
#define FICHAVACUNACION 1
#define FICHACONTROLPRENATAL 2
#define FICHAPRESIONARTERIAL 3
#define FICHAENFER_CRONICA 4

//pila de acciones para vacunacion

//funcion pop para guardar el tipo de ficha y el numero de ficha

void menuAccionVacunacion(PacienteBase **final,FichaVacunacion **nuevo_V,FichaVacunacion **frente_V,FichaVacunacion **ultimo_V,int *num_V){
    (*nuevo_V) = (struct FichaVacunacion*) malloc(sizeof(struct FichaVacunacion));
    strcpy((*nuevo_V) -> nombre,(*final) -> nombre);
    strcpy((*nuevo_V) -> apellidos,(*final) -> apellidos);
    (*nuevo_V) -> edad = (*final) -> edad;
    (*nuevo_V) -> no_Ficha = *num_V;

    if(*frente_V == NULL){
        *frente_V = *nuevo_V;
    }else{
        (*ultimo_V) -> sig = *nuevo_V;
    }
    (*nuevo_V) -> sig = NULL;
    *ultimo_V = *nuevo_V;
    printf("El paciente fue transferido al consultorio de Vacunacion\n");
}

void menuAccionPrenatal(PacienteBase **final,FichaControlPrenatal **nuevo_P,FichaControlPrenatal **frente_P,FichaControlPrenatal **ultimo_P,int *num_P){
    (*nuevo_P) = malloc(sizeof(struct FichaControlPrenatal));
    strcpy((*nuevo_P)->nombre, (*final)->nombre);
    strcpy((*nuevo_P)->apellidos, (*final)->apellidos);
    (*nuevo_P)->edad = (*final)->edad;
        (*nuevo_P)->no_Ficha = *num_P;
        if(*frente_P == NULL){
            *frente_P = *nuevo_P;
        } else {
            (*ultimo_P)->sig = *nuevo_P;
        }
        (*nuevo_P)->sig = NULL;
        *ultimo_P = *nuevo_P;
        printf("El paciente fue transferido al consultorio de control prenatal\n");
}

void menuAccionPresionArterial(PacienteBase **final,FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA,FichaPresionArterial **ultimoPA,int *num_PA){
    (*nuevoPA) = (struct FichaPresionArterial *) malloc(sizeof(struct FichaPresionArterial));
    strcpy((*nuevoPA) -> nombre,(*final) -> nombre);
    strcpy((*nuevoPA) -> apellidos,(*final) -> apellidos);
    (*nuevoPA) -> edad = (*final) -> edad;
    (*nuevoPA) -> no_Ficha = *num_PA;
    if(*frentePA == NULL){
        *frentePA = *nuevoPA;
    }else{
        (*ultimoPA) -> sig = *nuevoPA;
    }
    (*nuevoPA) -> sig = NULL;
    *ultimoPA = *nuevoPA;
    printf("El paciente fue transferido al consultorio de Presion arterial\n");
}

void menuAccionEnferCronica(PacienteBase **final,FichaEnferCronica **nuevoEC,FichaEnferCronica **frenteEC,FichaEnferCronica **ultimoEC,int *num_EC){
    (*nuevoEC) = (struct FichaEnferCronica *) malloc(sizeof(struct FichaEnferCronica));
    strcpy((*nuevoEC) -> nombre,(*final) -> nombre);
    strcpy((*nuevoEC) -> apellidos,(*final) -> apellidos);
    (*nuevoEC) -> edad = (*final) -> edad;
    (*nuevoEC) -> no_Ficha = *num_EC;
    if(*frenteEC == NULL){
        *frenteEC = (*nuevoEC);
    }else{
        (*ultimoEC) -> sig = (*nuevoEC);
    }
    (*nuevoEC) -> sig = NULL;
    *ultimoEC = *nuevoEC;
    printf("El paciente fue transferido al consultorio de enfermedades cronicas\n");
}

void menuAccionOtroServicio(PacienteBase **final,OtroServicios **nuevoOS,OtroServicios **frenteOS,OtroServicios **ultimoOS,int *num_OS){
    (*nuevoOS) = (struct OtroServicios *) malloc(sizeof(struct OtroServicios));
    strcpy((*nuevoOS) -> nombre,(*final) -> nombre);
    strcpy((*nuevoOS) -> apellidos,(*final) -> apellidos);
    printf("Describa brevemente los sintomas del paciente: \n");
    fgets((*nuevoOS) -> sintomas,50,stdin);
    (*nuevoOS) -> sintomas[strcspn((*nuevoOS) -> sintomas,"\n")] = '\0';
    (*nuevoOS) -> edad = (*final) -> edad;
    (*nuevoOS) -> no_Ficha = *num_OS;
    
    if(*frenteOS == NULL){
        *frenteOS = (*nuevoOS);
    }else{
        (*ultimoOS) -> sig = (*nuevoOS);
    }
    (*nuevoOS) -> sig = NULL;
    *ultimoOS = *nuevoOS;
    printf("El paciente fue transferido al consultorio de otros servicios medicos\n");
}

//funcion para regresar a un paciente a vacunacion
void regresarPacienteVacunacion(PacienteBase **inicio,PacienteBase **tempBa,FichaVacunacion **nuevo_V,FichaVacunacion **frente_V,FichaVacunacion **ultimo_V,int *num_V){
    printf("El paciente fue regresado a al consultorio de vacunacion\n");
    (*num_V)++;
    (*tempBa) = (*inicio);
    if((*tempBa) == NULL){
        printf("No hay pacientes por mover\n");
    }
    if((*tempBa) -> consultorioAnterior == 1){
        (*nuevo_V) = (struct FichaVacunacion *) malloc(sizeof(struct FichaVacunacion));

        strcpy((*nuevo_V) -> nombre,(*tempBa) -> nombre);
        strcpy((*nuevo_V) -> apellidos,(*tempBa) -> apellidos);
        (*nuevo_V) -> edad = (*tempBa) -> edad;
        (*nuevo_V) ->no_Ficha = (*num_V);

        if((*frente_V) == NULL){
        (*frente_V) = (*nuevo_V);
        }else{
            (*ultimo_V)->sig = (*nuevo_V);
        }
        (*nuevo_V) -> sig = NULL;
    }

    (*inicio) = (*tempBa) -> sig;
    free(*tempBa);
}

void regresarPacientePrenatal(PacienteBase **inicio,PacienteBase **tempBa, FichaControlPrenatal **nuevo_P,FichaControlPrenatal **frente_P,FichaControlPrenatal **ultimo_P,int *num_P){
        printf("El paciente fue regresado a al consultorio de Control Prenatal\n");
    (*num_P)++;
    (*tempBa) = (*inicio);
    if((*tempBa) == NULL){
        printf("No hay pacientes por mover\n");
    }
    if((*tempBa) -> consultorioAnterior == 2){
        (*nuevo_P) = (struct FichaControlPrenatal*) malloc(sizeof(struct FichaControlPrenatal));

        strcpy((*nuevo_P) -> nombre,(*tempBa) -> nombre);
        strcpy((*nuevo_P) -> apellidos,(*tempBa) -> apellidos);
        (*nuevo_P) -> edad = (*tempBa) -> edad;
        (*nuevo_P) -> no_Ficha = (*num_P);

        if((*frente_P) == NULL){
            (*frente_P) = (*nuevo_P);
        }else{
            (*ultimo_P) -> sig = (*nuevo_P);
        }
        (*nuevo_P) -> sig = NULL;
        *ultimo_P = *nuevo_P;
    }
    (*inicio) = (*tempBa) -> sig;
    free(*tempBa);
}

void regresarPacientePreArterial(PacienteBase **inicio,PacienteBase **tempBa,FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA,FichaPresionArterial **ultimoPA,int *num_PA){
    printf("El paciente fue regresado a al consultorio de Presion arterial\n");
    (*num_PA)++;
    (*tempBa) = (*inicio);
    if((*tempBa) == NULL){
        printf("No hay pacientes por mover\n");
    }
    if((*tempBa) -> consultorioAnterior == 3){
        (*nuevoPA) = (struct FichaPresionArterial*) malloc(sizeof(struct FichaPresionArterial));

        strcpy((*nuevoPA) -> nombre, (*tempBa) -> nombre);
        strcpy((*nuevoPA) -> apellidos,(*tempBa) -> apellidos);
        (*nuevoPA) -> edad = (*tempBa) -> edad;
        (*nuevoPA) -> no_Ficha = (*num_PA);

        if((*frentePA) == NULL){
            (*frentePA) = (*nuevoPA);
        }else{
            (*ultimoPA) -> sig = (*nuevoPA);
        }
        (*nuevoPA) -> sig = NULL;
        *ultimoPA = *nuevoPA;

    }
    (*inicio) = (*tempBa) -> sig;
    free(*tempBa);
}

void regresarEnferCronica(PacienteBase **inicio,PacienteBase **tempBa, FichaEnferCronica **nuevoEC,FichaEnferCronica **frenteEC,FichaEnferCronica **ultimoEC,int *num_EC){
        printf("El paciente fue regresado a al consultorio de enfermedades cronicas\n");
    (*num_EC)++;
    (*tempBa) = (*inicio);
    if((*tempBa) == NULL){
        printf("No hay pacientes por mover\n");
    }
    if((*tempBa) -> consultorioAnterior == 4){
        (*nuevoEC) = (struct FichaEnferCronica*) malloc(sizeof(struct FichaEnferCronica));

        strcpy((*nuevoEC) -> nombre,(*tempBa) -> nombre);
        strcpy((*nuevoEC) -> apellidos,(*tempBa) -> apellidos);
        (*nuevoEC) -> edad = (*tempBa) -> edad;
        (*nuevoEC) -> no_Ficha = (*num_EC);

        if((*frenteEC) == NULL){
            (*frenteEC) = (*nuevoEC);
        }else{
            (*ultimoEC) -> sig =  (*nuevoEC);
        }
        (*nuevoEC) -> sig = NULL;
        *ultimoEC = *nuevoEC;
    }
    (*inicio) = (*tempBa) -> sig;
    free(*tempBa);
}

void regresarOtroServicios(PacienteBase **inicio,PacienteBase **tempBa,OtroServicios **nuevoOS,OtroServicios **frenteOS,OtroServicios **ultimoOS,int *num_OS){  
    printf("El paciente fue regresado a al consultorio de Otros servicios\n");
    getchar();
    (*num_OS)++;
    (*tempBa) = (*inicio);
    if((*tempBa) == NULL){
        printf("No hay pacientes por mover\n");
    }
    if((*tempBa) -> consultorioAnterior == 5){
        (*nuevoOS) = (struct OtroServicios*) malloc(sizeof(struct OtroServicios));

        strcpy((*nuevoOS) -> nombre,(*tempBa) -> nombre);
        strcpy((*nuevoOS) -> apellidos,(*tempBa) -> apellidos);
        printf("Describa brevemente los sintomas del paciente: \n");
        fgets((*nuevoOS) -> sintomas,50,stdin);
        (*nuevoOS) -> sintomas[strcspn((*nuevoOS) -> sintomas,"\n")] = '\0';
        (*nuevoOS) -> edad = (*tempBa) -> edad;
        (*nuevoOS) -> no_Ficha = (*num_OS);

        if((*frenteOS) == NULL){
            (*frenteOS) = (*nuevoOS);
        }else{
            (*ultimoOS) -> sig = (*nuevoOS);
        }
        (*nuevoOS) -> sig = NULL;
        *ultimoOS = *nuevoOS;
        (*inicio) = (*tempBa) -> sig;
        free(*tempBa);
    }
}

//funciones para eliminar registros en caso de confirmar el cambio de consulta;

void eliminarConsultorioAnterior(PacienteBase **tempBa,FichaVacunacion **nuevo_V,FichaControlPrenatal **nuevo_P,FichaPresionArterial **nuevoPA,FichaEnferCronica **nuevoEC,OtroServicios **nuevoOS){
    if((*tempBa) -> consultorioAnterior == 1){
        free(*nuevo_V);
    }else if((*tempBa) -> consultorioAnterior == 2){
        free(*nuevo_P);
    }else if((*tempBa) -> consultorioAnterior == 3){
        free(*nuevoPA);
    }else if((*tempBa) -> consultorioAnterior == 4){
        free(*nuevoEC);
    }else if((*tempBa) -> consultorioAnterior == 5){
        free(*nuevoOS);
    }
}

void reduccionContadores(PacienteBase **tempBa,int *num_V, int *num_P,int *num_PA,int *num_EC,int *num_OS,int *pacientes_Vacunacion,int *pacientes_Prenatal,int *paciente_Arterial,int *paciente_Cronicos,int *paciente_OtroServicio){
    if((*tempBa) -> consultorioAnterior == 1){
        (*pacientes_Vacunacion)--;
        (*num_V)--;
    }else if((*tempBa) -> consultorioAnterior == 2){
        (*pacientes_Prenatal)--;
        (*num_P)--;
    }else if((*tempBa) -> consultorioAnterior == 3){
        (*paciente_Arterial)--;
        (*num_PA)--;
    }else if((*tempBa) -> consultorioAnterior == 4){
        (*num_EC)--;
        (*paciente_Cronicos)--;
    }else if((*tempBa) -> consultorioAnterior == 5){
        (*num_OS)--;
        (*paciente_OtroServicio)--;
    }
}

#endif