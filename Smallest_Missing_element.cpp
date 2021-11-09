//Find the smallest missing positive number from an unsorted array

#include<bits/stdc++.h>
using namespace std;

int missing_element(vector <int> &nums)
{
  int n=nums.size();
  int i=0;
  sort(nums.begin(),nums.end());
  for(i=0;i<n;i++)
  {
    if(i>0 && nums[i]!=nums[i-1]+1 && nums[i-1]>0)
    return nums[i-1]+1;
  }
  return nums[i-1]+1;
}

int main()
{
  vector<int> nums ={1, 2, 3, 4};
  cout<<missing_element(nums);
  return 0;
}

//Time complexity of this algorithm is n(1+logn)