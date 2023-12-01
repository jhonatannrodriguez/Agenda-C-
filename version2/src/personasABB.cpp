#include "../include/personasABB.h"

struct rep_personasAbb {
TPersona persona;
TPersonasABB izq, der;
};

TPersonasABB crearTPersonasABB() {
	TPersonasABB arbol = NULL;
    return arbol;
}

bool esVacioTPersonasABB(TPersonasABB personasABB) {
    return (personasABB == NULL);
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p){
    if(esVacioTPersonasABB(personasABB)){
		personasABB = new rep_personasAbb;
		personasABB->persona = p;
		personasABB->izq = NULL;
		personasABB->der = NULL;
				}
	else if(idTPersona(p) > idTPersona(personasABB->persona))
	      insertarTPersonasABB(personasABB->der, p);
	else if(idTPersona(p) < idTPersona(personasABB->persona))
	      insertarTPersonasABB(personasABB->izq, p);
}

void liberarTPersonasABB(TPersonasABB &personasABB) {
     if (personasABB != NULL) {	 
        liberarTPersonasABB(personasABB->izq);
        liberarTPersonasABB(personasABB->der);
        liberarTPersona(personasABB->persona);
        delete personasABB;
        personasABB = NULL;
    }
}

void imprimirTPersonasABB(TPersonasABB personasABB) {  
	if(personasABB != NULL){     
        imprimirTPersonasABB(personasABB->izq);
        imprimirTPersona(personasABB->persona);
        imprimirTPersonasABB(personasABB->der);      
}
}

nat cantidadTPersonasABB(TPersonasABB personasABB) {
	if (personasABB == NULL) return 0;
    else
      return 1 + cantidadTPersonasABB(personasABB->izq) + cantidadTPersonasABB(personasABB->der);
}

TPersona maxIdPersona(TPersonasABB personasABB) {
	if(personasABB->der == NULL)
	   return personasABB->persona;
    else 
       return maxIdPersona(personasABB->der);
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id) {
    if (personasABB != NULL) {
        if (id < idTPersona(personasABB->persona)) {
            removerTPersonasABB(personasABB->izq, id);
        } else if (id > idTPersona(personasABB->persona)) {
            removerTPersonasABB(personasABB->der, id);
        } else {
			    if (personasABB->izq == NULL) {
                TPersonasABB aux1 = personasABB;
                personasABB = personasABB->der;
                liberarTPersona(aux1->persona);
                delete aux1;
            }
               else if (personasABB->der == NULL) {
                TPersonasABB aux = personasABB;
                personasABB = personasABB->izq;
                liberarTPersona(aux->persona);
                delete aux;
            }  else {
				liberarTPersona(personasABB->persona);
                personasABB->persona = copiarTPersona(maxIdPersona(personasABB->izq));
                removerTPersonasABB(personasABB->izq, idTPersona(personasABB->persona));;
            }
        }
    }
}



bool estaTPersonasABB(TPersonasABB personasABB, nat id){
	if(personasABB == NULL)
	   return false;
	 else if(id == idTPersona(personasABB->persona))
       return true;
	 else if(id < idTPersona(personasABB->persona))
	    return estaTPersonasABB(personasABB->izq, id);
	 else 
	    return estaTPersonasABB(personasABB->der, id);      
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id) {
	TPersona aux;
	if(personasABB == NULL)
	  aux = NULL;
	 else
	   if(id == idTPersona(personasABB->persona))
	     aux = personasABB->persona;
	   else if(id < idTPersona(personasABB->persona))
	       aux = obtenerDeTPersonasABB(personasABB->izq, id);
	   else if(id > idTPersona(personasABB->persona))
	         aux = obtenerDeTPersonasABB(personasABB->der, id);	         
    return aux;
}

nat maximo(nat p1, nat p2){
    if(p1 > p2)
       return p1;
     else return p2;
}

nat alturaTPersonasABB(TPersonasABB personasABB){
	if(personasABB == NULL) return 0;
	else return 1 + maximo(alturaTPersonasABB(personasABB->izq), alturaTPersonasABB(personasABB->der));
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB){
    if(personasABB == NULL)
      return true;
    else if(personasABB->izq == NULL && personasABB->der == NULL)
       return true;    
      else  if(personasABB->izq != NULL && personasABB->der != NULL)
        return esPerfectoTPersonasABB(personasABB->izq) && esPerfectoTPersonasABB(personasABB->der) && 
        (alturaTPersonasABB(personasABB->izq) == alturaTPersonasABB(personasABB->der));
      else 
         return false;
}

void agregarMayores(TPersonasABB persona, nat edad, TPersonasABB& aux) {
    if (persona != NULL) {
        if (edadTPersona(persona->persona) > edad) {
            insertarTPersonasABB(aux, copiarTPersona(persona->persona));
        }
        agregarMayores(persona->izq, edad, aux);
        agregarMayores(persona->der, edad, aux);
    }
}

TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad) {
     TPersonasABB aux = NULL;
    agregarMayores(personasABB, edad, aux);
    return aux;
	}
   

void aplanar (TPersonasABB t, TPersonasLDE & l){
if ( t!= NULL){ 
   aplanar(t->der,l);
   insertarTPersonasLDE(l, copiarTPersona(t->persona), 1); 
   aplanar(t->izq,l);
}
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB){
	TPersonasLDE lista = crearTPersonasLDE();
        aplanar(personasABB, lista);
        return lista;
}

