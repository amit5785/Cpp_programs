#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
         int n=nums.size(),res=0;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    temp=max(temp,dp[j]);
                }
            }
            dp[i]=temp+1;
            res=max(res,dp[i]);
        }
        return res;
}

int main()
{
  vector<int> nums {41,18467,6334,26500,19169};
  cout<<solve(nums);
}