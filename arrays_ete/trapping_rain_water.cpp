#include <iostream>

using namespace std;

int trap(int height[], int n) {
    if (n == 0) return 0;

    int left = 0;           // Left pointer
    int right = n - 1;      // Right pointer
    int left_max = 0;       // Maximum height encountered from the left
    int right_max = 0;      // Maximum height encountered from the right
    int trapped_water = 0;  // Total trapped water

    while (left < right) {
        // Update the maximum height encountered from the left
        if (height[left] > left_max) {
            left_max = height[left];
        }
        
        // Update the maximum height encountered from the right
        if (height[right] > right_max) {
            right_max = height[right];
        }

        // Calculate trapped water at the current position
        if (left_max < right_max) {
            trapped_water += max(0, left_max - height[left]);
            left++;
        } else {
            trapped_water += max(0, right_max - height[right]);
            right--;
        }
    }

    return trapped_water;
}

int main() {
    int height[] = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);
    int trapped_water = trap(height, n);
    cout << "Trapped water: " << trapped_water << endl;

    return 0;
}
