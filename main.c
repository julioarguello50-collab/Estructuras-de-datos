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
#include"Alta_Incidencias.h"
#include"Incidencia_Datos.h"
#include"Incidencia_Consultorio.h"
/*Equipo 2 Yin Yang
Julio Cesar Arguello Palomeque
Juan Jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Samuel de la Cruz Lopez
Jose Fernando Dominguez Monzon*/

int main(){
    //estos contadores son para los reportes
    int pacientes_Vacunacion = 0,pacientes_Prenatal = 0,paciente_Arterial =0,paciente_Cronicos=0,paciente_OtroServicio = 0;
    //variables para los menus
    int opcion_GenerandoFicha = 0,opcion_ReportesConsulta = 0,opcion_ListaConsulta = 0,resp_CambioConsultorio = 0,opcion_Incidencias = 0,resp_gestionConsulta,opcion_ListaEspera = 0;
    //estos contadores son de las estructuras
    int num_V = 0,num_P = 0, num_PA = 0, num_EC = 0,num_OS = 0;
    int encontrado,No_lista,opcion,buscar_ficha,contador_incidencias = 0;
    //
    //Declaracion de las variables de las estructuras
    FichaVacunacion *frente_V = NULL, *ultimo_V =NULL, *nuevo_V= NULL,*historial_V = NULL,*temp = NULL,*historial_ultimoV = NULL;
    FichaControlPrenatal *frente_P =NULL, *ultimo_P =NULL, *nuevo_P =  NULL,*historial_P = NULL,*temp_P = NULL,*historial_ultimoP = NULL;
    FichaPresionArterial *frentePA =NULL, *ultimoPA =NULL, *nuevoPA= NULL,*historial_PA = NULL,*temp_PA = NULL,*historial_ultimoPA = NULL;
    FichaEnferCronica *frenteEC =NULL, *ultimoEC =NULL, *nuevoEC =  NULL,*historial_EC = NULL,*temp_EC = NULL,*historial_ultimoEC = NULL;
    OtroServicios *frenteOS = NULL, *ultimoOS = NULL,*nuevoOS = NULL,*historial_OS = NULL,*temp_OS = NULL,*historial_ultimoOS = NULL;
    PacienteBase *inicio = NULL,*nuevoBase = NULL,*final = NULL,*tempBa = NULL;
    incidencia *nuevo_Incidencia = NULL, *historial_incidencia = NULL,*temp_incidencia = NULL,*inicio_incidencia = NULL;
    
    do{
        opcion_GenerandoFicha = 0;
        printf("\n\nAdministracion de fichas\nConsulta Preventiva\n");
        printf("1 - Generar ficha\n2 - Pasar paciente a consulta\n3 - Reportes de consulta\n4 - Cambio de consultorio\n5 - Incidencias\n6 - salir\n");
        printf("Digite una opcion\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
            do{
                printf("\n\nGenerando Ficha\n");
                printf("Que tipo de consulta sera?\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermadades cronicas\n5 - Otro(especifique)\n6 -salir\n");
                printf("\nDigite una opcion\n");
                scanf("%d",&opcion_GenerandoFicha);
                getchar();
                switch(opcion_GenerandoFicha){
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
            }while(opcion_GenerandoFicha != 6);
            printf("\n\n");
            break;
            case 2:
            do{
                printf("\n\nGestion de consultas\n");
                printf("A que tipo de consulta ira el paciente?\n");
                printf("1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 -Enfermades cronicas\n5 - Otros servicios\n6 - Cancelar/salir\nDigite la opcion: ");
                scanf("%d",&opcion_ListaConsulta);
                switch(opcion_ListaConsulta){
                    case 1:
                    resp_gestionConsulta = 1;
                    do{
                            if(frente_V == NULL){
                                printf("\n\nNo hay pacientes en la lista de espera\n\n");
                                resp_gestionConsulta = 2;
                            }else{
                                Consulta_Vacunacion(&nuevoBase,&inicio,&final,&tempBa,&frente_V,&historial_V,&temp,&historial_ultimoV,&nuevo_Incidencia,&historial_incidencia);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp_gestionConsulta);
                            }
                    }while(resp_gestionConsulta != 2);
                    break;
                    case 2:
                    resp_gestionConsulta = 1;
                    do{
                        if(frente_P == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp_gestionConsulta = 2;
                        }else{
                                Consulta_ControlPrenatal(&nuevoBase,&inicio,&final,&tempBa,&frente_P,&historial_P,&temp_P,&historial_ultimoP,&nuevo_Incidencia,&historial_incidencia);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp_gestionConsulta);
                        }
                    }while(resp_gestionConsulta != 2);
                    break;
                    case 3:
                    resp_gestionConsulta = 1;
                    do{
                        if(frentePA == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp_gestionConsulta = 2;
                        }else{
                        Consulta_PresionArterial(&nuevoBase,&inicio,&final,&tempBa,&frentePA,&historial_PA,&temp_PA,&historial_ultimoPA,&nuevo_Incidencia,&historial_incidencia);
                        printf("Quieres pasar otro paciente?\n1 - si\n2 - no\n");
                        scanf("%d",&resp_gestionConsulta);
                        }
                    }while(resp_gestionConsulta != 2);
                    break;
                    case 4:
                    resp_gestionConsulta = 1;
                    do{
                        if(frenteEC == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp_gestionConsulta = 2;
                        }else{
                                Consulta_EnferCronica(&nuevoBase,&inicio,&final,&tempBa,&frenteEC,&historial_EC,&temp_EC,&historial_ultimoEC,&nuevo_Incidencia,&historial_incidencia);
                                printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                                scanf("%d",&resp_gestionConsulta);
                        }
                    }while(resp_gestionConsulta != 2);
                    break;
                    case 5:
                    do{
                        if(frenteOS == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            resp_gestionConsulta = 2;
                        }else{
                            Consulta_OtrosServicios(&nuevoBase,&inicio,&final,&tempBa,&frenteOS,&historial_OS,&temp_OS,&historial_ultimoOS,&nuevo_Incidencia,&historial_incidencia);
                            printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                            scanf("%d",&resp_gestionConsulta);
                        }
                    }while(resp_gestionConsulta != 2);
                    break;
                    case 6: printf("Regresando al menu principal\n");break;
                    default: printf("Opcion no valida\n");break;
                }
            }while(opcion_ListaConsulta != 6);
            printf("\n\n");
            break;
            case 3:
            printf("\n\nReportes de consulta\n");
            do{
                opcion_ReportesConsulta = 0;
                printf("Ingrese la opcion a usar\n1 - Reporte del dia\n2 - Reporte de pacientes pendientes\n3 - Servicios con mayor demanda\n4 - cancelar/salir\n");
                scanf("%d",&opcion_ReportesConsulta);
                switch(opcion_ReportesConsulta){
                    case 1:
                    printf("\n\nReporte de pacientes atendidos en el dia\n");
                    if(pacientes_Vacunacion == 0 && pacientes_Prenatal  == 0 && paciente_Arterial == 0 && paciente_Cronicos== 0 && paciente_OtroServicio == 0){
                        printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                    }else{
                        printf("\n");

                        Historial_Vacunacion(&temp,&historial_V,&No_lista,&encontrado);
                        //
                        Historial_Prenatal(&temp_P,&historial_P,&No_lista,&encontrado);
                        //
                        Historial_Arterial(&temp_PA,&historial_PA,&No_lista,&encontrado);
                        //
                        Historial_EnferCronica(&temp_EC,&historial_EC,&No_lista,&encontrado);
                        //
                        Historial_OtroServicio(&temp_OS,&historial_OS,&No_lista,&encontrado);
                        //
                        Historial_Incidencias(&temp_incidencia,&historial_incidencia,&contador_incidencias);
                        
                        printf("\n\nConsulta de Vacunacion: %d pacientes atendidos\nConsultas De Control Prenatal: %d pacientes atendidos",pacientes_Vacunacion,pacientes_Prenatal);
                        printf("\nConsultas de Presion arterial: %d pacientes atendidos\nConsultas de Enfermades Cronicas: %d pacientes atendidos\n",paciente_Arterial,paciente_Cronicos);
                        printf("Consultas de otros servicios: %d pacientes atendidos\n",paciente_OtroServicio);
                        printf("Incidencias: %d pacientes con incidencias\n\n",contador_incidencias);
                        
                    }
                    break;
                    case 2: 
                    if(num_V == 0 && num_P == 0 && num_EC == 0 && num_PA == 0 && num_OS == 0){
                        printf("\n\nNo hay pacientes de ningun tipo por antender\n\n");
                    }else{
                        do{
                            printf("\n\nListas de espera\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermades cronicas\n5 - Otro Servicio\n6 - cancelar/salir");
                            printf("\nDigite una opcion\n");
                            scanf("%d",&opcion_ListaEspera);
                            switch(opcion_ListaEspera){
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
                        }while(opcion_ListaEspera != 6);
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
            }while(opcion_ReportesConsulta != 4);
            printf("\n\n");
            break;
            case 4:
                printf("Pacientes en lista de movimiento\n");
                for((*nuevoBase) = (*final); nuevoBase != NULL;nuevoBase = nuevoBase -> sig){
                    printf("\nConsultorio de procedencia: %d\nNombre completo: %s %s\nEdad: %d\n",nuevoBase ->consultorioAnterior,nuevoBase -> nombre, nuevoBase -> apellidos,nuevoBase -> edad);
                }
                do{
                    do{
                        printf("\n");
                        printf("\nCambio de consultorio de ultima hora\nA que consultorio sera transeferido el paciente?\n");
                        printf("1 - Consultorio de vacunacion\n2 - Control Prenatal\n3 - Presion Arterial\n4 - Enfermedades cronicas\n5 - Otros Servicios\n6 - Salir/cancelar\nDigite una opcion\n");
                        scanf("%d",&resp_CambioConsultorio);
                        if(final -> consultorioAnterior == resp_CambioConsultorio){
                            printf("No se puede trasladar al mismo consultorio\n");
                        }
                    }while(final -> consultorioAnterior == resp_CambioConsultorio);
                    getchar();
                
                    switch(resp_CambioConsultorio){
                        case 1:
                            do{
                                printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                                scanf("%d",&opcion_GenerandoFicha);
                            }while(opcion_GenerandoFicha != 1 && opcion_GenerandoFicha != 2);
                            if(opcion_GenerandoFicha == 1){
                                tempBa = final;
                                menuAccionVacunacion(&historial_incidencia,&final,&nuevo_V,&frente_V,&ultimo_V,&num_V,&pacientes_Vacunacion);
                                eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                                reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            }else if(opcion_GenerandoFicha == 2){
                                restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                                    &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                                limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                            }
                        break;
                        case 2:
                            do{
                                printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                                scanf("%d",&opcion_GenerandoFicha);
                            }while(opcion_GenerandoFicha != 1 && opcion_GenerandoFicha != 2);
                            if(opcion_GenerandoFicha == 1){
                                tempBa = final;
                                menuAccionPrenatal(&historial_incidencia,&final,&nuevo_P,&frente_P,&ultimo_P,&num_P,&pacientes_Prenatal);
                                eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                                reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            }else if(opcion_GenerandoFicha == 2){
                                restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                                    &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                                limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                            }
                        break;
                        case 3:
                            do{
                                printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                                scanf("%d",&opcion_GenerandoFicha);
                            }while(opcion_GenerandoFicha != 1 && opcion_GenerandoFicha != 2);
                            if(opcion_GenerandoFicha == 1){
                                tempBa = final;
                                menuAccionPresionArterial(&historial_incidencia,&final,&nuevoPA,&frentePA,&ultimoPA,&num_PA,&paciente_Arterial);
                                eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                                reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            }else if(opcion_GenerandoFicha == 2){
                                restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                                    &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                                limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                            }
                        break;
                        case 4: 
                            do{
                                printf("Confirma que el cambio de la ficha es correcto?\n1 - si\n2 - no\n");
                                scanf("%d",&opcion_GenerandoFicha);
                            }while(opcion_GenerandoFicha != 1 && opcion_GenerandoFicha != 2);
                            if(opcion_GenerandoFicha == 1){
                                tempBa = final;
                                menuAccionEnferCronica(&historial_incidencia,&final,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&paciente_Cronicos);
                                eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                                reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            }else if(opcion_GenerandoFicha == 2){
                                restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                                    &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                                limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                            }
                        break;
                        case 5:
                            do{
                                printf("Confirma  que el cambio de la ficha es correcto?\n1 -si \n2 -no\n");
                                scanf("%d",&opcion_GenerandoFicha);
                            }while(opcion_GenerandoFicha != 1 && opcion_GenerandoFicha != 2);
                            if(opcion_GenerandoFicha == 1){
                                tempBa = final;
                                menuAccionOtroServicio(&historial_incidencia,&final,&nuevoOS,&frenteOS,&ultimoOS,&num_OS,&paciente_OtroServicio);
                                eliminarConsultorioAnterior(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                                reduccionContadores(&tempBa,&num_V,&num_P,&num_PA,&num_EC,&num_OS,&pacientes_Vacunacion,&pacientes_Prenatal,&paciente_Arterial,&paciente_Cronicos,&paciente_OtroServicio);
                            }else if(opcion_GenerandoFicha == 2){
                                restablecerPaciente(&inicio,&tempBa,&nuevo_V,&frente_V,&ultimo_V,&num_V,&nuevo_P,&frente_P,&ultimo_P,&num_P,
                                                    &nuevoPA,&frentePA,&ultimoPA,&num_PA,&nuevoEC,&frenteEC,&ultimoEC,&num_EC,&nuevoOS,&frenteOS,&ultimoOS,&num_OS);
                                limpiarConsultorio(&tempBa,&nuevo_V,&nuevo_P,&nuevoPA,&nuevoEC,&nuevoOS);
                            }
                        break;
                        case 6: printf("Regresando al menu principal\n");break;
                        default: printf("Opcion no valida\n");break;
                    }
                }while(resp_CambioConsultorio != 6);
            break;
            case 5:
            do{
                printf("\nMenu de incidencias\n1 - Dar de alta incidencia\n2 - Corregir incidencia\n3 - Reportes de incidencias\n4 - salir/cancelar\nDigite la opcion: ");
                scanf("%d",&opcion_Incidencias);

                switch(opcion_Incidencias){
                    case 1:
                        nuevo_Incidencia = (struct incidencia *) malloc(sizeof(struct incidencia));

                        printf("\nIncidencias\n1 - Datos de la ficha erroneos\n2 - Cambio de consultorio\nDigite una opcion: ");
                        scanf("%d",&nuevo_Incidencia->tipoModificacion);

                        printf("\nDe que consultorio es la ficha\n");
                        printf("\n1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 - Enfermedades cronicas\n5 - Otros servicios\n");
                        printf("Digite una opcion: ");
                        scanf("%d",&opcion_GenerandoFicha);
                        switch(opcion_GenerandoFicha){
                            case 1:
                                Alta_incidenciaVacunacion(&nuevo_Incidencia,&inicio_incidencia,&nuevo_V,&frente_V,&encontrado,&buscar_ficha);
                            break;
                            case 2:
                                Alta_incidenciaControlPrenatal(&nuevo_Incidencia,&inicio_incidencia,&nuevo_P,&frente_P,&encontrado,&buscar_ficha);
                            break;
                            case 3:
                                Alta_incidenciaPresionArterial(&nuevo_Incidencia,&inicio_incidencia,&nuevoPA,&frentePA,&encontrado,&buscar_ficha);
                            break;
                            case 4:
                                Alta_incidenciaEnferCronica(&nuevo_Incidencia,&inicio_incidencia,&nuevoEC,&frenteEC,&encontrado,&buscar_ficha);
                            break;
                            case 5:
                                Alta_incidenciaOtrosServicios(&nuevo_Incidencia,&inicio_incidencia,&nuevoOS,&frenteOS,&encontrado,&buscar_ficha);
                            break;
                            default: printf("Opcion no valida\n");break;
                        }
                    break;
                    case 2:
                        if(inicio_incidencia != NULL && inicio_incidencia->tipoModificacion == 1){
                            printf("\nIncidencias pendientes:\n");
                            for(temp_incidencia = inicio_incidencia;temp_incidencia != NULL;temp_incidencia = temp_incidencia->sig){
                                printf("Tipo de consultorio: %d\n", temp_incidencia->tipoConsultorio);
                                printf("No. Ficha: %d\n", temp_incidencia->no_Ficha);
                            }
                            switch(inicio_incidencia->tipoConsultorio){
                                case 1:
                                    Incidencia_Datos_Vacunacion(&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevo_V,&frente_V);
                                break;
                                case 2:
                                    Incidencia_Datos_ControlPrenatal(&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevo_P,&frente_P);
                                break;
                                case 3:
                                    Incidencia_Datos_PresionArterial(&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoPA,&frentePA);
                                break;
                                case 4:
                                    Incidencia_Datos_EnferCronica(&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoEC,&frenteEC);
                                break;
                                case 5:
                                    Incidencia_Datos_OtrosServicios(&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoOS,&frenteOS);
                                break;
                                default: printf("Opcion no valida\n");break;
                            }
                        }else if (inicio_incidencia != NULL &&inicio_incidencia -> tipoModificacion == 2){
                            nuevoBase = (struct PacienteBase *) malloc(sizeof(struct PacienteBase));
                            switch(inicio_incidencia -> tipoConsultorio){
                                case 1:
                                    Incidencia_Consultorio_Anterior_Vacunacion(&nuevo_Incidencia,&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoBase,&inicio,&final,&tempBa,&frente_V);
                                break;
                                case 2:
                                    Incidencia_Consultorio_Anterior_ControlPrenatal(&nuevo_Incidencia,&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoBase,&inicio,&final,&tempBa,&frente_P);
                                break;
                                case 3:
                                    Incidencia_Consultorio_Anterior_PresionArterial(&nuevo_Incidencia,&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoBase,&inicio,&final,&tempBa,&frentePA);
                                break;
                                case 4:
                                    Incidencia_Consultorio_Anterior_EnferCronica(&nuevo_Incidencia,&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoBase,&inicio,&final,&tempBa,&frenteEC);
                                break;
                                case 5:
                                    Incidencia_Consultorio_Anterior_OtrosServicios(&nuevo_Incidencia,&inicio_incidencia,&temp_incidencia,&historial_incidencia,&nuevoBase,&inicio,&final,&tempBa,&frenteOS);
                                break;
                                default: printf("Opcion no valida\n");break;
                            }
                        }
                    break;
                    case 3:
                        Historial_Incidencias(&temp_incidencia,&historial_incidencia,&contador_incidencias);
                    break;
                    case 4: printf("Regresando al menu principal\n");break;
                    default:printf("Opcion no valida\n");break;
                }
            }while(opcion_Incidencias != 4);
            printf("\n\n");
            break;
            case 6: printf("Saliendo del programa\n");break;
            default: printf("Opcion no valida\n");break;
        }
    }while(opcion != 6);
    return 0;
}
