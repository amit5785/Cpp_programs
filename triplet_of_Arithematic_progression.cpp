/*
Print all triplets that form an arithmetic progression
Given a sorted array of distinct positive integers, print all triplets that forms an arithmetic progression with an integral common difference.

An arithmetic progression is a sequence of numbers such that the difference between the consecutive terms is constant. For instance, sequence 5, 7, 9, 11, 13, 15, … is an arithmetic progression with a common difference of 2.

 
For example,

Input:  A[] = { 5, 8, 9, 11, 12, 15 }
 
Output:
5 8 11
9 12 15
 
 
Input:  A[] = { 1, 3, 5, 6, 8, 9, 15 }
 
Output:
1 3 5
1 5 9
3 6 9
1 8 15
3 9 15
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fun(vector<int> a)
{
  vector<vector<int>> res;
  int i,n,j,k;
  n=a.size();
  if(n<3)
  return {{}};
  for(i=1;i<n-1;i++)
  {
    j=i-1;k=i+1;
    while(true)
    {
      if(j>=0 && k<n && (a[i]-a[j])==(a[k]-a[i]))
      {
        res.push_back({a[j],a[i],a[k]});
        j--;
        k++;
      }

      if(j<0 || k>n)
      break;

      if(2*a[i]>(a[j]+a[k]))
      {
        k++;
      }
      else{
        j--;
      }
    }
  }
  return res;
}

int main()
{
  vector<int> a={ 1, 3, 5, 6, 8, 9, 15 };
  vector<vector<int>> res=fun(a);
  for(auto i: res)
  {
    for(auto j : i)
    {
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}