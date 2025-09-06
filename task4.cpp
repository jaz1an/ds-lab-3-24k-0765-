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
        cout << h->data;
        if(h->next) 
            cout << "->";
        h = h->next;
    }
    cout << "->NULL" << endl;
}

void rearrange(node* &head)
{
    if(!head || !head->next) 
        return;

    node* evenH = NULL;
    node* evenT = NULL;
    node* oddH = NULL;
    node* oddT = NULL;

    node* cur = head;
    while(cur)
    {
        if(cur->data % 2 == 0)
        {
            if(!evenH)
            {
                evenH = cur;
                evenT = cur;
            }
            else
            {
                evenT->next = cur;
                evenT = evenT->next;
            }
        }
        else
        {
            if(!oddH)
            {
                oddH = cur;
                oddT = cur;
            }
            else
            {
                oddT->next = cur;
                oddT = oddT->next;
            }
        }
        cur = cur->next;
    }

    if(!evenH || !oddH) 
        return;

    evenT->next = oddH;
    oddT->next = NULL;
    head = evenH;
}

int main()
{
    int arr[] = {17,15,8,12,10,5,4,1,7,6}; 

    node* head = new node{arr[0],NULL};
    node* t = head;

    for(int i=1;i<10;i++)
    {
        t->next = new node{arr[i],NULL};
        t = t->next;
    }

    print(head);
    rearrange(head);
    print(head);
}
