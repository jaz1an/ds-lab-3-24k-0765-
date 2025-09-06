#include<iostream>
using namespace std;

struct node
{ 
    int data;
    node* next;
};

void print(node* h)
{
    while(h)
    {
        cout<<h->data<<" ";
        h=h->next;
    } 
    cout<<endl;
}

void addEnd(node* h,int v)
{
    while(h->next)
    {
        h=h->next;
    }
    h->next=new node{v,NULL}; 
}

void addFront(node* &h,int v)
{
    node* t=new node{v,h}; 
    h=t;
}

void addPos(node* &h,int v,int p)
{
    node* t=h;
    for(int i=1;i<p-1 && t;i++)
    {
        t=t->next;
    }
    if(t)
    {
        node* n=new node{v,t->next};
        t->next=n;
    }
}

void delVal(node* &h,int v)
{
    if(!h) 
    {
        return;
    } 
    if(h->data==v)
    { 
        node* d=h;
        h=h->next;
        delete d;
        return; 
    }
    node* t=h; 
    while(t->next && t->next->data!=v)
    {
        t=t->next;
    }
    if(t->next)
    { 
        node* d=t->next;
        t->next=t->next->next;
        delete d;
    }
}

int main()
{
    int arr[5]={3,1,2,5,8}; 
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    node* head=new node{arr[0],NULL}; 
    node* t=head; 
    for(int i=1;i<5;i++)
    {
        t->next=new node{arr[i],NULL};
        t=t->next;
    }
    addEnd(head,9); 
    addPos(head,11,3); 
    addFront(head,4);
    delVal(head,1); 
    delVal(head,2); 
    delVal(head,5);
    print(head);
}
