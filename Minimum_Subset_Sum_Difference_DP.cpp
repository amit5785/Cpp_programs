/*

Problem Statem :
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> Subset1(vector<int> &nums,int sum)
{
  int n=nums.size();
  vector<int> res;
  vector<vector<bool>> dp(n+1,vector<bool>(sum+1));

  for(int i=0;i<n+1;i++)
  {
    for(int j=0;j<sum+1;j++)
    {
      if(i==0)
      {
        dp[i][j]=false;
      }
      if(j==0)
      {
        dp[i][j]=true;
      }
    }
  }

  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<sum+1;j++)
    {
      if(nums[i-1]<=j)
      {
        dp[i][j]=(dp[i-1][j-nums[i-1]]||dp[i-1][j]);
      }
      else
      {
        dp[i][j]=dp[i-1][j];
      }
    }
  }

  for(int i=0;i<=sum/2;i++)
  {
    if(dp[n][i])
    {
      res.push_back(i);
    }
  }

  return res;
}

int main()
{
  vector<int> nums={1,2,7};
  int sum=0;
  sum=accumulate(nums.begin(),nums.end(),sum);
  vector<int> flag=Subset1(nums,sum);
  int m=INT_MAX;
  for(auto x:flag)
  {
    m=min(m,abs(sum-2*x));
  }
  cout<<"Minimum subset sum diffrence is : "<<m;
  return 0;
}
