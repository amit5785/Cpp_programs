#include<bits/stdc++.h>
using namespace std;

/*

Find minimum product among all combinations of triplets in an array
Given an integer array, find the minimum product among all combinations of triplets in the array.

For example,

Input:  { 4, -1, 3, 5, 9 }
Output: The minimum product is -45 (-1, 5, 9)
 
 
Input:  { 1, 4, 10, -2, 4 }
Output: The minimum product is -80 (10, 4, -2)
 
 
Input:  { 3, 4, 1, 2, 5 }
Output: The minimum product is 6 (3, 1, 2)

*/

int minimumProduct(vector<int> nums)
{
  sort(nums.begin(),nums.end());
  int n=nums.size();
  if(n<3)
  return -1;

  if(nums[0]>0)
  return nums[0]*nums[1]*nums[2];

  if(nums[n-1]<0)
  return nums[0]*nums[1]*nums[2];
  
  if(nums[1]>0 || nums[2]>0)
  return nums[0]*nums[n-1]*nums[n-2];

  return nums[0]*nums[1]*nums[2];
}

int main()
{
  vector<int> nums={ 3,4, 1, 2, 5 };
  cout<<minimumProduct(nums)<<endl;
  return 0;
}