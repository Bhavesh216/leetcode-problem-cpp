#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100000;
    int arr[MAX_SIZE];
    int count = 0;
    int value;

    // Read input until -1 is encountered
    while (cin >> value && value != -1) {
        arr[count++] = value;
    }

    // Read k
    int k;
    cin >> k;

    // Check if k is valid
    if (k > count) {
        cerr << "Error: k is larger than the length of the list" << endl;
        return 1;
    }

    // Calculate the index of the kth element from the last
    int index = count - k;

    // Output the kth element from the last
    cout << arr[index] << endl;

    return 0;
}
