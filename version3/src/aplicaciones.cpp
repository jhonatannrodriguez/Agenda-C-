#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista) {
  TPilaPersona pila = crearTPilaPersona();
  while(cantidadTPersonasLDE(lista) > 0){
	  TPersona cima = obtenerInicioDeTPersonasLDE(lista);
	   while(cantidadEnTPilaPersona(pila) > 0 && edadTPersona(cimaDeTPilaPersona(pila)) > edadTPersona(cima))
	       desapilarDeTPilaPersona(pila);
	    apilarEnTPilaPersona(pila, cima);
	    eliminarInicioTPersonasLDE(lista);  
	    }    
  return pila;
}

bool sumaPares(nat k, TConjuntoIds c){
	bool sum = false;
	for(nat i =  1; i <= k/2 && !sum && (i != k-i); i++)
	    if(perteneceTConjuntoIds(i, c) && perteneceTConjuntoIds(k-i, c))
	         sum = true;
	 return sum;
	      
}
