#pragma once
#include "Nodo.h"
class Lista
{
	Nodo* header;
	Nodo* tail;
	libro book;
public:
	Lista();
	Lista(Nodo*, Nodo*);
	void insertarInicio(libro);
	void mostrar();
	void eliminarTodo();
	void eliminar(libro);
	void insertarFinal(libro);
	void mostrarLibro(libro);
	bool vacia();
	int tamanoLista();
	void insertarPosicion(int, libro);
	int buscar(int);
	void modificarRegistro(libro);
	void mergeSort(int, Lista*);
	void escribirArchivo();
	


};