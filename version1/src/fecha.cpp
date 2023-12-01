#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
     nat dia;
     nat mes;
     nat anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
     nuevaFecha = new rep_fecha;
     nuevaFecha->dia = dia;
     nuevaFecha->mes = mes;
     nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
     delete fecha;
     fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/

//Funcion para saber si un anio es Bisiesto
bool anioBisiesto(nat anio){
	 bool res;
     if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)){
         res = true;
     }else{
         res = false;
     }
      return res;
}

// Función para obtener la cantidad de días de un mes en un año dado
nat diasMes(nat mes, nat anio){
   nat cant;
   if (anioBisiesto(anio) && (mes == 2)) cant = 29;
   else if ( not anioBisiesto(anio) && mes == 2) cant = 28;
   else {
	 if (((mes % 2) == 0 && (mes <= 7)) || ((mes >= 8) && (mes % 2 ) != 0)) cant = 30;	
	 else cant = 31;}
  return cant;
}

void aumentarTFecha(TFecha &fecha, nat dias) {
     fecha->dia += dias;
     while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
       fecha->dia -= diasMes(fecha->mes, fecha->anio);
       fecha->mes++;
       if (fecha->mes > 12) {
          fecha->mes = 1;
          fecha->anio++;
          }
       }    
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
     if (fecha1->anio < fecha2->anio) res = -1;
     else if (fecha1->anio > fecha2->anio) res = 1;
     else if (fecha1->mes < fecha2->mes) res = -1;
     else if (fecha1->mes > fecha2->mes) res = 1;
     else if (fecha1->dia < fecha2->dia) res = -1;
     else if (fecha1->dia > fecha2->dia) res = 1;
     else res = 0;
    /****** Fin de parte Parte 3.10 *****/
   return res;
}
