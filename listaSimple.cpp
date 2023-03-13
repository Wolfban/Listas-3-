#include "listaSimple.h"

listaSimple::listaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

listaSimple::~listaSimple()
{
}

nodoS* listaSimple::getCab()
{
	return this->cab;
}

int listaSimple::getLargo()
{
	return this->largo;
}

void listaSimple::setCab(nodoS* ptr)
{
	this->cab = ptr;
}

void listaSimple::setLargo(int pLargo)
{
	this->largo = pLargo;
}

nodoS* listaSimple::dirNodo(int x)
{ //Devuelve la dirección del nodo cuyo valor sea x
	nodoS* aux = NULL;
	
	if (!esVacia()) {
		aux = getCab();
		while (aux !=NULL && aux->getDato() != x) 
			aux = aux->getSgte();
	}
	
	return aux;
}

nodoS* listaSimple::dirAnterior(int x)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea x

	bool encontrado = false;
	nodoS* aux = NULL;

	if (getLargo() > 1) {
		aux = getCab();
		while ((aux->getSgte() != NULL) && (!encontrado)) {
			if (aux->getSgte()->getDato() == x)
				encontrado = true;
			else
				aux = aux->getSgte();
		}
			
	}

	if (encontrado)
		return aux;
	else
		return NULL;


}
nodoS* listaSimple::dirPosterior(int x)
{ //Devuelve la dirección del nodo anterior al nodo cuyo valor sea x

	bool encontrado = false;
	nodoS* aux = NULL;

	if (getLargo() > 1) {
		aux = getCab();
		while ((aux->getSgte() != NULL) && (!encontrado)) {
			if (aux->getSgte()->getDato() == x)
				encontrado = true;
			else
				aux = aux->getSgte();
		}

	}

	if (encontrado)
		return aux;
	else
		return NULL;


}

nodoS* listaSimple::dirUltimo()
{  /*Devuelve la dirección del último nodo, si la lista está vacía devuelve NULL*/
	nodoS* ult = NULL;
	if (!esVacia()) {
		ult = this->cab; //Iniciando buscar a partir del primer nodo.
		while (ult->getSgte() != NULL)
			ult = ult->getSgte();

	}
	return ult;
}

bool listaSimple::esVacia()
{
	return cab==NULL;
}

void listaSimple::agregarInicio(int x)
{
	nodoS* nuevo = new nodoS(x); //Paso #1 crear el nodo
	if (!esVacia()) 
		nuevo->setSgte(getCab()); //Paso #2 Enlazar el nuevo nodo a la lista
	setCab(nuevo);//Paso #3 Reacomodar la lista con el nuevo nodo
	setLargo(getLargo() + 1);
	
}

void listaSimple::agregarFinal(int x)
{   //Agrega al final de la lista un nodo con el valor de x
	nodoS* nuevo = new nodoS(x); //Paso #1 crear el nodo
	if (esVacia()) {
		setCab(nuevo); //Paso #3 Reacomodar la lista con el nuevo nodo
	}
	else {
		dirUltimo()->setSgte(nuevo);//Paso #3 Reacomodar la lista con el nuevo nodo
	}
	setLargo(getLargo() + 1);
}

bool listaSimple::agregarAntesDe(int _dato, int _ref)
{ //Agregar un nodo con el valor _dato antes de nodo cuyo valor sea _ref
	bool agregado = false;
	if (!esVacia()) {
		if (getCab()->getDato() == _ref) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			nodoS* ant = dirAnterior(_ref); //Dirección del nodo anterior a _ref.
			if (ant != NULL) { //Encontró el anterior
				nodoS* aux = ant->getSgte();
				nodoS* nuevo = new nodoS(_dato);//Paso #1. Crear el nodo
				nuevo->setSgte(aux);//Paso #2. Enlazar el nuevo nodo a la lista
				ant->setSgte(nuevo);//Paso #3. Reacomodar la lista con el nuevo nodo.
				setLargo(this->largo + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

	

	bool listaSimple::agregarDespuesDe(int _dato, int _ref)
	{ //Agregar un nodo con el valor _dato antes de nodo cuyo valor sea _ref
		bool agregado = false;
		if (!esVacia()) {
		
		
				nodoS* ant = dirNodo(_ref); //Dirección del nodo anterior a _ref.
				if (ant != NULL) { //Encontró el anterior
					nodoS* aux = ant->getSgte();
					nodoS* nuevo = new nodoS(_dato);//Paso #1. Crear el nodo
					nuevo->setSgte(aux);//Paso #2. Enlazar el nuevo nodo a la lista
					ant->setSgte(nuevo);//Paso #3. Reacomodar la lista con el nuevo nodo.
					setLargo(this->largo + 1);
					agregado = true;
				}
			
		}

		return agregado;

	}


bool listaSimple::eliminar(int _dato)
{ //Eliminar el primer nodo cuyo valor sea igual a _dato
	bool removido = false;
	if (!esVacia()) {
		nodoS* aux = NULL;
		if (getCab()->getDato() == _dato) {
			//Proceso de remover el primer nodo
			aux = getCab();//Paso #1: Apunte el nodo a eliminar
			//Paso #2: reacomodar la lista sin el nodo
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux; //Paso #3: Eliminar el nodo
			removido = true;
		}
		else {
			nodoS* ant = dirAnterior(_dato);
			if (ant != NULL) {
				aux = ant->getSgte();//Paso #1: Apunte el nodo a eliminar
				ant->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				delete aux; //Paso #3: Eliminar el nodo
				removido = true;
			}
		}
	}


	return removido;
}

void listaSimple::eliminarLista()
{
	if (esVacia())
		std::cout << "La lista esta vacia...";
	else {
		nodoS* aux = getCab();
		nodoS* sig;
		while (aux != nullptr) {
			sig = aux->getSgte();
			delete aux;
			aux = sig;
		}
		setCab(nullptr);
		std::cout << "Nodos eliminados!";
	}
}

void listaSimple::desplegarLista()
{
	if (esVacia())
		std::cout << "La lista está vacía...";
	else {
		nodoS* aux = getCab();
		while (aux != NULL) {
			std::cout << aux->getDato() << "-";
			aux = aux->getSgte(); //permite pasar al siguiente nodo
		}
		std::cout << "Fin de la lista \n" ;

	}
}

void listaSimple::eliminarRepetidos()
{
		nodoS* aux = getCab();
		while (aux != NULL) {
			nodoS* nodoTemporal = aux;
			while (nodoTemporal->getSgte() != NULL) {
				if (nodoTemporal->getSgte()->getDato() == aux->getDato()) {
					nodoS* nodoDlt = nodoTemporal->getSgte();
					nodoTemporal->setSgte(nodoTemporal->getSgte()->getSgte());
					setLargo(getLargo() - 1);
					delete nodoDlt;
				}else {
					nodoTemporal = nodoTemporal->getSgte();
				}
			}
			aux = aux->getSgte();
		}
		std::cout << "Se han eliminado los datos repetidos correctamente \n";
}
