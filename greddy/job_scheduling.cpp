#include <bits/stdc++.h>
using namespace std;

pair<int, int> jobScheduling(vector<int>& deadline, vector<int>& profit) {
    int n = deadline.size();
    vector<pair<int, int>> jobs;  // {profit, deadline}
    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // Sort jobs by profit descending
    sort(jobs.rbegin(), jobs.rend());

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].second);
    }

    // Slot availability vector
    vector<bool> slot(maxDeadline + 1, false); // index 1 to maxDeadline
    int countJobs = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].second;
        int profit = jobs[i].first;

        // Try to find a free slot before or on deadline
        for (int j = deadline; j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = true;
                countJobs++;
                maxProfit += profit;
                break;
            }
        }
    }

    return {countJobs, maxProfit};
}
