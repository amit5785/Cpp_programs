//Truncate an integer array such that `2×min` becomes more than `max`

#include<bits/stdc++.h>
using namespace std;

int truncate(vector <int> &num)
{
  sort(num.begin(),num.end());
  int n=num.size();
  int start,rem,end,t,temp_rem,flag;
  start=0;
  rem=n;
  end=n-1;
  for(int i=0;i<n;i++)
  {
    flag=0;
    t=n-1;
    while(t>i)
    {
      if(2*num[i]>num[t])
      {
        flag=1;
        break;
      }
      if(2*num[i]<=num[t])
      {
        t--;
      }
    }
    if(flag==1)
    {
      temp_rem=n+i-t-1;
      if(temp_rem<rem)
      {
        start=i;
        end=t;
        rem=temp_rem;
      }
    }
  }
  vector<int> temp=num;
  num.clear();
  int j=start;
  for(int i=0;i<end-start+1;i++)
  {
    num[i]=temp[j++];
  }
  cout<<num.size();
  for(auto i:num)
  cout<<i<<" ";
  cout<<endl;
  return rem;
}

int main()
{
  vector<int> nums={4, 7, 5, 6};
  cout<<truncate(nums)<<endl;
  for(auto i:nums)
  cout<<i<<" ";
  cout<<endl;
  return 0;
}