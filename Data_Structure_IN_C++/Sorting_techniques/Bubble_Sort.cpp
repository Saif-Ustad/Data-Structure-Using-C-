#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp ;
}

void Bubble_Sort(int A[], int len)
{
    int i, j, flag;
    for(i=0; i<len; i++)
    {
        flag = 0;
        for(j=0; j<len-1-i; j++)
        {
            if(A[j]>A[j+1])
                swap(&A[j], &A[j+1]);
                flag = 1;
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[] = {3,1,2,8,8,5,4,3,2,6,4,8,9,0};
    Bubble_Sort(A, 14);

    for(int i=0; i<14; i++)
    {
        cout<<A[i]<<"\t";
    } 
}