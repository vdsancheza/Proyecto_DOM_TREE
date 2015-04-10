/*	Victor Sanchez y Jesus Aguilar
	Licenciatura en Ciencias de la Computacion.
	Facultad Experimental de Ciencias Y Tecnologia.
	Universidad de Carabobo.
	4er Semestre.
	Programacion II.
	Profesora: Kiara Ottogalli.
	CI: 22518142.							*/

#include <iostream>
#include "DOM_tree.hpp"
#include "element.hpp"

using namespace std;

int main()
{

	DOM_tree<element> d;
	string cadena="<html><head><title>Ejemplo de Página Web</title></head><body><h1>Una Página Web</h1><p id='contenido'>Hola Mundo!!!</p><p>Bye!!!</p></body></html>";
	d.appendChild(cadena);
	cout << d;

    return 0;
}
