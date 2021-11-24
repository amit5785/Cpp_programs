/*
Given a sorted array of distinct positive integers, print all triplets that forms a geometric progression with an integral common ratio.

Input:  A[] = { 1, 2, 6, 10, 18, 54 }
 
Output:
2 6 18
6 18 54
 
 
Input:  A[] = { 2, 8, 10, 15, 16, 30, 32, 64 }
 
Output:
2 8 32
8 16 32
16 32 64

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fun(vector<int> a)
{
  vector<vector<int>> res;
  int i,j,k,n;
  n=a.size();
  if(n<3)
  return {{}};
  for(i=1;i<n-1;i++)
  {
    j=i-1;k=i+1;
    while(1)
    {
      if(j>=0 && k<n && (a[i] % a[j] == 0) && (a[k] % a[i] == 0) && (a[i] / a[j] == a[k] / a[i])){
        res.push_back({a[j],a[i],a[k]});
        k++;
        j--;
      }
      if(j<0 || k>n)
      break;

      if(a[i]%a[j]==0 && a[k]%a[i]==0)
      {
        if(a[i]/a[j] <a[k]/a[i])
        {
          j--;
        }
        else{
          k++;
        }
      }
      else if(a[i]%a[j]==0)
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
  vector<int> a={ 1, 2, 6, 18, 36, 54 };
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