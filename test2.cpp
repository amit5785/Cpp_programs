/*
#include<stdio.h>
#include<iostream>
using namespace std;
#include<fstream>
int main()
{
   ifstream fin;
   fin.open("amit.txt",ios::in);
   char ch[50];
   fin.seekg(30,ios_base::beg);
   cout<<fin.tellg()<<endl;
   fin.getline(ch,30);
   cout<<ch;
   cout<<fin.tellg()<<endl;
   return 0;
}
class A
{
	public :
		 void fun()=0;
};
class B :public A
{
	void fun()
	{
		cout<<"Amit";
	}
};
int main()
{
	A obj;
	return 0;
}
*/
// #include<bits/stdc++.h>
// using namespace std;
// int masked(string s)
//     {
//         int t=0;
//         for(auto i:s)
//         {
//             t=t|(1<<(i-'a'));
//         }
//         return t;
//     }
// int main()
// {
//   cout<<masked("gaswxyz");
//    return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     for(int i=0;i<100;i++)
//     {
//         cout<<0<<',';
//     }
//     for(int i=0;i<100;i++)
//     {
//         cout<<1<<',';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;
// long long fun(int n,vector<int> a)
// {
//     vector<long long> pref(n+1);
//         priority_queue<int,vector<int>,greater<int>> pq;
//         long long sum =0;
//         for(int i=0;i<n;i++){
//             int elem = a[i];
//             sum+=elem;
//             pq.push(elem);
//         }
//         pref[0]=sum;
//         for(int i =n;i<2*n;i++){
//             sum+=a[i];pq.push(a[i]);
//             sum-=pq.top();
//             pq.pop();
//             pref[i-n+1]=sum;
//         }
        
//         sum=0;
//         vector<long long> suff(n+2);
//         priority_queue<int> pq2;
//         for(int i =2*n;i<3*n;i++){
//             sum+=a[i];
//             pq2.push(a[i]);
//         }
//         suff[n+1]=sum;
//         for(int i =2*n-1;i>=n;i--){
//             sum+=a[i];
//             pq2.push(a[i]);
//             sum -= pq2.top();
//             pq2.pop();
//             suff[i-n+1]=sum;
//         }
//         long long ans = pref[0]-suff[1];
//         for(int i =1;i<=n;i++){
//             ans= max(ans,pref[i]-suff[i+1]);
//         }
//         return ans;
// }
// int main()
// {
//     for(int i=0;i<100000;i++)
//    {
//        cout<<i<<',';
//    }
//     return 0;
// }

// #include <bits/stdc++.h> 
// using namespace std;
// #define mod 1000000007
// int solve(int i,int j,int m,int n)
// {
//     if(i==m-1 && j==n-1)
//     {
//         return 1;
//     }
//     long down,right;
//     down=right=0;
    
//     if(i+1<m)
//     {
//         down=solve(i+1,j,m,n);
//     }
    
//     if(j+1<n)
//     {
//         right=solve(i,j+1,m,n);
//     }
    
//     return (right%mod+down%mod)%mod;
// }

// int uniquePaths(int m, int n)
// {
// 	// Write your code here.
//     return solve(0,0,m,n);
// }

// int main()
// {
//     cout<<uniquePaths(3,3);
//     return 0;
// }

// #include <bits/stdc++.h> 
// using namespace std;

// int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) 
//     {
//         int n=energy.size(),res=0,curEn=initialEnergy,curEx=initialExperience;
//         for(int i=0;i<n;i++)
//         {
//             if(curEn>energy[i] && curEx>experience[i])
//             {
//                 curEn-=energy[i];
//                 curEx+=experience[i];
//             }
//             else if(curEn>energy[i])
//             {
//                 res+=experience[i]-curEx+1;
//                 curEx=curEx+experience[i]-curEx+1;
//                 curEx+=experience[i];
//             }
//             else if(curEx>experience[i])
//             {
//                 res+=energy[i]-curEn+1;
//                 curEn+=energy[i]-curEn+1-energy[i];
//             }
//             else
//             {
//                 res+=experience[i]-curEx+1;
//                 curEx+=experience[i]-curEx+1+experience[i];
//                 res+=energy[i]-curEn+1;
//                 curEn+=energy[i]-curEn+1-energy[i];
//             }
//         }
        
//         return res;
//     }


// vector<int> findOriginalArray(vector<int>& changed) 
// {
//     int n=changed.size();
//     if((n&1))
//     {
//         return {};
//     }
    
//     unordered_map<int,int> flag;
    
//     for(auto elem:changed)
//     {
//         flag[elem]++;
//     }
    
//     vector<int> res;


//     for(auto elem: flag)
//     {
//         if(elem.second!=0)
//         {
//             if(flag.find(2*elem.first)!=flag.end() && elem.second<flag[2*elem.first])
//             {
//                 res.push_back(elem.first);
//                 flag[2*elem.first]-=elem.second;
                
//             }  
//         }
//     }
        
//     if(res.size()!=n/2)
//     {
//         return {};
//     }
    
//     return res;
// }


//  string convert(unsigned int n)
//     {
//         string temp(32,'0');
        
//         for(int i=31;i>=0;i--)
//         {
//             if((n&(1<<i)))
//             {
//                 temp[31-i]='1';
//             }
//         }
        
//         return temp;
//     }

//     int longestNiceSubarray(vector<int>& nums) 
//     {
//         vector<string> temp;
//         for(auto elem:nums)
//         {
//             temp.push_back(convert(elem));
//         }
        
        
        
//         int i=0,j=0,res=1,count=0;
        
//         int n=nums.size();
        
//         vector<int> freq(32,0);
        
//         while(j<n)
//         {
//             bool flag=true;
//             for(int p=0;p<32;p++)
//             {
//                 if(temp[j][p]=='1')
//                 {
//                     freq[p]++;
                    
//                     if(freq[p]>1)
//                     {
//                         flag=false;
//                     }
//                 }
//             }
            
//             if(flag)
//             {
//                 count++;
//             }
            
//             if(j-i+1==count)
//             {
//                 res=max(res,count);
//             }
//             else
//             {
//                 while(i<j && count!=(j-i+1))
//                 {
//                    bool z=true;
//                    for(int p=0;p<32;p++)
//                    {
//                        if(temp[i][p]=='1')
//                        {
//                            freq[p]--;
                           
//                            if(freq[p]>0)
//                            {
//                                z=false;
//                            }
//                        }
                        
//                    } 
                    
//                     if(z)
//                     {
//                         count--;
//                     }
                    
                    
//                     i++;
//                 }
//             }
            
//             j++;
//         }
        
//         return res;
//     }

// int main()
// {
//     // vector<int> exp={1,1,1,50},en={1,1,1,1};
//     // int curEx=1,curEn=1;
//     // cout<<minNumberOfHours(curEn,curEx,en,exp);
//     vector<int> nums{178830999,19325904,844110858,806734874,280746028,64,256,33554432,882197187,104359873,453049214,820924081,624788281,710612132,839991691};
//     cout<<longestNiceSubarray(nums);
//     return 0;
// }

// /*
// 1
// 1
// [1,1,1,1]
// [1,1,1,50]
// */

#include<bits/stdc++.h>
using namespace std;


vector<int> findOriginalArray(vector<int>& changed) 
    {
        map<int,int> freq;
        
        for(auto elem:changed)
        {
            freq[elem]++;
        }
        
        vector<int> res;
        
        for(auto elem:freq)
        {
            if(elem.second==0)
            {
                continue;
            }
            
            if(elem.first==0)
            {
                for(int i=0;i<elem.second/2;i++)
                {
                    res.push_back(elem.first);
                }
                freq[0]=0;
                continue;
            }
            
            if(freq.find(2*elem.first)!=freq.end())
            {
                if(freq[2*elem.first]==elem.second)
                {
                     for(int i=0;i<elem.second;i++)
                     {
                         res.push_back(elem.first);
                     }
                }
                else
                {
                    return {};
                }
            }
            else
            {
                return {};
            }
            
            freq[2*elem.first]=0;
        }
        
        return res;
    }


// int garbageCollection(vector<string>& garbage, vector<int>& travel) 
// {
//     unordered_map<char,map<int,int>> flag;
    
//     int n=garbage.size(),m=travel.size();
    
//     vector<int> time(n,0);
    
//     for(int i=1;i<n;i++)
//     {
//         time[i]+=time[i-1]+travel[i-1];
//     }
    
//     for(int i=0;i<n;i++)
//     {
//         for(auto ch:garbage[i])
//         {
//             flag[ch][i]++;
//         }
//     }
    
//     int res=0;
    
//     for(auto elem:flag)
//     {
//         int prev=0;
//         for(auto e:elem.second)
//         {
//             res+=e.second+time[e.first]-time[prev];
//             prev=e.first;
//         }
//     }
    
//     return res;
// }

int main()
{
    vector<int> nums{1,2,3,4,6,8};
    // vector<string> garbage{"G","P","GP","GG"};
    // cout<<garbageCollection(garbage,time);
    auto res=findOriginalArray(nums);

    cout<<res.size();
    return 0;
}