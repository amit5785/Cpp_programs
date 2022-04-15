//This is simple program to calculate the total number of anagram of string "s2" in a given string "s1" using sliding window concept


#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1="aabaabaaba",s2="aaba";
  int k=s2.length(),i,j,count,res=0,n=s1.length();
  map<char,int> flag;
  for(auto x:s2)
  {
    flag[x]++;
  }
  i=j=0;
  count=flag.size();
  while(j<n)
  {
    if(flag.find(s1[j])!=flag.end())
    {
      flag[s1[j]]--;
      if(flag[s1[j]]==0)
      {
        count--;
      }
    }
    if(j-i+1==k)
    {
      if(count==0)
      {
        res++;
      }
      if(flag.find(s1[i])!=flag.end())
      {
        if(flag[s1[i]]==0)
        {
          count++;
        }
        flag[s1[i]]++;
      }
      i++;
    }
    j++;
  }
  cout<<"Total Number of Anagram in the given string s1 is :"<<res;
  return 0;
}