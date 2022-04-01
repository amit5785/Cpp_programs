#include<iostream>
#include<vector>
using namespace std;

int main()
{
  vector<int> nums {15, 18, 2, 3, 6, 12};
  int start,end,n;
  n=nums.size();
  start=0;
  end=n-1;
  while(start<=end)
  {
    int mid,next,prev;
    mid=start+(end-start)/2;
    next=(mid+1)%n;
    prev=(mid+n-1)%n;
    if(nums[mid]<=nums[next] &&  nums[mid]<=nums[prev])
    { 
      cout<<"Index of minimum element is : " <<mid<<endl<<"Minimum element is : "<<nums[mid]<<endl;
      if(mid)
      cout<<"Number of Left ratation in the array is : "<<n-mid<<endl;
      else {
        cout<<"Number of Left ratation in the array is : "<<0<<endl;
      }
      return 0;
    }
    else if(nums[mid]<=nums[end])
    {
      end=mid-1;
    }
    else if(nums[start]<=nums[mid])
    {
      start=mid+1;
    }
  }
  cout<<"No rotation"<<endl;
  return 0;
}