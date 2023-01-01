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

char stackTop()
{
    if(top==NULL)
    {
        return '0';
    }
    else
    {
        return top->data ;
    }
}

int isOparand(char x) 
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Evaluation_Of_Postfix(char *postfix)
{
    int i=0;
    int x1, x2, r;

    for(i=0; postfix[i]!='\0'; i++)
    {
        if(isOparand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
           
            x2 = pop();
            x1 = pop();
            
            switch(postfix[i])
            {
                case '+' :
                r = x1 + x2 ;
                push(r);
                break;

                case '-' : 
                r = x1 - x2 ;
                push(r);
                break;

                case '*' : 
                r = x1 * x2 ;
                push(r);
                break;
    
                case '/' : 
                r = x1 / x2 ;
                push(r);
                break;


            }
        }
    }
    return top->data; // or return (r);
    
}

int main()
{
    char *postfix = "234*+82/+";
    cout<<Evaluation_Of_Postfix(postfix);
}