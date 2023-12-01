#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
    nat cota;
    nat maxCant;
    bool * elem;
};


TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds conjunto = new rep_conjuntoIds;
	conjunto->cota = 0;
	conjunto->maxCant = cantMax;
	conjunto->elem = new bool[cantMax + 1];
	for(nat i = 0; i <= cantMax; i++)
	     conjunto->elem[i] = false;
	return conjunto;    
};


bool esVacioTConjuntoIds(TConjuntoIds c){
	return c->cota == 0;
};


void insertarTConjuntoIds(nat id, TConjuntoIds &c){
	if(c->cota <= c->maxCant && id > 0 && id <= c->maxCant){
    c->cota++;
    c->elem[id] = true;
    }
}; 

void borrarTConjuntoIds(nat id, TConjuntoIds &c){
     if(c->elem[id] == true){
         c->elem[id] = false; 
         c->cota--;
         }     
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	if(id > c->maxCant)
	   return false;
     else return c->elem[id];
};


nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cota;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->maxCant;
};

void imprimirTConjuntoIds(TConjuntoIds c) {
    if (!esVacioTConjuntoIds(c)) {
        for (nat i = 1; i <= c->maxCant; i++) {
            if (perteneceTConjuntoIds(i, c)) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

void liberarTConjuntoIds(TConjuntoIds &c){
    delete[] c->elem;
    delete c;
    c = NULL;
};




TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds uni = crearTConjuntoIds(c1->maxCant);
	for(nat i = 1; i <= c2->maxCant; i++)
	    if(c2->elem[i] == true || c1->elem[i] == true)
	       insertarTConjuntoIds(i, uni);
	return uni;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds inter = crearTConjuntoIds(c1->maxCant);
	for(nat i = 1; i <= c2->maxCant; i++)
	    if(c2->elem[i] == true && c1->elem[i] == true){
	       insertarTConjuntoIds(i, inter);
	       }
	return inter;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds dif = crearTConjuntoIds(c1->maxCant);
	for(nat i = 1; i <= c2->maxCant; i++)
	    if(c1->elem[i] == true && c2->elem[i] == false){
	       insertarTConjuntoIds(i, dif);
	       }
	return dif;
};
