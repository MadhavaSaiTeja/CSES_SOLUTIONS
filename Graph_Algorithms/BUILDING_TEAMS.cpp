
/*Problem Link: https://cses.fi/problemset/task/1668 */

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> used(n, false);
    vector<int> color(n);
    queue<int> q;
    q.push(0);
    used[0] = true;
    color[0] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it: adj[node]) {
            if (!used[it]) {
                color[it] = color[node] ^ 1;
                used[it] = true;
                q.push(it);
            } else {
                if (color[it] == color[node]) {
                    //cout << it << " " << node << endl;
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            q.push(i);
            used[i] = true;
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it: adj[node]) {
                    if (!used[it]) {
                        color[it] = color[node] ^ 1;
                        used[it] = true;
                        q.push(it);
                    } else {
                        if (color[it] == color[node]) {
                            //cout << it << " " << node << endl;
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for(auto &i:color){
        i++;
    }
    for(auto i:color){
        cout << i << " ";
    }    
    cout << endl;
}