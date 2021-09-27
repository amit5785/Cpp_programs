#include<stdio.h>
#include <iostream>
using namespace std;

int main() 
{
	int a,b,c,d,n,t;
    double amount;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
      scanf("%d%d%d%d",&a,&b,&c,&d);
      n=a/b;
      amount=(b*(c*n+ ((n*(n-1))/2.0)*d) + (a%b)*(c+n*d));
      printf("%.0f\n",amount);
    }
	return 0;
}

