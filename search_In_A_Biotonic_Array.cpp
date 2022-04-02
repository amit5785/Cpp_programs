// This problem is implementation of two other concepts 

// 1. Finding peak in a unsorted Array and than splitting the array into two sorted array.

// 2.
// the array from i=0 to i=peak_value_index ,sub_array is sorted in increasing order but from i=peak_value_index+1 to i= n-1 array is sorted in decensing order 

// 3. in unsorted array there might be any number of peak value i.e atleast one but in biotonic array it is must that there will be only one peak value and that point will be the spliting point in the given array

#include<bits/stdc++.h>
using namespace std;


int findThePeakValue(vector<int> &nums)
{
  int start,end,n;
  n=nums.size();
  start=0;
  end=n-1;
  while(start<=end)
  {
    int mid=start+ (end-start)/2;
    if(mid>0 && mid <n-1)
    {
      if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
      {
        return mid;
      }
      else if(nums[mid]>nums[mid-1])
      {
        start=mid+1;
      }
      else if(nums[mid]>nums[mid+1])
      {
        end=mid-1;
      }
    }
    else if(mid==0)
    {
      if(nums[mid]>nums[mid+1])
      {
        return mid;
      }
      else 
      {
        return mid+1;
      }
    }
    else if(mid==n-1)
    {
      if(nums[mid]>nums[mid-1])
      {
        return mid;
      }
      else 
      {
        return mid-1;
      }
    }
  }
  return -1;
}

bool bsOnAscendingArray(vector<int> &nums,int start,int end,int key,int &res)
{
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(nums[mid]==key)
    {
      res=mid;
      return true;
    }
    else if(nums[mid]>key)
    {
      end=mid-1;
    }
    else 
    {
      start=mid+1;
    }
  }
  return false;
}

bool bsOnDecsendingArray(vector<int> &nums,int start,int end,int key,int &res)
{
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(nums[mid]==key)
    {
      res=mid;
      return true;
    }
    else if(nums[mid]>key)
    {
      start=mid+1;
    }
    else 
    {
      end=mid-1;
    }
  }
  return false;
}

int main()
{
  vector<int> nums={12,6,5,4,3,2,1};
  int key,peak_value_index,n,res=-1;
  key=8;
  n=nums.size();
  peak_value_index=findThePeakValue(nums);
  cout<<"Peak value is found at index value : "<<peak_value_index<<"   & Peak value is : "<<nums[peak_value_index]<<endl;
  res=(bsOnAscendingArray(nums,0,peak_value_index,key,res)|| bsOnDecsendingArray(nums,peak_value_index+1,n-1,key,res))?res:-1;
  res!=-1?cout<<"Key is found at index : "<<res:cout<<"Key is not found";
  return 0;
}