#include "nodoS.h"

nodoS::nodoS()
{
	this->dato = 0;
	this->sgte = NULL;
}

nodoS::nodoS(int pDato)
{
	this->dato = pDato;
	this->sgte = NULL;
}

void nodoS::setDato(int pDato)
{
	this->dato = pDato;
}

void nodoS::setSgte(nodoS* ptr)
{
	this->sgte = ptr;
}

int nodoS::getDato()
{
	return this->dato;
}

nodoS* nodoS::getSgte()
{
	return this->sgte;
}
