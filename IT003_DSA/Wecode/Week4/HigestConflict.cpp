#include <iostream>
using namespace std;

struct hashtable{
    int M;
    int n;
    int *table;
};

int main() {
    int m, n;
    cin >> n >> m;
    hashtable htb;
    htb.M = m;
    htb.n = 0;
    htb.table = new int[m];
    int* check = new int[m];
    for(int i = 0; i < m; ++i) {
        htb.table[i] = 0;
        check[i] = 0;
    }

    int pivot = 0;

    for(int i = 0; i < n; ++i) {
        cin >> m;
        int index = m % htb.M;
        int base_index = index;
        
        for(int j = 0; j < htb.M; ++j) {
            index = (base_index + j) % htb.M;
            if(htb.table[index] == 0) {
                htb.table[index] = m;
                htb.n++;
                break;
            }
            ++check[index];
            if(check[index] > pivot) {
                pivot = check[index];
            }
        }
    }
    for(int i = 0; i < htb.M; ++i) {
        if(check[i] == pivot) cout << i << " ";
    }
    return 0;
}