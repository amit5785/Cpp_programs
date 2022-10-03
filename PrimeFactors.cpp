#include<bits/stdc++.h>
using namespace std;

vector<int> allPrimeFactors(int n)
{
  vector<int> res;
  for(int i=2;i*i<=n;i++)
  {
     while(n%i==0)
     {
       res.push_back(i);
       n=n/i;
     }
  }

  if(n>1)
  {
    res.push_back(n);
  }

  return res;
}

int main()
{
  int n=12;
  vector<int> factors=allPrimeFactors(n);

  vector<int> first26prime {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

  char ch='A';
  unordered_map<int,char> flag;


  for(auto elem:first26prime)
  {
    flag[elem]=ch;
    ch++;
  }

  string res="";

  for(auto elem:factors)
  {
    if(elem%26)
    {
      res.push_back(flag[elem%26]);
    }
    else
    {
      res.push_back('Z');
    }
  }

  cout<<res<<endl;

  return 0;
}