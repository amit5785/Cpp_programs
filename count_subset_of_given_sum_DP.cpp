#include<bits/stdc++.h>
using namespace std;
/*

Count of subsets sum with a Given sum

Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
Example:

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}
*/
int solve(vector<int> &nums,int sum)
{    
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++)
    {
      for(int j=0;j<sum+1;j++)
      {
        if(i==0)
        {
          dp[i][j]=0;
        }
        if(j==0)
        {
          dp[i][j]=1;
        }
      }
    }
    for(int i=1;i<n+1;i++)
    {
      for(int j=1;j<sum+1;j++)
      {
        if(nums[i-1]<=j)
        {
          dp[i][j]=(dp[i-1][j-nums[i-1]] + dp[i-1][j]);
        }
        else
        {
          dp[i][j]=dp[i-1][j];
        }
      }
    }
  return dp[n][sum];
}


int main()
{
    vector<int> nums {1, 2, 3, 3};
    cout<<solve(nums,6);
    return 0;
}