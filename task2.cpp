#include<iostream>
using namespace std;

struct node{ 
    int data;
 node* next; 
};

void print(node* h){ 
    while(h){ 
        cout<<h->data<<" "; 
        h=h->next; 
    } 
    cout<<endl; 
}

int length(node* h){ 
    int c=0; 
    while(h){
         c++; 
         h=h->next;
         } 
    return c; 
}

void rotate(node* &head,int k){
    if(!head||!head->next||k<=0) return;
    int n=length(head); 
    if(k>=n) return;
    node* t=head; 

    for(int i=1;i<k;i++)
     t=t->next;

    node* newHead=t->next; 
    t->next=NULL;
    node* end=newHead; 

    while(end->next) 
    end=end->next;

    end->next=head; 

    head=newHead;
}

int main(){
    int vals[]={5,3,1,8,6,4,2}; 
    node* head=new node{vals[0],NULL}; 
    node* cur=head;
    for(int i=1;i<7;i++){ 
        cur->next=new node{vals[i],NULL}; 
        cur=cur->next; 
    }
    print(head);
    int k; 
    cout<<"Enter the number: "; 
    cin>>k;
    rotate(head,k);
    print(head);
}
