#include<stdio.h>
#include<iostream>
using namespace std;
class complex
{
	private:
		int a,b;
    public:
    	void set_data()
    	{
    		cout<<"Enter the Real and Imaginay part of the Complex No:-\n";
    		cin>>a>>b;
		}
		
		void show_data()
		{
			cout<<"a:-  "<<a<<endl;
			cout<<"b:-  "<<b<<endl;
			cout<<"Complex form:- "<<a;
			if(b<0)
			{
				cout<<b<<"i\n";
			}
			else
			cout<<"+"<<b<<"i\n";
		}
		
		void add(complex c1,complex c2)
        {
	      a=c1.a+c2.a;
		  b=c2.b+c1.b;  
        }  
};
complex add(complex,complex);
int main()
{
	 complex c1,c2,c3;
	 c1.set_data();
	 c2.set_data();
	 c3.add(c1,c2);
	 cout<<"Sum Of The Two Complex Numer Is:-\n";
	 c3.show_data();
	return 0;
}


