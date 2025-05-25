#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minimumTimeToCollectCandies(vector<int>& candies) {
    // Create a min-heap (priority queue with greater<int>)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all candies into the min-heap using a proper for loop
    for (int i = 0; i < candies.size(); i++) {
        minHeap.push(candies[i]);
    }

    int totalTime = 0;

    // Perform N-1 combinations using a proper for loop
    for (int i = 0; i < candies.size() - 1; i++) {
        // Extract the two smallest elements
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Combine the two smallest boxes
        int combined = first + second;
        totalTime += combined;

        // Push the combined value back into the heap
        minHeap.push(combined);
    }

    return totalTime;
}

int main() {
    int N;
    cin >> N;

    vector<int> candies(N);
    for (int i = 0; i < N; i++) {
        cin >> candies[i];
    }

    cout << minimumTimeToCollectCandies(candies) << endl;
    return 0;
}
