#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona {
    TPersonasLDE listaLDE;
};

TPilaPersona crearTPilaPersona(){
	TPilaPersona pila = new rep_pilaPersona;
	pila->listaLDE = crearTPersonasLDE();
    return pila;
}

void liberarTPilaPersona(TPilaPersona &p) {
     liberarTPersonasLDE(p->listaLDE);
     delete p;
     p = NULL;
}

nat cantidadEnTPilaPersona(TPilaPersona p) { 
  return cantidadTPersonasLDE(p->listaLDE);
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona) {
     insertarInicioDeTPersonasLDE(p->listaLDE, copiarTPersona(persona));
}

TPersona cimaDeTPilaPersona(TPilaPersona p){ 
  return obtenerInicioDeTPersonasLDE(p->listaLDE);
}

void desapilarDeTPilaPersona(TPilaPersona &p) {
    eliminarInicioTPersonasLDE(p->listaLDE);
}
