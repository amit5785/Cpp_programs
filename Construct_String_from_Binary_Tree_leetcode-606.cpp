#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    
    TreeNode()
    {
        this->val=0;
        this->left=this->right=NULL;
    }
    
    TreeNode(int val)
    {
        this->val=val;
        this->left=this->right=NULL;
    }
    
    TreeNode(int val,TreeNode *left,TreeNode *right)
    {
        this->val=val;
        this->left=left;
        this->right=right;
    }
};


string tree2str(TreeNode* root) 
{
    if(root==NULL)
    {
        return "";
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        return to_string(root->val);
    }
    
    string temp=to_string(root->val);
    
    temp+='('+tree2str(root->left);
    temp+=')';
    
    if(root->right)
    {
        temp+='('+tree2str(root->right)+')';
    }
    
    return temp;
}


TreeNode* str2tre(string &s,int &ind)
{
    if(s[ind]==')')
    {
        return NULL;
    }
    
    string temp;
    while(ind<s.length() && (s[ind]>='0' && s[ind]<='9'))
    {
        temp.push_back(s[ind]);
        ind++;
    }
    
    TreeNode *root=new TreeNode(stoi(temp));
    
    if(ind<s.length() && s[ind]=='(')
    {
        ind++;
        root->left=str2tre(s,ind);
    }
    else
    {
        return root;
    }
    
    ind++;
    if(ind<s.length() && s[ind]=='(')
    {
        ind++;
        root->right=str2tre(s,ind);
    }
    
    return root;
}

//Printing the Tree

void print(TreeNode *root)
{
    if(root==NULL)
    {
        return ;
    }
    
    cout<<root->val<<" ";
    
    print(root->left);
    print(root->right);
}

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->left->left=new TreeNode(4);
    root->left->left->left->left=new TreeNode(5);
    root->left->left->left->left->right=new TreeNode(6);
    
    
    //Step to convert the Tree into String
    string s=tree2str(root);
    cout<<s<<endl;



    //Step to convert the String into Tree
    
    int ind=0;
    TreeNode *temp=str2tre(s,ind);
    
    print(temp);
    
    return 0;
}