#include<bits/stdc++.h>
using namespace std;
static vector<vector<char>> ans;
void per(string s,int k,int len)
{
  static vector<int> flag(len,0);
  static vector<char> res(len);
  if(k==3)
  {
    ans.push_back(res);
    return;
  }
  for(int i=0;i<len;i++)
  {
    if(flag[i]==0)
    {
      flag[i]=1;
      res[k]=s[i];
      per(s,k+1,len);
      flag[i]=0;
    }
  }
}

int main()
{
  string s="123";
  per(s,0,s.length());
  cout<<ans.size()<<endl;
  for(auto s:ans)
  {
    ostringstream out;
    for(auto ch:s)
    {
      out<<ch;
    }
    cout<<out.str()<<endl;
  }
  return 0;
}