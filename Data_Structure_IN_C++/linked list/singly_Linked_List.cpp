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
        struct Node *temp;
        //newnode = new Node;
        newnode = accept(); 
        if(Head==NULL)
        {
            Head = newnode ;
            temp = Head;
        }
        else
        {
            
            temp->Next = newnode;
            temp = newnode; 
        }
    }  
    return  Head ;
}
void display_linked_list(struct Node *Head)
{
    struct Node *t;
    t = Head;

    while(t!=NULL)
    {
        cout<<t->data<<"\t";
        t = t->Next ;
    }
}

struct Node *insert_at_begining(struct Node *Head)
{
    struct Node *nn;
    nn = accept();
    nn->Next = Head;
    Head = nn;
    return Head;

}
struct Node *insert_at_position(struct Node *Head)
{
    int pos;
    cout<<"enter the position where you want to add data : ";
    cin>>pos;

    struct Node *nn;
    nn = accept();

    struct Node *t;
    t = Head;

    int i=1;
    while(i < pos-1)
    {
        t = t->Next;
        i++;
    } 
   

    nn->Next = t->Next; 
    t->Next = nn;

    return Head;
}
struct Node *insert_at_end(struct Node *Head)
{
    struct Node *nn;
    nn = accept();

    struct Node *t;
    t = Head;

    while(t->Next != NULL)
    {
        t = t->Next;
    }
    t->Next = nn;
    nn->Next = NULL;
    
    return Head;
}

struct Node *delete_begin(struct Node *Head)
{
    struct Node *t;
    t = Head;
    Head = t->Next;
    t->Next = NULL;
    free(t);

    return Head;
}
struct Node *delete_end(struct Node *Head)
{
    struct Node *t, *t1;
    t = Head;

    while(t->Next != NULL)
    {
        t1 = t;
        t = t->Next;  
    }
    
    t1->Next = NULL;
  
    free(t);

    return  Head;
}

struct Node *delete_at_position(struct Node *Head)
{
    struct Node *t, *t1;
    t = Head;

    int pos;
    cout<<"enter the position which you want to delete data : ";
    cin>>pos;

    int i=1;
    while(i != pos)
    {
        t1 = t;
        t = t->Next; 
        i++; 
    }
    
    t1->Next = t->Next;
    t->Next = NULL;
  
    free(t);

    return  Head;   
}

struct Node *search(struct Node *Head)
{
    struct Node *t;
    t = Head;

    int val;
    cout<<"Enter the data number which you want to search : ";
    cin>>val;

    while(t->data != val)
    {
        t = t->Next ;
    }
 
    return t;
    
}

int count_nodes(struct Node *Head)
{
    struct Node *t;
    t = Head;

    int i = 1;
    while(t->Next != NULL)
    {
        t = t->Next;
        i++ ;
    }

    return i ;

}

void Display_reverse(struct Node *Head)
{
    if(Head != NULL)
    {
        Head = Head->Next;
        Display_reverse(Head);
        cout<<Head->data;
    
    }
}

int main()
{
    struct Node *Head;
    Head = new Node;
    Head = NULL;

    Head = creat_linked_list(Head);
   // display_linked_list(Head);
    //Head =  insert_at_begining(Head);
   // display_linked_list(Head);
    //Head = insert_at_position(Head);
    //display_linked_list(Head);
    //Head = insert_at_end(Head);  
    //display_linked_list(Head);
    //Head = delete_begin(Head);
    //display_linked_list(Head);
    //Head = delete_end(Head);
    //display_linked_list(Head);
    //Head = delete_at_position(Head);
    //display_linked_list(Head);
    //cout<<search(Head)->data;
    //cout<<count_nodes(Head);
    //Display_reverse(Head);

}
