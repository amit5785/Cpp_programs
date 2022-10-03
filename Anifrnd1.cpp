#include<bits/stdc++.h>
using namespace std;



Result DuplicateArray(int input1,int input2[])
{
  map<int,int> flag;
  for(int i=0;i<input1;i++)
  {
    flag[input2[i]]++;
  }

  Result res;
  int i=0;
  for(auto temp:flag)
  {
    if(temp.second!=1)
    {
      res.output1[i]=temp.first;
      i++;
    }
    
  }
  if(i==0)
  {
    res.output1[0]=-1;
  }
  return res;
}

int main()
{
  vector<vector<int>> points{{5,5},{5,3}};

  cout<<DuplicateArray();
}