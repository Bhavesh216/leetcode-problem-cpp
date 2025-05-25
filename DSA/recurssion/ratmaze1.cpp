#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, int x, int y, string path, vector<string> &res) {
    int n = mat.size();
    if (x < 0 || y < 0 || x >= n || y >= n || mat[x][y] == 0) return; // Out of bounds or blocked
    if (x == n - 1 && y == n - 1) { // Reached destination
        res.push_back(path);
        return;
    }
    mat[x][y] = 0; // Mark as visited
    solve(mat, x + 1, y, path + 'D', res); // Move Down
    solve(mat, x, y - 1, path + 'L', res); // Move Left
    solve(mat, x, y + 1, path + 'R', res); // Move Right
    solve(mat, x - 1, y, path + 'U', res); // Move Up
    mat[x][y] = 1; // Backtrack
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> res;
    if (mat[0][0]==1){
        solve(mat, 0, 0, "", res);
    } 
    return res;
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> paths = findPath(mat);
    sort(paths.begin(), paths.end()); // Optional sorting
    for (auto &p : paths) cout << p << " ";
    return 0;
}
