#include<stdio.h>
#include<stdlib.h>
/*Equipo 2 Yin Yang
Julio Cesar Arguello Palomeque
Juan Jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Samuel de la Cruz Lopez
Jose Fernando Dominguez Monzon*/
struct FichaVacunacion{
    int no_Ficha;
    char nombre[20];
    char apellidos[20];
    struct FichaVacunacion *sig;
}*nuevo_V,*frente_V,*ultimo_V;

struct FichaControlPrenatal{
    int no_Ficha;
    char nombre[20];
    char apellidos[20];
    struct FichaControlPrenatal *sig;
}*nuevo_P,*frente_P,*ultimo_P;

struct FichaPresionArterial{
    int no_Ficha;
    char nombre[20];
    char apellidos[20];
    struct FichaPresionArterial *sig;
}*nuevoPA,*frentePA,*ultimoPA;

struct FichaEnferCronica{
    int no_Ficha;
    char nombre[20];
    char apellidos[20];
    struct FichaEnferCronica *sig;
}*nuevoEC,*frenteEC,*ultimoEC;
int main(){
    //estos contadores son para los reportes
    int opc,pacientes_Vacunacion = 0,pacientes_Prenatal = 0,paciente_Arterial =0,paciente_Cronicos=0,resp,opc1;
    //estos contadores son de las estructuras
    int num_V = 0,num_P = 0, num_PA = 0, num_EC = 0;
    //
    int max = 0,min = 999,m,pos_servicio = 0,No_lista;
    frente_V = ultimo_V = NULL;
    frente_P = ultimo_P = NULL;
    frentePA = ultimoPA = NULL;
    frenteEC = ultimoEC = NULL;
    
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
                switch(opc){
                    case 1:
                        nuevo_V = (struct FichaVacunacion*) malloc(sizeof(struct FichaVacunacion));
                        num_V++;
                        pacientes_Vacunacion++;
                        printf("\nDigite el nombre del paciente\n");
                        scanf("%s",nuevo_V -> nombre );
                        printf("\nDigite el apellido del paciente\n");
                        scanf("%s",nuevo_V -> apellidos);
                        nuevo_V -> no_Ficha = num_V;
                        if(frente_V == NULL){
                                frente_V = nuevo_V;
                        }else{
                            ultimo_V -> sig = nuevo_V;
                        }
                        nuevo_V -> sig = NULL;
                        ultimo_V = nuevo_V;
                        
                        printf("\n\nVacunacion\nNombre completo: %s %s\n",nuevo_V -> nombre,nuevo_V -> apellidos);
                        printf("Numero de ficha: %d\n\n",nuevo_V -> no_Ficha);

                    break;
                case 2:
                        nuevo_P = (struct FichaControlPrenatal*) malloc(sizeof (struct FichaControlPrenatal));
                        num_P++;
                        pacientes_Prenatal++;
                        printf("\nDigite el nombre del paciente\n");
                        scanf("%s",nuevo_P -> nombre );
                        printf("\nDigite el apellido del paciente\n");
                        scanf("%s",nuevo_P -> apellidos);
                        nuevo_P -> no_Ficha = num_P;
                        if(frente_P == NULL){
                                frente_P = nuevo_P;
                        }else{
                            ultimo_P -> sig = nuevo_P;
                        }
                        nuevo_P -> sig = NULL;
                        ultimo_P = nuevo_P;
                        printf("\n\nControl Prenatal\nNombre completo: %s %s\n",nuevo_P -> nombre,nuevo_P -> apellidos);
                        printf("Numero de ficha: %d\n\n",nuevo_P -> no_Ficha);
                    break;
                case 3:
                        nuevoPA = (struct FichaPresionArterial*) malloc(sizeof(struct FichaPresionArterial));
                        num_PA++;
                        paciente_Arterial++;
                        printf("\nDigite el nombre del paciente\n");
                        scanf("%s",nuevoPA -> nombre );
                        printf("\nDigite el apellido del paciente\n");
                        scanf("%s",nuevoPA -> apellidos);
                        nuevoPA -> no_Ficha = num_PA;
                        if(frentePA == NULL){
                                frentePA = nuevoPA;
                        }else{
                            ultimoPA -> sig = nuevoPA;
                        }
                        nuevoPA -> sig = NULL;
                        ultimoPA = nuevoPA;
                        printf("\n\nPresion Arterial\nNombre completo: %s %s\n",nuevoPA -> nombre,nuevoPA -> apellidos);
                        printf("Numero de ficha: %d\n\n",nuevoPA -> no_Ficha);
                    break;
                case 4:
                        nuevoEC = (struct FichaEnferCronica*) malloc(sizeof(struct FichaEnferCronica));
                        num_EC++;
                        paciente_Cronicos++;
                        printf("\nDigite el nombre del paciente\n");
                        scanf("%s",nuevoEC -> nombre );
                        printf("\nDigite el apellido del paciente\n");
                        scanf("%s",nuevoEC -> apellidos);
                        nuevoEC -> no_Ficha = num_EC;
                        if(frenteEC == NULL){
                                frenteEC = nuevoEC;
                        }else{
                            ultimoEC -> sig = nuevoEC;
                        }
                        nuevoEC -> sig = NULL;
                        ultimoEC = nuevoEC;
                        printf("\n\nEnfermades cronicas\nNombre completo: %s %s\n",nuevoEC -> nombre,nuevoEC -> apellidos);
                        printf("Numero de ficha: %d\n\n",nuevoEC -> no_Ficha);
                    break;
                }
            }while(opc != 5);
            break;
            case 2:
            printf("\n\nGestion de consultas\n");
            printf("A que tipo de consulta ira el paciente?\n");
            printf("1 - Vacunacion\n2 - Control Prenatal\n3 - Presion arterial\n4 -Enfermades cronicas\nDigite la opcion: ");
            scanf("%d",&opc);
            switch(opc){
                case 1:
                do{
                        if(frente_V == NULL){
                            printf("\n\nNo hay pacientes en la lista de espera\n\n");
                            break;
                        }else{
                            printf("\nFicha: %d\n",frente_V -> no_Ficha);
                            printf("Nombre: %s %s\n\n",frente_V -> nombre,frente_V -> apellidos);
                            nuevo_V -> no_Ficha = frente_V -> no_Ficha;
                            free(nuevo_V);
                            frente_V = nuevo_V -> sig;
                            num_V--;
                            printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                            scanf("%d",&resp);
                        }
                    
                    }while(resp != 2 || frente_V == NULL);
                break;
                case 2:
                do{
                    if(frente_P == NULL){
                        printf("\n\nNo hay pacientes en la lista de espera\n\n");
                        break;
                    }else{
                            printf("\nFicha: %d\n",frente_P -> no_Ficha);
                            printf("Nombre: %s %s\n\n",frente_P -> nombre,frente_P -> apellidos);
                            nuevo_P ->no_Ficha = frente_P ->no_Ficha;
                            free(nuevo_P);
                            frente_P = nuevo_P -> sig;
                            num_P--;
                            printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                            scanf("%d",&resp);
                    }
                }while(resp != 2 || frente_P == NULL);
                break;
                case 3:
                do{
                    if(frentePA == NULL){
                        printf("\n\nNo hay pacientes en la lista de espera\n\n");
                        break;
                    }else{
                    printf("\nFicha: %d\n",frentePA -> no_Ficha);
                    printf("Nombre: %s %s\n\n",frentePA -> nombre, frentePA-> apellidos);
                    nuevoPA -> no_Ficha = frentePA ->no_Ficha;
                    free(nuevoPA);
                    frentePA = nuevoPA -> sig;
                    num_PA--;
                    printf("Quieres pasar otro paciente?\n1 - si\n2 - no\n");
                    scanf("%d",&resp);
                    }
                }while(resp != 2 || frentePA == NULL);
                break;
                case 4:
                do{
                if(frenteEC == NULL){
                        printf("\n\nNo hay pacientes en la lista de espera\n\n");
                        break;
                    }else{
                            printf("\nFicha: %d\n",frenteEC -> no_Ficha);
                            printf("Nombre: %s %s\n\n",frenteEC -> nombre,frenteEC -> apellidos);
                            nuevoEC ->no_Ficha = frenteEC ->no_Ficha;
                            free(nuevoEC);
                            frenteEC = nuevoEC -> sig;
                            num_EC--;
                            printf("Quieres pasar a otro paciente?\n1 - si\n2 - no\n");
                            scanf("%d",&resp);
                    }
                }while(resp != 2 || frenteEC == NULL);
                break;
            }
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
                    No_lista = 1;
                    printf("Consultas de Vacunacion\n");
                    for(nuevo_V = frente_V; nuevo_V != NULL; nuevo_V = nuevo_V -> sig ){
                        printf("Paciente no. %d\nNombre: %s %s\n",No_lista,nuevo_V -> nombre,nuevo_V -> apellidos);
                        No_lista++;
                    }
                    system("pause");
                    system("cls");
                    No_lista = 1;
                    printf("Consultad de Control Prental\n");
                    for(nuevo_P = frente_P; nuevo_P != NULL; nuevo_P = nuevo_P -> sig){
                        printf("Paciente no. %d\nNombre: %s %s\n",No_lista,nuevo_P -> nombre,nuevo_P ->apellidos);
                        No_lista++;
                    }
                    system("pause");
                    system("cls");
                    No_lista = 1;
                    printf("Consultas de Presion Arterial\n");
                    for(nuevoPA = frentePA; nuevoPA != NULL; nuevoPA = nuevoPA -> sig){
                        printf("Paciente no. %d\nNombre: %s %s\n",No_lista,nuevoPA -> nombre,nuevoPA -> apellidos);
                        No_lista++;
                    }
                    system("pause");
                    system("cls");
                    No_lista = 1;
                    printf("Consultas de Enfermades cronicas\n");
                    for(nuevoEC = frenteEC; nuevoEC != NULL; nuevoEC = nuevoEC -> sig){
                        printf("Paciente no. %d\nNombre: %s %s\n",No_lista,nuevoEC -> nombre,nuevoEC ->apellidos);
                        No_lista++;
                    }
                    system("pause");
                    system("cls");
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
                            for(nuevo_V = frente_V; nuevo_V != NULL; nuevo_V = nuevo_V -> sig){
                                printf("Nombre completo: %s %s\n",nuevo_V -> nombre, nuevo_V -> apellidos);
                                printf("Numero de ficha %d\n\n",nuevo_V -> no_Ficha);
                            }
                        }
                        break;
                        case 2:
                        if(frente_P == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            for(nuevo_P = frente_P; nuevo_P != NULL; nuevo_P = nuevo_P -> sig){
                                printf("Nombre completo: %s %s\n",nuevo_P -> nombre, nuevo_P -> apellidos);
                                printf("Numero de ficha: %d\n\n",nuevo_P -> no_Ficha);
                            }
                        }
                        break;
                        case 3:
                        if(frentePA == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            for(nuevoPA = frentePA; nuevoPA != NULL; nuevoPA = nuevoPA -> sig){
                                printf("Nombre completo: %s %s\n",nuevoPA -> nombre,nuevoPA -> apellidos);
                                printf("Numero de fichas: %d\n\n",nuevoPA -> no_Ficha);
                            }
                        }
                        break;
                        case 4:
                        if(frenteEC == NULL){
                            printf("\n\nNo hay pacientes en lista de espera\n\n");
                        }else{
                            printf("\n\n");
                            for(nuevoEC = frenteEC; nuevoEC != NULL; nuevoEC = nuevoEC -> sig){
                                printf("Nombre completo: %s %s\n",nuevoEC -> nombre,nuevoEC -> apellidos);
                                printf("Numero de fichas: %d\n\n",nuevoEC -> no_Ficha);
                            }
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
                    char tipos[4][40] = {"Vacunacion","Control Prenatal","Presion Arterial","Enfermedades Cronicas"};
                    int array[4] = {pacientes_Vacunacion,pacientes_Prenatal,paciente_Arterial,paciente_Cronicos};
                    max = array[0];
                    for(m = 0; m<4;m++){
                        if(array[m] > max){
                            max = array[m];
                            pos_servicio = m;
                        }
                        if(array[m] < min){
                            min = array[m];
                            pos_servicio = m;
                        }
                    }
                    printf("\n\n");
                    for(m = 0 ; m < 4; m++){
                        if(max == array[m]){
                            printf("El servicio con mayor demanda es %s con %d pacientes\n",tipos[m],array[m]);
                        }
                    }

                    for(m = 0; m<4;m++){
                        if(min == array[m]){
                            printf("El servicio con menor demanda es %s con %d pacientes\n",tipos[m],array[m]);
                        }
                    }
                    printf("\n\n");
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

