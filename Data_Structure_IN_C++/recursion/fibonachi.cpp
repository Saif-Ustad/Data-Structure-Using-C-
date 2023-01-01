#include <iostream>
using namespace std;

int fibo(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        int result;
        result = fibo(num - 2) + fibo(num - 1);
        cout << result << "\t";
    }
}
int main()
{
    int n;
    cout << "enter the number up to which you want finonachi series : ";
    cin >> n;

    cout << fibo(n) << "\t";
}