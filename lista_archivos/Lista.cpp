#include "Lista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;



Lista::Lista() {
	header = nullptr;
	tail = nullptr;

}
Lista::Lista(Nodo* ptr, Nodo* ptrtail) {
	header = ptr;
	tail = ptrtail;

}


void Lista::insertarInicio(libro book) {
	Nodo* temp = new Nodo(book, nullptr, nullptr);
	if (!header) {
		header = temp;
		tail = temp;

	}
	else {

		temp->sig = header;
		header->ant = temp;
		header = temp;
	}
}

void Lista::mostrar() {
	Nodo* aux = header;

	if (header) {
		while (aux) {
			cout << "Titulo: " << aux->book.getTitulo() << " | Autor: " << aux->book.getAutor() << " | Precio: " << aux->book.getPrecio() << " | Paginas: " << aux->book.getPaginas() << " | Id: " << aux->book.getId() << endl;
			aux = aux->sig;
		}
		cout << endl;
	}
	else {
		cout << endl << "Lista vacia" << endl;
	}

}

void Lista::eliminarTodo() {

	Nodo* aux = header;
	while (aux != nullptr) {
		Nodo* temp = aux;
		aux = aux->sig;
		delete temp;
	}
	header = nullptr;
	tail = nullptr;
	delete aux;
	cout << "Lista eliminada con exito!" << endl;
}

void Lista::insertarFinal(libro book) {

	Nodo* temp = new Nodo(book, nullptr, nullptr);
	temp->sig = nullptr; // Asegúrate de que el nuevo nodo tenga su siguiente como nullptr

	if (tail == nullptr) {
		// Si la lista está vacía, tanto header como tail deben apuntar al nuevo nodo
		header = temp;
		tail = temp;
	}
	else {
		temp->ant = tail; // Establece el nodo anterior de temp como el antiguo tail
		tail->sig = temp; // Establece el siguiente del antiguo tail como temp
		tail = temp;      // Actualiza tail para que apunte al nuevo nodo
	}

	cout << "Libro ingresado con exito!" << endl;

}
void Lista::eliminar(libro book) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	if (header != nullptr) {
		while (aux && bandera) {
			if (book.getId() == aux->book.getId()) {
				bandera = false;
			}
			else {
				auxAnterior = aux;
				aux = aux->sig;

			}
		}
		if (aux == nullptr) {
			cout << "No se encontro el libro" << endl;

		}
		else if (aux == header) {
			header = header->sig;
			delete aux;

		}
		else if (aux->sig == nullptr) {
			tail = tail->ant;
			tail->sig = nullptr;
			delete aux;

		}
		else {

			aux->ant->sig = aux->sig;
			aux->sig->ant = aux->ant;
			delete aux;
		}

	}
}

bool Lista::vacia() {

	if (header) {
		return false;
	}
	else {
		cout << endl << "Lista vacia" << endl;
		return true;
	}

}

int Lista::tamanoLista() {
	int contador = 0;
	Nodo* aux = header;
	while (aux != nullptr) {
		aux = aux->sig;
		contador++;

	}
	return contador;
}

void Lista::insertarPosicion(int posicion, libro book) {
	int contador = 0;
	Nodo* aux = header;
	Nodo* temp = new Nodo(book, nullptr, nullptr);
	if (posicion == 1) {
		temp->sig = header;
		header->ant = temp;
		header = temp;

		cout << "Libro ingresado con exito!" << endl;
	}
	else {
		while (contador < posicion - 1) {

			aux = aux->sig;
			contador++;

		}
		temp->sig = aux;
		temp->ant = aux->ant;
		aux->ant->sig = temp;
		aux->ant = temp;
		cout << "Libro ingresado con exito!" << endl;
	}
}

int Lista::buscar(int id) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	int contador = 1;
	bool bandera = true;
	while (aux && bandera) {
		if (aux->book.getId() == id) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
			contador++;
		}
	}if (bandera != false) {
		cout << "No existe un libro con ese ID!" << endl;
		return 0;
	}
	else {
		return contador;
	}
}



void Lista::mostrarLibro(libro book) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (strcmp(book.getTitulo(), aux->book.getTitulo()) == 0 && strcmp(book.getAutor(), aux->book.getAutor()) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
		}
	}
	if (bandera == false) {

		cout << "*** DATOS DEL LIBRO ***" << endl;
		cout << "Titulo: " << aux->book.getTitulo() << endl;
		cout << "Autor: " << aux->book.getAutor() << endl;
		cout << "Precio: " << aux->book.getPrecio() << endl;
		cout << "Paginas: " << aux->book.getPaginas() << endl;
		cout << "ID: " << aux->book.getId() << endl;

	}
	else {
		cout << "El libro no se encuentra en la lista" << endl;
	}


}

void Lista::modificarRegistro(libro book) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (book.getId() == aux->book.getId()) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
		}
	}
	if (bandera == false) {
		int precio, paginas;
		char titulo[30], autor[30];

		cout << "*** INGRESE LOS NUEVOS DATOS ***" << endl;

		cout << "Ingrese el precio del libro: ";
		cin >> precio;
		aux->book.setPrecio(precio);
		cout << "Ingrese el numero de paginas del libro: ";
		cin >> paginas;
		aux->book.setPaginas(paginas);
		cout << "Ingrese el titulo del libro: ";
		cin.ignore();
		cin.getline(titulo, 30);
		aux->book.setTitulo(titulo);

		cout << "Ingrese el nombre del autor del libro: ";
		cin.getline(autor, 30);
		aux->book.setAutor(autor);
	}
	else {
		cout << "El libro no se encuentra en la lista" << endl;
	}
}


void Lista::mergeSort(int contador, Lista* list) {
	Lista* derecha = new Lista;
	Lista* izquierda = new Lista;
	Nodo* aux = list->header;
	int med = contador / 2;
	int dif = contador % 2;
	int i, j;

	if (list->tamanoLista() > 1) {
		i = 0;
		while (aux && i < med) {
			izquierda->insertarInicio(aux->book);
			i++;
			aux = aux->sig;
		}
		j = 0;
		while (aux && j < med + dif) {
			derecha->insertarInicio(aux->book);
			j++;
			aux = aux->sig;
		}
		mergeSort(izquierda->tamanoLista(), izquierda);
		mergeSort(derecha->tamanoLista(), derecha);


		Nodo* iz = izquierda->header;
		Nodo* de = derecha->header;
		aux = list->header;
		i = 0;
		while (aux && iz && de) {
			if (iz->book.getId() < de->book.getId()) {
				aux->book = iz->book;
				iz = iz->sig;
				aux = aux->sig;
			}
			else {
				aux->book = de->book;
				de = de->sig;
				aux = aux->sig;

			}
		}
		if (iz) {
			while (iz) {
				aux->book = iz->book;
				iz = iz->sig;
				aux = aux->sig;


			}
		}
		if (de) {
			while (de) {
				aux->book = de->book;
				de = de->sig;
				aux = aux->sig;

			}

		}
	}

}



void Lista::escribirArchivo() {
	ofstream file("libros.txt", ios::out);
	Nodo* aux = header;

	if (!file.is_open())
	{
		cerr << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	if (header) {
		while (aux) {
			file << aux->book.getTitulo() << '|' << aux->book.getAutor() << '|' << aux->book.getPrecio() << '|' << aux->book.getPaginas() << '|' << aux->book.getId() << '*' << endl;
			aux = aux->sig;

		}
		//file << '#';
	}

	file.close();



}
