/*	Victor Sanchez y Jesus Aguilar
	Licenciatura en Ciencias de la Computacion.
	Facultad Experimental de Ciencias Y Tecnologia.
	Universidad de Carabobo.
	4er Semestre.
	Programacion II.
	Profesora: Kiara Ottogalli.
	CI: 22518142.							*/
#ifndef NODE_H
#define NODE_H
#include <iostream>


template<class Tdate>
class node{

	private:
		Tdate e;
		node<Tdate> *firstchild,*nextsibling;

	public:

		node<Tdate>():e(),firstchild(NULL),nextsibling(NULL){}///Constructor
		node<Tdate>(Tdate e):e(e),firstchild(NULL),nextsibling(NULL){}///Constructor
		node<Tdate>(Tdate e,node<Tdate> *first,node<Tdate> *next):e(e),firstchild(first),nextsibling(next){}///Constructor
		node<Tdate>(const node<Tdate> &n);///Constructor

		Tdate Element(){return this->e;} ///Devuelve el Tipo tdate e
		node<Tdate>* firstChild(){return this->firstchild;}///Devuelve apuntador a firstChild
		node<Tdate>* nextSibling(){return this->nextsibling;}///Devuelve apuntador a nextSibling
		void setElement(Tdate e){this->e=e;}///reemplaza e
		void setFirstchild(node<Tdate> *f){this->firstchild=f;}///Reemplaza a Firstchild
		void setnExtsibling(node<Tdate> *n){this->nextsibling=n;}///Reemplaza a nextSibling

		node<Tdate>& operator =(const node<Tdate> &n);///Sobrecarga de =

};//end class

template<class Tdate>
node<Tdate>& node<Tdate>:: operator =(const node<Tdate> &n){

	this->e=n.e;
	this->firstchild=n.firstchild;
	this->nextsibling=n.nextsibling;

	return *this;
};//end node<Tdate>& operator =(const node<Tdate> &n);

template<class Tdate>
node<Tdate>::node(const node<Tdate> &n){

	*this=n;

};//end node<Tdate>(const node<Tdate> &n);

#endif
