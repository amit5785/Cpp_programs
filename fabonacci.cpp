#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mul(vector<vector<int>> &flag,vector<vector<int>> &temp)
{
    int n1,n2,m1,m2;
    n1=flag.size();
    n2=temp.size();
    m1=flag[0].size();
    m2=temp[0].size();
    vector<vector<int>> res(n1,vector<int>(m2,0));
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m2;j++)
        {
            for(int p=0;p<m1;p++)
            {
                res[i][j]+=flag[i][p]*temp[p][j];
            }
        }
    }
    
    return res;
}
    
vector<vector<int>> pow(vector<vector<int>> &flag,int n)
{
    if(n==0)
    {
        
        return {{1,0},{0,1}};
    }
    auto temp=pow(flag,n/2);
    temp=mul(temp,temp);
    if((n&1)!=0)
    {
        temp=mul(flag,temp);
    }
    
    return temp;
}

int fib(int n) 
{
    vector<vector<int>> flag(2,vector<int>(2,1));
    flag[1][1]=0;
    auto res=pow(flag,n);
    return res[0][1];
}

int main()
{
    int n=20;
    cout<<fib(n);
    return 0;


//Ayush question

// int res=0;
// int num=fib(n);
// cout<<num<<endl;
// while(num)
// {
//     res+=num%10;
//     num=num/10;
// }
// cout<<res<<endl;
// return res;
}