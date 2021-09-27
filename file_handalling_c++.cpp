#include<iostream>
using namespace std;
#include<stdio.h>
#include<fstream>
int main()
{
	ifstream fin;
	fin.open("amit.txt",ios::in);
	char ch=fin.get();
	while(!fin.eof())
	{
		cout<<ch;
		ch=fin.get();
	}
	
	return 0;
}
