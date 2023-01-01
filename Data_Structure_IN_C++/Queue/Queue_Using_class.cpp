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
        size = 10;
        front = rare = -1 ;
        Q = new int[size];
    }
    
    void creat(int size);
    void enqueue(int x);
    int delqueue();
    void display();
   
};

void Queue::creat(int size)
{
    front = rare = -1 ;
    Q = new int[size];
}

void Queue::enqueue(int x)
{
    if(rare==size-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rare++;
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
        front++;
        int x;
        x = Q[front];
        return x;  
    }

}

void Queue::display()
{
    for(int i=front+1; i<=rare; i++)
    {
        cout<<Q[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    Queue q;
    q.creat(5);
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
