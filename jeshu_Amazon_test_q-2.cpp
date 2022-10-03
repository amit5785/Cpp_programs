#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<int> &nums,int mid,int key)
{
  for(auto num:nums)
  {
    mid=mid-num;

    if(mid<=0)
    {
      if(mid<=0 && key)
      {
        mid=mid+min(num,key);
        key=0;
        if(mid<=0)
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  vector<int> nums={1,2,6,7};

  int start=INT_MIN;
  int end=0;

  for(auto num:nums)
  {
    start=max(start,num);
    end+=num;
  }
  int res=-1;
  while(start<=end)
  {
    int mid=start+(end-start)/2;

    if(isvalid(nums,mid,5))
    {
      res=mid;
      end=mid-1;
    }
    else
    {
      start=mid+1;
    }
  }

  cout<<res;
  return 0;
}