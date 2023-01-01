#include<iostream>
using namespace std;

struct stack 
{
    int size;
    int top;
    int *s;
};

void creat(struct stack *st)
{
    cout<<"enter the size of stack : "<<endl;
    cin>>st->size;

    st->top = -1;

    st->s = new int[st->size];
}

void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        if(i==-1)
        {
            cout<<"stack underflow"<<endl;
        }
        else
        {
            cout<<st.s[i]<<"\t";
        }
    }
}

int isEmpty(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack st)
{
    if(st.top==st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *st, int x)
{
    if(st->top==st->size-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }

}

int pop(struct stack *st)
{
    int x;
    if(st->top==-1)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        x = st->s[st->top--] ;
    }
    
    return x;
}

int peek(struct stack st, int pos)
{
    if(st.top-pos+1<0)
    {
        cout<<"invalide position"<<endl;
    }
    else
    {
        return st.s[st.top-pos+1];
    }
}

int stackTop(struct stack st)
{
    if(!isEmpty(st))
    {
        return st.s[st.top];
    }
    else 
    {
        return -1;
    }
   
}


int main()
{
    struct stack st;
    
    creat(&st);

    int choice;
    
    while(true)
    {
    cout<<"enter what you want to do : "<<endl;
    cout<<" 1.push \n 2.pop \n 3.isEmpty \n 4.isFull \n 5.peek \n 6.stactTop"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        int num;
        cout<<"enter the number to push"<<endl;
        cin>>num;
        push(&st,num);
        break;

        case 2:
        cout<<"poped element is : ";
        cout<<pop(&st)<<endl;
        break;

        case 3:
        cout<<isEmpty(st)<<endl;
        break;

        case 4:
        cout<<isFull(st)<<endl;
        break;

        case 5:
        int pos;
        cout<<"enter the position : ";
        cin>>pos;
        cout<<"peeked element is : ";
        cout<<peek(st,pos)<<endl;
        break;

        case 6:
        cout<<"Stact Top is : ";
        cout<<stackTop(st)<<endl;
        break;

    }

    char ask;
    cout<<"Enter Q to exit and N to carry on : ";
    cin>>ask;
    if(ask=='Q')
    {
        break;
    }
    
    }


    display(st);
}