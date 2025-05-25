#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int x;
    cout << "Enter the number of elements: ";
    cin >> x;

    int arr[x];

    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    cout << "Printing the original array: ";
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deleting from the start
    for (int i = 0; i < x; i++)
    {
        arr[i] = arr[i + 1];
    }
    x = x - 1;
    cout << "array after deletion from beginning: ";
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deleting from the end
    x = x - 1;
    cout << "array after deletion from end: ";
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deleting the Kth element
    int k = 2;
    for (int i = k - 1; i < x; i++)
    {
        arr[i] = arr[i + 1];
    }
    x = x - 1;
    cout << "array after deletion from Kth position: ";
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
