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
        cout << h->data;
        if(h->next) 
            cout << "->";
        h = h->next;
    }
    cout << "->NULL" << endl;
}

void del(Node*& head,int val)
{
    if(!head) 
    {
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->data==val)
    {
        Node* tmp=head;
        head=head->next;
        delete tmp;
        cout<<"Value deleted"<<endl;
        return;
    }

    Node* cur=head;
    while(cur->next && cur->next->data!=val)
    {
        cur=cur->next;
    }

    if(cur->next)
    {
        Node* tmp=cur->next;
        cur->next=tmp->next;
        delete tmp;
        cout<<"Value deleted"<<endl;
    }
    else
    {
        cout<<"Value not present"<<endl;
    }
}

int main()
{
    int arr[]={10,20,30,40,50};
    Node* head=new Node{arr[0],NULL};
    Node* t=head;
    for(int i=1;i<5;i++)
    {
        t->next=new Node{arr[i],NULL};
        t=t->next;
    }

    print(head);
    del(head,30);
    print(head);
    del(head,100);
    print(head);
}
