#include "../include/personasLDE.h"
struct nuevo{ 
   nuevo * sig;
   TPersona persona;
   nuevo * ant;
};

typedef nuevo *Nodoper;

struct rep_personasLDE {
 Nodoper prim;
 Nodoper ult;
 nat pos;
};

TPersonasLDE crearTPersonasLDE(){
    TPersonasLDE nuevaLista = new rep_personasLDE;
    nuevaLista->prim = NULL;
    nuevaLista->ult = NULL;
    nuevaLista->pos = 0;
    return nuevaLista;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos){
    Nodoper person = new nuevo;
    person->persona = persona;
	nat i;	
       if (personas->pos == 0) {
        personas->prim = person;
        personas->ult = person;
	personas->prim->sig = NULL;
	}
       else  if(pos == 1){
       person->sig = personas->prim;
       personas->prim->ant = person;  
       personas->prim = person;
        }
       else if(pos > personas->pos){
       	 personas->ult->sig = person;
	 person->ant = personas->ult;
	 personas->ult = person;
       	}
	else{
	  Nodoper aux = personas->prim;
	     for(i = 1; i < pos; i++){
		 aux = aux->sig;}
       	aux->ant->sig = person;
        person->ant = aux->ant;
        person->sig = aux;
        aux->ant = person;
		}
	personas->pos++;
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE){
if(personasLDE->prim != NULL){
  Nodoper aux1 = personasLDE->prim; 
  personasLDE->ult = NULL;
  for (nat i = 1; i <= personasLDE->pos; i++){
  personasLDE->prim = aux1->sig;
  liberarTPersona(aux1->persona);
  delete aux1;
  aux1 = personasLDE->prim;}}
  delete personasLDE;
  personasLDE = NULL;
}

void imprimirTPersonasLDE(TPersonasLDE personas){
  Nodoper aux1 = personas->prim; 
  for(nat i = 1; i <= personas->pos; i++){
  imprimirTPersona(aux1->persona);
  aux1 = aux1->sig;}
}

nat cantidadTPersonasLDE(TPersonasLDE personas){
    return personas->pos;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas){        
    if (personas->prim != NULL) {
        Nodoper aux = personas->prim;
        personas->prim = aux->sig;
        liberarTPersona(aux->persona);
        delete aux;
        personas->pos--;
    }
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas){    
    if (personas->ult != NULL) {  
       	Nodoper aux = personas->ult;
        personas->ult = aux->ant;
        liberarTPersona(aux->persona);
        delete aux;
        personas->pos--;
}
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id){
    Nodoper aux = personas->prim;
    nat i;
	for(i = 1; i <= personas->pos && idTPersona(aux->persona) != id; i++)
	      aux = aux->sig;
    return i <= personas->pos;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id){
    	Nodoper aux = personas->prim;
	for(nat i = 1; aux != NULL && idTPersona(aux->persona) != id; i++)
	      aux = aux->sig;
    return aux->persona;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2){
   TPersonasLDE nuevaLista = crearTPersonasLDE();
   nuevaLista->pos = cantidadTPersonasLDE(personas1) + cantidadTPersonasLDE(personas2);
   if(cantidadTPersonasLDE(personas1) == 0){
      nuevaLista->prim = personas2->prim;
      nuevaLista->ult = personas2->ult;}
   else if(cantidadTPersonasLDE(personas2)== 0){
      nuevaLista->prim = personas1->prim;
      nuevaLista->ult = personas1->ult;}
   else{
		nuevaLista->prim = personas1->prim;
		personas1->ult->sig = personas2->prim;
		personas2->prim->ant = personas1->ult;
		nuevaLista->ult = personas2->ult;
   }
   personas1->prim = NULL;
   personas2->prim = NULL;
   personas2->ult = NULL;
   personas1->ult = NULL;
   liberarTPersonasLDE(personas1);
   liberarTPersonasLDE(personas2);
   return nuevaLista;
}
