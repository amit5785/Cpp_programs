#include<bits/stdc++.h>
using namespace std;

void solve(vector<float> &nums,int n)
{
  for(int i=1;i<n-1;i++)
  {
    if(nums[i]>=nums[i+1])
    {
      int x=nums[i];
      while(x>nums[i-1] && x<nums[i+1])
      {
        x=(x+nums[i+1])/2;
      }
      if(!(x>nums[i-1] && x<nums[i+1]))
      {
        cout<<"No";
        return ;
      }
      nums[i]=x;
    }
  }
  cout<<"Yes";
}

int main()
{
  int n;
  cin>>n;
  vector<float> nums(n);
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  if(n==1)
  {
    cout<<"Yes";
    return 0;
  }
  if(n==2)
  {
    if(nums[0]<nums[1])
    {
      cout<<"Yes";
      return 0;
    }
    else
    {
      int x=nums[0],y=nums[1];
      while(x>(x+y)/2)
      {
        x=(x+y)/2;
      }
      if(y>x)
      {
        cout<<"Yes";
        return 0;
      }
      cout<<"No"<<endl;
    }

    return 0;
  }
  solve(nums,n);
  return 0;
}

/*

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin>>input;
    string output;
    int n=input.length();
    output.push_back('/');
    int i=0;
    while(i<n)
    {
        if(input[i]=='/')
        {
            output.push_back(input[i]);
            while(i<n && input[i]=='/')
            {
                i++;
            }
            continue;
        }
        else if(input[i]=='.' && i>1 && output.back()=='.')
        {
            int count=0;
            while(count<2)
            {
                if(output.back()=='/')
                {
                    count++;
                }
                output.pop_back();
            }
            i++;
            continue;
        }
        output.push_back(input[i]);
        i++;
    }
    if(output.back()=='/')
    {
        output.pop_back();
    }
    cout<<output<<endl;
    return 0;
}

*/