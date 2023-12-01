#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"

struct rep_colaDePrioridadPersona {
   nat cant, cota;
   TPersona * heap;
   TPersona * ident; 
   bool invertir;
};

TColaDePrioridadPersona crearCP(nat N) {
	TColaDePrioridadPersona cola = new rep_colaDePrioridadPersona;
	cola->cant = 0;
	cola->cota = N;
	cola->invertir = false;
	cola->ident = new TPersona[N + 1];
	for(nat i = 0; i <= N; i++)
	   cola->ident[i] = NULL;
	cola->heap = new TPersona[N+1];
	for(nat i = 0; i <= N; i++)
	      cola->heap[i] = NULL;
  return cola;
} 

void filtrado_descendente(nat pos, TColaDePrioridadPersona &cp){
	TPersona aux = cp->heap[pos];
	nat hijo;
	while (2 * pos <= cp->cant) {
		hijo = 2 * pos;
		if (hijo + 1 <= cp->cant && compararTFechas(fechaTEvento(primerEventoDeTPersona(cp->heap[hijo + 1])), fechaTEvento(primerEventoDeTPersona(cp->heap[hijo]))) == (!cp->invertir ? -1 : 1))
			hijo++;
		if (compararTFechas(fechaTEvento(primerEventoDeTPersona(cp->heap[hijo])), fechaTEvento(primerEventoDeTPersona(aux))) == (!cp->invertir ? -1 : 1)) {
			cp->heap[pos] = cp->heap[hijo];
			pos = hijo;
		} else {
			break;
		}
	}
	cp->heap[pos] = aux;
	aux = NULL;
}

void filtrado_ascendente(nat pos, TColaDePrioridadPersona &cp){
	TPersona aux = cp->heap[pos];
	int comparacion;

	if (!cp->invertir) {
		comparacion = 1;
	} else {
		comparacion = -1;
	}
	while (pos > 1 && compararTFechas(fechaTEvento(primerEventoDeTPersona(cp->heap[pos / 2])), fechaTEvento(primerEventoDeTPersona(aux))) == comparacion) {
		cp->heap[pos] = cp->heap[pos / 2];
		pos = pos / 2;
	}
	cp->heap[pos] = aux;
	aux = NULL;

}

void invertirPrioridad(TColaDePrioridadPersona &cp) {
	if(cp->cant == 0) cp->invertir = !cp->invertir;
	else{
       	cp->invertir = !cp->invertir;
        for (nat i = 1; i <= cp->cant/ 2; i++) {
            filtrado_descendente(i, cp);}
        filtrado_ascendente(cp->cant/2, cp);
	}
}
void liberarCP(TColaDePrioridadPersona &cp) {
  for(nat i = 1; i <= cp->cota; i++){
	  liberarTPersona(cp->heap[i]);
	  liberarTPersona(cp->ident[i]);
  }  
   delete[] cp->heap;
   delete[] cp->ident;
   delete cp;
   cp = NULL;
}



void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp) {
  if(cp->cant < cp->cota){
	cp->ident[idTPersona(persona)] = copiarTPersona(persona);
	cp->cant++;
        cp->heap[cp->cant] = persona;
        filtrado_ascendente(cp->cant, cp);
           }
}

bool estaVaciaCP(TColaDePrioridadPersona cp) {
  return cp->cant == 0;
}

TPersona prioritaria(TColaDePrioridadPersona cp) {
  return cp->heap[1];
} 


void eliminarPrioritaria(TColaDePrioridadPersona &cp){
	if(cp->cant > 0){
		liberarTPersona(cp->ident[idTPersona(cp->heap[1])]);
		liberarTPersona(cp->heap[1]);
		cp->cant--;
		if(cp->cant > 0){
		cp->heap[1] = copiarTPersona(cp->heap[cp->cant+1]);	
		liberarTPersona(cp->heap[cp->cant+1]);
	    filtrado_descendente(1, cp);}	    
	}
}


bool estaEnCP(nat id, TColaDePrioridadPersona cp) {
  if (id > 0 && id <= cp->cota) {
    return cp->ident[id] != NULL;
  }
  return false;
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp){
   if(estaEnCP(id, cp)) return fechaTEvento(primerEventoAgendaLS( agendaTPersona(cp->ident[id]))) ;
   else return NULL;
}
