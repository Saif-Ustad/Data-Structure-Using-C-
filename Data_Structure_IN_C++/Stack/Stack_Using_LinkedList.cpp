#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t = new Node();

    if(t==NULL)
    {
        cout<<"stack is overflow"<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    if(top==NULL)
    {
        cout<<"stack is underflow"<<endl;
    }
    else
    {
        int x;
        struct Node *t;
        t = top;
        x = t->data;
        top = t->next;
        free(t);
        return x;

    }
}

void display()
{
    struct Node *p;
    p = top;

    if(p==NULL)
    {
        cout<<"stack is empty "<<endl;
    }
    
    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int isEmpty()
{
    return top ? 0:1 ; 
}

int isFull()
{
    struct Node *t;
    t = new Node();

    return t ? 1:0 ;
}
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    cout<<isFull()<<endl;
    cout<<isEmpty()<<endl;
}