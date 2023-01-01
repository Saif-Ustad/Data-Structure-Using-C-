#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(char x)
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

char pop()
{
    if(top==NULL)
    {
        cout<<"stack is underflow"<<endl;
    }
    else
    {
        char x;
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

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==NULL)
            {
                return 0;
            }
            else if(exp[i]==')' && top->data=='(' || exp[i]=='}' && top->data=='{' || exp[i]==']' && top->data=='[')
            {
                pop();
            }

        }
    }

    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "(){";
    cout<<"Expression balanced : "<<isBalanced(exp);
}