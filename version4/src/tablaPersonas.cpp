#include "../include/tablaPersonas.h"


struct rep_tablaPersonas {
    TPersonasLDE * tab;
	int cantidad;
};

nat funcionDeDispersion(const char nombre[100]){
    nat res = 0;
    int i = 0;
    while(i< 100 && nombre[i] != '\0'){
        res += int(nombre[i]);
        i++;
    }
    return res;
}

TTablaPersonas crearTTablaPersonas(int max){
	TTablaPersonas tabla = new rep_tablaPersonas;
	tabla->cantidad = max;
	tabla->tab = new TPersonasLDE[max]; 
	for(int i = 0; i < max; i++)
	    tabla->tab[i] = crearTPersonasLDE();
    return tabla;
}

void insertarPersonaEnTabla(TTablaPersonas &tabla, TPersona persona){
	nat pos = funcionDeDispersion(nombreTPersona(persona)) % tabla->cantidad;
	insertarInicioDeTPersonasLDE(tabla->tab[pos] ,persona);
}


void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100]){
	nat pos = funcionDeDispersion(nombre) % tabla->cantidad;
	eliminarPersonaConNombreTPersonasLDE(tabla->tab[pos], nombre);
}

bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
	nat pos = funcionDeDispersion(nombre) % tabla->cantidad;
    return estaPersonaConNombreEnTPersonasLDE(tabla->tab[pos], nombre);
}

TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100]){
	nat pos = funcionDeDispersion(nombre) % tabla->cantidad;
    return obtenerPersonaConNombreTPersonasLDE(tabla->tab[pos], nombre);
}


void liberarTTablaPersonas(TTablaPersonas &tabla){
	for(int i = 0; i < tabla->cantidad; i++)
	    liberarTPersonasLDE(tabla->tab[i]);
	 delete[] tabla->tab;
	 delete tabla;
	 tabla = NULL;
}


void imprimirTTablaPersonas(TTablaPersonas tabla){
	for(int i = 0; i < tabla->cantidad; i++)
	    imprimirTPersonasLDE(tabla->tab[i]);
}
