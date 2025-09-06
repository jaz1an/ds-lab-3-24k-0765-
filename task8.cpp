#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

struct DList
{
    Node* head;
    Node* tail;
};

void append(DList& lst,int val)
{
    Node* n=new Node{val,NULL,NULL};
    if(!lst.head)
    {
        lst.head=n;
        lst.tail=n;
        return;
    }
    lst.tail->next=n;
    n->prev=lst.tail;
    lst.tail=n;
}

void show(DList lst)
{
    Node* p=lst.head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

DList concat(DList A,DList B)
{
    if(!A.head) return B;
    if(!B.head) return A;
    A.tail->next=B.head;
    B.head->prev=A.tail;
    A.tail=B.tail;
    return A;
}

int main()
{
    DList L{NULL,NULL};
    DList M{NULL,NULL};
    append(L,1);
    append(L,2);
    append(L,3);
    append(M,4);
    append(M,5);
    append(M,6);
    show(L);
    show(M);
    DList R=concat(L,M);
    show(R);
}
