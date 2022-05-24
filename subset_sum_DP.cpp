#include<bits/stdc++.h>
using namespace std;

/*
Problem statement : we are given an array of integer and we have to check whether we can form a set 
such that sum of the elements of the set is equal to the given sum

Input :
we are given an array and sum

Output :
Return true if there exits a set otherwise return false

Approch that i feel first : 

bool solve(vector<int> &nums,int sum,int target,int i)
{
    int n=nums.size();
    if(i==n)
    {
        return sum==target;
    }
    if(sum==target)
    {
        return true;
    }
    if(sum>target)
    {
        return false;
    }
    return solve(nums,sum+nums[i],target,i+1)|| solve(nums,sum,target,i+1);
}

int main()
{
    vector<int> nums {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<solve(nums,0,1000,0);
    return 0;
}

but this will work efficiently only when the length of the array is less than 30 otherwise it will take a huge time that is why we think of concept of DP
*/
bool solve(vector<int> &nums,int sum)
{
    int n=nums.size();
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
          dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]);
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
    vector<int> nums {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<solve(nums,10000 );
    return 0;
}


