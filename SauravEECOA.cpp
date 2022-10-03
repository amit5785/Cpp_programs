#include <bits/stdc++.h>
using namespace std;

int buyShares(int n,vector<int> wt,vector<int> val,int w)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    for(int i=1;i<n+1;i++)
    {
        
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];
}

int main()
{
    // int n;
    // cin>>n;
    // vector<int> wt(n),val(n);
    // for(int i=0;i<n;i++)
    // {
    //     cin>>wt[i]>>val[i];
    // }
    
    // int w;
    
    // cin>>w;
    
    cout<<buyShares(5,{70,20,10,50,30},{50000,2000,45000,100000,10000},80);

    return 0;
}