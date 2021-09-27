#include<stdio.h>
#include<iostream>
using namespace std;
template <class T>
class Arithematic
{
	private :
		T a,b;
	public :
		Arithematic(T,T);
		T add();
		T sub();
		T div();
};
template <class T>
Arithematic<T> :: Arithematic(T a,T b)
{
	this->a=a;
	this->b=b;
}
template <class T>
T Arithematic<T> :: add()
{
	return (this->a+this->b);
}
template <class T>
T Arithematic<T> :: sub()
{
	return (this->a-this->b);
}
template <class T>
T Arithematic<T> ::div()
{
	return (this->b/this->a);
}
int main()
{
	Arithematic<float> a(20,2.5);
	cout<<a.add()<<"\n"<<a.div()<<"\n"<<a.sub();
	return 0;
}
