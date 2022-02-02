/*
Convert a multilevel linked list to a singly linked list
Given a multilevel linked list, convert it into a singly linked list so that all nodes of the first level appear first, followed by all nodes of the second level, and so on.

The multilevel linked list is similar to the simple linked list, except that it has one extra field that points to that node’s child. The child may point to a separate list altogether, which may have children of its own.

 
For example, consider the following multilevel linked list:
see from this link : https://www.techiedelight.com/convert-multilevel-linked-list-singly/
Multilevel Linked List

We should convert it into list 1—>2—>3—>4—>5—>6—>7—>8—>9—>10—>11—>12—>null
*/


#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
  int val;
  Node *child,*next;
  Node(int val,Node *child,Node *next)
  {
    this->val=val;
    this->next=next;
    this->child=child;
  }
  Node()
  {
    this->val=0;
    this->next=next;
    this->child=child;
  }
  Node(int val)
  {
    this->val=val;
    this->next=this->child=NULL;
  }
  Node(int val,Node *temp,int flag)
  {
    this->val=val;
    if(flag)
    {
      this->next=temp;
      this->child=NULL;
    }
    else{
      this->next=NULL;
      this->child=temp;
    }
  }
};

int main()
{
  Node *root,*temp,*prev;
  root=new Node(1,(new Node(6,(new Node(7,(new Node(10,(new Node(11,(new Node(12)),0)),1)),0)),1)),(new Node(2,(new Node(3,(new Node(8,(new Node(9)),1)),(new Node(4,(new Node(5)),1)))),1)));
  deque<Node*> q;
  q.push_back(root);
  while(!q.empty())
  {
    temp=q.front();
    if(temp!=root)
    {
      prev->next=temp;
      prev->child=NULL;
    }
    q.pop_front();
    while(temp)
    {
      if(temp->child)
      {
        q.push_back(temp->child);
      }
      prev=temp;
      temp=temp->next;
    }
  }
  while(root)
  {
    cout<<root->val<<" ";
    root=root->next;
  }
  cout<<endl;
  return 0;
}