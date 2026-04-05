#include<stdio.h>
#include<stdlib.h>
#include"registros.h"
#include"estructuras.h"
#include"Consultorios.h"
#include"lista_espera.h"
#include"Reportes.h"
#include"Demanda_Servicios.h"
/*Equipo 2 Yin Yang
Julio Cesar Arguello Palomeque
Juan Jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Samuel de la Cruz Lopez
Jose Fernando Dominguez Monzon*/

int main(){
    //estos contadores son para los reportes
    int opc,pacientes_Vacunacion = 0,pacientes_Prenatal = 0,paciente_Arterial =0,paciente_Cronicos=0,resp,opc1;
    //estos contadores son de las estructuras
    int num_V = 0,num_P = 0, num_PA = 0, num_EC = 0,encontrado;
    //
    int No_lista;
    //Declaracion de las variables de las estructuras
    FichaVacunacion *frente_V = NULL, *ultimo_V =NULL, *nuevo_V= NULL,*historial_V = NULL,*temp = NULL;
    FichaControlPrenatal *frente_P =NULL, *ultimo_P =NULL, *nuevo_P =  NULL,*historial_P = NULL,*temp_P = NULL;
    FichaPresionArterial *frentePA =NULL, *ultimoPA =NULL, *nuevoPA= NULL,*historial_PA = NULL,*temp_PA = NULL;
    FichaEnferCronica *frenteEC =NULL, *ultimoEC =NULL, *nuevoEC =  NULL,*historial_EC = NULL,*temp_EC = NULL;
    
    do{
        printf("\n\nAdministracion de fichas\nConsulta Preventiva\n");
        printf("1 - Generar ficha\n2 - Pasar paciente a consulta\n3 - Reportes de consulta\n4 - Salir\n");
        printf("Digite una opcion\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                printf("\n\nGenerando Ficha\n");
            do{
                printf("Que tipo de consulta sera?\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermadades cronicas\n5 - Salir");
                printf("\nDigite una opcion\n");
                scanf("%d",&opc);
                getchar();
                switch(opc){
                    case 1:
                        nuevo_V = (struct FichaVacunacion *) malloc(sizeof(struct FichaVacunacion));
                        registrarPacienteVacunacion(&nuevo_V,&frente_V,&ultimo_V,&num_V,&pacientes_Vacunacion);
                    break;
                case 2:
                        nuevo_P = (struct FichaControlPrenatal*) malloc(sizeof (struct FichaControlPrenatal));
                        registrarPacienteConPrenatal(&nuevo_P,&frente_P,&ultimo_P,&num_P,&pacientes_Prenatal);
                    break;
                case 3:
                        nuevoPA = (struct FichaPresionArterial*) malloc(sizeof(struct FichaPresionArterial));
                        registrarPaciente_PresionAr(&nuevoPA,&frentePA,&ultimoPA,&num_PA,&paciente_Arterial);
                    break;
                case 4:
                        nuevoEC = (struct FichaEnferCronica*) malloc(sizeof(struct FichaEnferCronica));
                        registrarPaciente_Cronico(&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&paciente_Cronicos);
                    break;
                    case 5: printf("Regresando al menu\n");
                }
            }while(opc != 5);
            break;
            case 2:
            do{
                printf("\n\nGestion de consultas\n");
                printf("A que tipo de consulta ira el paciente?\n");
                printf("1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 -Enfermades cronicas\n5 - cancelar/salir\nDigite la opcion: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                    do{
                            if(frente_V == NULL){
                                printf("\n\nNo hay pacientes en la lista de espera\n\n");
                                break;
                            }else{
                                Consulta_Vacunacion(&frente_V,&historial_V,&num_V);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                            }
                        
                        }while(resp != 2 || frente_V == NULL);
                        system("pause");
                        system("cls");
                    break;
                    case 2:
                    do{
                        if(frente_P == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            break;
                        }else{
                                Consulta_Prenatal(&frente_P,&historial_P,&temp_P,&num_P);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                        }
                    }while(resp != 2 || frente_P == NULL);
                    system("pause");
                    system("cls");
                    break;
                    case 3:
                    do{
                        if(frentePA == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            break;
                        }else{
                        Consulta_PreArterial(&frentePA,&historial_PA,&temp_PA,&num_PA);
                        printf("Quieres pasar otro paciente?\n1 - si\n2 - no\n");
                        scanf("%d",&resp);
                        }
                    }while(resp != 2 || frentePA == NULL);
                    system("pause");
                    system("cls");
                    break;
                    case 4:
                    do{
                    if(frenteEC == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            break;
                        }else{
                                Consulta_EnferCronica(&frenteEC,&historial_EC,&temp_EC,&num_EC);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                        }
                    }while(resp != 2 || frenteEC == NULL);
                    system("pause");
                    system("cls");
                    break;
                }
            }while(opc != 5);
            break;
            case 3:
            printf("\n\nReportes de consulta\n");
            do{
                printf("Ingrese la opcion a usar\n1 - Reporte del dia\n2 - Reporte de pacientes pendientes\n3 - Servicios con mayor demanda\n4 - cancelar/salir\n");
                scanf("%d",&opc);
                switch(opc){
                case 1:
                printf("\n\nReporte de pacientes atendidos en el dia\n");
                if(pacientes_Vacunacion == 0 && pacientes_Prenatal  == 0 && paciente_Arterial == 0 && paciente_Cronicos== 0){
                    printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                }else{
                    printf("Consultas de Vacunacion\n");
                    //funciona mas o menos
                    Historial_Vacunacion(&nuevo_V,&frente_V,&temp,&historial_V,&No_lista,&encontrado);
                    //
                    Historial_Prenatal(&nuevo_P,&frente_P,&temp_P,&historial_P,&No_lista,&encontrado);
                    //
                    Historial_Arterial(&nuevoPA,&frentePA,&temp_PA,&historial_PA,&No_lista,&encontrado);
                    //
                    Historial_EnferCronica(&nuevoEC,&frenteEC,&temp_EC,&historial_EC,&No_lista,&encontrado);
                    printf("\n\nConsulta de Vacunacion: %d pacientes atendidos\nConsultas De Control Prenatal: %d pacientes atendidos",pacientes_Vacunacion,pacientes_Prenatal);
                    printf("\nConsultas de Presion arterial: %d pacientes atendidos\nConsultas de Enfermades Cronicas: %d pacientes atendidos\n\n",paciente_Arterial,paciente_Cronicos);
                }
                system("pause");
                system("cls");
                break;
                case 2: 
                if(num_V == 0 && num_P == 0 && num_EC == 0 && num_PA == 0){
                    printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                }else{
                    printf("\n\nListas de espera\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermades cronicas\n5 - cancelar/salir");
                    printf("Digite una opcion\n");
                    scanf("%d",&opc1);
                    switch(opc1){
                        case 1:
                        if(frente_V == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            LISTA_ESPERA_VACUNACION(&nuevo_V,&frente_V);
                        }
                        break;
                        case 2:
                        if(frente_P == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            LISTA_ESPERA_PRENATAL(&nuevo_P,&frente_P);
                        }
                        break;
                        case 3:
                        if(frentePA == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            LISTA_ESPERA_PREARTERIAL(&nuevoPA,&frentePA);
                        }
                        break;
                        case 4:
                        if(frenteEC == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            LISTA_ESPERA_CRONICOS(&nuevoEC,&frenteEC);
                        }
                        break;
                        case 5: printf("Regresando el menu\n");break;
                    }
                }
                break;
                case 3:
                if(pacientes_Vacunacion == 0 && paciente_Arterial == 0 && pacientes_Prenatal == 0 && paciente_Cronicos == 0){
                    printf("\n\nNo hay pacientes registrados\n\n");
                }else{
                    Mayor_Demanda(&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos);
                    Menor_Demanda(&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos);
                }
                break;
                case 4: printf("Redirigiendo al menu\n");break;
                }
            }while(opc != 4);
            break;
            case 4: printf("Saliendo del programa");break;
            default: printf("Opcion no valida\n");break;
        }
    }while(opc != 6);
    return 0;
}