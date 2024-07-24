/* Problem link: https://cses.fi/problemset/task/1671 */

#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
#define ll long long
#define int ll


int32_t main(){

    int n,m; cin >> n >> m;
    vector<pair<int,int>> adj[n];

    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b,c});
    }

    vector<int>dist(n, INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int d = top.first,node = top.second;
        if (d > dist[node]) continue;
        for(auto it : adj[node]){
            int wt = it.second,adjNode = it.first;
            if(d + wt < dist[adjNode]){
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    
    for(auto i : dist){
        cout << i << " ";
    }
    cout << endl;
}