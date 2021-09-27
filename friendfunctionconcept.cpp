#include<stdio.h>
#include <iostream>
using namespace std;
class B;
class A
{
  int a=9;
  public :
  friend int operator +(A,B);
  
};
class B
{
  int b=4;
  public:
  friend int operator +(A,B);
};
int  operator +(A a,B b)
{
  cout<<"Sum of these two is "<<a.a+b.b;
  return a.a+b.b;
}
int main()
{
  A a;B b;int x;
  x=a+b;
  cout<<"\n"<<x;
}