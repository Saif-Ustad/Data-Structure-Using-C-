#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rare;
    int * Q;
};

void creat(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rare = -1;
    q->Q = new int[q->size];

}

void enqueue_front(struct Queue *q, int x)
{
    if(q->front==-1)
    {
        cout<<"front is full"<<endl;
    }
    else
    {
        q->Q[q->front] = x;
        q->front--;
    }

}

void enqueue_rare(struct Queue *q, int x)
{
    if(q->rare == q->size)
    {
        cout<<"rare is full"<<endl;
    }
    else
    {
        q->rare++ ;
        q->Q[q->rare] = x;
        
    }

}

 
int dequeue_front(struct Queue *q)
{
    if(q->front==q->rare)
    {
        cout<<"front is empty"<<endl;
    }
    else
    {
        q->front++;
        int x;
        x = q->Q[q->front];
        //free(q->Q[q->front]) ;
        return x;
    }

}

int dequeue_rare(struct Queue *q)
{
    if(q->front==q->rare)
    {
        cout<<"rare is empty"<<endl;
    }
    else
    {
        int x;
        x = q->Q[q->rare];
        q->rare--;
        //free(q->Q[q->front]) ;
        return x;
    }

}

void display(struct Queue *q)
{
    for(int i=q->front+1; i<=q->rare; i++)
    {
        cout<<q->Q[i]<<"\t" ;
    }
    cout<<endl;

}

int main()
{
    struct Queue q;
    creat(&q,5);
    enqueue_rare(&q,10);
    enqueue_rare(&q,20);
    enqueue_rare(&q,30);
    enqueue_rare(&q,40);
    enqueue_rare(&q,50);

    display(&q);

    dequeue_front(&q);
    dequeue_front(&q);

    display(&q);

    enqueue_front(&q,100);

    display(&q);

    

    

    
}