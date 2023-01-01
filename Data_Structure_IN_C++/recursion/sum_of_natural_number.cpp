#include<iostream>
using namespace std;

int sum_of_natural_number(int n)
{
    if(n==0)
    {
        return 0 ;
    }
    return (n + sum_of_natural_number(n-1));
}

int main()
{
    int num;
    cout<<"enter the number : ";
    cin>>num;

    cout<<"sum of n natural number is : "<<sum_of_natural_number(num);
}