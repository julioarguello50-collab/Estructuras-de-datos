#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include<stdio.h>

typedef struct FichaVacunacion{
    int no_Ficha;
    int atendido;
    int edad;
    char nombre[50];
    char apellidos[50];
    struct FichaVacunacion *sig;
}FichaVacunacion;

typedef struct FichaControlPrenatal{
    int no_Ficha;
    int atendido;
    int edad;
    char nombre[50];
    char apellidos[50];
    struct FichaControlPrenatal *sig;
}FichaControlPrenatal;

typedef struct FichaPresionArterial{
    int no_Ficha;
    int atendido;
    int edad;
    char nombre[50];
    char apellidos[50];
    struct FichaPresionArterial *sig;
}FichaPresionArterial;

typedef struct FichaEnferCronica{
    int no_Ficha;
    int atendido;
    int edad;
    char nombre[50];
    char apellidos[50];
    struct FichaEnferCronica *sig;
}FichaEnferCronica;

typedef struct OtroServicios{
    int no_Ficha;
    int atendido;
    int edad;
    char nombre[50];
    char apellidos[50];
    char sintomas[80];
    struct OtroServicios *sig;
}OtroServicios;

//estructuras de pilas de acciones

typedef struct PacienteBase
{
    int edad;
    int consultorioAnterior;
    int nuevoConsultorio;
    char nombre[50];
    char apellidos[50];
    char sintomas[50];//solo para el caso de servicios de OtroServicios
    struct PacienteBase *sig;
}PacienteBase;

#endif