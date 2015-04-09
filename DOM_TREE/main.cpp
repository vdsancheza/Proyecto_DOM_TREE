#include <iostream>
#include "DOM_tree.hpp"
#include "element.hpp"

using namespace std;

int main()
{

	DOM_tree<element> d,aux,aux1;
	element e;
	string cadena="<p>Este es un <b>string <x>hola</x><y>cagon</y></b><t> joder rat kid</t></p>",cadena1="<x>Este<y>string</y></x>";
	d.appendChild(cadena);
	e.settagna("jeus");
	e.setinnerHTML("daniel");
	aux.appendChild(cadena1);

	d.appendChild(e);
	e.settagna("jeus1");
	e.setinnerHTML("daniel1");
	d.appendChild(e);
	//d.appendChild(cadena);
	//d.replaceChild(1,aux);

	//aux1=d.getElementByID("x");
	d.mostrar();
    cout << "Hello world!" << endl;

    return 0;
}
