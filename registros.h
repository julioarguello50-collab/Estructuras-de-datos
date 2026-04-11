#ifndef REGISTROS_H
#define REGISTROS_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"estructuras.h"

//Funcion para registrar pacientes del tipo de vacunacion
void registrarPacienteVacunacion(FichaVacunacion **nuevo, FichaVacunacion **frente, FichaVacunacion **ultimo,int *num_v,int *pacientes_Vacunacion){
    int opc = 0,confirmacion = 0,cancelar = 0;
    do{
        (*num_v)++;
        (*pacientes_Vacunacion)++;
        printf("\nDigite el nombre del paciente\n");
        fgets((*nuevo) -> nombre,50,stdin );
        //eliminamos el salto de linea que emplea fgets
        (*nuevo) -> nombre[strcspn((*nuevo) -> nombre, "\n")] = '\0';
        printf("\nDigite los apellidos del paciente\n");
        fgets((*nuevo) -> apellidos,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevo) -> apellidos[strcspn((*nuevo) -> apellidos, "\n")] = '\0';
        (*nuevo) -> no_Ficha = (*num_v);

        //confirmamos si el registro es correcto
        printf("\n\nVacunacion\nNombre completo:\n%s %s",(*nuevo) -> nombre,(*nuevo) -> apellidos);
        printf("\nNumero de ficha: %d\n\n",(*nuevo) -> no_Ficha);
        printf("Confirma que el registro es correcto\n1 - si\n2 - no\n");
        scanf("%d",&confirmacion);
        getchar();
        if(confirmacion == 1){
            if(*frente == NULL){
            *frente = *nuevo;
            }else{
            (*ultimo) -> sig = *nuevo;
            }
            (*nuevo) -> sig = NULL;
            *ultimo = *nuevo;
        }else if(confirmacion == 2){
            printf("Que se corregira?\n1 - Nombre del paciente\n2 - Ficha completa\n");
            scanf("%d",&opc);
            getchar();
            if(opc == 1){
                (*num_v)--;
                (*pacientes_Vacunacion)--;
            }
            else if(opc == 2){
            free(*nuevo);
            *nuevo = NULL;
            (*num_v)--;
            (*pacientes_Vacunacion)--;
            cancelar = 1;
            printf("\nRegistro cancelado. Volviendo al menu de registro\n");
            }
        }
    }while(confirmacion != 1 && !cancelar);

}

//Funcion para registrar pacientes del tipo de control prenatal
void registrarPacienteConPrenatal(FichaControlPrenatal **nuevo_P, FichaControlPrenatal **frente_P, FichaControlPrenatal **ultimo_P,int *num_P,int *pacientes_Prenatal){
    int opc = 0,confirmacion = 0, cancelar = 0;
    do{
        (*num_P)++;
        (*pacientes_Prenatal)++;
        printf("\nDigite el nombre del paciente\n");
        fgets((*nuevo_P) -> nombre,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevo_P) -> nombre[strcspn((*nuevo_P) -> nombre, "\n")] = '\0';
        printf("\nDigite los apellidos del paciente\n");
        //eliminamos el salto de linea que emplea fgets
        fgets((*nuevo_P) -> apellidos,50,stdin);
        (*nuevo_P) -> apellidos[strcspn((*nuevo_P) -> apellidos, "\n")] = '\0';
        (*nuevo_P) -> no_Ficha = (*num_P);

        printf("\n\nControl Prenatal\nNombre completo: %s %s\n",(*nuevo_P) -> nombre,(*nuevo_P) -> apellidos);
        printf("Numero de ficha: %d\n\n",(*nuevo_P) ->no_Ficha);
        printf("Confirma que el registro es correcto\n1 - si\n2 - no\n");
        scanf("%d",&confirmacion);
        getchar();
        if(confirmacion == 1){
            if(*frente_P == NULL){
            *frente_P = *nuevo_P;
            }else{
            (*ultimo_P) -> sig = *nuevo_P;
            }
            (*nuevo_P) -> sig = NULL;
            *ultimo_P = *nuevo_P;
        }else if(confirmacion == 2){
            printf("Que se corregira\n1 - Nombre completo\n2 - Ficha Completa\n");
            scanf("%d",&opc);
            getchar();
            if(opc == 1){
                (*num_P)--;
                (*pacientes_Prenatal)--;
            }else if(opc == 2){
                free(*nuevo_P);
                *nuevo_P = NULL;
                (*num_P)--;
                (*pacientes_Prenatal)--;
                cancelar = 1;
                printf("\nRegistro cancelado. Volviendo al menu de registro\n");
            }
        }
    }while(confirmacion != 1 && !cancelar);   
}

//Funcion para regsitrar pacientes del tipo presion arterial
void registrarPaciente_PresionAr(FichaPresionArterial **nuevoPA,FichaPresionArterial **frentePA,FichaPresionArterial **ultimoPA,int *num_PA,int *pacientes_Arterial){
    int opc = 0,confirmacion = 0,cancelar = 0;
    do{
        (*num_PA)++;
        (*pacientes_Arterial)++;
        printf("\nDigite el nombre del paciente\n");
        fgets((*nuevoPA) -> nombre,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevoPA) -> nombre[strcspn((*nuevoPA) -> nombre, "\n")] = '\0';
        printf("\nDigite los apellidos del paciente\n");
        fgets((*nuevoPA) -> apellidos,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevoPA) -> apellidos[strcspn((*nuevoPA) -> apellidos, "\n")] = '\0';
        (*nuevoPA) -> no_Ficha = (*num_PA);

        printf("\n\nPresion arterial\nNombre completo: %s %s\n",(*nuevoPA) -> nombre,(*nuevoPA) -> apellidos);
        printf("Numero de ficha: %d\n\n",(*nuevoPA) -> no_Ficha);
        printf("Confirma que el registro es correcto\n1 - si/2 - NO\n");
        scanf("%d",&confirmacion);
        getchar();
        if(confirmacion == 1){
            if(*frentePA == NULL){
                *frentePA = *nuevoPA;
            }else{
                (*ultimoPA) -> sig = *nuevoPA;
            }
            (*nuevoPA) -> sig = NULL;
            *ultimoPA = *nuevoPA;
        }else if(confirmacion == 2){
            printf("Que se corregira\n1 - Nombre completo\n2 - Ficha Completa\n");
            scanf("%d",&opc);
            getchar();
            if(opc == 1){
                (*num_PA)--;
                (*pacientes_Arterial)--;
            }else if(opc == 2){
                free(*nuevoPA);
                *nuevoPA = NULL;
                (*num_PA)--;
                (*pacientes_Arterial)--;
                cancelar = 1;
                printf("\nRegistro cancelado. Volviendo al menu de registro\n");
            }
        }
    }while(confirmacion != 1 && !cancelar);
}

//Funcion para registrar pacientes del tipo de enfermedades cronicas
void registrarPaciente_Cronico(FichaEnferCronica **nuevoEC,FichaEnferCronica **frenteEC,FichaEnferCronica **ultimoEC,int *num_EC,int *pacientes_Cronicos){
    int opc = 0,confirmarcion = 0,cancelar = 0;
    do{
        (*num_EC)++;
        (*pacientes_Cronicos)++;
        printf("\nDigite el nombre del paciente\n");
        fgets((*nuevoEC) -> nombre,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevoEC) -> nombre[strcspn((*nuevoEC) -> nombre, "\n")] = '\0';
        printf("\nDigite los apellidos del paciente\n");
        fgets((*nuevoEC) -> apellidos,50,stdin);
        //eliminamos el salto de linea que emplea fgets
        (*nuevoEC) -> apellidos[strcspn((*nuevoEC) -> apellidos, "\n")] = '\0';
        (*nuevoEC) -> no_Ficha = (*num_EC);

        printf("\n\nEnfermedades cronicas\nNombre completo: %s %s\n",(*nuevoEC) -> nombre,(*nuevoEC) -> apellidos);
        printf("Numero de ficha: %d\n\n",(*nuevoEC) -> no_Ficha);
        printf("Confirma que el registro es correcto?\n1 - si/2 - NO\n");
        scanf("%d",&confirmarcion);
        if(confirmarcion == 1){
            if(*frenteEC == NULL){
                *frenteEC = *nuevoEC;
                (*nuevoEC) -> sig = NULL;
            }else{
                (*ultimoEC) -> sig = *nuevoEC;
                (*nuevoEC) -> sig = NULL;
            }
            *ultimoEC = *nuevoEC;
        }else if(confirmarcion == 2){
            printf("Que se corregira\n1 - Nombre completo\n2 - Ficha Completa\n");
            scanf("%d",&opc);
            getchar();
            if(opc == 1){
                (*num_EC)--;
                (*pacientes_Cronicos)--;
            }else if(opc == 2){
                free(*nuevoEC);
                *nuevoEC = NULL;
                (*num_EC)--;
                (*pacientes_Cronicos)--;
                cancelar = 1;
                printf("\nRegistro cancelado. Volviendo al menu de registro\n");
            }
        }
    }while(confirmarcion != 1 && !cancelar);
}

#endif
