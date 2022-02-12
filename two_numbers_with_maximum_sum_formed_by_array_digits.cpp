#include<bits/stdc++.h>
using namespace std;

/*
Find two numbers with maximum sum formed by array digits

Given an integer array between 0 and 9, find two numbers with maximum sum formed using all the array digits. The difference in the number of digits of the two numbers should be ± 1.

For example,

Input:  { 4, 6, 2, 7, 9, 8 }
Output: The two numbers with maximum sum are 974 and 862
 
 
Input:  { 9, 2, 5, 6, 0, 4 }
Output: The two numbers with maximum sum are 952 and 640
*/

bool fun(int a,int b)
{
  return a>b;
}

vector<int> maximumSum(vector<int> &nums)
{
  sort(nums.begin(),nums.end(),fun);
  vector<int> res(2);
  int res1,res2,i,j,pow;
  res1=res2=0;
  i=0;
  j=1;
  while(j<nums.size())
  {
    res1=res1*10+nums[i];
    res2=res2*10+nums[j];
    i+=2;
    j+=2;
  }
  if(nums.size()%2!=0)
  {
    res1=res1*10+nums[i];
  }
  res[0]=res1;
  res[1]=res2;
  return res;
}

int main()
{
  vector<int> input{ 4, 6, 2, 7, 9, 8 ,1};
  vector<int> res=maximumSum(input);
  cout<<res[0]<< "  "<<res[1]<<endl;
  return 0;
}