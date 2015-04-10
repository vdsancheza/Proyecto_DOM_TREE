#include <iostream>
#include "DOM_tree.hpp"
#include "element.hpp"

using namespace std;

int main()
{

	DOM_tree<element> d,aux,aux1;
	element e;
	string cadena="<html><head><title>Ejemplo de Página Web</title></head><body><h1>Una Página Web</h1><p id='contenido'>Hola Mundo!!!</p><p>Bye!!!</p></body></html>";
	d.appendChild(cadena);
	d.mostrar();

    return 0;
}
