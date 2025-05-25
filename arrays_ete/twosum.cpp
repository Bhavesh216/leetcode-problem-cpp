#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,f;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int target;
    cin >> target;
    sort(a, a + n);
    int i, j;
    while (i < j)
    {
        if (a[i] + a[j] == target)
        {
             f = 1;
            cout << " true";
            break;
        }
        else if (a[i] + a[j] < target)
        {
            i++;
        }
        else
            j--;
    }
    if ( f == 0)
    {
        cout << "false";
    }
    return 0;
}