// In this problem we are given an array either sorted or unsorted where each element represent a book wiht page books[i] and a integer k,which reprent that we have to assign the pages to k student 

// if we are assigning a book[i] to a student than its whole pages will be assign to that student only we have to divide the books array into continious subarray.

// we have to minimize the max page of any combination

#include<bits/stdc++.h>
using namespace std;

bool isvallid(vector<int> &books,int max,int k)
{
  int sum=0,sub_groups=1;
  for(auto x : books)
  {
    sum+=x;
    if(sum>max)
    {
      sum=x;
      sub_groups++;
    }
  }
  return sub_groups>k?false:true;
}

int main()
{
  vector<int> books={20,10,30,40};
  int start,end,k,total_sum=0,maximum=INT_MIN,n,res=-1;
  n=books.size();
  k=2;
  if(k>n)
  {
    goto result;
  }
  for(int i=0;i<n;i++)
  {
    maximum= std::max(maximum,books[i]);
    total_sum+=books[i];
  }
  start=maximum;
  end=total_sum;
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(isvallid(books,mid,k))
    {
      res=mid;
      end=mid-1;
    }
    else 
    {
      start=mid+1;
    }
  }
  result:
  res!=-1?cout<<"So minimum number of pages a student need to study is :"<<res:cout<<"No possible combination";
  return 0;
}