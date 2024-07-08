#include <bits/stdc++.h>
using namespace std;
 
void dfs(int i, int j, vector<vector<char>>& arr, vector<vector<bool>>& visited) {
    int n = arr.size(), m = arr[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || arr[i][j] == '#')
        return;
 
    visited[i][j] = true;
 
    dfs(i - 1, j, arr, visited);
    dfs(i + 1, j, arr, visited);
    dfs(i, j - 1, arr, visited);
    dfs(i, j + 1, arr, visited);
}
 
void Sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, arr, visited);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
 
int main() {
    Sol();
    return 0;
}