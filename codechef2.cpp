#include <iostream>
using namespace std;
int min(int a,int b,int c)
{
    int l=a;
    if(l>b)
    l=b;
    else if(l>c)
    {
        l=c;
    }
    return l;
}
int main() {
	// your code goes here
	int t,a,b,c,l;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	  cin>>a>>b>>c;
	  l=min(a,b,c);
	  if(a==l)
	  cout<<"Draw\n";
	  else if(b==l)
	  cout<<"Bob\n";
	  else if(c==l)
	  cout<<"Alice\n";
	}
	return 0;
}

