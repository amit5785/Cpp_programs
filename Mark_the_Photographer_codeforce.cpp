#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    vector<int> nums(2*n);
    for(int i=0;i<2*n;i++)
    {
      cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    int i=0,j=n;
    while(i<n)
    {
      if(nums[j]-nums[i]<x)
      {
        break;
      }
      i++;
      j++;
    }
    cout<<(i==n?"YES":"NO")<<endl;
  }
}