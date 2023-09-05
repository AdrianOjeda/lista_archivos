#include "libro.h"
#include <string.h>

libro::libro() {

	precio = 0;
	strcpy_s(titulo, "");
	strcpy_s(autor, "");
	paginas = 0;
	id = 0;
}

libro::libro(char* titulo, char* autor, float precio, int paginas, int id) {
	this->precio = precio;
	strcpy_s(this->titulo, titulo);
	strcpy_s(this->autor, autor);
	this->id = id;
	this->paginas = paginas;
}