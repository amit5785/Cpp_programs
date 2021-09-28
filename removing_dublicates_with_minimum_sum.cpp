//  Given an array of elements and change the array in such a way that all the elements on the array are distinct. if you are replacing a value, then the replacing value should be great than the previous value and after modification sum of the elements should be as less as possible. Example: arr[1, 2, 3, 4, 5, 5, 5] and the result should be [1, 2, 3, 4, 5, 6, 7]  example 2 [1, 2, 5, 7, 8, 8, 7] then the result should be [1, 2, 5, 7, 8, 9, 10] or 1, 2, 5, 7, 8, 10, 9]

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of the element :"<<endl;
  cin>>n;
  vector <int> num;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    num.push_back(x);
  }
  for(int i=1;i<n;i++)
  {
    if(count(num.begin(),num.end(),num[i])!=1)
    {
      while(count(num.begin(),num.end(),num[i])!=1)
      {
        num[i]+=1; 
      }
    }
  }
  sort(num.begin(),num.end());
  for(auto i:num)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}