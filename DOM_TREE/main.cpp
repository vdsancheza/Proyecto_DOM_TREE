#include <iostream>
#include "DOM_tree.hpp"
#include "element.hpp"

using namespace std;

int main()
{

	DOM_tree<element> d,aux,aux1;
	element e;
	string cadena="<html><head><title>Ejemplo de Página Web</title></head><body><h1>Una Página Web</h1></body></html>";
	d.appendChild(cadena);
	///
	//std::cout << "Dom_Tree: " << d << std::endl;7
	///
	//e.settagna("jeus");
	//e.setinnerHTML("daniel");
	//aux.appendChild(cadena1);

	//d.appendChild(e);
	//e.settagna("jeus1");
	//e.setinnerHTML("daniel1");
	//d.appendChild(e);
	//d.appendChild(cadena);
	//d.replaceChild(1,aux);7

	//aux1=d.getElementByID("x");
	d.mostrar();
    //cout << "Hello world!" << endl;

    return 0;
}
