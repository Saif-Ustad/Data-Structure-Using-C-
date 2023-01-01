#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node * Next;
};

struct Node * accept()
{
    struct Node *a;
    a = new Node;
    cout<<"Enter Node data : ";
    cin>>a->data;
    a->Next = NULL;
    return a;

}

struct Node *creat_linked_list(struct Node *Head)
{
    int number_of_nodes = 5;
    while(number_of_nodes--)
    {
        struct Node *newnode;
        newnode = new Node;
        newnode = accept(); 
        if(Head==NULL)
        {
            Head = newnode ;
        }
        else
        {
            Head->Next = newnode;
            Head = newnode; 
        }
    }    
}
void display_linked_list(struct Node *Head)
{
    struct Node *t;
    t = Head;
    while(t!=NULL)
    {
        cout<<t->data;
        t = t->Next ;
    }
}

int main()
{
    struct Node *Head;
    Head = new Node;
    Head = NULL;

    creat_linked_list(Head);
    display_linked_list(Head);
    




}
