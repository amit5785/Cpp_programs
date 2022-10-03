#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &points)
{
  vector<int> row(8,0),col(8,0);
  for(auto point:points)
  {
    row[point[0]-1]=1;
    col[point[1]-1]=1;
  }

  int res=0;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(row[i] || col[j])
      {
        res++;
      }
    }
  }

  return res;
}

int main()
{
  vector<vector<int>> points{{5,5},{5,3}};

  cout<<solve(points);
}