#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*front=NULL, *rare=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node();

    if(t==NULL)
    {
        cout<<"Queue is full "<<endl;
    } 
    else
    {
        t->data = x;
        t->next = NULL;
        if(front==NULL)
        {
            front = rare = t ;
        }
        else
        {
            rare->next = t;
            rare = t;
        }
    }

}

int dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        struct Node *t;
       
        int x;
        x = front->data;
        t = front;
        front = front->next;
        free(t);
        return x;

    }

}

void display()
{
    struct Node *p;
    p = front;

    while(p)
    {
        cout<<p->data<<"\t";
        p = p->next;

    }
    cout<<endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
   
    
    display();

}