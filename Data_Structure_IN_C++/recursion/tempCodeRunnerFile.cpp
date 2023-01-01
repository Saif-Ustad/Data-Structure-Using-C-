#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return fact(n-1)*n ;
    }
}

int ncr(int n, int r)
{
    int num,deno;
    num = fact(n);
    deno = fact(r)*fact(n-r);
    return num/deno ;
}

int main()
{
    
    cout<<ncr(5,1);
}