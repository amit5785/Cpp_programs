#include<bits/stdc++.h>
using namespace std;
/*
Equal Sum Partition Problem

Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
Examples:

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1,4,12,5}
Output: false


NOTE : it is important that it is only possible to do partitation if sum of all elemnt is even otherwise not possible

*/

bool solve(vector<int> &nums)
{    
    int sum=0;
    sum=accumulate(nums.begin(),nums.end(),sum);
    
    if(sum%2)
    {
      return false;
    }

    sum=sum/2;
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
    vector<int> nums {1,4,12,5};
    cout<<solve(nums);
    return 0;
}