#include <iostream>
#include <climits>
using namespace std;

struct hashtable {
    int M;
    int n;
    bool* table;
};

int main() {
    hashtable ht;
    int m, n;
    cin >> n >> m;
    ht.M = m;
    ht.n = 0;
    ht.table = new bool[m];
    int *check = new int[m];
    for(int i = 0; i < m; ++i) {
        ht.table[i] = 0;
        check[i] = 0;
    }

    for(int i = 0; i < n; ++i) {
        cin >> m;
        int index = m % ht.M;
        if(ht.table[index] == 0) {
            ht.table[index] = 1;
            continue;
        }
        ++check[index];
    }

    int pivot = INT_MIN;
    for(int i = 0; i < ht.M; ++i) {
        if(check[i] > 0 && check[i] > pivot) {
            pivot = check[i];
        }
    }

    for(int i = 0; i < ht.M; ++i) {
        if(check[i] == pivot) {
            cout << i << "\n";
        }
    }
    return 0;
}