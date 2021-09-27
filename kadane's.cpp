#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int max_so_far=0;
	int max_ends_here=0;
	int first=-1,last=first;
	for(int i=0;i<8;i++)
	{
		max_ends_here+=A[i];
		if(max_so_far<max_ends_here && max_ends_here%2==0)
		{
			max_so_far=max_ends_here;
			if(first==-1)
			first=i;
			else
			last=i;
		}
		if(max_ends_here<0)
		max_ends_here=0;
	}
	printf("%d \n",max_so_far);
	cout<<first<<" "<<last;
	for(int l=first;l<=last;l++)
	cout<<A[l]<<" ";
	return 0;
}
