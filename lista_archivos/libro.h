#pragma once
#include <string.h>
class libro
{

private:
	char titulo[30];
	char autor[30];
	float precio = 0;
	int paginas = 0;
	int id = 0;
public:
	libro();
	libro(char*, char*, float, int, int);
	//getters
	char* getAutor() { return autor; }
	char* getTitulo() { return titulo; }
	int getPrecio() { return precio; }
	int getId() { return id; }
	int getPaginas() { return paginas; }

	// setters
	void setAutor(char* a) { strncpy_s(autor, a, sizeof(autor)); }
	void setTitulo(char* n) { strncpy_s(titulo, n, sizeof(titulo)); }
	void setPrecio(int e) { precio = e; }
	void setId(int i) { id = i; }
	void setPaginas(int p) { paginas = p; }
};

