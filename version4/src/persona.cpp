#include "../include/persona.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_persona {
    nat id, edad;
    char  nomb[100];
    TAgendaLS agen;
};

TPersona crearTPersona(nat id, nat edad, const char nombre[100], TAgendaLS agenda) {
	TPersona nuevaPersona = new rep_persona;
	nuevaPersona->id = id;
	nuevaPersona->edad = edad;
	strcpy(nuevaPersona->nomb, nombre);
	nuevaPersona->agen = copiarAgendaLS(agenda);
	liberarAgendaLS(agenda);
    return nuevaPersona;
}

void liberarTPersona(TPersona &persona) {
	 if(persona != NULL){
     liberarAgendaLS(persona->agen);
     delete persona;
     persona = NULL;}
}

//Imprime a la persona utilizando printf e imprimeAgendaLS
void imprimirTPersona(TPersona persona){
	if(persona != NULL){
	printf("Persona %d: %s, %d años\n", persona->id, persona->nomb, persona->edad);
	imprimirAgendaLS(persona->agen);
    }
}

nat idTPersona(TPersona persona){
    return persona->id;
}

nat edadTPersona(TPersona persona) {
    return persona->edad;
}

char* nombreTPersona(TPersona persona) {
    return persona->nomb;
}

TAgendaLS agendaTPersona(TPersona persona) {
    return persona->agen;
}

void agregarEventoATPersona(TPersona &persona, TEvento evento) {
    agregarEnAgendaLS(persona->agen, evento);
}

void posponerEventoEnTPersona(TPersona &persona, int id, nat n) {
     posponerEnAgendaLS(persona->agen, id, n);
}

void removerEventoDeTPersona(TPersona &persona, int id) {
     removerDeAgendaLS(persona->agen, id);
}

bool estaEnAgendaDeTPersona(TPersona persona, int id){
    return estaEnAgendaLS(persona->agen, id);
}

TEvento obtenerDeAgendaDeTPersona(TPersona persona, int id) {
    return obtenerDeAgendaLS(persona->agen, id);
}

TPersona copiarTPersona(TPersona persona) {
	TPersona copia = new rep_persona;
	copia->id = idTPersona(persona);
	copia->edad = edadTPersona(persona);
	strcpy(copia->nomb, nombreTPersona(persona));
	copia->agen = copiarAgendaLS(agendaTPersona(persona));
    return copia;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoDeTPersona(TPersona persona){
    return primerEventoAgendaLS(persona->agen);
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
