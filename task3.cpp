#include<iostream>
#include<string>
using namespace std;

struct node{ 
    string name; node* next; 
};

void display(node* h){
    while(h){ 
        cout<<h->name<<endl; 
        h=h->next; 
    }
}

void reserve(node* &h,string n){
    node* p=new node{n,NULL};
    if(!h||n<h->name){ 
        p->next=h; h=p; return; 
    }
    node* t=h;
    while(t->next && t->next->name<n) t=t->next;
    p->next=t->next; t->next=p;
}

void cancel(node* &h,string n){
    if(!h) return;
    if(h->name==n){ node* d=h; h=h->next; delete d; return; }
    node* t=h;
    while(t->next && t->next->name!=n) t=t->next;
    if(t->next){ node* d=t->next; t->next=t->next->next; delete d; }
}

bool check(node* h,string n){
    while(h){ 
        if(h->name==n) return true; 
        h=h->next; 
    }
    return false;
}

int main(){
    node* head=NULL; 
    int ch; string name;
    do{
        cout<<"\n1.Reserve\n2.Cancel\n3.Check\n4.Display\n5.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter name: "; cin>>name; reserve(head,name); break;
            case 2: cout<<"Enter name: "; cin>>name; cancel(head,name); break;
            case 3: cout<<"Enter name: "; cin>>name; cout<<(check(head,name)?"Reserved":"Not Reserved")<<endl; break;
            case 4: display(head); break;
        }
    }while(ch!=5);
}
