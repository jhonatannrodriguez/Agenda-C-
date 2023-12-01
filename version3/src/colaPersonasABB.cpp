#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct nuevoABB{ 
   nuevoABB * sig;
   TPersonasABB persona;
};

typedef nuevoABB *NodoperABB;

struct rep_colaPersonasABB{
  nat cant; 
  NodoperABB prim;
  NodoperABB ult;   
};

TColaPersonasABB crearTColaPersonasABB() {
	TColaPersonasABB cola = new rep_colaPersonasABB;
	cola->cant = 0;
    cola->prim = cola->ult = NULL;
    return cola;
}

void liberarTColaPersonasABB(TColaPersonasABB &c) {
     while(c->prim != NULL){
		 NodoperABB aux = c->prim;
		 c->prim = aux->sig;
		 delete aux;
		 }
		 c->prim = c->ult = NULL;
		 delete c;
		 c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c) { 
  return c->cant;
 }

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c) {
NodoperABB encolar = new nuevoABB;
	encolar->persona = t;
	encolar->sig = NULL;
	if(c->prim == NULL){
		c->prim = c->ult = encolar;		
		}
	 else{
		 c->ult->sig = encolar;
		 c->ult = encolar;
		 }
	c->cant++;
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c) { 
  return c->prim->persona;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {
     NodoperABB aux = c->prim;
     c->prim = aux->sig;
     aux->sig = NULL;
     delete aux;
     aux = NULL;
     c->cant--;
}
