#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums)
{
    int n=nums.size();
    vector<int> sum(n,0);
    sum[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=nums[i]+sum[i-1];
    }
    
    int res=-1;
    int mini=INT_MAX;
    
    for(int i=0;i<n-1;i++)
    {
        int left=sum[i]/(i+1);
        int right=(sum[n-1]-sum[i])/(n-i-1);
        
        int diff=abs(left-right);
        
        if(diff<=mini)
        {
            mini=diff;
            res=i;
        }
    }
    
    return res+1;
}

int main()
{
    vector<int> nums={1,3,2,3};
    
    cout<<solve(nums);
    return 0;
}