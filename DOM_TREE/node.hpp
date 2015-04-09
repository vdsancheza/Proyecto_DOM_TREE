#ifndef NODE_H
#define NODE_H
#include <iostream>


template<class Tdate>
class node{

	private:
		Tdate e;
		node<Tdate> *firstchild,*nextsibling;

	public:

		node<Tdate>():e(),firstchild(NULL),nextsibling(NULL){}
		node<Tdate>(Tdate e):e(e),firstchild(NULL),nextsibling(NULL){}
		node<Tdate>(Tdate e,node<Tdate> *first,node<Tdate> *next):e(e),firstchild(first),nextsibling(next){}
		node<Tdate>(const node<Tdate> &n);

		Tdate Element(){return this->e;}
		node<Tdate>* firstChild(){return this->firstchild;}
		node<Tdate>* nextSibling(){return this->nextsibling;}
		void setElement(Tdate e){this->e=e;}
		void setFirstchild(node<Tdate> *f){this->firstchild=f;}
		void setnExtsibling(node<Tdate> *n){this->nextsibling=n;}

		node<Tdate>& operator =(const node<Tdate> &n);

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
