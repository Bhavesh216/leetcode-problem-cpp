#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Take input N
    int N;
    cin >> N;

    // Determine the sizes of the odd and even arrays
    int oddSize = (N % 2 == 0) ? N / 2 : N / 2 + 1;
    int evenSize = N / 2;

    // Arrays to store odd and even numbers
    vector<int> oddArray;
    vector<int> evenArray;

    // Fill the odd array with odd numbers in decreasing order
    for (int i = N; i > 0; i--) {
        if (i % 2 != 0) {
            oddArray.push_back(i);
        }
    }

    // Fill the even array with even numbers in increasing order
    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            evenArray.push_back(i);
        }
    }

    // Print the odd numbers in decreasing order
    for (int num : oddArray) {
        cout << num;
    }

    // Print the even numbers in increasing order
    for (int num : evenArray) {
        cout << num;
    }

    cout << endl;
    return 0;
}
