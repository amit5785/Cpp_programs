#include<bits/stdc++.h>
using namespace std;
int digit(int);
string result(int,int);
int n;
    string intToRoman(int num) 
    {
        n=digit(num);
        return result(num,n);
    }
    int digit(int num)
    {
        int count=0;
        while(num!=0)
        {
            num=num/10;
            count++;
        }
        return count;
    }
    string result(int num,int n)
    {
        int t;
        string s="";
        if(num<11)
        {
           if(num<4)
           {
               for(int i=0;i<num;i++)
               {
                   s+="I";
               }
           }
            else if(num==4)
                s+="IV";
            else if(num<9)
            {
                s+="V";
                for(int i=0;i<num-5;i++)
                    s+="I";
            }
            else if(num==9)
                s+="IX";
            else if(num==10)
                s+="X";
            return s;
        }
        else
        {
          t=num/pow(10,n-1);
          if(n==2)
          {
            if(t<4)
           {
              for(int i=0;i<t;i++)
                  s+="X";
           }  
            else if(t<5)
            {
                s+="XL";
            }
              else if(t<9)
              {
                  s+="L";
                  for(int i=0;i<t-5;i++)
                  {
                      s+="X";
                  }
              }
              else
              {
                  s+="XC";
              }
          }
          else if(n==3)
          {
            if(t<4)
           {
              for(int i=0;i<t;i++)
                  s+="C";
           }  
            else if(t<5)
            {
                s+="CD";
            }
              else if(t<9)
              {
                  s+="D";
                  for(int i=0;i<t-5;i++)
                  {
                      s+="C";
                  }
              }
              else
              {
                  s+="CM";
              }
          }
          else if(n==4)
          {
            if(t<4)
           {
              for(int i=0;i<t;i++)
                  s+="M";
           }  
            
          }
          s+=result(num%(int)pow(10,n-1),n-1);
          return s;
        }
    }
int main()
{
  string s="CMXL";
  cout<<intToRoman(3999);
  return 0;
}