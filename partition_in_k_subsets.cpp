#include <bits/stdc++.h>
using namespace std;

/*
1. You are given two integers n and k, where n represents number of elements and k  represents number of subsets.

2. You have to partition n elements in k subsets and print all such configurations.

*/


void solve(vector<int> &nums,int ind,int k,int &count,vector<vector<int>> &partitions,int vis)
{
    if(ind>=nums.size())
    {
        if(vis!=k)
        {
            return ;
        }
        count++;
        cout<<count<<" [ ";
        for(auto partition:partitions)
        {
            cout<<"[ ";
            for(auto x:partition)
            {
                cout<<x<<" ";
            }
            cout<<"] ";
        }
        cout<<"]"<<endl;
        return;
    }
    
    for(int i=0;i<k;i++)
    {
        if(partitions[i].size())
        {
            partitions[i].push_back(nums[ind]);
            solve(nums,ind+1,k,count,partitions,vis);
            partitions[i].pop_back();
        }
        else
        {
            partitions[i].push_back(nums[ind]);
            solve(nums,ind+1,k,count,partitions,vis+1);
            partitions[i].pop_back();
            break;
        }
    }
    
    return ;
}

int main()
{
    vector<int> nums={1,2,3,4,5,6};
    int n=18,k=2;
    if(k>n)
    {
        cout<<"Not Possible :"<<endl;
        return 0;
    }
    
    if(k==1|| k==0)
    {
        for(auto num:nums)
        {
            cout<<num<<"  ";
        }
        cout<<endl;
        return 1;
    }
    vector<vector<int>> partitions(k);
    int count=0,vis=0;
    solve(nums,0,k,count,partitions,vis);
    return 0;
}