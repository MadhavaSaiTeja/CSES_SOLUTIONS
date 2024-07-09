
/*Problem link: https://cses.fi/problemset/task/1666/ */

#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define pb push_back
#define vpi vector<pair<int,int>>
#define ff first
#define ss second

void dfs(vvi &adj,int v,vector<bool>&used,vi &cc){
    used[v] = true;
    cc.pb(v);
    for(auto u : adj[v]){
        if(!used[u]){
            dfs(adj,u,used,cc);
        }
    }
}

int main() {

    int n,m; cin>>n>>m;
    vpi arr;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        arr.pb({a,b});
    }
    vvi adj(n+1);
    for(auto i:arr){
        adj[i.ff].pb(i.ss);
        adj[i.ss].pb(i.ff);
    }
    vvi comp;
    vector<bool>used(n+1,false);
    for(int i=1;i<=n;i++){
        if(!used[i]){
            vi cc;
            dfs(adj,i,used,cc);
            comp.pb(cc);
        }
    }
    vpi ans;
    for(int i=1; i < comp.size(); i++){
        ans.pb({comp[i - 1][0], comp[i][0]});
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.ff<<" "<<i.ss<<endl;
    }
    
    return 0;
}
