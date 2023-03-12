#pragma once
#include <iostream>
class nodoS
{
private:
	int dato;
	nodoS* sgte;
public:
	nodoS();
	nodoS(int);

	void setDato(int);
	void setSgte(nodoS*);
	int getDato();
	nodoS *getSgte();
	
};

