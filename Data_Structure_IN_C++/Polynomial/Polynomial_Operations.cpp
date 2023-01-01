#include <iostream>
using namespace std;

struct terms
{
    int coeff;
    int expo;
};

void creat_polynomial(int num, struct terms *p1)
{
    for (int i = 0; i < num; i++)
    {
        cin >> p1[i].coeff >> p1[i].expo;
    }
}

void display_polynomial(int num, struct terms *p1)
{
    int i;
    for (i = 0; i < num; i++)
    {
        cout << p1[i].coeff << "X^" << p1[i].expo;
        if (i + 1 != num)
        {
            cout << " + ";
        }
    }
}

struct terms *add_polynomial(struct terms *p1, struct terms *p2, int num1, int num2, int *size)
{
    struct terms *sum;
    sum = new terms;

    int i = 0, j = 0, k = 0;
    while (i < num1 && j < num2)
    {
        if (p1[i].expo == p2[j].expo)
        {
            sum[k].expo = p1[i].expo;
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            sum[k].expo = p1[i].expo;
            sum[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else if (p1[i].expo < p2[j].expo)
        {
            sum[k].expo = p2[i].expo;
            sum[k].coeff = p2[i].coeff;
            j++;
            k++;
        }
    }

    for (; i < num1; i++)
    {
        sum[k] = p1[i];
        k++;
    }
    for (; j < num1; j++)
    {
        sum[k] = p1[j];
        k++;
    }

    *size = k;
    return sum;
}

int main()
{
    int num1;
    cout << "enter the terms of polynomial 1 : ";
    cin >> num1;

    struct terms p1[num1];
    cout << "Enter the polynomial (coeff expo): " << endl;
    creat_polynomial(num1, p1);

    int num2;
    cout << "enter the terms of polynomial 2 : ";
    cin >> num2;

    struct terms p2[num2];
    cout << "Enter the polynomial (coeff expo): " << endl;
    creat_polynomial(num2, p2);

    struct terms *addition;
    struct terms sub[num1 + num2];
    struct terms multi[num1 * num2];

    int size = 0;
    addition = add_polynomial(p1, p2, num1, num2, &size);
    display_polynomial(size, addition);

    return 0;
}