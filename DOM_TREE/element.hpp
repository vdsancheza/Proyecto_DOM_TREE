#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
/*	Victor Sanchez y Jesus Aguilar
	Licenciatura en Ciencias de la Computacion.
	Facultad Experimental de Ciencias Y Tecnologia.
	Universidad de Carabobo.
	4er Semestre.
	Programacion II.
	Profesora: Kiara Ottogalli.
	CI: 22518142.							*/
#include <string>
#include <list>

using namespace std;

class element{

	private:

		string tagna,inner;
		list<string > l;

	public:

		element():tagna(),inner(),l(){}///constructor
		element(string tag);///constructor
		element(const element &e);///constructor

		string tagname(){return this->tagna;}///Devuelve el tagname
		list<string>& attributelist(){return (this->l);};///devuelve la lista de attr
		string innerHTML(){return this->inner;} /// Devuelve el innerhtml
		void settagna(string tag){this->tagna=tag;} ///reemplaza el tagname
		void setattributelist(list<string> l){this->l=l;}///reemplaza la lista de attr por una nueva
		void setinnerHTML(string inner){this->inner=inner;}///reemplaza el inner por uno nuevo

		element& operator =(const element &e);

		void mostrar();

};//end class

void element:: mostrar(){

	/*list<string>::iterator it;
	cout<<tagna<<" ";
	cout<<inner<<" "<<endl;
	std::cout << "mylist contains:";

  for (it=l.begin(); it != l.end(); ++it)
    std::cout << ' ' << *it;

  std::cout <<endl;*/
  list<string>::iterator it;
  cout << "<"<< tagna;
  if(l.size() !=0)
  {
	  for (it=l.begin(); it != l.end(); ++it)
		std::cout << ' ' << *it;
	  }
	cout << ">";
	//cout << inner;
	///cout << "</"<< tagna << ">";
	
};

element::element(string tag){

	this->tagna=tag;

};//end element(string tag);



element::element(const element& e){

	*this=e;

};//end element(const element &e);

element& element:: operator =(const element &e){


	this->tagna=e.tagna;
	this->l=e.l;
	this->inner=e.inner;

	return *this;
};//end element& operator =(const element &l);*/


#endif
