// Given a string you need to print the size of the longest possible substring that has exactly k unique characters.

// Example:
// Input:
// 2
// aabacbebebe
// 3
// aaaa
// 1
// Output:
// 7
// 4

#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int i,j,n,k,count,res;
  cin>>k;
  map<char,int> flag;
  i=j=count=res=0;
  n=s.length();
  while(j<n)
  {
    flag[s[j]]++;
    count=flag.size();
    if(count==k)
    {
      res=max(res,(j-i+1));
    }
    if(count>k)
    {
      while(i<j && count>k)
      {
        if(flag[s[i]]==1)
        {
          count--;
          flag.erase(s[i]);
          i++;
          continue;
        }
        flag[s[i]]--;
        i++;
      }
    }
    j++;
  }
  cout<<"Maximum length of substring having exactly k unique charecter is : "<<res<<endl;
  return 0;
}

