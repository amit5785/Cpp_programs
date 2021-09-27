#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) 
    {
        char prev='t';
        int res=0;
        for(auto i=s.begin();i!=s.end();i++)
        {
            if(*i=='I')
                res+=1;
            else if(*i=='V')
            {
                if(prev=='I')
                {
                    res+=3;
                }
                else
                    res+=5;
            }
            else if(*i=='X')
            {
                if(prev=='I')
                {
                    res+=8;
                }
                else
                    res+=10;
            }
            else if(*i=='L')
            {
                if(prev=='X')
                {
                    res+=30;
                }
                else
                    res+=50;
            }
            else if(*i=='C')
              {
                if(prev=='X')
                {
                    res+=80;
                }
                else
                    res+=100;
            }
            else if(*i=='D')
               {
                if(prev=='C')
                {
                    res+=300;
                }
                else
                    res+=500;
            }
            else
            {
                if(prev=='C')
                {
                    res+=800;
                }
                else
                {
                    res+=1000;
                }
            }
            
            prev=*i;
        }
        return res;
    }
int main()
{
  string s="C";
  cout<<romanToInt(s);
  return 0;
}