#include "../include/agenda.h"

struct rep_agenda {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
     TEvento agen[MAX_EVENTOS];
     int tope;
    /****** Fin de parte Parte 5.1 *****/
};

TAgenda crearTAgenda() {
    TAgenda nuevaAgenda = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
     nuevaAgenda = new rep_agenda;
     for(int i = 0; i < MAX_EVENTOS; i++){
		nuevaAgenda->agen[i] = NULL;}
     nuevaAgenda->tope = 0;
    /****** Fin de parte Parte 5.2 *****/
    return nuevaAgenda;
}

void ordenarAgenda(TAgenda &agenda){
    if(agenda->tope >= 2){
       for(int i = 0; i < agenda->tope-1; i++){
		  for(int j = i + 1; j < agenda->tope; j++){
		      if(compararTFechas(fechaTEvento(agenda->agen[i]), fechaTEvento(agenda->agen[j])) == 1){		
			     TEvento aux = agenda->agen[i];
			     agenda->agen[i] = agenda->agen[j];
			     agenda->agen[j] = aux;}
                 }
               }
             }
}

void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
     if(agenda->tope < 1){
       agenda->tope++;
       agenda->agen[agenda->tope-1] = evento;}
     else if(agenda->tope >= 1 && agenda->tope < MAX_EVENTOS){
	   agenda->tope++;
       for(int i = agenda->tope-1; i > 0; i--){
	     agenda->agen[i]  = agenda->agen[i-1];} 
	     agenda->agen[0] = evento;}
     ordenarAgenda(agenda);
    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
     for(int i = 0; i < agenda->tope; i++){
       liberarTEvento(agenda->agen[i]);}
     delete agenda;
     agenda = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

void imprimirTAgenda(TAgenda agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
     if(agenda != NULL){
		for(int i = 0; i < agenda->tope; i++){
		   imprimirTEvento(agenda->agen[i]);}
		 }
    /****** Fin de parte Parte 5.2 *****/
}

bool estaEnAgenda(TAgenda agenda, int id) {
    bool res = false;
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
     int j = 0;
     while((j < agenda->tope) && (idTEvento(agenda->agen[j]) != id)){
	    j++;}
	 if(j < agenda->tope) res = true;
    /****** Fin de parte Parte 5.4 *****/
    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    TEvento res = NULL;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
     int j = 0;
       if(estaEnAgenda(agenda, id)){
		   while((idTEvento(agenda->agen[j]) != id)) j++;
		     res = agenda->agen[j];   
		   }
    /****** Fin de parte Parte 5.5 *****/
    return res;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
     if(estaEnAgenda(agenda, id)){
		TEvento res = obtenerDeAgenda(agenda, id);
		posponerTEvento(res, n);
		int j = 0;
		while((idTEvento(agenda->agen[j]) != id)) j++;
		   agenda->agen[j] = res;}
	 ordenarAgenda(agenda);
    /****** Fin de parte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
     for(int i = 0; i < agenda->tope; i++)
        if (compararTFechas(fechaTEvento(agenda->agen[i]), fecha) == 0) 
          imprimirTEvento(agenda->agen[i]);
    /****** Fin de parte Parte 5.7 *****/
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    bool res = false;
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    /*La función debe ejecutar una versión */
    /*Iterativa del algoritmo de búsqueda  */
    /*binaria.                              */
     int i = 0;
      int s = agenda->tope - 1;
      int mit;
      while((i<=s) && res == false){
		  mit = (i + s)/2;
		  if(compararTFechas(fechaTEvento(agenda->agen[mit]),
		     fecha) == 0) res = true;
		  if(compararTFechas(fechaTEvento(agenda->agen[mit]),
		     fecha) == 1) s = mit - 1;
		  if(compararTFechas(fechaTEvento(agenda->agen[mit]),
		      fecha) == -1){
		        i = mit + 1;}	 
      }
    /****** Fin de parte Parte 5.7 *****/
    return res;
}

void removerDeAgenda(TAgenda &agenda, int id) {
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */
     int i = 0;
     while(i < agenda->tope && idTEvento(agenda->agen[i]) != id){
              i++;}
	 liberarTEvento(agenda->agen[i]);
	 for(int j = i; j < agenda->tope-1; j++)
		agenda->agen[j] = agenda->agen[j+1];
	 agenda->tope--;
     /****** Fin de parte Parte 5.8 *****/
}





