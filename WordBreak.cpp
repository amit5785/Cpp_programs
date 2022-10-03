/*
Question link :- 

https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Given a non-empty string s and a array of string we have to place space such that we convert the string s into a sentence containing the words of the dictionary(array of string)


e.g

s=  "godisnowherenowhere"
dict= {"god" ,"is" ,"now", "no", "where", "here"}

o/p :- 4 they are :-

god is no where no where
god is no where now here
god is now here no where
god is now here now here

*/

#include <bits/stdc++.h> 
using namespace std;

class MyTrieNode
{
private :
    vector<MyTrieNode *> data;
    bool isEnd;
public :
    
    MyTrieNode()
    {
        data=vector<MyTrieNode*> (26,NULL);
        isEnd=false;
    }
    
    void insert(string word)
    {
        MyTrieNode *root=this;
        for(auto ch : word)
        {
            if(root->data[ch-'a']==NULL)
            {
                root->data[ch-'a']=new MyTrieNode();
            }
            root=root->data[ch-'a'];
        }
        
        root->isEnd=true;
    }
    
    bool searchWord(string &word,int i,int j)
    {
        MyTrieNode *root=this;
        while(i<=j)
        {
            char ch=word[i];
            if(root->data[ch-'a']==NULL)
            {
                return false;
            }

            root=root->data[ch-'a'];
            i++;
        }
        
        return root->isEnd;
    }
};

int solve(string &s,vector<string> &dict,int ind,MyTrieNode *root)
{
    if(ind==s.length())
    {
        return 1;
    }
    
    long long int res=0;
    
    for(int i=ind;i<s.length();i++)
    {
        if(root->searchWord(s,ind,i)==true)
        {
            res = res + solve(s,dict,i+1,root);
        }
    }
    
    return res;
}


int wordBreak(string s, vector<string> dictionary)
{
    // Write your code here
    MyTrieNode *root=new MyTrieNode();
    
    
    for(auto word:dictionary)
    {
        root->insert(word);
    }
    
    return solve(s,dictionary,0,root);
}

int main()
{
    cout<<wordBreak("godisnowherenowhere",{"god" ,"is" ,"now", "no", "where", "here"});
}