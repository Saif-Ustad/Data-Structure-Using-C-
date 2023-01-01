#include<iostream>
using namespace std;

int pow(int base, int exp)
{
    if(exp == 0)
        return 1;
    else if(exp%2==0)
        return pow(base*base,exp/2);
    else
        return base*pow(base*base,(exp-1)/2 ) ;    
}

int main()
{
    int m;
    int n;
    cout<<"enter the number and there power :";
    cin>>m>>n;
    cout<<pow(m,n);
}