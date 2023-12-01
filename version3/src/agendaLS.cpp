#include "../include/agendaLS.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_agendaLS {
     TEvento evento ;
    rep_agendaLS * sig ;
};

TAgendaLS crearAgendaLS() {
	TAgendaLS nuevaAgenda = NULL;
    return nuevaAgenda;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento){
    TAgendaLS nuevo= new rep_agendaLS;
    nuevo->evento=evento;
    nuevo->sig=NULL;
    if (agenda==NULL || compararTFechas(fechaTEvento(agenda->evento), fechaTEvento(evento)) >= 1){ // insertar al ppio
        nuevo->sig=agenda;
        agenda=nuevo;
    }
    else{
        TAgendaLS aux=agenda;
        while (aux->sig !=NULL && compararTFechas(fechaTEvento(aux->sig->evento), fechaTEvento(evento)) < 0){
            aux= aux->sig;
        }
        nuevo->sig=aux->sig;
        aux->sig=nuevo;       
    }
}

void imprimirAgendaLS(TAgendaLS agenda) {
	   while(agenda != NULL){
    imprimirTEvento(agenda->evento);
    agenda = agenda->sig;}
}

void liberarAgendaLS(TAgendaLS &agenda) {
    TAgendaLS varaux, nueva = agenda;   
    while (nueva != NULL) {	
        liberarTEvento(nueva->evento);
        varaux = nueva;
        nueva = nueva->sig;
        delete varaux;
    }
    agenda = NULL;  
}

bool esVaciaAgendaLS(TAgendaLS agenda){
	if(agenda == NULL) return true;
    else return false;
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda){
	TAgendaLS agend = NULL;
	while(agenda != NULL){
         agregarEnAgendaLS(agend, copiarTEvento(agenda->evento));
	 agenda = agenda->sig;
		}
    return agend;
}

bool estaEnAgendaLS(TAgendaLS agenda, int id) {
    while(agenda != NULL && idTEvento(agenda->evento) != id)
	     agenda = agenda->sig;  
    return agenda != NULL;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id) {
	TAgendaLS auxi = agenda;
	while(auxi != NULL && idTEvento(auxi->evento) != id)
	    auxi = auxi->sig;	    
    return auxi->evento;
}

void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n) {
    TEvento even = copiarTEvento(obtenerDeAgendaLS(agenda, id));
    posponerTEvento(even, n);
    TAgendaLS aux1 = agenda;
    TAgendaLS aux = NULL; 
       while(aux1 != NULL && idTEvento(aux1->evento) != id){
           aux = aux1;
            aux1 = aux1->sig;}
        if(aux == NULL){
			agenda = agenda->sig;
			liberarTEvento(aux1->evento);
			delete aux1;
			}
	    else{
              aux->sig = aux1->sig;
              liberarTEvento(aux1->evento);
              delete aux1;}
     agregarEnAgendaLS(agenda, even);
  
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
    while(agenda != NULL){
        if(compararTFechas(fecha, fechaTEvento(agenda->evento)) == 0){
            imprimirTEvento(agenda->evento);
        }
        agenda = agenda->sig;
    }   
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha){
	TAgendaLS aux = agenda;
	while(aux != NULL && compararTFechas(fechaTEvento(aux->evento), fecha) != 0)
	   aux = aux->sig; 
    return aux != NULL;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id) {
	 TAgendaLS auxuno = agenda;
    TAgendaLS aux = NULL; 
       while(auxuno != NULL && idTEvento(auxuno->evento) != id){
           aux = auxuno;
            auxuno = auxuno->sig;}
        if(aux == NULL){
			agenda = agenda->sig;
			liberarTEvento(auxuno->evento);
			delete auxuno;
			}
	    else{
              aux->sig = auxuno->sig;
              liberarTEvento(auxuno->evento);
              delete auxuno;}
    }


///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////
