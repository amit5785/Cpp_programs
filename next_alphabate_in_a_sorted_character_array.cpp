#include<bits/stdc++.h>
using namespace std;

char nextAlphabate(vector<char> s,char key)
{
  int start=0,end=s.size()-1;
  char res;
  while(start<=end)
  {
    int mid;
    mid=start + (end-start)/2;
    if(s[mid]>key)
    {
      res=s[mid];
      end=mid-1;
    }
    else{
      start=mid+1;
    }
  }
  return res;
}

int main()
{
  char key='h';
  vector<char> s{'a','c','f','h','i','l','o'};
  cout<<nextAlphabate(s,key);
  return 0;
}