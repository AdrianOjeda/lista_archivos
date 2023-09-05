#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Lista.h"
using namespace std;
using namespace std;



int main()
{

    Lista* list = new Lista;
    libro book;
    int resp, buscar_id, id, paginas, posicion;
    char autor[30], titulo[30];
    float precio;
    do {
        cout << "*** Almacen de libros ***" << endl;
        cout << "1. Altas" << endl;
        cout << "2. Bajas" << endl;
        cout << "3. Consultar" << endl;
        cout << "4. Modificar registro" << endl;
        cout << "5. Salir" << endl;
        cout << "6. Ordenar" << endl;
        cout << "7. Guardar informacion en archivo" << endl;
        cout << "8. Recuperar informacion del archivo" << endl;

        cin >> resp;
        switch (resp) {
        case 1: {
            cout << "*** ALTAS ***" << endl;
            cout << "1. Insertar al inicio" << endl;
            cout << "2. Insertar por posicion" << endl;
            cout << "3. Insertar al final" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {
                cout << "*** Insertar producto al inicio ***" << endl;
                id = rand();
                book.setId(id);
                cout << "Ingrese el precio del libro: ";
                cin >> precio;
                book.setPrecio(precio);
                cout << "Ingrese el numero de paginas del libro: ";
                cin >> paginas;
                book.setPaginas(paginas);
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                cin.getline(titulo, 30);
                book.setTitulo(titulo);
                //cin.ignore();
                cout << "Ingrese el nombre del autor del libro: ";
                cin.getline(autor, 30);
                book.setAutor(autor);
                list->insertarInicio(book);
                cout << "Producto ingresado con exito!" << endl;

                break;
            }case 2: {
                cout << "*** Insertar producto por posicion ***" << endl;
                if (list->vacia() == false) {
                    cout << "Escriba la posicion en la que quiere insertar el elemento: ";
                    cin >> posicion;
                    if (posicion > 0 && posicion <= list->tamanoLista()) {
                        id = rand();
                        book.setId(id);
                        cout << "Ingrese la posicion a la que desea ingresar un libro: ";
                        cin >> posicion;
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        book.setPrecio(precio);
                        cout << "Ingrese el numero de paginas del libro: ";
                        cin >> paginas;
                        book.setPaginas(paginas);
                        cout << "Ingrese el titulo del libro: ";
                        cin.ignore();
                        cin.getline(titulo, 30);
                        book.setTitulo(titulo);

                        cout << "Ingrese el nombre del autor del libro: ";
                        cin.getline(autor, 30);
                        book.setAutor(autor);
                        list->insertarPosicion(posicion, book);
                        cout << "Producto ingresado con exito!" << endl;
                    }if (posicion == list->tamanoLista() + 1) {

                        id = rand();
                        book.setId(id);
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        book.setPrecio(precio);
                        cout << "Ingrese el numero de paginas del libro: ";
                        cin >> paginas;
                        book.setPaginas(paginas);
                        cout << "Ingrese el titulo del libro: ";
                        cin.ignore();
                        cin.getline(titulo, 30);
                        book.setTitulo(titulo);

                        cout << "Ingrese el nombre del autor del libro: ";
                        cin.getline(autor, 30);
                        book.setAutor(autor);
                        cout << "Producto ingresado con exito!" << endl;
                        list->insertarFinal(book);
                    }
                    else {
                        cout << "La posicion deseada no es valida" << endl;
                    }
                }
                break;
            }case 3: {
                cout << "*** Insertar al final ***" << endl;
                id = rand();
                book.setId(id);
                cout << "Ingrese el precio del libro: ";
                cin >> precio;
                book.setPrecio(precio);
                cout << "Ingrese el numero de paginas del libro: ";
                cin >> paginas;
                book.setPaginas(paginas);
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                cin.getline(titulo, 30);
                book.setTitulo(titulo);

                cout << "Ingrese el nombre del autor del libro: ";
                cin.getline(autor, 30);
                book.setAutor(autor);
                cout << "Producto ingresado con exito!" << endl;
                list->insertarFinal(book);

                break;
            }default: {

                cout << "Ingrese una opcion valida" << endl;
                break;
            }
            }
            resp = 0;
            break;
        }case 2: {
            cout << "*** Bajas ***" << endl;
            cout << "1. Eliminar libro" << endl;
            cout << "2. Vaciar lista" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {
                cout << "*** Eliminar libro ***" << endl;
                if (list->vacia() == false) {

                    cout << "Ingrese el id del libro: ";
                    cin >> id;
                    book.setId(id);

                    list->eliminar(book);
                }

                break;
            }case 2: {
                cout << "*** Eliminando todo ***" << endl;
                cout << endl;
                if (list->vacia() == false) {
                    list->eliminarTodo();
                }


                break;
            }default: {

                cout << "Ingrese una opcion valida" << endl;
                break;
            }
            }
            resp = 0;

            break;
        }case 3: {
            cout << "*** CONSULTAR ***" << endl;
            cout << "1. Mostrar todo" << endl;
            cout << "2. Mostrar libro" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {
                list->mostrar();
                break;
            }case 2: {
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                cin.getline(titulo, 30);
                book.setTitulo(titulo);

                cout << "Ingrese el nombre del autor del libro: ";
                cin.getline(autor, 30);
                book.setAutor(autor);

                list->mostrarLibro(book);

                break;
            }default: {
                cout << "Ingresa una opcion valida" << endl;
            }
            }
            resp = 0;
            break;
        }case 4: {

            cout << "MODIFICAR REGISTRO" << endl;
            cout << "Ingrese el ID del libro que desea modificar: ";
            cin >> buscar_id;
            book.setId(buscar_id);
            list->modificarRegistro(book);
            cout << "Registro modificado" << endl;
            break;
        }case 5: {

            cout << "Saliendo del programa..." << endl;
            break;

        }case 6: {
            int tamano = list->tamanoLista();
            list->mergeSort(tamano, list);
            cout << "***LISTA ORDENADA ***" << endl;

            break;

        } case 7: {

            if (list->vacia());
            else {
                list->escribirArchivo();
                cout << "***Informacion guardada en el archivo con exito***" << endl;

            }

            break;
        }case 8: {

            //Lista* list = new Lista;
            libro book;
            //Nodo* header = nullptr;

            ifstream inputFile("libros.txt");

            if (!inputFile.is_open()) {
                cerr << "Failed to open the file!" << endl;
                return 1;
            }

            string line;

            while (getline(inputFile, line, '*')) {

                istringstream iss(line);
                string token;
                int paginas = 0;
                int id = 0;
                float precio = 0.0;
                char titulo[30] = "";
                char autor[30] = ""; // Initialize the character array

                int fieldIndex = 0;
                while (getline(iss, token, '|')) {
                    if (fieldIndex == 0) {
                        strncpy_s(titulo, token.c_str(), sizeof(titulo) - 1); // Copy the character array value
                        titulo[sizeof(titulo) - 1] = '\0'; // Ensure null-termination
                        book.setTitulo(titulo);
                    }
                    else if (fieldIndex == 1) {
                        strncpy_s(autor, token.c_str(), sizeof(autor) - 1); // Copy the character array value
                        autor[sizeof(autor) - 1] = '\0'; // Ensure null-termination
                        book.setAutor(autor);

                    }
                    else if (fieldIndex == 2) {
                        precio = stof(token);
                        book.setPrecio(precio);
                    }
                    else if (fieldIndex == 3) {
                        paginas = stoi(token);

                        book.setPaginas(paginas);
                    }
                    else if (fieldIndex == 4) {
                        id = stoi(token);
                        book.setId(id);
                    }
                    fieldIndex++;

                }
                list->insertarFinal(book);

                //list->mostrar();

            }
            list->mostrar();
            //Close the file
            inputFile.close();


            cout << "*** Informacion recuperada ***" << endl;

            break;
        }default: {

            cout << "Ingrese una opcion correcta!" << endl;
            break;
        }
        }

    } while (resp != 5);




}

