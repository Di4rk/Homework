#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<int> vertex(1005, 0);
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        vertex[u]++;
        vertex[v]++;
    }

    int isolate_vertex = 0;
    for(int i = 0; i < v; ++i) {
        if(vertex[i] == 0) {
            isolate_vertex++;
        }
    }
    cout << isolate_vertex;
    return 0;
}