//This code to determine the continious subsequence of vowel of max length in a string
#include<bits/stdc++.h>
using namespace std;
bool isVowel(char);
string LCS(string);
int main()
{
  cout<<LCS("aechgxnvaeiou");
  return 0;
}

string LCS(string s)
{
  string max="";
  string com="";
  transform(s.begin(),s.end(),s.begin(),::tolower);
  for (int i=0;i<s.length();i++)
  {
    if(isVowel(s[i]))
    com+=s[i];
    else
    com="";
    if(com.length()>max.length())
    max=com;
  }
  return max!=""?max:"No subsequence";
}

bool isVowel(char ch)
{
  if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u')
  return true;
  return false;
}