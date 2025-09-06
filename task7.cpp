#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void print(Node* last)
{
    if(!last) 
    {
        cout<<"List empty"<<endl;
        return;
    }
    Node* p=last->next;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    while(p!=last->next);
    cout<<endl;
}

void insertEnd(Node*& last,int val)
{
    Node* n=new Node{val,NULL};
    if(!last)
    {
        last=n;
        last->next=last;
        return;
    }
    n->next=last->next;
    last->next=n;
    last=n;
}

void insertFront(Node*& last,int val)
{
    Node* n=new Node{val,NULL};
    if(!last)
    {
        last=n;
        last->next=last;
        return;
    }
    n->next=last->next;
    last->next=n;
}

void insertPos(Node*& last,int val,int pos)
{
    if(!last) return;
    Node* p=last->next;
    for(int i=1;i<pos-1 && p!=last;i++)
    {
        p=p->next;
    }
    Node* n=new Node{val,p->next};
    p->next=n;
    if(p==last) last=n;
}

void del(Node*& last,int val)
{
    if(!last) return;
    Node* cur=last->next;
    Node* prev=last;
    do
    {
        if(cur->data==val)
        {
            if(cur==last && cur==last->next)
            {
                delete cur;
                last=NULL;
                return;
            }
            prev->next=cur->next;
            if(cur==last) last=prev;
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->next;
    }
    while(cur!=last->next);
}

int main()
{
    Node* last=NULL;
    insertEnd(last,10);
    insertEnd(last,20);
    insertEnd(last,30);
    print(last);
    insertFront(last,5);
    print(last);
    insertPos(last,15,3);
    print(last);
    del(last,20);
    print(last);
}
