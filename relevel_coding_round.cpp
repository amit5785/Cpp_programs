#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//   int n,m,k;
//   cin>>n>>m>>k;
//   vector<int> nums(n),us(100001,0);
//   for(int i=0;i<n;i++)
//   {
//     cin>>nums[i];
//   }
//   for(int i=0;i<m;i++)
//   {
//     int x;
//     cin>>x;
//     us[x]=1;
//   }

//   int i=0,j=0,count=0,res=0;
//   while(j<n)
//   {
//     if(us[nums[j]])
//     {
//       count++;
//     }

//     if(count<=k)
//     {
//       res=max(res,(j-i+1));
//     }
//     else
//     {
//       while(count>=k)
//       {
//         if(us[nums[i]])
//         {
//           count--;
//         }
//         i++;
//       }
//     }
//     j++;
//   }

//   cout<<res<<endl;
//   return 0;
// }



int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  int mod=1000000007;
  sort(nums.begin(),nums.end());
  long res=nums[0];
  for(int i=1;i<n;i++)
  {
    if(nums[i]!=nums[i-1])
    {
      res=((long)res*(nums[i]-nums[i-1])%mod+nums[i-1]%mod)%mod;
    }
    else
    {
      res=(res+1)%mod;
    }
  }
  cout<<res%mod<<endl;
  return 0;
}