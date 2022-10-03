#include<bits/stdc++.h>
using namespace std;

// class TreeNode
// {
//   public:
//   int val;
//   TreeNode *left,*right;
//   TreeNode()
//   {
//     this->val=0;
//     this->left=this->right=NULL;
//   }

//   TreeNode(int val)
//   {
//     this->val=val;
//     this->left=this->right=NULL;
//   }

//   TreeNode(int val,TreeNode *left,TreeNode *right)
//   {
//     this->val=0;
//     this->left=left;
//     this->right=right;
//   }
// };


// class Solution 
// {
// private:
//     unordered_map<long long int,int> temp;
    
//     void solve(TreeNode *root,long long int sum,int tar,int &res)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
        
//         sum+=root->val;
        
//         if(sum==tar)
//         {
//             res++;
//         }
        
//         if(temp.find(sum-tar)!=temp.end())
//         {
//             res+=temp[sum-tar];
//         }
        
//         temp[sum]++;
        
//         solve(root->left,sum,tar,res);
//         solve(root->right,sum,tar,res);
        
//         temp[sum]--;
//     }
// public:
//     int pathSum(TreeNode* root, int targetSum) 
//     {
//         int res=0;
//         solve(root,0,targetSum,res);
//         return res;
//     }
// };


vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int,int>> temp;

        for(auto building:buildings)
        {
            temp.push_back({building[0],-building[2]});
            temp.push_back({building[1],building[2]});
        }

        sort(temp.begin(),temp.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.first<b.first?true:(a.first==b.first?a.second<=b.second:false);
        });

        multiset<int,greater<int>> q;
        q.insert(0);

        int cur_height=0;

        vector<vector<int>> res;

        for(auto elem:temp)
        {
            if(elem.second>0)
            {
                q.erase(q.find(elem.second));
            }
            else
            {
                q.insert(abs(elem.second));
            }

            if(*q.begin()!=cur_height)
            {
                cur_height=*q.begin();
                res.push_back({elem.first,cur_height});
            }
        }


        return res;
}


// int main()
// {
//   // //{1000000000,1000000000,null,294967296,null,1000000000,null,1000000000,null,1000000000}
//   // //0

//   // TreeNode *root=new TreeNode(1000000000);
//   // root->left=new TreeNode(1000000000);
//   // root->left->left=new TreeNode(294967296);
//   // root->left->left->left=new TreeNode(1000000000);
//   // root->left->left->left->left=new TreeNode(1000000000);
//   // root->left->left->left->left->left=new TreeNode(1000000000);


//   // Solution obj;

//   // cout<<obj.pathSum(root,0)<<endl;

//   vector<vector<int>> building {{0,2,3},{2,5,3}};  
//   auto res=getSkyline(building);
//   return 0;
// }





// class Example
// {
//     public:
//     static int count;
//     Example()
//     {
//         count+=1;
//         cout<<"Inside Example Constructor "<<count<<endl;
//     }

//     ~Example()
//     {
//         count--;
//         cout<<"Inside Example Destructor "<<count<<endl;
//     }
// };

// int Example :: count=0;

// int main()
// {
//     Example obj;
//     Example temp[5];
// }





// void solve(int num)
// {
//     int n=2*num-1;

//     for(int i=0;i<n/2+1;i++)
//     {
//         int m=num;

//         for(int j=0;j<i;j++)
//         {
//             cout<<m<<" ";
//             m--;
//         }

//         for(int j=0;j<n-2*i;j++)
//         {
//             cout<<num-i<<" ";
//         }

//         // m=num-i+1;
//         m++;
        

//         for(int j=0;j<i;j++)
//         {
//             cout<<m<<" ";
//             m++;
//         }

//         cout<<endl;
//     }

//     for(int i=n/2-1;i>=0;i--)
//     {
//         int m=num;

//         for(int j=0;j<i;j++)
//         {
//             cout<<m<<" ";
//             m--;
//         }

//         for(int j=0;j<n-2*i;j++)
//         {
//             cout<<num-i<<" ";
//         }

//         // m=num-i+1;m++;

//         for(int j=0;j<i;j++)
//         {
//             cout<<m<<" ";
//             m++;
//         }

//         cout<<endl;
//     }
// }


vector<vector<int>> solve(int num)
{
    int n=2*num-1,m=num;

    vector<vector<int>> temp(n,vector<int>(n));
    int gap=0,top=0,but=n-1,left=0,right=n-1,t=0;
    while(m)
    {
        for(int i=t;i<n-gap+t;i++)
        {
            temp[top][i]=m;
            temp[but][i]=m;
            temp[i][left]=m;
            temp[i][right]=m;
        }
        top++;
        but--;
        left++;
        right--;
        m--;
        gap+=2;
        t++;
    }

    return temp;
}

int main()
{
   auto temp=solve(2);

   for(auto elem:temp)
   {
        for(auto e:elem)
        {
            cout<<e<<" ";
        }

        cout<<endl;
   }

    return 0;
}