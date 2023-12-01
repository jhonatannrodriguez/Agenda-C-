#include "../include/aplicaciones.h"
#include "../include/colaDePrioridadPersona.h"
void listarEnOrden(TTablaPersonas t, char** nombres, nat n){
TColaDePrioridadPersona tabla =  crearCP(MAX_ID);
    for(nat i = 0; i < n; i++){
    	if(perteneceATTablaPersonas(t, nombres[i])){
			 insertarEnCP(copiarTPersona(obtenerPersonaDeTTablaPersonas(t, nombres[i])), tabla); 
		}
      }
	while(!estaVaciaCP(tabla)){
        imprimirTPersona(prioritaria(tabla));
        eliminarPrioritaria(tabla);
	}
	liberarCP(tabla);
}
