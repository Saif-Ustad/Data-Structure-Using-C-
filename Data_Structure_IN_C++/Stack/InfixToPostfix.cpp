#include<iostream>
#include<string.h>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
};

class stack
{
    private:
    Node *top;


    public:
    stack()
    {
        top = NULL;
    }

    void push(char x);
    char pop();
    int isEmpty();
    char stackTop();
    void display();
    int isOparand_B(char x);
    int isOparand_U(char x);
    int pre(char x);
    int In_Stack_Pre(char x);
    int Out_Stack_Pre(char x);
    char * InfixToPostfix_B(char *infix);
    char * InfixToPostfix_U(char *infix);


};

void stack::push(char x)
{
    Node *t;
    t = new Node();
    t->data = x;
    t->next = top;
    top = t;

}

char stack::pop()
{
    if(top==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        Node *p;
        char x;
        p = top;
        x = p->data;
        top = top->next;
        free(p);
        return x;
    }
}

char stack::stackTop()
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

int stack::isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stack::display()
{
    Node *p;
    p = top;
    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<"\n";
}

//this for simple + - * / operators 
int stack::isOparand_B(char x) // B = Basic
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// this for all type of operators
int stack::isOparand_U(char x) // U = Universal 
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


// this for basic operator precident
int stack::pre(char x) // B = Basic
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

//this for universal operator precident
int stack::In_Stack_Pre(char x)
{
    if(x=='+' || x=='-')
    {
        return 2;
    }
    else if(x=='*' || x=='/')
    {
        return 4;
    }
    else if(x=='^')
    {
        return 5;
    }
    else if(x=='(')
    {
        return 0;
    }
    else if(x==')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//this for universal operator precident
int stack::Out_Stack_Pre(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 3;
    }
    else if(x=='^')
    {
        return 6;
    }
    else if(x=='(')
    {
        return 7;
    }
    else if(x==')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

// this for infix to postfix for basic + - * / operator 
char * stack::InfixToPostfix_B(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+2];
    int i=0, j=0;    

    while(infix[i]!='\0')
    {
        if(isOparand_B(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++]=pop();
            }
           
        }

    }
    while(top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';

    return postfix;
}

//this for infix to postfix for universal operators
char * stack::InfixToPostfix_U(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+2];
    int i=0, j=0;    

    while(infix[i]!='\0')
    {
        if(isOparand_U(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(Out_Stack_Pre(infix[i])>In_Stack_Pre(top->data))
            {
                push(infix[i++]);
            }
            else if(Out_Stack_Pre(infix[i]) == In_Stack_Pre(top->data))
            {
                pop();
                i++ ;
            }
            else
            {
                postfix[j++]=pop();
            }
           
        }

    }
    
    while(top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';

    return postfix;
}



int main()
{
    stack stk1, stk2;
    
    // this code for conversion infix to postfix for basic + - * \ operator 
    char *infix1 = "a+b*c-d";
    stk1.push('#');
    char *postfix1 = stk1.InfixToPostfix_B(infix1);
    cout<<postfix1<<endl;
    
    // this code for conversion infix to postfix for universal  operator 
    
    char *infix2 = "((8-(3+3))*(3+(6/2))^2)";
    stk2.push('#');
    
    char *postfix2 = stk2.InfixToPostfix_U(infix2);
    
    cout<<postfix2<<endl;

}