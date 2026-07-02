#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v,e;
    cin >> v >> e;

    for(int i =0 ; i< v; ++i) {
        visited[i] = false;
    }

    for(int i =0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;

    for(int i = 0; i < v; ++i) {
        if(!visited[i]) {
            ++cnt;
            dfs(i);
        }
    }

    cout << cnt; 
    return 0;
}