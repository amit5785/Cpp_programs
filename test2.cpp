#include<stdio.h>
#include<iostream>
using namespace std;
#include<fstream>
/*int main()
{
   ifstream fin;
   fin.open("amit.txt",ios::in);
   char ch[50];
   fin.seekg(30,ios_base::beg);
   cout<<fin.tellg()<<endl;
   fin.getline(ch,30);
   cout<<ch;
   cout<<fin.tellg()<<endl;
   return 0;
}*/
class A
{
	public :
		 void fun()=0;
};
class B :public A
{
	void fun()
	{
		cout<<"Amit";
	}
};
int main()
{
	A obj;
	return 0;
}
