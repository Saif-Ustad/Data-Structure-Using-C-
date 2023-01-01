#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *pre, *next ;
};

struct Node * accept()
{
    struct Node *a;
    a = new Node;
    cout<<"Enter Node data : ";
    cin>>a->data;
    a->next = NULL;
    a->pre = NULL ;
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
            
            temp->next = newnode;
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
        t = t->next ;
    }
}

struct Node *insert_at_begining(struct Node *Head)
{
    struct Node *nn;
    struct Node *t;
    t = Head;
    nn = accept();

    nn->next = t;
    t->pre = nn ;
    Head = nn;

    return Head;

}

struct Node *insert_at_end(struct Node *Head)
{
    struct Node *t;
    t = Head;

    struct Node *nn;
    nn = accept();

    while(t->next != NULL)
    {
        t = t->next ;
    }

    t->next = nn;
    nn->pre = t ;

    return Head;
}

struct Node *insert_at_position(struct Node *Head)
{
    struct Node *t;
    int pos;
    cout<<"Enter the postion where you want to insert data element : ";
    cin>>pos;

    struct Node *nn;
    nn = accept();
 
    t = Head;
    int i=1;
    while(i != pos-1)
    {
        t = t->next;
        i++ ;
    } 
    nn->next = t->next;
    (t->next)->pre = nn;
    t->next = nn;
    nn->pre = t ;

    return Head;
}

struct Node *delete_begin(struct Node *Head)
{
    struct Node *t;
    t = Head;
    Head = t->next;
    (t->next)->pre = NULL;
    t->next = NULL ;
    free(t);

    return Head;
}

struct Node *delete_end(struct Node *Head)
{
    struct Node *t;
    t = Head;
    
    while(t->next != NULL)
    {
        t = t->next;
    }
   
    cout<<(t->pre)->next->data ;   
    (t->pre)->next = NULL;
     

    t->pre = NULL;
    free(t);

    return Head;
}
struct Node *delete_position(struct Node *Head)
{
    struct Node *t;
    int pos;
    cout<<"Enter the postion where you want to delete data element : ";
    cin>>pos;
 
    t = Head;
    int i=1;
    while(i != pos)
    {
        t = t->next;
        i++ ;
    } 
     

    (t->next)->pre = t->pre ;
    (t->pre)->next = t->next ;
 
     
    t->next = NULL;
    t->pre = NULL ;

    

    free(t);

    return Head;
}

int main()
{
 
 struct Node *Head ;
 Head = new Node;
 Head = NULL;
 
 Head = creat_linked_list(Head);
 
 //Head = insert_at_begining(Head);
 //display_linked_list(Head);
//Head = insert_at_end(Head);
//display_linked_list(Head);
//Head = insert_at_position(Head);
//display_linked_list(Head);
//Head = delete_begin(Head);
//display_linked_list(Head);
//something problem is there Head = delete_end(Head);
//display_linked_list(Head);
Head = delete_position(Head);
display_linked_list(Head);


}