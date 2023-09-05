#pragma once
#include "libro.h"
class Nodo
{
public:
	libro book;
	Nodo* sig;
	Nodo* ant;
	Nodo();
	Nodo(libro, Nodo*, Nodo*);
};

