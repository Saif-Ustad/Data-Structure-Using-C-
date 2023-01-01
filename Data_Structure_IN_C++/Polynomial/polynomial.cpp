#include<iostream>
using namespace std;
struct term
{
    int coeff;
    int expo;
}; 

class polynomial
{
    private:
    struct term terms[5];

    public:
    void put()
    {
        for(int i=0; i<5; i++)
        {
            cout<<"term "<<i+1<<"(coeff expo)"<< " : " ;
            cin>>terms[i].coeff>>terms[i].expo ;
        }
    }
    void get()
    {
        for(int i=0; i<5; i++)
        {
            cout<<terms[i].coeff<<"x^"<<terms[i].expo<<" + ";
        }
    }
    void add()
};

int main()
{
   polynomial p1,p2;
   p1.put();
   p2.put();
   p1.get();
   cout<<"\n";
   p2.get();

}