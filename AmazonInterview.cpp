/*
This question was asked in my interview in Amazon very sad couldn't answer 😢😢😢😢😢😢😢😢

Minimize Cash Flow among a given set of friends who have borrowed money from each other

Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the friends is minimized. 

*/

#include <bits/stdc++.h>
using namespace std;
#define n 3

void printTransection(vector<int> &peopleNetBalance)
{
    int payer=0,receiver=0;
    
    for(int i=0;i<n;i++)
    {
        if(peopleNetBalance[payer]<peopleNetBalance[i])
        {
            payer=i;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(peopleNetBalance[receiver]>peopleNetBalance[i])
        {
            receiver=i;
        }
    }
    
    if(peopleNetBalance[payer]==0 && peopleNetBalance[receiver]==0)
    {
        return ;
    }
    
    int netTransectionHere=min(peopleNetBalance[payer],-peopleNetBalance[receiver]);
    
    peopleNetBalance[payer]-=netTransectionHere;
    peopleNetBalance[receiver]+=netTransectionHere;
    
    cout<<"person "<<payer<<" will pay "<<netTransectionHere<<"  to person "<<receiver<<endl;
    
    printTransection(peopleNetBalance);
}

int main()
{
    vector<vector<int>> trans(n,vector<int>(n,0));
    
    trans[0][1]=1000;//this show that p0 will pay p1 1000
    trans[1][2]=5000;//this show that p1 will pay p2 5000
    trans[0][2]=2000;//this show that p0 will pay p2 2000
    
    vector<int> peopleNetBalance(n,0);
    
    for(int people=0;people<n;people++)
    {
        for(int i=0;i<n;i++)
        {
            peopleNetBalance[people]+=(trans[people][i]-trans[i][people]);
        }
    }
    
    // for(auto elem:peopleNetBalance)
    // {
    //     cout<<elem<<"  ";
    // }
    // cout<<endl;
    
    printTransection(peopleNetBalance);
    
    return 0;
}