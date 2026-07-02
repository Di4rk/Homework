#include <iostream>
#include <vector>
using namespace std;


vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(visited[v] == false) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;
    
    for(int i = 0 ; i <= v; ++i) {
        visited[i] = false;
    }

    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    vector<int> D;
    for(int i = 1; i <= v; ++i) {
        if(visited[i] == true){
            D.push_back(i);
        }
    }

    if(D.empty()) {
        cout << "KHONG\n";  
    }
    else {
        for(int i : D) {
            cout << i << " ";
        }
    }
    return 0;
}