#include <bits/stdc++.h>
using namespace std;
int maxDivide(int a, int b)
{
    while(a % b == 0)
    {
        a = a / b;
    }
    return a;
}
int isUgly(int n)
{
    n = maxDivide(n, 2);
    n = maxDivide(n, 3);
    n = maxDivide(n, 5);

    return (n == 1) ? 1 : 0;
}
int getNthUgly(int N)
{
    int i = 1;
    int cnt = 1;

    while (N > cnt)
    {
        i++;
        if (isUgly(i))
        {
            cnt++;
        }
    }
    return i;
}
int main()
{
    int num;
    cin >> num;
    cout << getNthUgly(num);

    return 0;
}