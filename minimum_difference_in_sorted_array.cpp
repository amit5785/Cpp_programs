// Here we will be given a key and we have the find out the minimum differnce between the elements of the array and the key provided.

// Fact 1 : difference would be minimum when key is present the array itself

// Fact 2 : when binary search for an element/key end without finding it than start points to the left and end points to the ceil index.

#include<bits/stdc++.h>
using namespace std;

int floorValueInSortedArray(vector<int> nums,int key)
{
  int start,end,res;
  start=0;
  end=nums.size()-1;
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(nums[mid]==key)
    {
      return key;
    }
    else if(nums[mid]>key)
    {
      end=mid-1;
    }
    else
    {
      res=nums[mid];
      start=mid+1;
    }
  }
  return res;
}

int ceilValueInSortedArray(vector<int> nums,int key)
{
  int start,end,res;
  start=0;
  end=nums.size()-1;
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(nums[mid]==key)
    {
      return key;
    }
    else if(nums[mid]>key)
    {
      res=nums[mid];
      end=mid-1;
    }
    else
    {
      start=mid+1;
    }
  }
  return res;
}

int main()
{
  vector<int> nums={2,3,8,10,15,18,20,28};
  int key,floor,ceil;
  key=12;
  floor=floorValueInSortedArray(nums,key);
  ceil=ceilValueInSortedArray(nums,key);
  cout<<"Key Value is : "<<key<<"  Floor value is :  "<<floor<<"  Ceil value is : "<<ceil<<endl;
  cout<<"\n"<<"Minimum difference would be : "<<min(abs(key-floor),abs(key-ceil));
  return 0;
}