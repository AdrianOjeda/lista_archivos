#include "Nodo.h"
#include <string.h>

Nodo::Nodo() {
	book.setPrecio(0);
	book.setTitulo(0);
	book.setAutor(0);
	book.setPaginas(0);
	book.setId(0);
}
Nodo::Nodo(libro book, Nodo* sig, Nodo* ant) {

	this->book.setTitulo(book.getTitulo());
	this->book.setPrecio(book.getPrecio());
	this->book.setId(book.getId());
	this->book.setAutor(book.getAutor());
	this->book.setPaginas(book.getPaginas());
	this->sig = sig;
	this->ant = ant;

}