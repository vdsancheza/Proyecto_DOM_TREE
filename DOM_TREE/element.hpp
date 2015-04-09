#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class element{

	private:

		string tagna,inner;
		list<string > l;

	public:

		element():tagna(),inner(),l(){}
		element(string tag);
		element(const element &e);

		string tagname(){return this->tagna;}
		list<string>& attributelist(){return (this->l);};
		string innerHTML(){return this->inner;}
		void settagna(string tag){this->tagna=tag;}
		void setattributelist(list<string> l){this->l=l;}
		void setinnerHTML(string inner){this->inner=inner;}

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
	cout << " >";
	cout << inner;
	cout << "</"<< tagna << ">";
	
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
