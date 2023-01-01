#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rare;
    int *Q;
};

void creat(Queue *q, int size)
{

    q->size = size;
    q->front = q->rare = -1 ;
    q->Q = new int[q->size];
}

void enqueue(Queue *q, int x)
{
    if(q->rare==q->size-10)
    {
        cout<<"Queue is full";
    }
    else
    {
        q->rare++;
        q->Q[q->rare] = x;
    }
}

int dequeue(Queue *q)
{
    if(q->front==q->rare)
    {
        cout<<"Queue is empty";
        return -1;
    }
    else 
    {
        q->front++;
        int x;
        x = q->Q[q->front] ;
        return x;
    }
    
}

void display(Queue *q)
{
    for(int i=q->front+1; i<=q->rare; i++)
    {
        cout<<q->Q[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    
    struct Queue q;

    cout<<"enter the size of Queue : ";
    int size;
    cin>>size;
    creat(&q, size);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);
    dequeue(&q);
    display(&q);



}