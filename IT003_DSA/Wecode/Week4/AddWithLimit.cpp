#include <iostream>
using namespace std;

struct hashtable {
    int M;
    int n;
    int* table;
};

int search(hashtable& tb, int x) {
    long long index = ((x % tb.M) + tb.M) % tb.M;
    long long base_index = index;
    int cnt = 0;
    for(int i =0; i < tb.M; ++i) {
        ++cnt;
        index = (base_index + i*i) % tb.M;
        if(tb.table[index] == x) {
            return cnt;
        }
        if(tb.table[index] == 0) {
            return 0;
        }
    }
    return 0;
}

int main() {
    int m, n;
    float LOAD;
    cin >> m >> LOAD >> n;
    
    hashtable tb;
    tb.M = m;
    tb.n = 0;
    tb.table = new int[m];
    for(int i =0; i < m; ++i) {
        tb.table[i] = 0;
    }

    for(int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        if(tb.n + 1> (LOAD * tb.M) + 1e-5) {
            continue;
        }

        long long index = ((key % tb.M) + tb.M) % tb.M;
        long long base_index = index;
        for(int j = 0; j < tb.M; ++j) {
            index = (base_index + j*j) % tb.M;
            if(tb.table[index] == 0) {
                tb.table[index] = key;
                ++tb.n;
                break;
            }
        }
    }

    cin >> n;
    for(int i= 0; i < n; ++i) {
        int key;
        cin >> key;
        if(search(tb, key)) {
            cout << search(tb,key);
        }
        else cout << "KHONG";
        cout << endl;
    }

    return 0;
}