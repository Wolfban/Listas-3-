#pragma once
#include <stdlib.h>
#include <iostream>

#include "nodoS.h"

class listaSimple
{
private:
	nodoS* cab;
	int largo;

public:
	listaSimple();
	~listaSimple();

	nodoS* getCab();
	int getLargo();

	void setCab(nodoS*);
	void setLargo(int);

	/*UTILITARIOS */
	
	nodoS* dirNodo(int);
	nodoS* dirAnterior(int);
	nodoS* dirPosterior(int);
	nodoS* dirUltimo();

	
	bool esVacia();

	void agregarInicio(int);
	void agregarFinal(int);
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int);

	bool eliminar(int);
	void eliminarLista();
	void desplegarLista();
	void eliminarRepetidos();


};

