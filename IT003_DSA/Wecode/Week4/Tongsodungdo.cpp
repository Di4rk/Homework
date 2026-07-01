#include <iostream>
using namespace std;

struct Hashtable {
    int M;
    int n;
    int *x;
};

int main() {
    Hashtable table;
    int M, n;
    cin >> M >> n;
    table.M = M;
    table.x = new int[n];
    table.n = 0;
    for(int i = 0; i < M; ++i) {
        table.x[i] = 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> M;
        int index = M % table.M;
        int base_index = index;
        for(int j = 0; j < table.M; ++j) {
            index = (base_index + j) % table.M;
            if(table.x[index] == 0) {
                table.x[index] = M;
                ++table.n;
                break;
            }
            ++cnt;
        }
    }

    cout << cnt;
    return 0;
}