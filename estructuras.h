#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include<stdio.h>

typedef struct FichaVacunacion{
    int no_Ficha;
    char nombre[50];
    char apellidos[50];
    struct FichaVacunacion *sig;
}FichaVacunacion;

typedef struct FichaControlPrenatal{
    int no_Ficha;
    char nombre[50];
    char apellidos[50];
    struct FichaControlPrenatal *sig;
}FichaControlPrenatal;

typedef struct FichaPresionArterial{
    int no_Ficha;
    char nombre[50];
    char apellidos[50];
    struct FichaPresionArterial *sig;
}FichaPresionArterial;

typedef struct FichaEnferCronica{
    int no_Ficha;
    char nombre[50];
    char apellidos[50];
    struct FichaEnferCronica *sig;
}FichaEnferCronica;

#endif