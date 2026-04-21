#ifndef RESTABLECIMIENTO_H
#define RESTABLECIMIENTO_H
#include<stdio.h>
#include"estructuras.h"
#include"Update.h"

//otra funcion asquerosa mas : )

void restablecerPaciente(PacienteBase **inicio, PacienteBase **tempBa,
    FichaVacunacion **nuevo_V, FichaVacunacion **frente_V, FichaVacunacion **ultimo_V, int *num_V,
    FichaControlPrenatal **nuevo_P, FichaControlPrenatal **frente_P, FichaControlPrenatal **ultimo_P, int *num_P,
    FichaPresionArterial **nuevoPA, FichaPresionArterial **frentePA, FichaPresionArterial **ultimoPA, int *num_PA,
    FichaEnferCronica **nuevoEC, FichaEnferCronica **frenteEC, FichaEnferCronica **ultimoEC, int *num_EC,
    OtroServicios **nuevoOS,OtroServicios **frenteOS, OtroServicios **ultimoOS,int *num_OS){

        switch((*tempBa) -> consultorioAnterior){
            case 1:
                regresarPacienteVacunacion(inicio,tempBa,nuevo_V,frente_V,ultimo_V,num_V);
            break;
            case 2:
                regresarPacientePrenatal(inicio,tempBa,nuevo_P,frente_P,ultimo_P,num_P);
            break;
            case 3:
                regresarPacientePreArterial(inicio,tempBa,nuevoPA,frentePA,ultimoPA,num_PA);
            break;
            case 4:
                regresarEnferCronica(inicio,tempBa,nuevoEC,frenteEC,ultimoEC,num_EC);
            break;
            case 5:
                regresarOtroServicios(inicio,tempBa,nuevoOS,frenteOS,ultimoOS,num_OS);
            break;
            default: printf("Opcion no valida\n");break;
        }
}

void limpiarConsultorio(PacienteBase **tempBa,FichaVacunacion **nuevo_V,FichaControlPrenatal **nuevo_P,FichaPresionArterial **nuevoPA,FichaEnferCronica **nuevoEC,OtroServicios **nuevoOS){
    eliminarConsultorioAnterior(tempBa,nuevo_V,nuevo_P,nuevoPA,nuevoEC,nuevoOS);
}
#endif