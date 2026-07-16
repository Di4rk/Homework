#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int left = -1;
    int right = -1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> key(n + 1);
    for(int i = 1; i < n+1; ++i) {
        cin >> key[i];
    }

    vector<node> tree(n + 1);
    vector<bool> has_parent(n + 1, false);

    for(int i = 0; i < n; ++i) {
        int id, id_left, id_right;
        cin >> id >> id_left >> id_right;

        tree[id].left = id_left;
        tree[id].right = id_right;
        
        if(id_left != -1) {
            has_parent[id_left] = true;
        }

        if(id_right != -1) {
            has_parent[id_right] = true;
        }
    }

    int root = -1;
    for(int i = 1; i <= n; ++i) {
        if(!has_parent[i]) {
            root = i;
            break;
        }
    }

    if(root == -1) {
        return 0;
    }

    queue<int> q;
    q.push(root);

    vector<long long> level_sum;

    while(!q.empty()) {
        int level_size = q.size();
        long long  current_level_sum = 0;

        for(int i = 0; i < level_size; ++i) {
            int u = q.front();
            q.pop();

            current_level_sum += key[u];

            if(tree[u].left != -1) {
                q.push(tree[u].left);
            }
            if(tree[u].right != -1) {
                q.push(tree[u].right);
            }
        }

        level_sum.push_back(current_level_sum);
    }

    for(size_t i = 0; i < level_sum.size(); ++i) {
        cout << level_sum[i] << (i + 1 == level_sum.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}