#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int a[n], b[m], c[k];

    // Read elements of the first list
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read elements of the second list
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // Read elements of the third list
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }

    int target;
    cin >> target;

    // Use three nested loops to find the first matching sum
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                if (a[i] + b[j] + c[l] == target) {
                    cout << a[i] << " " << b[j] << " " << c[l] << endl;
                    return 0;
                }
            }
        }
    }

    // If no such combination is found
    cout << "No combination found" << endl;
    return 0;
}
