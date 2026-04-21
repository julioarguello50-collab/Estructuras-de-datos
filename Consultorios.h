#ifndef Consultorios_H
#define Consultorios_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"estructuras.h"
#include"registros.h"

//funciones para imprimir pacientes por consultas

//funcion para imprimir pacientes por consulta de vacunacion

void Consulta_Vacunacion(PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa ,FichaVacunacion **frente_V,FichaVacunacion **historial_V,FichaVacunacion **temp,FichaVacunacion **historial_ultimoV){
    int opc;
    printf("\nFicha: %d\n",(*frente_V) -> no_Ficha);
    printf("Nombre: %s %s\nEdad: %d\n",(*frente_V) -> nombre,(*frente_V) -> apellidos,(*frente_V) -> edad);
    printf("Los datos del paciente son correctos?\n1 - si/2 - no\n");
    scanf("%d",&opc);
    if(opc == 1){
        (*frente_V) -> atendido = 1;
         *temp = *frente_V;
        *frente_V = (*frente_V) -> sig;
        if(*historial_V == NULL){
            *historial_V = *temp;
            *historial_ultimoV = *temp;
        }else{
            (*historial_ultimoV) -> sig = *temp;
        }
        (*temp) -> sig = NULL;
        (*historial_ultimoV)  = *temp;
    }else{
        printf("1 - Sera actualizacion de datos de ultima hora/2 - Cambio de consulta\n");
        scanf("%d",&opc);
        if(opc == 1){
            getchar();
            printf("Digite el nombre del paciente: ");
            fgets((*frente_V) -> nombre,50,stdin);
            (*frente_V) -> nombre[strcspn((*frente_V) -> nombre, "\n")] = '\0';
            printf("Digite los apellidos: ");
            fgets((*frente_V) -> apellidos,50,stdin);
            (*frente_V) -> apellidos[strcspn((*frente_V) -> apellidos, "\n")] = '\0';
            printf("Digite la edad del paciente: ");
            scanf("%d",&(*frente_V) -> edad);
        }else{
            (*nuevoBase) = (struct PacienteBase*) malloc(sizeof(struct PacienteBase));

            strcpy((*nuevoBase) -> nombre,(*frente_V) -> nombre);
            strcpy((*nuevoBase) -> apellidos,(*frente_V) -> apellidos);
            (*nuevoBase) -> edad = (*frente_V) ->edad;
            (*nuevoBase) ->consultorioAnterior = 1; 

            if((*inicio) == NULL){
                (*inicio) = (*nuevoBase);
                (*final) = (*nuevoBase);
            }else{
                (*final) -> sig = (*nuevoBase);
                (*final) = (*nuevoBase);
            }

            (*nuevoBase) -> sig = NULL;
            *tempBa = *nuevoBase;
            (*frente_V) = (*frente_V) -> sig;
            printf("Para mover a un paciente a otro consultorio dirigase al menu principal en la opcion 4\n");
        }
        
    }
    
}

void Consulta_Prenatal(PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa,FichaControlPrenatal **frente_P,FichaControlPrenatal **historial_P,FichaControlPrenatal **temp_P,FichaControlPrenatal **historial_ultimoP){
    int opc = 0;
    printf("\nFicha: %d\n",(*frente_P) -> no_Ficha);
    printf("Nombre: %s %s\nEdad: %d\n",(*frente_P) -> nombre,(*frente_P) -> apellidos,(*frente_P) -> edad);
    printf("Los datos del paciente son correctos?\n1 - si/2 - no\n");
    scanf("%d",&opc);
    if(opc == 1){
        (*frente_P) -> atendido = 1;
        (*temp_P) = *frente_P;
        *frente_P = (*frente_P) -> sig;

        if(*historial_P == NULL){
            *historial_P = *temp_P;
            *historial_ultimoP = *temp_P;
        }else{
            (*historial_ultimoP) -> sig = *temp_P;
        }

        (*temp_P) -> sig = NULL;
        *historial_ultimoP = *temp_P;
    }else{
        printf("Que se requiere actualizar?\n1 - Datos del paciente/ 2 - Cambio de consultorio\n");
        scanf("%d",&opc);
        if(opc == 1){
            getchar();
            printf("Digite el nombre del paciente: ");
            fgets((*frente_P) -> nombre,50,stdin);
            (*frente_P) -> nombre[strcspn((*frente_P) -> nombre, "\n")] = '\0';

            printf("Digite los apellidos del paciente: ");
            fgets((*frente_P) -> apellidos,50,stdin);
            (*frente_P) -> apellidos[strcspn((*frente_P) -> apellidos,"\n")] = '\0';

            printf("Digite la edad del paciente: ");
            scanf("%d",&(*frente_P) -> edad);
        }else{
            (*nuevoBase) = (struct PacienteBase*) malloc(sizeof(struct PacienteBase));

            strcpy((*nuevoBase) -> nombre,(*frente_P) -> nombre);
            strcpy((*nuevoBase) -> apellidos,(*frente_P) -> apellidos);
            (*nuevoBase) -> edad = (*frente_P) ->edad;
            (*nuevoBase) ->consultorioAnterior = 2; 

            if((*inicio) == NULL){
                (*inicio) = (*nuevoBase);
                (*final) = (*nuevoBase);
            }else{
                (*final) -> sig = (*nuevoBase);
                (*final) = (*nuevoBase);
            }

            (*nuevoBase) -> sig = NULL;
            *tempBa = *nuevoBase;
            (*frente_P) = (*frente_P) -> sig;
            printf("Para mover a un paciente a otro consultorio dirigase al menu principal en la opcion 4\n");
        }
    }
}

void Consulta_PreArterial(PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa,FichaPresionArterial **frentePA,FichaPresionArterial **historial_PA,FichaPresionArterial **temp_PA,FichaPresionArterial **historial_ultimoPA){
    int opc = 0;
    printf("\nFicha: %d\n",(*frentePA) -> no_Ficha);
    printf("Nombre: %s %s\nEdad: %d\n",(*frentePA) -> nombre,(*frentePA) -> apellidos,(*frentePA) -> edad);
    printf("Los datos del paciente son correctos\n1 - si/2 - no\n");
    scanf("%d",&opc);
    if(opc == 1){
        (*frentePA) -> atendido = 1;
        (*temp_PA) = *frentePA;
        *frentePA = (*frentePA) -> sig;

        if(*historial_PA == NULL){
            *historial_PA = *temp_PA;
            *historial_ultimoPA = *temp_PA;
        }else{
            (*historial_ultimoPA) -> sig = *temp_PA;
        }

        (*temp_PA) -> sig = NULL;
        *historial_ultimoPA = *temp_PA;
    }else{
        printf("Que se requiere actualizar?\n1 - Datos de la ficha/2 - Cambio de ficha\n");
        scanf("%d",&opc);
        if(opc == 1){
            getchar();
            printf("Digite el nombre del paciente: ");
            fgets((*frentePA) -> nombre,50,stdin);
            (*frentePA) -> nombre[strcspn((*frentePA) -> nombre ,"\n")] = '\0';
            printf("Digite los apellidos del paciente: ");
            fgets((*frentePA) -> apellidos,50,stdin);
            (*frentePA) -> apellidos[strcspn((*frentePA) -> apellidos,"\n")] = '\0';
            printf("Digite la edad del paciente: ");
            scanf("%d",&(*frentePA) -> edad);
        }else{
            (*nuevoBase) = (struct PacienteBase*) malloc(sizeof(struct PacienteBase));

            strcpy((*nuevoBase) -> nombre,(*frentePA) -> nombre);
            strcpy((*nuevoBase) -> apellidos,(*frentePA) -> apellidos);
            (*nuevoBase) -> edad = (*frentePA) ->edad;
            (*nuevoBase) ->consultorioAnterior = 3; 

            if((*inicio) == NULL){
                (*inicio) = (*nuevoBase);
                (*final) = (*nuevoBase);
            }else{
                (*final) -> sig = (*nuevoBase);
                (*final) = (*nuevoBase);
            }

            (*nuevoBase) -> sig = NULL;
            *tempBa = *nuevoBase;
            (*frentePA) = (*frentePA) -> sig;
            printf("Para mover a un paciente a otro consultorio dirigase al menu principal en la opcion 4\n");
        }
    }
}

void Consulta_EnferCronica(PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa,FichaEnferCronica **frenteEC,FichaEnferCronica **historial_EC,FichaEnferCronica **temp_EC,FichaEnferCronica **historial_ultimoEC){
    int opc = 0;
        getchar();
        printf("\nFicha: %d\n",(*frenteEC) -> no_Ficha);
        printf("Nombre: %s %s\nEdad: %d\n",(*frenteEC) -> nombre,(*frenteEC) -> apellidos,(*frenteEC) -> edad);
        printf("Los datos del paciente son correctos\n1 - si/2 - no\n");
        scanf("%d",&opc);
        if(opc == 1){
            (*frenteEC) -> atendido = 1;
            (*temp_EC) = *frenteEC;
            *frenteEC = (*frenteEC) -> sig;

            if(*historial_EC == NULL){
                *historial_EC = *temp_EC;
                *historial_ultimoEC = *temp_EC;
            }else{
                (*historial_ultimoEC) -> sig = *temp_EC;
            }

            (*temp_EC) -> sig = NULL;
            *historial_ultimoEC = *temp_EC;
        }else{
            printf("Que se requiere actualizar?\n1 - Datos del paciente/2 - Cambio de consulta\n");
            scanf("%d",&opc);
            if(opc == 1){
                getchar();
                printf("Digite el nombre del paciente: ");
                fgets((*frenteEC) -> nombre,50,stdin);
                (*frenteEC) -> nombre[strcspn((*frenteEC) -> nombre ,"\n")] = '\0';
                printf("Digite los apellidos del paciente: ");
                fgets((*frenteEC) -> apellidos,50,stdin);
                (*frenteEC) -> apellidos[strcspn((*frenteEC) -> apellidos,"\n")] = '\0';
                printf("Digite la edad del paciente: ");
                scanf("%d",&(*frenteEC) -> edad);
            }else{
                (*nuevoBase) = (struct PacienteBase*) malloc(sizeof(struct PacienteBase));

                strcpy((*nuevoBase) -> nombre,(*frenteEC) -> nombre);
                strcpy((*nuevoBase) -> apellidos,(*frenteEC) -> apellidos);
                (*nuevoBase) -> edad = (*frenteEC) ->edad;
                (*nuevoBase) ->consultorioAnterior = 4; 

                if((*inicio) == NULL){
                    (*inicio) = (*nuevoBase);
                    (*final) = (*nuevoBase);
                }else{
                    (*final) -> sig = (*nuevoBase);
                    (*final) = (*nuevoBase);
                }

                (*nuevoBase) -> sig = NULL;
                *tempBa = *nuevoBase;
                (*frenteEC) = (*frenteEC) -> sig;
                printf("Para mover a un paciente a otro consultorio dirigase al menu principal en la opcion 4\n");
            }
        }
}

void Consulto_OtroServicio(PacienteBase **nuevoBase,PacienteBase **inicio,PacienteBase **final,PacienteBase **tempBa, OtroServicios **frenteOS,OtroServicios **historial_OS,OtroServicios **temp_OS,OtroServicios **historial_ultimoOS){
    int opc = 0;
        printf("\nFicha: %d\n",(*frenteOS) -> no_Ficha);
        printf("Nombre: %s %s\nEdad: %d\n",(*frenteOS) -> nombre,(*frenteOS) -> apellidos,(*frenteOS) -> edad);
        printf("Sintomas/causas: %s\n",(*frenteOS) ->sintomas);
        printf("Los datos del paciente son correctos\n1 - si/2 - no\n");
        scanf("%d",&opc);
        if(opc == 1){
            (*frenteOS) -> atendido = 1;
            (*temp_OS) = *frenteOS;
            *frenteOS = (*frenteOS) -> sig;

            if(*historial_OS == NULL){
                *historial_OS = *temp_OS;
                *historial_ultimoOS = *temp_OS;
            }else{
                (*historial_ultimoOS) -> sig = *temp_OS;
            }

            (*temp_OS) -> sig = NULL;
            *historial_ultimoOS = *temp_OS;
        }else{
            printf("Que se requiere actualizar?\n1 - Datos de la ficha/2 - Cambio de consulta\n");
            scanf("%d",&opc);
            if(opc == 1){
                getchar();
                printf("Digite el nombre del paciente: ");
                fgets((*frenteOS) -> nombre,50,stdin);
                (*frenteOS) -> nombre[strcspn((*frenteOS) -> nombre ,"\n")] = '\0';
                printf("Digite los apellidos del paciente: ");
                fgets((*frenteOS) -> apellidos,50,stdin);
                (*frenteOS) -> apellidos[strcspn((*frenteOS) -> apellidos,"\n")] = '\0';
                printf("Digite la edad del paciente: ");
                scanf("%d",&(*frenteOS) -> edad);
                getchar();
                printf("Describa brevemente los posibles sintomas/causas: ");
                fgets((*frenteOS) -> sintomas,80,stdin);
                (*frenteOS) -> sintomas[strcspn((*frenteOS) -> sintomas,"\n")] = '\0';
            }else{
                (*nuevoBase) = (struct PacienteBase*) malloc(sizeof(struct PacienteBase));

                strcpy((*nuevoBase) -> nombre,(*frenteOS) -> nombre);
                strcpy((*nuevoBase) -> apellidos,(*frenteOS) -> apellidos);
                strcpy((*nuevoBase) -> sintomas,(*frenteOS) -> sintomas);
                (*nuevoBase) -> edad = (*frenteOS) ->edad;
                (*nuevoBase) ->consultorioAnterior = 5; 

                if((*inicio) == NULL){
                    (*inicio) = (*nuevoBase);
                    (*final) = (*nuevoBase);
                }else{
                    (*final) -> sig = (*nuevoBase);
                    (*final) = (*nuevoBase);
                }

                (*nuevoBase) -> sig = NULL;
                *tempBa = *nuevoBase;
                (*frenteOS) = (*frenteOS) -> sig;
                printf("Para mover a un paciente a otro consultorio dirigase al menu principal en la opcion 4\n");
            }
        }
}

/*Para mañana seguir con la configuracion de las funciones en el menu principal para que no se te olvide pendejo
y ya veremos mañana que mas hace falta :)*/
#endif