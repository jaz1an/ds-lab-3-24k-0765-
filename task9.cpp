#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void print(Node* h)
{
    while(h)
    {
        cout<<h->data<<" ";
        h=h->next;
    }
    cout<<endl;
}

void rearrange(Node*& head)
{
    if(!head||!head->next) return;

    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;

    while(even&&even->next)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    Node* prev=NULL;
    Node* cur=evenHead;
    while(cur)
    {
        Node* nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }

    odd->next=prev;
}

int main()
{
    int arr[]={10,4,9,1,3,5,9,4};
    Node* head=new Node{arr[0],NULL};
    Node* t=head;
    for(int i=1;i<8;i++)
    {
        t->next=new Node{arr[i],NULL};
        t=t->next;
    }
    print(head);
    rearrange(head);
    print(head);
}
