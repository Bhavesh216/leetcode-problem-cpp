#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the vector
    vector<int> vec(n); // Initialize the vector with size n

    for (int i = 0; i < n; ++i) {
        cin >> vec[i]; // Read each element
    }

    // Print the vector elements (optional)
    for (const int &elem : vec) {
        cout << elem << " ";
    }

    return 0;
}

