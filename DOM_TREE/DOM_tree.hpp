#ifndef DOM_tree_H
#define DOM_tree_H
#include <iostream>
#include "element.hpp"
#include "node.hpp"
#include <string>
#include<list>

using namespace std;
template<class Tdate>
class DOM_tree{

	private:

		node<Tdate> *dom;

	private:

		node<Tdate>& childnode(node<Tdate> *dom,int &aux,int p);
		node<Tdate>& copiarnodes(node<Tdate> *n);
		void eliminarnodes(node<Tdate> *p);
		node<Tdate>& appendChild(string str,int tus,int &ind,list<string> &tags);
		node<Tdate>& appendChild1(string str,int tus,int &ind,list<string> &tags);
		string gettagname(string str,int &ind);
		string getinner(string str,int &ind);
		void getattlistatribute(string str,int &ind,list<string> &l);
		void extractingdata(string str,int &ind,element &e);
		node<Tdate>& estanode(node<Tdate> *raiz,string ID);
		void mostrar(node<Tdate> *d);

	public:
		DOM_tree<Tdate>():dom(NULL){}
		DOM_tree<Tdate>(Tdate e);
		DOM_tree<Tdate>(const DOM_tree<Tdate>& d);

		DOM_tree<Tdate>& childnode(int p);
		void appendChild(int pos,DOM_tree<Tdate> d);
		void appendChild(DOM_tree<Tdate> d);
		void appendChild(Tdate e);
		void appendChild(string str);
		void removeChild(int pos);
		void replaceChild(int pos,DOM_tree<Tdate> d);
		DOM_tree<Tdate>& getElementByID(string ID);
		node<Tdate>& estanode(string ID);
		//void DOM_tree();

		void mostrar();

		DOM_tree<Tdate>& operator = (const DOM_tree<Tdate> &d);
};//end class

template<class Tdate>
void DOM_tree<Tdate>:: mostrar(){

    mostrar(this->dom);
};

template<class Tdate>
void DOM_tree<Tdate>::mostrar(node<Tdate> *d){
    element e;

	if(d!=NULL){

		e=d->Element();
		e.mostrar();
		mostrar(d->firstChild());
		cout<<endl;
		mostrar(d->nextSibling());
	}
}//end mostrar(const nodoArbol<Tdate>& n);

template<class Tdate>
DOM_tree<Tdate>::DOM_tree(Tdate e){

	this->dom=new node<Tdate>(e);


};// end DOM_tree(element e);

template<class Tdate>
void DOM_tree<Tdate>:: appendChild(Tdate e){

	DOM_tree<Tdate> *d=new DOM_tree<Tdate>();

	if(this->dom==NULL){

		this->dom=new node<Tdate>(e);

	}else{
		d->dom= new node<Tdate>(e);
		this->appendChild(*d);
	}


};//end void appendChild(Tdate e);

template<class Tdate>
DOM_tree<Tdate>& DOM_tree<Tdate>:: childnode(int p){

	int aux=1;
	DOM_tree<Tdate> *aux1=new DOM_tree<Tdate>();
	aux1->dom=&childnode(this->dom->firstChild(),aux,p);

	return *aux1;

};//end DOM_tree<Tdate>& estanodo(Tdate p);

template <class Tdate>
node<Tdate>& DOM_tree<Tdate>:: childnode(node<Tdate> *dom,int &aux,int p){

	node<Tdate> *result=new node<Tdate>();

	if(dom!=NULL && aux!=p){

		aux++;
		result=&childnode(dom->nextSibling(),aux,p);

	}else{

		if(dom==NULL){
			result=NULL;
		}else{

			result=dom;

		}//end if;
	}//end if-else

	return *result;
};//end int estanodo(DOM_tree<Tdate> *n);

template<class Tdate>
void DOM_tree<Tdate>:: appendChild(DOM_tree<Tdate> d){

	node<Tdate> *aux;

	if(this->dom->firstChild()==NULL){

		this->dom->setFirstchild(&copiarnodes(d.dom));

	}else{

		aux=this->dom->firstChild();

			while(aux->nextSibling()!=NULL){
				aux=aux->nextSibling();
			}//end

			aux->setnExtsibling(&copiarnodes(d.dom));

	}//end if-else

};//end void appendChild(int pos);

template<class Tdate>
void DOM_tree<Tdate>:: appendChild(int pos,DOM_tree<Tdate> d){

	node<Tdate> *aux,*aux2;
	int i=2;
	DOM_tree<Tdate> *d1=new DOM_tree<Tdate>();

	if(pos==1){

		aux=this->dom->firstChild();
		this->dom->setFirstchild(d.dom);
		d1->dom=aux;
		this->appendChild(*d1);

	}else{

		aux2=this->dom->firstChild();
		aux=aux2->nextSibling();

		while(aux!=NULL && i<=pos){
			aux2=aux;
			aux=aux->nextSibling();
			i++;
		}//end while

		aux2->setnExtsibling(&copiarnodes(d.dom));
		aux2=aux2->nextSibling();
		aux2->setnExtsibling(aux);

	}//end if-else

};//end void appendChild(int pos,DOM_tree<Tdate> d);

template<class Tdate>
void DOM_tree<Tdate>:: appendChild(string str){

	int ind=1;
	int tus=str.size();
	list<string> tags;
	tags.push_back("");
	if(str[3]!='<'){

		this->dom=(&appendChild1(str,tus,ind,tags));

	}//end if;
};//end void appendChild(st

template<class Tdate>
node<Tdate>& DOM_tree<Tdate>:: appendChild1(string str,int tus,int &ind,list<string> &tags){


	node<Tdate> *aux=NULL;
	element *e=new element();
	string st;
	int tu;
    if(ind<tus){


        if(str[ind]!='/'&& str[ind-1]!='/'){

            extractingdata(str,ind,*e);
            tags.push_back(e->tagname());
            aux=new node<Tdate>(*e);
            aux->setFirstchild(&appendChild(str,tus,ind,tags));
            aux->setnExtsibling(&appendChild1(str,tus,ind,tags));

		}else{

				st=tags.back();
				tags.pop_back();
            	tu=st.size();

                ind+=tu+3;
		}
    }
        return *aux;

};//end void appendChild(string str);

template<class Tdate>
node<Tdate>& DOM_tree<Tdate>:: appendChild(string str,int tus,int &ind,list<string> &tags){

	element *e=new element();
	node<Tdate> *aux=NULL;
	string st;
	int tu;

	if(ind<tus){


            if( str[ind]!='/' && str[ind-1]!='/'){



                extractingdata(str,ind,*e);
                tags.push_back(e->tagname());
				aux=new node<Tdate>(*e);
                aux->setFirstchild(&appendChild1(str,tus,ind,tags));
                aux->setnExtsibling(&appendChild(str,tus,ind,tags));
            }else{

            	st=tags.back();
            	tags.pop_back();
            	tu=st.size();

                ind+=tu+3;
            }


	}//end if
    return *aux;
};//end DOM_tree<Tdate>& appendChild(string str,int &ind);

template<class Tdate>
void DOM_tree<Tdate>:: extractingdata(string str,int &ind,element &e){

	list<string> l;

    e.settagna(gettagname(str,ind));

    if(str[ind]==' '){
        ind++;
        getattlistatribute(str,ind,l);
        e.setattributelist(l);
    }//end if

    ind++;

    if(str[ind]!='<'){

        e.setinnerHTML(getinner(str,ind));

    }//end if

		e.setattributelist(l);
		l.clear();

        ind++;

};

template<class Tdate>
string DOM_tree<Tdate>:: gettagname(string str,int &ind){

	string aux;

	while(str[ind]!=' ' && str[ind]!='>'){
		aux+=str[ind];
		ind++;
	}//end tagname while

	return aux;
};

template<class Tdate>
void DOM_tree<Tdate>:: getattlistatribute(string str,int &ind,list<string> &l){

	string aux;
	while(str[ind]!='>'){

		while(str[ind]!=' ' && str[ind]!='>'){
			aux+=str[ind];
			ind++;
		}//end while*
		if(str[ind]!='>'){
			ind++;
		}

		l.push_back(aux);
		aux.clear();

	}//end while

};//end list<string> getattlistatribute(string str,int &ind);

template<class Tdate>
string DOM_tree<Tdate>:: getinner(string str,int &ind){

	string aux;

	while(str[ind]!='<'){
		aux+=str[ind];
		ind++;
	}//end while

	return aux;
};//end string getinner(string str,int &ind);

template<class Tdate>
DOM_tree<Tdate>& DOM_tree<Tdate>:: operator = (const DOM_tree<Tdate> &d){

	this->dom=new node<Tdate>();
	this->dom=&copiarnodes(d.dom);
	return *this;

};//end DOM_tree

template<class Tdate>
DOM_tree<Tdate>::DOM_tree(const DOM_tree<Tdate>& d){
	*this=d;
};//end DOM_tree<Tdate>(const DOM_tree<Tdate>& d);

template<class Tdate>
node<Tdate>& DOM_tree<Tdate>:: copiarnodes(node<Tdate> *n){

	node<Tdate> *aux;

	if(n==NULL){

		aux=NULL;

	}else{
		aux=new node<Tdate>(n->Element(),&copiarnodes(n->firstChild()),&copiarnodes(n->nextSibling()));
	}//end if-else

	return *aux;

}//end node<Tdate>& copiarnodes(node<Tdate> n);

template<class Tdate>
void DOM_tree<Tdate>:: removeChild(int pos){

	node<Tdate> *aux,*aux1;
	int i;

	if(pos==1){

		aux1=this->dom->firstChild();
		this->dom->setFirstchild(aux1->nextSibling());
	}else{

		aux=this->dom->firstChild();

		for(i=1;i<pos-1;i++){

			aux=aux->nextSibling();

		}//end for

		aux1=aux->nextSibling();
		aux->setnExtsibling(aux1->nextSibling());

	}//end if-else

	aux1->setnExtsibling(NULL);
	eliminarnodes(aux1);
	aux1=NULL;

};//end void removeChild(int p);

template <class Tdate>
void DOM_tree<Tdate>:: eliminarnodes(node<Tdate> *p){

	if(p!=NULL){

		if(p->nextSibling()!=NULL){
			eliminarnodes(p->nextSibling());
		}//end if

		if(p->firstChild()!=NULL){
			eliminarnodes(p->firstChild());
		}//end if

	}//end if

	delete p;
	p=NULL;

}//end void eleminiarnodos(nodoArbol<Tdate> *p);

template<class Tdate>
void DOM_tree<Tdate>:: replaceChild(int pos,DOM_tree<Tdate> d){

	if(this->dom->firstChild()!=NULL ){
		this->removeChild(pos);
		this->appendChild(pos,d);
	}//end if

};//end void replaceChild(int pos,DOM_tree<Tdate> d);

template<class Tdate>
DOM_tree<Tdate>& DOM_tree<Tdate>:: getElementByID(string ID){

	DOM_tree<Tdate> *aux=new DOM_tree<Tdate>(),*aux1=new DOM_tree<Tdate>();

	aux->dom=&estanode(this->dom,ID);

	if(aux->dom!=NULL){
        aux1->dom=aux->dom;
        aux1->dom->setFirstchild(&copiarnodes(aux->dom->firstChild()));
	}//end if
	return *aux1;

};//end DOM_tree<Tdate>& getElementByID(string ID);

template<class Tdate>
node<Tdate>& DOM_tree<Tdate>:: estanode(string ID){

	node<Tdate> *aux=new node<Tdate>();
	aux=&estanode(this->dom,ID);

	return *aux;

};//end nodoArbol<Tdate>& estanodo(Tdate p);

template <class Tdate>
node<Tdate>& DOM_tree<Tdate>:: estanode(node<Tdate> *raiz,string ID){

	node<Tdate> *result=new node<Tdate>();
	element e;

	if(raiz==NULL){

		result=NULL;

	}else{

		result=&estanode(raiz->firstChild(),ID);
		e=raiz->Element();
		if(e.tagname()==ID){

			result=raiz;
		}//end if*

		if(result==NULL){

			result=&estanode(raiz->nextSibling(),ID);

		}//end if
	}//end if-else

	return(*result);
};//end int estanodo(nodoArbol<Tdate> *n);


#endif
