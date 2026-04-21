#include<stdio.h>
#include<stdlib.h>
#include"registros.h"
#include"estructuras.h"
#include"Consultorios.h"
#include"lista_espera.h"
#include"Reportes.h"
#include"Demanda_Servicios.h"
#include"Update.h"
#include"Restablecimiento.h"
/*Equipo 2 Yin Yang
Julio Cesar Arguello Palomeque
Juan Jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Samuel de la Cruz Lopez
Jose Fernando Dominguez Monzon*/

int main(){
    //estos contadores son para los reportes
    int opc = 0,pacientes_Vacunacion = 0,pacientes_Prenatal = 0,paciente_Arterial =0,paciente_Cronicos=0,paciente_OtroServicio = 0,resp,opc1;
    //estos contadores son de las estructuras
    int num_V = 0,num_P = 0, num_PA = 0, num_EC = 0,num_OS = 0,encontrado,No_lista,opcion;
    //
    //Declaracion de las variables de las estructuras
    FichaVacunacion *frente_V = NULL, *ultimo_V =NULL, *nuevo_V= NULL,*historial_V = NULL,*temp = NULL,*historial_ultimoV = NULL;
    FichaControlPrenatal *frente_P =NULL, *ultimo_P =NULL, *nuevo_P =  NULL,*historial_P = NULL,*temp_P = NULL,*historial_ultimoP = NULL;
    FichaPresionArterial *frentePA =NULL, *ultimoPA =NULL, *nuevoPA= NULL,*historial_PA = NULL,*temp_PA = NULL,*historial_ultimoPA = NULL;
    FichaEnferCronica *frenteEC =NULL, *ultimoEC =NULL, *nuevoEC =  NULL,*historial_EC = NULL,*temp_EC = NULL,*historial_ultimoEC = NULL;
    OtroServicios *frenteOS = NULL, *ultimoOS = NULL,*nuevoOS = NULL,*historial_OS = NULL,*temp_OS = NULL,*historial_ultimoOS = NULL;
    PacienteBase *inicio = NULL,*nuevoBase = NULL,*final = NULL,*tempBa = NULL;
    
    do{
        opc = 0;
        printf("\n\nAdministracion de fichas\nConsulta Preventiva\n");
        printf("1 - Generar ficha\n2 - Pasar paciente a consulta\n3 - Reportes de consulta\n4 - Correcion de ultima hora\n5 - Salir\n");
        printf("Digite una opcion\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
            do{
                printf("\n\nGenerando Ficha\n");
                printf("Que tipo de consulta sera?\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermadades cronicas\n5 - Otro(especifique)\n6 -salir\n");
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
                    case 5: 
                        nuevoOS = (struct OtroServicios *) malloc(sizeof(struct OtroServicios));
                        registrarOtroServicio(&nuevoOS,&frenteOS,&ultimoOS,&num_OS,&paciente_OtroServicio);
                    break;
                    case 6: printf("Regresando al menu\n");break;
                    default: printf("Opcion no valida\n");break;
                }
            }while(opc != 6);
            printf("\n\n");
            break;
            case 2:
            do{
                printf("\n\nGestion de consultas\n");
                printf("A que tipo de consulta ira el paciente?\n");
                printf("1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 -Enfermades cronicas\n5 - Otros servicios\n6 - Cancelar/salir\nDigite la opcion: ");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                    resp = 1;
                    do{
                            if(frente_V == NULL){
                                printf("\n\nNo hay pacientes en la lista de espera\n\n");
                                resp = 2;
                            }else{
                                Consulta_Vacunacion(&nuevoBase,&inicio,&final,&tempBa,&frente_V,&historial_V,&temp,&historial_ultimoV);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                            }
                    }while(resp != 2);
                    break;
                    case 2:
                    resp = 1;
                    do{
                        if(frente_P == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp = 2;
                        }else{
                                Consulta_Prenatal(&nuevoBase,&inicio,&final,&tempBa,&frente_P,&historial_P,&temp_P,&historial_ultimoP);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                        }
                    }while(resp != 2);
                    break;
                    case 3:
                    resp = 1;
                    do{
                        if(frentePA == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp = 2;
                        }else{
                        Consulta_PreArterial(&nuevoBase,&inicio,&final,&tempBa,&frentePA,&historial_PA,&temp_PA,&historial_ultimoPA);
                        printf("Quieres pasar otro paciente?\n1 - si\n2 - no\n");
                        scanf("%d",&resp);
                        }
                    }while(resp != 2);
                    break;
                    case 4:
                    resp = 1;
                    do{
                        if(frenteEC == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp = 2;
                        }else{
                                Consulta_EnferCronica(&nuevoBase,&inicio,&final,&tempBa,&frenteEC,&historial_EC,&temp_EC,&historial_ultimoEC);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp);
                        }
                    }while(resp != 2);
                    break;
                    case 5:
                    do{
                        if(frenteOS == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp = 2;
                        }else{
                            Consulto_OtroServicio(&nuevoBase,&inicio,&final,&tempBa,&frenteOS,&historial_OS,&temp_OS,&historial_ultimoOS);
                            printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                            scanf("%d",&resp);
                        }
                    }while(resp != 2);
                    break;
                    case 6: printf("Regresando al menu principal\n");break;
                    default: printf("Opcion no valida\n");break;
                }
            }while(opc != 6);
            printf("\n\n");
            break;
            case 3:
            printf("\n\nReportes de consulta\n");
            do{
                opc = 0;
                printf("Ingrese la opcion a usar\n1 - Reporte del dia\n2 - Reporte de pacientes pendientes\n3 - Servicios con mayor demanda\n4 - cancelar/salir\n");
                scanf("%d",&opc);
                switch(opc){
                    case 1:
                    printf("\n\nReporte de pacientes atendidos en el dia\n");
                    if(pacientes_Vacunacion == 0 && pacientes_Prenatal  == 0 && paciente_Arterial == 0 && paciente_Cronicos== 0 && paciente_OtroServicio == 0){
                        printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                    }else{
                        printf("\n");
                        printf("Consultas de Vacunacion\n");

                        Historial_Vacunacion(&temp,&historial_V,&No_lista,&encontrado);
                        //
                        Historial_Prenatal(&temp_P,&historial_P,&No_lista,&encontrado);
                        //
                        Historial_Arterial(&temp_PA,&historial_PA,&No_lista,&encontrado);
                        //
                        Historial_EnferCronica(&temp_EC,&historial_EC,&No_lista,&encontrado);
                        //
                        Historial_OtroServicio(&temp_OS,&historial_OS,&No_lista,&encontrado);
                        
                        printf("\n\nConsulta de Vacunacion: %d pacientes atendidos\nConsultas De Control Prenatal: %d pacientes atendidos",pacientes_Vacunacion,pacientes_Prenatal);
                        printf("\nConsultas de Presion arterial: %d pacientes atendidos\nConsultas de Enfermades Cronicas: %d pacientes atendidos\n",paciente_Arterial,paciente_Cronicos);
                        printf("Consultas de otros servicios: %d pacientes atendidos\n\n",paciente_OtroServicio);
                        
                    }
                    break;
                    case 2: 
                    if(num_V == 0 && num_P == 0 && num_EC == 0 && num_PA == 0 && num_OS == 0){
                        printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                    }else{
                        do{
                            printf("\n\nListas de espera\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermades cronicas\n5 - Otro Servicio\n6 - cancelar/salir");
                            printf("\nDigite una opcion\n");
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
                                case 5: 
                                if(frenteOS == NULL){
                                    printf("\n\nNo hay pacientes en lista de espera\n\n");
                                }else{
                                    printf("\n\n");
                                    LISTA_ESPERA_OTROSSERVICIOS(&nuevoOS,&frenteOS);
                                }
                                break;
                                case 6: printf("Regresando al menu\n");break;
                                default: printf("Opcion no valida\n");
                            }
                        }while(opc1 != 5);
                    }
                    break;
                    case 3:
                        if(pacientes_Vacunacion == 0 && paciente_Arterial == 0 && pacientes_Prenatal == 0 && paciente_Cronicos == 0 && paciente_OtroServicio == 0){
                            printf("\n\nNo hay pacientes registrados\n\n");
                        }else{
                            Mayor_Demanda(&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            Menor_Demanda(&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                        }
                    break;
                    case 4: printf("Redirigiendo al menu\n");break;
                    default: printf("Opcion no valida\n");break;
                }
            }while(opc != 4);
            printf("\n\n");
            break;
            case 4:
            printf("Pacientes en lista de movimiento\n");
            for((*nuevoBase) = (*final); nuevoBase != NULL;nuevoBase = nuevoBase -> sig){
                printf("\nConsultorio de procedencia: %d\nNombre completo: %s %s\nEdad: %d\n",nuevoBase ->consultorioAnterior,nuevoBase -> nombre, nuevoBase -> apellidos,nuevoBase -> edad);
            }
            printf("\n");
            printf("\nCambio de consultorio de ultima hora\nA que consultorio sera transeferido el paciente?\n");
            printf("1 - Consultorio de vacunacion\n2 - Control Prenatal\n3 - Presion Arterial\n4 - Enfermedades cronicas\n5 - Otros Servicios\n6 - Salir/cancelar\nDigite una opcion\n");
            scanf("%d",&resp);
            getchar();
            switch(resp){
                case 1:
                do{
                    printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                    scanf("%d",&opc);
                }while(opc != 1 && opc != 2);
                if(opc == 1){
                    menuAccionVacunacion(&final,&nuevo_V,&frente_V,&ultimo_V,&num_V);
                    eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                    reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                }else if(opc == 2){
                    restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                        &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                }
                break;
                case 2:
                do{
                    printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                    scanf("%d",&opc);
                }while(opc != 1 && opc != 2);
                if(opc == 1){
                    menuAccionPrenatal(&final,&nuevo_P,&frente_P,&ultimo_P,&num_P);
                    eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                    reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                }else if(opc == 2){
                    restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                        &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                }
                break;
                case 3:
                do{
                    printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                    scanf("%d",&opc);
                }while(opc != 1 && opc != 2);
                if(opc == 1){
                    menuAccionPresionArterial(&final,&nuevoPA,&frentePA,&ultimoPA,&num_PA);
                    eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                    reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                }else if(opc == 2){
                    restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                        &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                }
                break;
                case 4: 
                do{
                    printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                    scanf("%d",&opc);
                }while(opc != 1 && opc != 2);
                if(opc == 1){
                    menuAccionEnferCronica(&final,&nuevoEC,&frenteEC,&ultimoEC,&num_EC);
                    eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                    reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                }else if(opc == 2){
                    restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                        &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                }
                break;
                case 5:
                do{
                    printf("Confirma  que el cambio de la ficha es correcto?\n1 -si \n2 -no\n");
                    scanf("%d",&opc);
                }while(opc != 1 && opc != 2);
                if(opc == 1){
                    menuAccionOtroServicio(&final,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                    reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                }else if(opc == 2){
                    restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                        &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                    limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                }
                break;
                case 6: printf("Regresando al menu principal\n");break;
                default: printf("Opcion no valida\n");break;
            }
            
            break;
            case 5: printf("Saliendo del programa\n"); break;
            default: printf("Opcion no valida\n");break;
        }
    }while(opcion != 6);
    return 0;
}
/*solucionar el problema del caso 3*/