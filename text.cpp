#include<iostream>
using namespace std;
#include<string>
#include<stack>
class Solution {
public:
    int calculate(string s) {
        stack <char> cont;
        int i=0;
        string postfix="";
  while(s[i]!='\0')
  {
    if(isoperand(s[i]))
    postfix+=s[i++];
    else
    {
      if(!cont.empty())
      {
        if(pre(s[i],0)>pre(cont.top(),1))
        {
          cont.push(s[i++]);
        }
        else
        {
        if(s[i]==')')
        {
          postfix=postfix+cont.pop();
          i++;
          cont.pop();
        }
        else
        {
        	postfix=postfix+cont.pop();
		}
        }
      }
      else
      {
        cont.push(s[i++]);
      }
    }
  }
  while(!cont.empty())
  {
    postfix=postfix+pop(&s);
  }
 int res=evaluation(postfix);
 return res;
}

int evaluation(string res)
{
  stack <char> cont;
  int i=0;
	while(res[i]!='\0')
	{
		if(isoperand(res[i]))
		{
			cont.push(res[i++]-'0');
		}
		else
		{
			int a=cont.pop();
			int b=cont.pop();
			int r;
			switch(res[i])
			{
				case '+' :
					r=a+b;
					break;
				case '-' :
					r=b-a;
					break;
			}
			cont.push(r);
			i++;
		}
	}
	return cont.pop();
}
    
    
    
int isoperand(char ch)
{
  if(ch=='+' || ch=='-' || ch=='(' || ch==')')
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
    
int pre(char ch,int stackIn)//stackIn==1 mean operator is inside stack
{
  if(stackIn==0)
  {
    if(ch=='+' || ch== '-')
     return 1;
    else if(ch=='(')
    return 7;
    else if(ch==')')
    return 0;
  }
  else
  {
    if(ch=='+' || ch== '-')
     return 2;
    else if(ch=='(')
    return 0;
    else if(ch==')')
    return 0;
  }
}
};

int main()
{
    Solution s;
    cout<<s.calculate("6+5+3-4");
    return 0;
}
