#include<iostream>
#include<vector>
using namespace std;
int main()
{
  vector<int> arr={30,29,28,7,4,3,2,1};
  int n=arr.size();
  int start,end,key=12;
  start=0;
  end=n-1;
  while(start<=end)
  {
    int mid=start + (end-start)/2;
    if(arr[mid]==key)
    {
      cout<<mid<<endl;
      return 0;
    }
    else if(arr[mid]>key)
    {
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  cout<<-1<<endl;
  return 0;
}