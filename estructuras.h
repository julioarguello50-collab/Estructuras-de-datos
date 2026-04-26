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

typedef struct incidencia{
    int edad_Original;
    int edad_nueva;
    int no_Ficha;
    int tipoConsultorio;
    int tipoModificacion;
    int nuevo_Consultorio;
    char Nuevo_nombre[50];
    char nombre_Anterior[50];
    char nuevos_apellidos[50];
    char apellidos_anteriores[50];
    char modificacion[50];
    struct incidencia *sig;
}incidencia;

#endif