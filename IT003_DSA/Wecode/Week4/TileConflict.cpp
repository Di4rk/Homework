#include <iostream>
using namespace std;

struct hashtable {
    int M;
    int n;
    int conflict;
};

int main() {
    hashtable ht;
    int m, n;
    cin >> n >> m;
    if(n == 0) {
        cout << "GOOD";
        return 0;
    }

    ht.M = m;
    ht.n = 0;
    ht.conflict = 0;
    int* check = new int[m]{0};

    for(int i =0; i < n; ++i) {
        cin >> m;
        int index= m % ht.M; 
        ht.n++;
        ++check[index];
        if(check[index] > 1) {
            ht.conflict++;
        }
    }

    if(ht.conflict * 100 > ht.n * 33) {
        cout << "BAD";
    }
    else cout << "GOOD";
    return 0;
}