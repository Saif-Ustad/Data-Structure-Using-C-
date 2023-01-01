#include<iostream>
using namespace std;

long long int fact(long long int n)
{
    if(n==0 || n==1)
        return 1 ;
    return fact(n-1)*n ;    
}

int main()
{
    int num;
    cout<<"enter the number to find factorial : ";
    cin>>num;

    cout<<fact(num);
}