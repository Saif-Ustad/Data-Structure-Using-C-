#include<iostream>
using namespace std;

class Queue
{
    private:
    int size;
    int front;
    int rare;
    int *Q;

    public:

    Queue()
    {
        size = 5;
        front = rare = 0 ;
        Q = new int[size];
    }

    Queue(int size)
    {
        front = rare = 0 ;
        Q = new int[size];
    }
    

    void enqueue(int x);
    int delqueue();
    void display();
   
};

void Queue::enqueue(int x)
{
    if((rare+1)%size == front)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rare = (rare+1)%size;
        Q[rare] = x ;
    }
    
}

int Queue::delqueue()
{
    if(front==rare)
    {
       cout<<"Queue is empty"<<endl;
       return -1; 
    }
    else
    {
        front = (front+1)%size;
        int x;
        x = Q[front];
        free(Q);
        return x;  
    }

}

void Queue::display()
{
    int i=(front+1)%size;
    do{
        cout<<Q[i]<<"\t";
        i = (i+1)%size ;
    }while(i!=(rare+1)%size);
    cout<<endl;
    
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    cout<<"Deleted  number : ";
    cout<<q.delqueue();
    cout<<endl;
    q.display();
    
}
