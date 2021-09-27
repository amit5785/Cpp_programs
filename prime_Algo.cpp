#include<bits/stdc++.h>
using namespace std;
int main()
{
	int count=0,n=10;
	for(int i=2;i<n;i++)
	{
		if(count>0)
		break;
		else
		if(n%i==0)
		count++;
	}
	count?cout<<"No":cout<<"Yes";
}
